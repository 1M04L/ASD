#include <iostream>
#include <vector>

void shellSort(std::vector<int>& arr) {
  int n = arr.size();
  int gap = n / 2;

  while (gap > 0) {
    for (int i = gap; i < n; ++i) {
      int temp = arr[i];
      int j;
      for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
        arr[j] = arr[j - gap];
      }
      arr[j] = temp;
    }
    gap /= 2;
  }
}

bool isSorted(const std::vector<int>& arr) {
  for (int i = 1; i < arr.size(); ++i) {
    if (arr[i] < arr[i - 1]) {
      return false;
    }
  }
  return true;
}

int main() {
    
  std::vector<int> arr = {5, 2, 8, 1, 9,6,10,12,-3,0,-7};

  std::cout << "array: ";
  for (int i : arr) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  shellSort(arr);

  std::cout << "sorted array: ";
  for (int i : arr) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  if (isSorted(arr)) {
    std::cout << "sorted successfully " << std::endl;
  } else {
    std::cerr << "unsorted" << std::endl;
  }

  return 0;
}
