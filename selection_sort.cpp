//
// Created by Szymon on 01.03.2026.
//
#include <iostream>
#include <ctime>
using namespace std;

void SelectionSort(int tab[], int n){
    for (int x = 0; x < n - 1; x++) {
        int IndexOfLowestElement = x;

        for (int y = x + 1; y < n; y++) {
            if (tab[y] < tab[IndexOfLowestElement])        // '>' and '<' decides if algorithm sort in ascending or descending order
                IndexOfLowestElement = y;

        }

        swap(tab[IndexOfLowestElement], tab[x]);            // changing the position of LowestElement with the element from current iteration
    }
}

int main() {
    srand(time(NULL));    
    const int n = 10;
    int tab[n];

    cout << "Array after filling it with pseudorandom elements: " << '\n';

    for (int x = 0; x < n; x++) {   // generating random elements and writing them out
        tab[x] = rand() % 201-100;  // range -100 to 100
        cout << tab[x] << " ";
    }

    SelectionSort(tab, n);
    cout << '\n' << '\n' << "Array after Selection Sort algorithm: " << '\n';
    for (int x = 0; x < n; x++) {
        cout << tab[x] << " ";
    }

}
