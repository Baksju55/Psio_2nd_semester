#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "Macierz.h"

using namespace std;

int main()
{
    // Tworzymy macierz A
    Macierz<int> A({ {1,2,3},{4,5,6},{7,8,9} });

    // Dodajemy skalar do macierzy A
    A = A + 2;

    // Tworzymy macierz identity "B" i dodajemy do A
    Macierz<int> B = Macierz<int>::identity(3, 3);
    A = A + B;

    // Wyswietlanie
    cout << "Macierz A:" << endl;
    A.wyswietl();
    cout << "-----------------" << endl;

    // Macierz C z randomowymi wartosciami
    Macierz<int> C = Macierz<int>::wypelnianie(3, 3, []() {
        static default_random_engine e{};
        uniform_int_distribution<int> distribution{ 0, 100 };
        return distribution(e);
        });


    cout << "Macierz C:" << endl;
    C.wyswietl();
    cout << "-----------------" << endl;


    cout << "Macierz A:" << endl;
    A.wyswietl();
    cout << "-----------------" << endl;

    // Mnozenie macierzy A razy 2
    A = A * 2;

    cout << "Macierz A (pomnozona razy 2):" << endl;
    A.wyswietl();
    cout << "-----------------" << endl;

    return 0;
}
