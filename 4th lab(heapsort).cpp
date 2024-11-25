#include <iostream>
#include <string>
#include <vector>

void heap(std::vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heap(arr, n, largest);
    }
}

void heapSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        heap(arr, n, i);
    }
    for (int i = n - 1; i >= 0; i--) {
        std::swap(arr[0], arr[i]);
        heap(arr, i, 0);
    }
}

bool isSorted(const std::vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

void printArray(const std::vector<int>& arr) {
    std::cout << "array: ";
    for (int x : arr) std::cout << x << " ";
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr = {-67, 1, 54, 5, 6, 7};

    printArray(arr);

    heapSort(arr);
    std::cout<< "sorted ";

    printArray(arr);

    if (isSorted(arr)) {
        std::cout << "sorted successfully" << std::endl;
    } else {
        std::cerr << "unsorted" << std::endl;
    }

    return 0;
}
