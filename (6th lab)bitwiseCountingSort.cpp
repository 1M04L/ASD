#include <iostream>
#include <vector>
#include <algorithm>

bool isSorted(const std::vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

void bitwiseSort(std::vector<int>& arr, int l, int r, int k) {
    if (l >= r || k < 0) return;

    int i = l, j = r;
    while (i <= j) {
        while (i <= j && !((arr[i] >> k) & 1)) i++;
        while (i <= j && ((arr[j] >> k) & 1)) j--;

        if (i < j) {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    bitwiseSort(arr, l, j, k - 1);
    bitwiseSort(arr, i, r, k - 1);
}


int main() {
    std::vector<int> arr = {1488,0, 5, 2, 228, 1, 9, 3, 7, 4, 6};
    int maxVal = *std::max_element(arr.begin(), arr.end());
    int maxBit = 0;
    int temp = maxVal;
    while (temp > 0) {
      maxBit++;
      temp >>= 1;
    }

    std::cout << "original array: ";
    for (int x : arr) std::cout << x << " ";
    std::cout << std::endl;

    bitwiseSort(arr, 0, arr.size() - 1, maxBit -1);

    std::cout << "sorted array: ";
    for (int x : arr) std::cout << x << " ";
    std::cout << std::endl;

    if (isSorted(arr)) {
        std::cout << "array has been sorted" << std::endl;
    } else {
        std::cerr << "array wasnt sorted" << std::endl;
    }

    return 0;
}
