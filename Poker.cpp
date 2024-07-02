#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

// Estructura para representar una carta
struct Carta {
    std::string valor;
    std::string palo;

    // Mostrar la carta
    void mostrar() const {
        std::cout << valor << " de " << palo << std::endl;
    }
};

// Estructura para representar la mano de un jugador
struct Mano {
    std::vector<Carta> cartas;

    // Mostrar la mano
    void mostrar() const {
        for (const auto& carta : cartas) {
            carta.mostrar();
        }
        std::cout << std::endl;
    }
};

// Función para crear un mazo de cartas
std::vector<Carta> crearMazo() {
    std::vector<Carta> mazo;
    std::vector<std::string> valores = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    std::vector<std::string> palos = {"Corazones", "Diamantes", "Tréboles", "Picas"};

    for (const auto& palo : palos) {
        for (const auto& valor : valores) {
            mazo.push_back({valor, palo});
        }
    }
    return mazo;
}

// Función para barajar el mazo
void barajarMazo(std::vector<Carta>& mazo) {
    std::random_device rd;         // Generador de entropía no determinística
    std::mt19937 g(rd());          // Motor de números pseudoaleatorios inicializado con la semilla del random_device
    std::shuffle(mazo.begin(), mazo.end(), g);  // Mezclar el mazo usando el motor de números aleatorios
}

// Función para repartir cartas
Mano repartirMano(std::vector<Carta>& mazo) {
    Mano mano;
    for (int i = 0; i < 5; ++i) {
        mano.cartas.push_back(mazo.back());
        mazo.pop_back();
    }
    return mano;
}

// Función para evaluar la mano (simplificada, sólo compara la carta más alta)
int evaluarMano(const Mano& mano) {
    std::vector<std::string> valores = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    int maxIndice = -1;
    for (const auto& carta : mano.cartas) {
        auto it = std::find(valores.begin(), valores.end(), carta.valor);
        int indice = std::distance(valores.begin(), it);
        if (indice > maxIndice) {
            maxIndice = indice;
        }
    }
    return maxIndice;
}

// Función principal
int main() {
    std::vector<Carta> mazo = crearMazo();
    barajarMazo(mazo);

    Mano jugador1 = repartirMano(mazo);
    Mano jugador2 = repartirMano(mazo);

    std::cout << "Mano del Jugador 1:" << std::endl;
    jugador1.mostrar();
    std::cout << "Mano del Jugador 2:" << std::endl;
    jugador2.mostrar();

    int valor1 = evaluarMano(jugador1);
    int valor2 = evaluarMano(jugador2);

    if (valor1 > valor2) {
        std::cout << "El Jugador 1 gana!" << std::endl;
    } else if (valor2 > valor1) {
        std::cout << "El Jugador 2 gana!" << std::endl;
    } else {
        std::cout << "Es un empate!" << std::endl;
    }

    return 0;
}
