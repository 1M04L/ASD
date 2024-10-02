#include <iostream>

int totalCost(int numberOfCities , int** matrix , int* route){
    int total=0;
    
    for(int i=0;i<numberOfCities;i++){
        int from = route[i];
        int to= route[(i + 1) % numberOfCities];
        total+=matrix[from][to];
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

int main(){
    int numberOfCities;
    cout<<" number of cities? : ";
    cin>>numberOfCities;

    int** matrix = new int*[numberOfCities];
    for (int i = 0; i < numberOfCities; i++) {
        matrix[i] = new int[numberOfCities];
    }

    cout << "matrix? " << numberOfCities << "x" << numberOfCities<< ":";
    for (int i = 0; i < numberOfCities; i++) {
        for (int j = 0; j < numberOfCities; j++) {
            cin >> matrix[i][j];
        }
    }

    int startNumber;
    cout << "number of da city ((in scope from 0 to" << numberOfCities- 1 << "): ";
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

    do {
        int currentCost = totalCost(numberOfCities, matrix, route);

        if (currentCost < bestRouteCost) {
            bestRouteCost = currentCost;
            for (int i = 0; i < numberOfCities; i++) {
                bestRoute[i] = route[i];
            }
        }

    } while (nextPermutation(cities, numberOfCities));

    cout << "Optimal route: ";
    for (int i = 0; i < numberOfCities; i++) {
        cout << bestRoute[i] << " ";
    }
    cout << endl;
    cout << "Total cost: " << bestRouteCost << endl;

    delete[] route;
    delete[] bestRoute;
    delete[] cities;
    for (int i = 0; i < numberOfCities; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
