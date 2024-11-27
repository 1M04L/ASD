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

void bitwiseCountingSort(std::vector<int>& arr) {
    if (arr.empty()) return;

    int maxVal = *std::max_element(arr.begin(), arr.end());
    int numBits = 0;
    int temp = maxVal;
    while (temp > 0) {
        numBits++;
        temp >>= 1;
    }


    std::vector<int> output(arr.size());
    std::vector<int> count(1 << numBits, 0);


    for (int x : arr) {
        count[x]++;
    }

    for (int i = 1; i < count.size(); i++) {
        count[i] += count[i - 1];
    }

    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    arr = output;
}


int main() {
    std::vector<int> arr = {10, 5, 2, 8, 1, 9, 3, 7, 4, 6};
    std::cout << "original array: ";
    for (int x : arr) std::cout << x << " ";
    std::cout << std::endl;

    bitwiseCountingSort(arr);

    std::cout << "sorted array: ";
    for (int x : arr) std::cout << x << " ";
    std::cout << std::endl;

    if (isSorted(arr)) {
        std::cout << "array has been sorted" << std::endl;
    } else {
        std::cerr<< "array wasnt sorted" << std::endl;
    }

    return 0;
}
