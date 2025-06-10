#include <vector>              // Para el uso del contenedor dinámico std::vector
#include <algorithm>           // Para la función std::sort
#include <cstdint>             // Para tipos de tamaño fijo como int32_t
#include "../sorting_lib.h"    // Declaración de STLSort 


// Esta función utiliza el algoritmo de ordenamiento por defecto de la STL, 
// que es un híbrido llamado **Introsort**, una combinación de:
// QuickSort (rápido en la mayoría de los casos)
// HeapSort (para evitar el peor caso de QuickSort)
// InsertionSort (para arreglos pequeños)
  
void STLSort(std::vector<int32_t>& vec) {
    std::sort(vec.begin(), vec.end());
}
