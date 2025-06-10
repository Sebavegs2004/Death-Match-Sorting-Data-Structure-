#include <vector>               // Para usar std::vector
#include "../sorting_lib.h"     // Declaración de mergeSort y merge
#include <cstdint>              // Tipos enteros fijos como int32_t

// Combina dos subarreglos ordenados dentro del vector arr.
// El primero va de 'left' a 'mid', y el segundo de 'mid+1' a 'right'.
void merge(std::vector<int32_t>& arr, int left, int mid, int right)
{
    int n1 = mid - left + 1; // Tamaño del subarreglo izquierdo
    int n2 = right - mid;    // Tamaño del subarreglo derecho

    // Crear copias de los subarreglos
    std::vector<int32_t> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Fusionar los subarreglos en arr[left..right]
    int i = 0, j = 0;
    int k = left;

    // Comparar elementos de L y R, y copiar el menor a arr
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiar cualquier elemento restante de L
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copiar cualquier elemento restante de R
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Aplica el algoritmo Merge Sort al vector arr entre las posiciones left y right.
// Divide el arreglo en mitades, ordena cada mitad recursivamente y luego las fusiona.
void mergeSort(std::vector<int32_t>& arr, int left, int right)
{
    if (left >= right)
        return; // Caso base: subarreglo de 1 solo elemento

    int mid = left + (right - left) / 2;

    // Ordenar la mitad izquierda y la mitad derecha
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    // Combinar las dos mitades ordenadas
    merge(arr, left, mid, right);
}
