//
// Created by Szymon on 02.03.2026.
//
#include <iostream>
#include <ctime>
using namespace std;

void BubbleSort(int tab[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (tab[j] > tab[j + 1]) {              //comparison of two “neighboring” elements
                swap(tab[j], tab[j + 1]); //swapping their position
            }

        }
    }
}

int main () {
    srand(time(NULL));

    const int n = 10;
    int tab[n];

    cout << "Array before sorting: " << '\n';
    for (int i = 0; i < n; i++) {
        tab[i] = rand() % 201-100;  // range -100 to 100
        cout << tab[i] << ' ';
    }
    cout << '\n' << '\n' << "Array after sorting: " << '\n';
    BubbleSort(tab, n);
    for (int i = 0; i < n; i++) {
        cout << tab[i] << ' ';
    }

}