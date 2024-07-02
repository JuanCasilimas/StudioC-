/*
Hex mk2 montecarlo game Code
jcasilimas coder 
jun 12, 2024 
*/

#include <iostream>
#include <vector>
#include <set>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <limits>
#include <cmath>

class HexBoard {
public:
    HexBoard(int size = 11) : size(size), board(size, std::vector<char>(size, '.')) {
        // Initialize the random number generator seed
        srand(time(NULL));
    }

    // Display the current state of the board
    void displayBoard() {
        for (int i = 0; i < size; ++i) {
            for (int k = 0; k < i; ++k) std::cout << " ";
            for (int j = 0; j < size; ++j) {
                std::cout << board[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    // Check if a move is legal
    bool isLegalMove(int x, int y) {
        return x >= 0 && x < size && y >= 0 && y < size && board[x][y] == '.';
    }

    // Make a move on the board
    bool makeMove(int x, int y, char player) {
        if (isLegalMove(x, y)) {
            board[x][y] = player;
            return true;
        }
        return false;
    }

    // Check if the specified player has won
    bool checkWinner(char player) {
        std::set<std::pair<int, int>> visited;
        if (player == 'B') {
            for (int i = 0; i < size; ++i) {
                if (board[i][0] == 'B' && dfs(i, 0, player, visited)) {
                    return true; // Player Blue wins if a path is found from left to right "sidewall"
                }
            }
        } else if (player == 'R') {
            for (int i = 0; i < size; ++i) {
                if (board[0][i] == 'R' && dfs(0, i, player, visited)) {
                    return true; // Player Red wins if a path is found from top to bottom "Tob-bottom"
                }
            }
        }
        return false;
    }

    // Make a random move for the specified player
    void makeRandomMove(char player) {
        int x, y;
        do {
            x = rand() % size;
            y = rand() % size;
        } while (!isLegalMove(x, y));
        makeMove(x, y, player);
    }

    // Get all legal moves on the board
    std::vector<std::pair<int, int>> getLegalMoves() {
        std::vector<std::pair<int, int>> moves;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (isLegalMove(i, j)) {
                    moves.emplace_back(i, j);
                }
            }
        }
        return moves;
    }

    // Reset the board to its initial state
    void reset() {
        board = std::vector<std::vector<char>>(size, std::vector<char>(size, '.'));
    }

    // Get the current state of the board
    std::vector<std::vector<char>> getBoard() {
        return board;
    }

private:
    int size;
    std::vector<std::vector<char>> board;

    // Depth-First Search to check for a winning path
    bool dfs(int x, int y, char player, std::set<std::pair<int, int>>& visited) {
        if ((player == 'B' && y == size - 1) || (player == 'R' && x == size - 1)) {
            return true; // If the path reaches the opposite side, the player wins
        }

        visited.insert({x, y});

        // Define the possible directions to move
        std::vector<std::pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, 1}, {1, -1}};
        for (const auto& dir : directions) {
            int nx = x + dir.first;
            int ny = y + dir.second;

            // Check if the next move is valid and has the same player's piece
            if (nx >= 0 && nx < size && ny >= 0 && ny < size && board[nx][ny] == player && visited.find({nx, ny}) == visited.end()) {
                if (dfs(nx, ny, player, visited)) {
                    return true; // Continue searching recursively
                }
            }
        }
        return false; // No winning path found
    }
};

class HexGame {
public:
    HexGame(int size = 11) : board(size), boardSize(size) {}

    // Main game loop
    void playGame() {
        while (true) {
            board.displayBoard();
            playerMove('B'); // Player 'B' makes a move
            if (board.checkWinner('B')) {
                board.displayBoard(); // Display the board after the winning move
                std::cout << "Blue won!" << std::endl;
                break;
            }
            board.displayBoard();
            aiMove('R'); // AI (player 'R') makes a move
            if (board.checkWinner('R')) {
                board.displayBoard(); // Display the board after the winning move
                std::cout << "Red won!" << std::endl;
                break;
            }
        }
    }

private:
    HexBoard board;
    int boardSize;

    // the user now can handle the player as blue
    void playerMove(char player) {
        int x, y;
        while (true) {
            std::cout << "Enter move for " << (player == 'B' ? "Blue" : "Red") << " (row and column): ";
            std::cin >> x >> y;
            if (std::cin.fail()) {
                std::cin.clear(); // Clear the error flag
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter numeric values." << std::endl;
                continue;
            }
            if (board.makeMove(x, y, player)) {
                break;
            } else {
                std::cout << "Illegal move. Try again." << std::endl;
            }
        }
    }

    // AIMOVE
    void aiMove(char player) {
        std::pair<int, int> bestMove = monteCarloMove(player);
        board.makeMove(bestMove.first, bestMove.second, player);
        std::cout << "AI moves at: (" << bestMove.first << ", " << bestMove.second << ")" << std::endl;
    }

    // Determine the best move using Monte Carlo simulations as said
    std::pair<int, int> monteCarloMove(char player) {
        int simulations = 100; 
        std::vector<std::pair<int, int>> legalMoves = board.getLegalMoves();
        std::vector<int> moveWins(legalMoves.size(), 0);

        for (int i = 0; i < simulations; ++i) {
            for (size_t j = 0; j < legalMoves.size(); ++j) {
                HexBoard simBoard = board; // Copy the board for simulation
                simBoard.makeMove(legalMoves[j].first, legalMoves[j].second, player);
                if (simulateRandomGame(simBoard, player)) {
                    moveWins[j]++;
                }
            }
        }

        int bestMoveIndex = std::distance(moveWins.begin(), std::max_element(moveWins.begin(), moveWins.end()));
        return legalMoves[bestMoveIndex];
    }

    // Simulate a random game to completion
    bool simulateRandomGame(HexBoard& simBoard, char player) {
        char currentPlayer = player;
        while (true) {
            simBoard.makeRandomMove(currentPlayer);
            if (simBoard.checkWinner(currentPlayer)) {
                return currentPlayer == player;
            }
            currentPlayer = (currentPlayer == 'B') ? 'R' : 'B';
        }
    }
};

int main() {
    HexGame game;
    std::cout << "The sidewalls are blue And the top-bottom are red" << std::endl;
    game.playGame();
    return 0;
}
