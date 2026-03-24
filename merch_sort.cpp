//
// Created by pl_sz on 24.03.2026.
//

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <ostream>
#include <bits/locale_classes.h>
using namespace std;
//zlozonosc O(n log n)
//zlozonosc pamieciowa O(n)

int tmp[10];

void wizualizuj(int t[10]) {
    cout << "\nWizualizacja (wykres slupkowy):\n\n";

    for (int i = 0; i < 10; i++) {
        cout << "[" << i << "] " << t[i] << " | ";

        if (t[i] > 0) {
            for (int j = 0; j < t[i]; j += 2) { // skala (co 2 żeby nie było za szerokie)
                cout << "#";
            }
        } else {
            cout << "(ujemna)";
        }

        cout << endl;
    }
}


void sortuj(int t[10], int p, int k) {
    int s, i1, i2;

    if (p < k) {

        s = (p + k) / 2;
        sortuj(t, p, s);
        sortuj(t, s+1, k);
        i1 = p;
        i2 = s + 1;
        for (int i = p; i <= k; i++) {

            if (i1 > s || (i2 <= k && t[i2] < t[i1])) {
                tmp[i] = t[i2++];

            }
            else {
                tmp[i] = t[i1++];
            }
        }

        for (int i = p; i <= k; i++) {
            t[i] = tmp[i];
        }
    }
}




int main() {
    srand(time(nullptr));
    int t[10];

    for (int i = 0; i < 10; i++) {
        t[i] = rand()% 201 - 100;
        cout << t[i] << ' ';
    }
    int p = 0;
    int k = 9;
    wizualizuj(t);
    sortuj(t, p, k);
    wizualizuj(t);
    cout << '\n';

    for (int i = 0; i < 10; i++) {
        cout << t[i] << ' ';
    }

                                                            
}
