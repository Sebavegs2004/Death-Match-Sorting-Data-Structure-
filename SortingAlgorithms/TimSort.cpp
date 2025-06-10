#include <vector>              // Para usar el contenedor dinámico std::vector
#include <cstdint>             // Para tipos enteros de tamaño fijo como int32_t
#include <algorithm>           // Para std::min
#include "../sorting_lib.h"    // Declaracion timSort

// -----------------------------------------------------------------------------
// insertionSort_tim
// Ordena un subarreglo de arr utilizando el algoritmo de inserción.
// Se aplica sobre el segmento [left, right].
// -----------------------------------------------------------------------------
void insertionSort_tim(std::vector<int32_t>& arr, int left, int right)
{
    for (int i = left + 1; i <= right; i++) {
        int temp = arr[i];
        int j = i - 1;

        // Desplaza hacia la derecha los elementos mayores que temp
        while (j >= left && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Inserta el elemento en su posición ordenada
        arr[j + 1] = temp;
    }
}

// -----------------------------------------------------------------------------
// merge_tim
// Realiza la fusión de dos subarreglos ordenados:
// arr[l..m] y arr[m+1..r], y almacena el resultado combinado en arr[l..r].
// -----------------------------------------------------------------------------
void merge_tim(std::vector<int32_t>& arr, int l, int m, int r)
{
    int len1 = m - l + 1;
    int len2 = r - m;

    // Crear vectores temporales para los dos subarreglos
    std::vector<int32_t> left(len1);
    std::vector<int32_t> right(len2);

    // Copiar los elementos correspondientes a los subarreglos
    for (int i = 0; i < len1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < len2; i++)
        right[i] = arr[m + 1 + i];

    // Índices para iterar sobre left, right y arr
    int i = 0, j = 0, k = l;

    // Fusionar los elementos ordenadamente en arr
    while (i < len1 && j < len2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // Copiar los elementos restantes (si hay) del subarreglo izquierdo
    while (i < len1) {
        arr[k] = left[i];
        k++;
        i++;
    }

    // Copiar los elementos restantes (si hay) del subarreglo derecho
    while (j < len2) {
        arr[k] = right[j];
        k++;
        j++;
    }
}

// -----------------------------------------------------------------------------
// timSort
// Implementación simplificada del algoritmo TimSort.
// Combina ordenamiento por inserción y mezcla para lograr eficiencia en la práctica.
// -----------------------------------------------------------------------------
void timSort(std::vector<int32_t>& arr, int n)
{
    // Paso 1: dividir el arreglo en bloques de tamaño fijo y ordenarlos con insertion sort
    for (int i = 0; i < n; i += 32)
        insertionSort_tim(arr, i, std::min(i + 31, n - 1));

    // Paso 2: fusionar los bloques de forma progresiva duplicando el tamaño en cada paso
    for (int size = 32; size < n; size = 2 * size) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = left + size - 1;
            int right = std::min(left + 2 * size - 1, n - 1);

            // Solo fusionar si mid < right (es decir, si existe segundo bloque)
            if (mid < right)
                merge_tim(arr, left, mid, right);
        }
    }
}
