#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>

std::vector<int> generateArray(int n) {
    srand(time(0));
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 100;
    }
    return arr;
}

void isSorted(const std::vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i - 1] > arr[i]) {
            std::cout << "array was not sorted" << std::endl;
            return;
        }
    }
    std::cout << "  array was sorted" << std::endl;
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        int pivot = arr[mid];
        int i = low;
        int j = high;

        while (i <= j) {
            while (arr[i] < pivot) {
                i++;
            }
            while (arr[j] > pivot) {
                j--;
            }
            if (i <= j) {
                std::swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }

        quickSort(arr, low, j);
        quickSort(arr, i, high);
    }
}

int main() {
    const int n = 11;
    std::vector<int> arr = generateArray(n);

    std::cout << "given array: ";
    for (int x : arr) std::cout << x << " ";
    std::cout << std::endl;

    quickSort(arr, 0, n - 1);

    std::cout << " sorted array: ";
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    isSorted(arr);

    return 0;
}
