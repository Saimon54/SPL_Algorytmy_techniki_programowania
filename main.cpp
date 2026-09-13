//
// Created by Szymon on 13.09.2026.
//
#include <iostream>
#include <ctime>
#include <limits>
#include <vector>
#define MIN_VAL -10000000
#define MAX_VAL 10000000
#define MIN_SIZE 2
#define MAX_SIZE 10000000
using namespace std;

struct NeededInfo {
    int sort;
    vector<int> numbers;
};



void welcome() {
    cout << "----------------------------Welcome!----------------------------" << '\n';
    cout << "This program is just gathering some basics sorting algorithms." << '\n'
    << "You may look into the source code to check how they works\nand see it working by "
       "running "
       "them." << '\n'<< "----------------------------------------------------------------" << '\n' << '\n';

}

int get_input_numeric(int min_size, int maximal_size) {
    int numeric_input;
    while (true) {


        cin >> numeric_input;

        if (cin.fail()) {
            cout << "You've not passed a number!" << '\n' << "Try again...." << '\n';
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if ((numeric_input > maximal_size) || (numeric_input < min_size)) {
            cout << "Out of range!" << '\n' << "Try again...." << '\n';
        }
        else {
            cout << "Okay..." << '\n';
            break;
        }
    }
    return numeric_input;
}




int available_sorts() {
    string avl_sorts[3] = {
        "Bubble sort",
        "Selection sort",
        "Insertion sort"
    };

    for (int i = 0; i < size(avl_sorts) ; i++) {
        cout << i+1 << ".  " << avl_sorts[i] << '\n';
    }
    cout << '\n' << "Choose one using the number assigned to it." << '\n';

    return get_input_numeric( 1, size(avl_sorts));


}

vector<int> randomize(int arr_elements, int arr_min, int arr_max) {

    vector<int> numbs;

    for (int i = 0; i < arr_elements; i++) {
        numbs.push_back(rand() % (arr_max - arr_min + 1) + arr_min);        //formula for rand range is (max - min + 1) + min
    }

    if (arr_elements <= 15) {
        cout << '\n' << "Random number generator started..." << '\n';
        cout << "Your array is: " << '\n' << '\n';
        for (int numb: numbs) {
            cout << numb << " ";
        }
        cout << '\n';
    }
    return numbs;
}


NeededInfo get_info() {
    int n_of_elements;
    int arr_max;
    int arr_min;
    NeededInfo info;
    cout << "Enter number of elements in Your array: ";
    n_of_elements = get_input_numeric(MIN_SIZE, MAX_SIZE);
    cout << "Enter the range of elements in Your array: " << '\n'
    << "Minimal value: ";
    arr_min = get_input_numeric(MIN_VAL, MAX_VAL);
    cout << '\n' << "Maximal value: ";
    arr_max = get_input_numeric(MIN_VAL, MAX_VAL);
    info.numbers = randomize(n_of_elements, arr_min, arr_max);
    cout << '\n' << "What kind of sort You want use?" << '\n';
    cout << "Available sorts: " << '\n';
    info.sort = available_sorts();
    return info;
}

void bubble_sort(vector<int>& numbs) {
    for (int i = 0; i < numbs.size() - 1; i++) {
        for (int j = 0; j < numbs.size() - i - 1; j++) {
            if (numbs[j] > numbs[j+1]) {
                swap(numbs[j], numbs[j+1]);
            }
        }
    }
}

void selection_sort(vector<int>& numbs) {
    for (int x = 0; x < numbs.size() - 1; x++) {
        int IndexOfLowestElement = x;

        for (int y = x + 1; y < numbs.size(); y++) {
            if (numbs[y] < numbs[IndexOfLowestElement])        // '>' and '<' decides if algorithm sort in ascending or descending order
                IndexOfLowestElement = y;

        }

        swap(numbs[IndexOfLowestElement], numbs[x]);            // changing the position of LowestElement with the element from current iteration

    }
}

void insertion_sort(vector<int>& numbs) {
    for (int x = 1; x < numbs.size(); x++) {                // This algorithm starts sorting from the second element (1st index)
        int key = numbs[x];
        int j = x - 1;


        while (j >= 0 && numbs[j] > key) {         // '>' and '<' decides if algorithm sort in ascending or descending order

            numbs[j+1] = numbs[j];
            j--;
        }

        numbs[j+1] = key;
    }
}
void print_sorted_array(vector<int>& numbs) {
    int print_width;
    if (numbs.size() >= 15) {
        print_width = 15;
    }
    else {
        print_width = numbs.size();
    }
    for (int x = 0; x < print_width; x++) {
        cout << numbs[x] << " ";

    }

}

int main() {
    srand(time(NULL));


    welcome();
    NeededInfo info = get_info();
    if (info.sort == 1) {
        bubble_sort(info.numbers);
    }
    else if (info.sort == 2) {
        selection_sort(info.numbers);
    }
    else if (info.sort == 3) {
        insertion_sort(info.numbers);
    }

    print_sorted_array(info.numbers);
}