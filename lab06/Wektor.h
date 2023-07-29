#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>

class Wektor
{
private:
    int wielkosc;
    Wektor<T> dane;

public:
    Wektor()
    {
        cout << "Podaj rozmiar wektora: ";
        cin >> wielkosc;

        dane.resize(wielkosc);

        cout << "Wypełnij wektor liczbami:" << endl;

        for (int i = 0; i < wielkosc; i++)
        {
            T n;
            cin >> n;
            dane[i] = n;
        }

        display();
    }

    void display()
    {
        for (int i = 0; i < wielkosc; i++)
        {
            cout << dane[i] << endl;
        }
    }

    Wektor<T> add(const Wektor<T>& v2)
    {
        if (wielkosc != v2.wielkosc)
        {
            cerr << "Wektory różnią się rozmiarem." << endl;
            return Wektor<T>();
        }

        Wektor<T> wynik(wielkosc);

        for (int i = 0; i < wielkosc; i++)
        {
            wynik[i] = dane[i] + v2.dane[i];
        }

        return wynik;
    }

    Wektor<T> subtract(const Wektor<T>& v2)
    {
        if (wielkosc != v2.wielkosc)
        {
            cerr << "Wektory roznia sie rozmiarem." << endl;
            return Wektor<T>();
        }

        Wektor<T> wynik(wielkosc);

        for (int i = 0; i < wielkosc; i++)
        {
            wynik[i] = dane[i] - v2.dane[i];
        }

        return wynik;
    }

    Wektor<T> mnozenie(const Wektor<T>& v2)
    {
        if (wielkosc != v2.wielkosc)
        {
            cerr << "Wektory roznia sie rozmiarem." << endl;
            return Wektor<T>();
        }

        Wektor<T> wynik(wielkosc);

        for (int i = 0; i < wielkosc; i++)
        {
            wynik[i] = dane[i] * v2.dane[i];
        }

        return wynik;
    }

    Wektor<T> dzielenie(const Wektor<T>& v2)
    {
        if (wielkosc != v2.wielkosc)
        {
            cerr << "Wektory różnią się rozmiarem." << endl;
            return Wektor<T>();
        }

        Wektor<T> wynik(wielkosc);

        for (int i = 0; i < wielkosc; i++)
        {
            wynik[i] = dane[i] / v2.dane[i];
        }

        return wynik;
    }

    ~Wektor() = default;
};
