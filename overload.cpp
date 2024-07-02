#include <iostream>

void f(int a) {
    std::cout << "Function f with int: " << a << std::endl;
}

void f(double a) {
    std::cout << "Function f with double: " << a << std::endl;
}

void f(int a, double b) {
    std::cout << "Function f with int and double: " << a << ", " << b << std::endl;
}

int main() {
    f(10);        // Llama a f(int)
    f(10.5);      // Llama a f(double)
    f(10, 10.5);  // Llama a f(int, double)
    return 0;
}