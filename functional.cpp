#include <iostream>
#include <vector>
#include <numeric>  // Para std::accumulate

// Functor que multiplica los valores y lleva un contador de cuántos elementos ha procesado
class Multiplier {
private:
    int count;  // Estado interno para llevar el conteo de elementos procesados
public:
    Multiplier() : count(0) {}

    int operator()(int total, int value) {
        count++;
        return total * value;
    }

    int getCount() const {
        return count;
    }
};

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    Multiplier multiplier;
    int product = std::accumulate(vec.begin(), vec.end(), 1, multiplier);
    std::cout << "El producto es: " << product << std::endl;  // Output: El producto es: 120
    std::cout << "Se procesaron " << multiplier.getCount() << " elementos." << std::endl;  // Output: Se procesaron 5 elementos.
    return 0;
}