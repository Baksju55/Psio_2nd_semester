#ifndef LICZBA_ZESPOLONA_H
#define LICZBA_ZESPOLONA_H
#include <iostream>

using namespace std;

template <typename T>
class liczby_zespolone {
private:
    T rzeczywista;
    T urojona;

public:
    liczby_zespolone() {
        cout << "Podaj czesc rzeczywista:" << endl;
        cin >> rzeczywista;
        cout << "Podaj czesc urojona:" << endl;
        cin >> urojona;
    }
    void wyswietlanie_liczb() {
        cout << rzeczywista << "+" << urojona << "j" << endl;
    }

    auto dodawanie_liczb(T t1, T t2) {
        rzeczywista += t1;
        urojona += t2;
        return rzeczywista, urojona;
    }

    auto odejmowanie_liczb(T t1, T t2) {
        rzeczywista -= t1;
        urojona -= t2;
        return rzeczywista, urojona;
    }

    auto mnozenie_liczb(T t1, T t2) {
        T a = rzeczywista;
        T b = urojona;
        T c = t1;
        T d = t2;

        rzeczywista = a * c - b * d;
        urojona = a * d + b * c;

        return rzeczywista, urojona;
    }

    auto podzielLiczby(T t1, T t2) {
        T a = rzeczywista;
        T b = urojona;
        T c = t1;
        T d = t2;

        T mianownik = c * c + d * d;

        rzeczywista = (a * c) + (b * d);
        rzeczywista = rzeczywista / mianownik;

        urojona = (b * c - a * d) / mianownik;

        return rzeczywista, urojona;
    }
};

#endif // LICZBA_ZESPOLONA_H
