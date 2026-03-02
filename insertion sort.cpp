//
// Created by Szymon on 01.03.2026.
//

#include <iostream>
#include <ctime>

using namespace std;

void InsertionSort(int tab[], int n) {
    for (int x = 1; x < n; x++) {                // This algorithm starts sorting from the second element (1st index)
        int key = tab[x];
        int j = x - 1;


        while (j >= 0 && tab[j] > key) {         // '>' and '<' decides if algorithm sort in ascending or descending order
            tab[j+1] = tab[j];
            j--;
        }

        tab[j+1] = key;
    }
}

int main() {
    srand(time(NULL));
    const int n = 10;
    int tab[n];

    cout << "Array before sorting, filled with pseudorandom elements: " << '\n';
    for (int x = 0; x < n; x++) {
        tab[x] = rand() % 201-100;    //Range -100 to 100
        cout << tab[x] << " ";
    }

    cout << '\n' << '\n' << "Array after Insertion sort: " << '\n';
    InsertionSort(tab, n);
    for (int x = 0; x < n; x++) {
        cout << tab[x] << " ";
    }

}

