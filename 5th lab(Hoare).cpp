#include <iostream>
#include <ctime>
#include <cstdlib>

void isSorted(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i - 1] > arr[i]) {
            std::cout << "array was not sorted" << std::endl;
            return;
        }
    }
    std::cout << "array was sorted" << std::endl;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = (low - 1); 

        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[high]);

        int partitionIndex = i + 1; 

        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }
}

int main() {
    srand(time(0)); 

    const int n = 10; 
    int arr[n];

    std::cout << "given array: ";
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    quickSort(arr, 0, n - 1);

    std::cout << " sorted array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    isSorted(arr, n);

    return 0;
}
