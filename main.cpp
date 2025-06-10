#include "sorting_lib.h"         // Biblioteca con las implementaciones de los algoritmos de ordenamiento
#include <fstream>               // Para lectura de archivos binarios
#include <vector>                // Contenedor dinámico para manejar los datos
#include <cstdint>               // Tipos de datos de tamaño fijo como int32_t
#include <iostream>              // Entrada/salida estándar
#include <chrono>                // Para medir tiempos de ejecución

// Lee un archivo binario que contiene enteros de 32 bits y los carga en un vector
std::vector<int32_t> leerArchivoBinario(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo, std::ios::binary);
    std::vector<int32_t> datos;

    // Verifica si el archivo pudo abrirse correctamente
    if (!archivo) {
        std::cerr << "Error al abrir el archivo: " << nombreArchivo << std::endl;
        return datos;
    }

    // Obtiene el tamaño total del archivo
    archivo.seekg(0, std::ios::end);
    std::streamsize size = archivo.tellg();
    archivo.seekg(0, std::ios::beg);

    // Calcula la cantidad de elementos int32_t que contiene
    size_t cantidad = size / sizeof(int32_t);
    datos.resize(cantidad);

    // Lee todo el contenido al vector
    archivo.read(reinterpret_cast<char*>(datos.data()), size);

    return datos;
}

int main(int argc, char* argv[])
{
    // Validación del número de argumentos
    if (argc != 2) {
        std::cerr << "Uso: " << argv[0] << " archivo.bin" << std::endl;
        return 1;
    }

    // Variables para acumular los tiempos de ejecución de cada algoritmo
    double insertionSort_prom = 0;
    double mergeSort_prom = 0;
    double quickSort_prom = 0;
    double heapSort_prom = 0;
    double STLSort_prom = 0;
    double timSort_prom = 0;

    // Leer el archivo binario y cargarlo en un vector
    std::string archivo = argv[1];
    std::vector<int32_t> datos = leerArchivoBinario(archivo);
    int vector_size = datos.size();

    // ======================
    // Insertion Sort (no se ejecuta actualmente)
    // ======================
    for(int tries = 0; tries < 1; tries++){
        std::vector<int32_t> datos_copia = datos;  
        auto start = std::chrono::high_resolution_clock::now();
        insertionSort(datos_copia, vector_size);
        auto end = std::chrono::high_resolution_clock::now();
        insertionSort_prom += std::chrono::duration<double>(end - start).count();
    }
    std::cout << "FIN insertionSort" << std::endl;

    // ======================
    // Merge Sort
    // ======================
    for(int tries = 0; tries < 20; tries++){
        std::vector<int32_t> datos_copia = datos;
        auto start = std::chrono::high_resolution_clock::now();
        mergeSort(datos_copia, 0, vector_size - 1);
        auto end = std::chrono::high_resolution_clock::now();
        mergeSort_prom += std::chrono::duration<double>(end - start).count();
    }
    std::cout << "FIN mergeSort" << std::endl;

    // ======================
    // Quick Sort
    // ======================
    for(int tries = 0; tries < 20; tries++){
        std::vector<int32_t> datos_copia = datos;
        auto start = std::chrono::high_resolution_clock::now();
        quickSort(datos_copia, 0 , vector_size - 1);
        auto end = std::chrono::high_resolution_clock::now();
        quickSort_prom += std::chrono::duration<double>(end - start).count();
    }
    std::cout << "FIN quickSort" << std::endl;

    // ======================
    // STL Sort (std::sort)
    // ======================
    for(int tries = 0; tries < 20; tries++){
        std::vector<int32_t> datos_copia = datos;
        auto start = std::chrono::high_resolution_clock::now();
        STLSort(datos_copia);
        auto end = std::chrono::high_resolution_clock::now();
        STLSort_prom += std::chrono::duration<double>(end - start).count();
    }
    std::cout << "FIN STLSort" << std::endl;

    // ======================
    // Heap Sort
    // ======================
    for(int tries = 0; tries < 20; tries++){
        std::vector<int32_t> datos_copia = datos;
        auto start = std::chrono::high_resolution_clock::now();
        heapSort(datos_copia);
        auto end = std::chrono::high_resolution_clock::now();
        heapSort_prom += std::chrono::duration<double>(end - start).count();
    }
    std::cout << "FIN heapSort" << std::endl;

    // ======================
    // Tim Sort
    // ======================
    for(int tries = 0; tries < 20; tries++){
        std::vector<int32_t> datos_copia = datos;
        auto start = std::chrono::high_resolution_clock::now();
        timSort(datos_copia, vector_size);
        auto end = std::chrono::high_resolution_clock::now();
        timSort_prom += std::chrono::duration<double>(end - start).count();
    }
    std::cout << "FIN timSort" << std::endl;

    // ======================
    // Resultados promedio
    // ======================
    std::cout << "Tiempos:" << std::endl << 
    "Insertion Sort = " << insertionSort_prom  << std::endl <<
    "Merge Sort = " << mergeSort_prom / 20 << std::endl <<
    "Quick Sort = " << quickSort_prom / 20 << std::endl <<
    "STL Sort = " << STLSort_prom / 20 << std::endl <<
    "Heap Sort = " << heapSort_prom / 20 << std::endl <<
    "Tim Sort = " << timSort_prom / 20 << std::endl;

    return 0;
}
