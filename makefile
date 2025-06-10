# Nombre del ejecutable
TARGET = sortingtest

# Archivos fuente
SRCS = main.cpp SortingAlgorithms/InsertionSort.cpp SortingAlgorithms/MergeSort.cpp SortingAlgorithms/QuickSort.cpp SortingAlgorithms/STLSort.cpp SortingAlgorithms/HeapSort.cpp SortingAlgorithms/TimSort.cpp

# Compilador y banderas
CXX = g++
CXXFLAGS = -Wall -std=c++17

# Regla principal
all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

# Limpieza
clean:
	rm -f $(TARGET)
