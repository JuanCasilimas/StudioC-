/*
Hex game Code
jcasilimas coder 
jun 10, 2024 
*/

#include <iostream>
#include <vector>
#include <set>
#include <cstdlib>
#include <ctime>

class HexBoard {
public:
    HexBoard(int size = 7) : size(size), board(size, std::vector<char>(size, '.')) {
        // Initialize random number generator seed
        srand(time(NULL));
    }

    // Display the current state of the board
    void displayBoard() {
        for (int i = 0; i < size; ++i) {
            for (int k = 0; k < i; ++k) std::cout << " "; // Spaces to make the board hexagonal
            for (int j = 0; j < size; ++j) {
                std::cout << board[i][j] << " "; // Display each cell with its contents
            }
            std::cout << std::endl; // Move to the next row
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
                    return true; // Player 'B' wins if a path is found from left to right
                }
            }
        } else if (player == 'R') {
            for (int i = 0; i < size; ++i) {
                if (board[0][i] == 'R' && dfs(0, i, player, visited)) {
                    return true; // Player 'R' wins if a path is found from top to bottom
                }
            }
        }
        return false;
    }

    // Random move each player
    void makeRandomMove(char player) {
        int x, y;
        do {
            x = rand() % size;
            y = rand() % size;
        } while (!isLegalMove(x, y));
        makeMove(x, y, player);
    }

private:
    int size;
    std::vector<std::vector<char>> board;

    // Depth first search to check for a winning path
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

            // And this will check if the next move is valid and has the same player's piece
            if (nx >= 0 && nx < size && ny >= 0 && ny < size && board[nx][ny] == player && visited.find({nx, ny}) == visited.end()) {
                if (dfs(nx, ny, player, visited)) {
                    return true; // This is a continue searching recursively
                }
            }
        }
        return false; // No winning path found
    }
};

int main() {
    HexBoard board;

    std::cout << "The sidewalls are blue And the top-bottom are red" << std::endl;

    // Display the initial board
    board.displayBoard();
    
    // Make random moves for both players
    for (int i = 0; i < 7 * 7 / 2; ++i) { // Maximum possible number of moves
        board.makeRandomMove('B');
        board.displayBoard();
        board.makeRandomMove('R');
        board.displayBoard();
    }


    // Check if there is a winner for each player
    std::cout << "Blue won?: " << (board.checkWinner('B') ? "Yes" : "No") << std::endl;
    std::cout << "Red won?: " << (board.checkWinner('R') ? "Yes" : "No") << std::endl; 

    return 0;
}
