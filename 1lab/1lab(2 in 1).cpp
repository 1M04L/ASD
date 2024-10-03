#include <iostream>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <chrono>

int totalCost(int numberOfCities, int** matrix, int* route) {
    int total = 0;
    for (int i = 0; i < numberOfCities; i++) {
        int from = route[i];
        int to = route[(i + 1) % numberOfCities];
        total += matrix[from][to];
    }
    return total;
}

bool nextPermutation(int *arr, int n) {
    int i = n - 2;
    while (i >= 0 && arr[i] >= arr[i + 1]) {
        i--;
    }
    if (i < 0) {
        return false;
    }
    int j = n - 1;
    while (arr[j] <= arr[i]) {
        j--;
    }
    std::swap(arr[i], arr[j]);

    int left = i + 1;
    int right = n - 1;
    while (left < right) {
        std::swap(arr[left], arr[right]);
        left++;
        right--;
    }
    return true;
}

void fillMatrixRandomly(int** matrix, int numberOfCities) {
    for (int i = 0; i < numberOfCities; i++) {
        for (int j = 0; j < numberOfCities; j++) {
            if (i == j) {
                matrix[i][j] = 0;
            } else {
                matrix[i][j] = rand() % 100 + 1;
            }
        }
    }
}

void fillMatrixManually(int** matrix, int numberOfCities) {
    std::cout << "Enter the cost matrix:n";
    for (int i = 0; i < numberOfCities; i++) {
        for (int j = 0; j < numberOfCities; j++) {
            std::cout << "Cost from city " << i << " to city " << j << ": ";
            std::cin >> matrix[i][j];
        }
    }
}

void findBestRoute(int numberOfCities, int** matrix, int startNumber, int* bestRoute, int& bestRouteCost) {
    int *cities = new int[numberOfCities];
    for (int i = 0; i < numberOfCities; i++) {
        cities[i] = i;
    }

    int *route = new int[numberOfCities];
    route[0] = startNumber;

    int index = 1;
    for (int i = 0; i < numberOfCities; i++) {
        if (cities[i] != startNumber) {
            route[index++] = cities[i];
        }
    }

    do {
        int currentCost = totalCost(numberOfCities, matrix, route);

        if (currentCost < bestRouteCost) {
            bestRouteCost = currentCost;
            for (int i = 0; i < numberOfCities; i++) {
                bestRoute[i] = route[i];
            }
        }

    } while (nextPermutation(cities, numberOfCities));

    delete[] route;
    delete[] cities;
}

int main() {
    
    
    srand(time(0));

    int numberOfCities;
    std::cout << "number of cities: ";
    std::cin >> numberOfCities;

    int fillMethod;
    std::cout << "Choose method\n ";
    std::cout << "1 - random;\n";
    std::cout << "  2 - by hands;\n";
    std::cout << "so , 1 or 2?\n";
    std::cin >> fillMethod;

    int** matrix = new int*[numberOfCities];
    for (int i = 0; i < numberOfCities; i++) {
        matrix[i] = new int[numberOfCities];
    }

    if (fillMethod == 1) {
        fillMatrixRandomly(matrix, numberOfCities);
    } else if (fillMethod == 2) {
        fillMatrixManually(matrix, numberOfCities);
    } else {
        std::cerr << "Invalid choice";
        return 1;
    }

    int startNumber;
    std::cout << "number of da startcity (from 0 to " << numberOfCities - 1 << "): ";
    std::cin >> startNumber;

    int *bestRoute = new int[numberOfCities];
    int bestRouteCost = INT_MAX;

    auto start = std::chrono::high_resolution_clock::now();

    findBestRoute(numberOfCities, matrix, startNumber, bestRoute, bestRouteCost);

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Optimal route: ";
    for (int i = 0; i < numberOfCities; i++) {
        std::cout << bestRoute[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Total Cost: " << bestRouteCost << std::endl;
    std::cout << "time : " << duration.count() << " milliseconds" << std::endl;

    delete[] bestRoute;
    for (int i = 0; i < numberOfCities; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
