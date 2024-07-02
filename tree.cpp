#include <iostream>
#include <map>
#include <memory>
#include <string>

// Define the valtab map to hold variable values
std::map<char, int> valtab;

// Tree node class definition
class Tree {
public:
    std::string op;
    int value;
    char var;
    std::shared_ptr<Tree> left;
    std::shared_ptr<Tree> right;

    // Constructor for value nodes
    Tree(int val) : op(""), value(val), var(0), left(nullptr), right(nullptr) {}

    // Constructor for variable nodes
    Tree(char v) : op(""), value(0), var(v), left(nullptr), right(nullptr) {}

    // Constructor for operator nodes
    Tree(const std::string& operation, const Tree& l, const Tree& r)
        : op(operation), value(0), var(0), left(std::make_shared<Tree>(l)), right(std::make_shared<Tree>(r)) {}

    // Evaluate the tree
    int eval() const {
        if (op.empty()) {
            if (var != 0) {
                return valtab[var]; // return value from valtab for variable nodes
            }
            return value; // return value for value nodes
        }
        int leftVal = left->eval();
        int rightVal = right->eval();
        if (op == "+") return leftVal + rightVal;
        if (op == "-") return leftVal - rightVal;
        if (op == "*") return leftVal * rightVal;
        if (op == "/") return leftVal / rightVal;
        throw std::invalid_argument("Unsupported operation");
    }
};

// Overload operator<< to print the tree
std::ostream& operator<<(std::ostream& os, const Tree& tree) {
    if (tree.op.empty()) {
        if (tree.var != 0) {
            os << tree.var;
        } else {
            os << tree.value;
        }
    } else {
        os << "(" << *tree.left << " " << tree.op << " " << *tree.right << ")";
    }
    return os;
}

int main() {
    // Initialize variable values in valtab
    valtab['A'] = 3;
    valtab['B'] = 4;
    std::cout << "A = 3, B = 4" << std::endl;

    // Create expression trees
    Tree t1 = Tree("*", Tree("-", 5), Tree("+", Tree('A'), Tree(4)));
    Tree t2 = Tree("+", Tree("-", Tree('A'), Tree(1)), Tree("+", t1, Tree('B')));

    // Print the trees and their evaluations
    std::cout << "t1 = " << t1 << " ; t2 = " << t2 << std::endl;
    std::cout << "t1: " << t1.eval() << " t2: " << t2.eval() << std::endl;

    return 0;
}
