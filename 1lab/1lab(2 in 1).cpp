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
// up to 10-11 = ok
// about 11-14 = quite long time compilation
// 14+ = long time compilation(enaugh to make me bored without compilation result)




/*

/tmp/qvXbhgwbJQ.o
(---...(.)...(.)...---)
count of cities: 2
number of da start city (from 0 to 1): 1
optimal route: 1 0 
total Cost: 88
time : 0 milliseconds
(---...(.)...(.)...---)
count of cities: 3
number of da start city (from 0 to 2): 2
optimal route: 2 0 1 
total Cost: 77
time : 0 milliseconds
(---...(.)...(.)...---)
count of cities: 4
number of da start city (from 0 to 3): 3
optimal route: 3 0 1 2 
total Cost: 215
time : 0 milliseconds
(---...(.)...(.)...---)
count of cities: 5
number of da start city (from 0 to 4): 4
optimal route: 4 0 1 2 3 
total Cost: 233
time : 0 milliseconds
(---...(.)...(.)...---)
count of cities: 6
number of da start city (from 0 to 5): 5
optimal route: 5 0 1 2 3 4 
total Cost: 375
time : 0 milliseconds
(---...(.)...(.)...---)
count of cities: 7
number of da start city (from 0 to 6): 6
optimal route: 6 0 1 2 3 4 5 
total Cost: 388
time : 0 milliseconds
(---...(.)...(.)...---)
count of cities: 8
number of da start city (from 0 to 7): 6
optimal route: 6 0 1 2 3 4 5 7 
total Cost: 249
time : 2 milliseconds
(---...(.)...(.)...---)
count of cities: 9
number of da start city (from 0 to 8): 6
optimal route: 6 0 1 2 3 4 5 7 8 
total Cost: 501
time : 20 milliseconds
(---...(.)...(.)...---)
count of cities: 10
number of da start city (from 0 to 9): 6
optimal route: 6 0 1 2 3 4 5 7 8 9 
total Cost: 411
time : 330 milliseconds
(---...(.)...(.)...---)
count of cities: 11
number of da start city (from 0 to 10): 6
optimal route: 6 0 1 2 3 4 5 7 8 9 10 
total Cost: 514
time : 3325 milliseconds
(---...(.)...(.)...---)
count of cities: 12
number of da start city (from 0 to 11): 6
optimal route: 6 0 1 2 3 4 5 7 8 9 10 11 
total Cost: 601
time : 50379 milliseconds


*/
