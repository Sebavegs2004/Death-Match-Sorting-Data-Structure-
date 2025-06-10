#ifndef SORTING_LIB_H
#define SORTING_LIB_H

#include <vector>     // Para usar std::vector
#include <cstdint>    // Para usar int32_t

// Ordena un vector de enteros usando Insertion Sort.
void insertionSort(std::vector<int32_t>& arr, int n);

// Ordena un vector de enteros usando Merge Sort.
void mergeSort(std::vector<int32_t>& arr, int left, int right);

// Ordena un vector usando Quick
void quickSort(std::vector<int32_t>& vec, int low, int high);

// Ordena un vector usando la función std::sort de la STL.
void STLSort(std::vector<int32_t>& vec);

// Ordena un vector usando Heap Sort.
void heapSort(std::vector<int32_t>& arr);

// Ordena un vector usando Tim Sort.
void timSort(std::vector<int32_t>& arr, int n);

#endif
