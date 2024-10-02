#include <iostream>
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
    swap(arr[i], arr[j]);

    int left = i + 1;
    int right = n - 1;
    while (left < right) {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
    return true;
}

void fillMatrixRandomly(int** matrix, int numberOfCities) {
    srand(time(0));
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

int main() {
    for (int numberOfCities = 7; numberOfCities <= 10; numberOfCities++) {
        cout << "(---...(.)...(.)...---)" << endl;
        cout << "count of cities: " << numberOfCities << endl;

        int** matrix = new int*[numberOfCities];
        for (int i = 0; i < numberOfCities; i++) {
            matrix[i] = new int[numberOfCities];
        }

        fillMatrixRandomly(matrix, numberOfCities);

        int startNumber;
        cout << "number of da start city (from 0 to " << numberOfCities - 1 << "): ";
        cin >> startNumber;

        int *cities = new int[numberOfCities];
        for (int i = 0; i < numberOfCities; i++) {
            cities[i] = i;
        }

        int *bestRoute = new int[numberOfCities];
        int bestRouteCost = 9999999;

        int *route = new int[numberOfCities];

        route[0] = startNumber;

        int index = 1;
        for (int i = 0; i < numberOfCities; i++) {
            if (cities[i] != startNumber) {
                route[index++] = cities[i];
            }
        }

        auto start = chrono::high_resolution_clock::now();
        do {
            int currentCost = totalCost(numberOfCities, matrix, route);

            if (currentCost < bestRouteCost) {
                bestRouteCost = currentCost;
                for (int i = 0; i < numberOfCities; i++) {
                    bestRoute[i] = route[i];
                }
            }

        } while (nextPermutation(cities, numberOfCities));
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

        cout << "optimal route: ";
        for (int i = 0; i < numberOfCities; i++) {
            cout << bestRoute[i] << " ";
        }
        cout << endl;
        cout << "total Cost: " << bestRouteCost << endl;
        cout << "time : " << duration.count() << " milliseconds" << endl;

        delete[] route;
        delete[] bestRoute;
        delete[] cities;
        for (int i = 0; i < numberOfCities; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
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

71-99 запихнуть в функцию

*/
