#include <vector>               // Para usar std::vector
#include "../sorting_lib.h"     // Declaración de insertionSort
#include <cstdint>              // Tipos enteros como int32_t

// Ordena un vector de enteros usando el algoritmo de Insertion Sort.
// Recorre el arreglo desde el segundo elemento y lo inserta en la posición correcta
// dentro de la parte ya ordenada del arreglo.
void insertionSort(std::vector<int32_t>& arr, int n)
{
    for (int i = 1; i < n; ++i) {
        int key = arr[i];     // Elemento actual a insertar
        int j = i - 1;

        // Desplaza los elementos mayores que 'key' una posición a la derecha
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        // Inserta 'key' en su posición ordenada
        arr[j + 1] = key;
    }
}

