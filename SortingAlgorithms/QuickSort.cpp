#include <vector>               // Para el uso de std::vector
#include "../sorting_lib.h"     // Declaración de quickSort 
#include <cstdint>              // Tipos enteros con tamaño fijo (int32_t)
#include <random>               // Para generación de pivotes aleatorios

// Realiza la partición del vector usando el esquema de Lomuto.
// Toma el último elemento como pivote y reorganiza el subarreglo vec[low..high]
// de forma que todos los elementos menores o iguales al pivote quedan a la izquierda,
// y los mayores a la derecha. Devuelve la posición final del pivote.
int partition(std::vector<int32_t>& vec, int low, int high) {
    int pivot = vec[high];         // Usamos el último elemento como pivote
    int i = low - 1;               // i rastrea la frontera de elementos <= pivote

    // Recorremos el subarreglo desde low hasta high-1
    for (int j = low; j <= high - 1; ++j) {
        if (vec[j] <= pivot) {
            ++i;
            std::swap(vec[i], vec[j]);  // Colocamos elementos menores o iguales al pivote
        }
    }

    std::swap(vec[i + 1], vec[high]);   // Colocamos el pivote en su lugar final
    return i + 1;                       // Retornamos la nueva posición del pivote
}


// Ordena el vector utilizando el algoritmo QuickSort con optimización de cola y pivote aleatorio.
// Esta implementación:
// - Utiliza un pivote aleatorio para evitar el peor caso en arreglos parcialmente ordenados.
// - Aplica optimización de cola (tail recursion optimization) para reducir el uso de pila.

void quickSort(std::vector<int32_t>& vec, int low, int high) {
    static std::mt19937 gen{std::random_device{}()};  // Generador aleatorio global (una sola vez)

    // QuickSort iterativo usando optimización de cola
    while (low < high) {
        // Elegimos un pivote aleatorio entre low y high
        std::uniform_int_distribution<> dist(low, high);
        std::swap(vec[dist(gen)], vec[high]);  // Lo movemos al final

        // Particionamos el arreglo alrededor del pivote
        int pi = partition(vec, low, high);

        // Optimización: procesar primero el lado más pequeño
        int leftSize  = pi - low;
        int rightSize = high - pi;

        if (leftSize < rightSize) {
            // Ordenamos recursivamente la parte izquierda
            quickSort(vec, low, pi - 1);
            // Continuamos en el bucle con la parte derecha
            low = pi + 1;
        } else {
            // Ordenamos recursivamente la parte derecha
            quickSort(vec, pi + 1, high);
            // Continuamos en el bucle con la parte izquierda
            high = pi - 1;
        }
    }
}
