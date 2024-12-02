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

void hoareSort(std::vector<int>& array, int left, int right) {
    if (left >= right) return;

    int pivot = array[(left + right) / 2];
    int i = left;
    int j = right;

    while (i <= j) {
        while (array[i] < pivot) i++;
        while (array[j] > pivot) j--;
        if (i <= j) {
            std::swap(array[i], array[j]);
            i++;
            j--;
        }
    }

    hoareSort(array, left, j);
    hoareSort(array, i, right);
}

int main() {
    const int n = 11;
    std::vector<int> arr = generateArray(n);

    std::cout << "given array: ";
    for (int x : arr) std::cout << x << " ";
    std::cout << std::endl;

    hoareSort(arr, 0, n - 1);

    std::cout << " sorted array: ";
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    isSorted(arr);

    return 0;
}

