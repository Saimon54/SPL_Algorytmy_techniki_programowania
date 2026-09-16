//
//Made by Szymon at 16.09.2026
//

#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

class Pojazd {
public:
        string marka, model, nadwozie;
        int moc, rocznik, przebieg;
        bool bezwypadkowy, bylo_palone;

    //konstruktor bazowy

    Pojazd() {
        marka = "Volkswagen";
        model = "Passat";
        nadwozie = "kombii";
        moc = 116;
        rocznik = 2001;
        przebieg = 444141;
        bezwypadkowy = true;
        bylo_palone = false;
    }

    //konstruktor parametryczny

    Pojazd(string ma, string mo, string nad, int mc, int ro, int przebg, bool bezwypad, bool
        bypal) {
        marka = ma;
        model = mo;
        nadwozie = nad;
        moc = mc;
        rocznik = ro;
        przebieg = przebg;
        bezwypadkowy = bezwypad;
        bylo_palone = bypal;
    }

    void Wyswietl() {
        cout << "Wyswietl" << endl;
        cout << "marka: " << marka << endl;
        cout << "model: " << model << endl;
        cout << "nadwozie: " << nadwozie << endl;
        cout << "moc: " << moc << endl;
        cout << "rocznik: " << rocznik << endl;
        cout << "przebieg: " << przebieg << endl;
        cout << "Bezwypadkowy: " << (bezwypadkowy ? "Tak" : "Nie") << endl;
        cout << "Bylo_palone: " << (bylo_palone ? "Tak" : "Nie") << endl;
    }

};


class Osobowy : public Pojazd {
public:
    int liczba_miejsc;
    int pojemnosc_bagaznika;

    //konstruktor bazowy

    Osobowy() {
        liczba_miejsc = 5;
        pojemnosc_bagaznika = 430;
    }

    //konstruktor parametryczny

    Osobowy(string ma, string mo, string nad, int mc, int ro, int przebg, bool bezwypad, bool
        bypal, int lm, int pb) : Pojazd(ma, mo, nad, mc, ro, przebg, bezwypad, bypal)
    {
        liczba_miejsc = lm;
        pojemnosc_bagaznika = pb;
    }

};


class Motocykl : public Pojazd {
public:
    int pojemnosc_silnika;
    bool quick_shifter;


    //konstruktor bazowy

    Motocykl() {
        pojemnosc_silnika = 650;
        quick_shifter = true;
    }

    //konstruktor parametryczny

    Motocykl(string ma, string mo, string nad, int mc, int ro, int przebg, bool bezwypad, bool
        bypal, int ps, bool qs) : Pojazd(ma, mo, nad, mc, ro, przebg, bezwypad, bypal) {

        pojemnosc_silnika = ps;
        quick_shifter = qs;

    }

};



int main() {
    Pojazd passat1;
    passat1.Wyswietl();
    Pojazd passat2;
    passat2.marka = "AUdik";
    passat2.Wyswietl();
    Pojazd passat4("BMW", "M4", "Sedan", 240, 2020, 10000, true, false);
    passat4.Wyswietl();
}