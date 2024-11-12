#include <iostream>
#include <vector>
#include <chrono>

// Declaração da função partition
int partition(std::vector<int>& arr, int low, int high);

void quicksort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

// Definição da função partition
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

int main() {
    std::vector<int> arr = {10, 7, 8, 9, 1, 5, 10, 7, 8, 9, 1, 5 ,12, 44,44,53,54,45,45};
    int n = arr.size();

    // Inicia a medição de tempo
    auto start = std::chrono::high_resolution_clock::now();

    quicksort(arr, 0, n - 1);

    // Finaliza a medição de tempo
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    std::cout << "Sorted array: ";
    printArray(arr);
    std::cout << "Execution time: " << duration.count() << " seconds" << std::endl;

    return 0;
}
