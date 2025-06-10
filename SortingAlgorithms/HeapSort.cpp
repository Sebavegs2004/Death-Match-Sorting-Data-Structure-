#include <vector>               // Para usar std::vector
#include "../sorting_lib.h"     // Declaración de heapSort y heapify
#include <cstdint>              // Tipos enteros como int32_t

// Reorganiza un subárbol con raíz en el índice i para mantener la propiedad de heap máximo.
// 'n' es el tamaño del heap. Si un hijo es mayor que el padre, se intercambian y se aplica recursivamente.
void heapify(std::vector<int32_t>& arr, int n, int i) {
    int largest = i;           // Índice del nodo más grande
    int l = 2 * i + 1;         // Hijo izquierdo
    int r = 2 * i + 2;         // Hijo derecho

    // Si el hijo izquierdo es mayor que la raíz
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // Si el hijo derecho es mayor que el más grande hasta ahora
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // Si el nodo más grande no era la raíz
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        // Aplicar heapify recursivamente sobre el subárbol afectado
        heapify(arr, n, largest);
    }
}

// Ordena un vector de enteros usando Heap Sort.
// Primero construye un heap máximo, luego intercambia el primer elemento con el último,
// reduce el tamaño del heap y aplica heapify para restaurar el orden.
void heapSort(std::vector<int32_t>& arr) {
    int n = arr.size();

    // Construir el heap máximo (reordenar el arreglo)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extraer elementos uno por uno del heap
    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);    // Mover la raíz actual al final
        heapify(arr, i, 0);           // Restaurar la propiedad de heap en el resto
    }
}
