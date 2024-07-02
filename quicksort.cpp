#include <iostream>
#include <vector>

// Función para realizar el particionamiento del array
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Elegir el pivote
    int i = low - 1; // Índice del elemento más pequeño

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]); // Intercambiar elementos
        }
    }
    std::swap(arr[i + 1], arr[high]); // Colocar el pivote en su posición correcta
    return i + 1;
}

// Función recursiva para ordenar el array
void quicksort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot_index = partition(arr, low, high);
        quicksort(arr, low, pivot_index - 1); // Ordenar subarray izquierdo
        quicksort(arr, pivot_index + 1, high); // Ordenar subarray derecho
    }
}

// Función principal
int main() {
    std::vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();
    quicksort(arr, 0, n - 1);
    std::cout << "Array ordenado: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    return 0;
}
