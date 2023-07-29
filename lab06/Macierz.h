#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class Macierz
{
private:
    vector<vector<T>> wartosci;
    int rzedy = 1;
    int kolumny = 1;

public:
    Macierz() : rzedy(0), kolumny(0)
    {
        cout << "Macierz zostala poprawnie stworzona" << endl;
    }

    Macierz(vector<vector<T>> cos) : rzedy(cos.size()), kolumny(cos[0].size()), wartosci(cos) {}

    Macierz(int rzedy, int kolumny) : rzedy(rzedy), kolumny(kolumny), wartosci(vector<vector<T>>(rzedy, vector<T>(kolumny))) {}

    void wypelnianie()
    {
        cout << "Podaj wartosci:" << endl;
        for (int i = 0; i < rzedy; i++)
        {
            for (int j = 0; j < kolumny; j++)
            {
                cin >> wartosci[i][j];
            }
        }
    }

    void wyswietl() const
    {
        for (const auto& row : wartosci)
        {
            for (const auto& val : row)
            {
                cout << val << " ";
            }
            cout << endl;
        }
        cout << endl << endl;
    }

    // Jednostkowa
    static Macierz<T> identity(int rzedy, int kolumny) {

        Macierz<T> mat(rzedy, kolumny);
        for (int i = 0; i < min(rzedy, kolumny); i++)
        {
            mat.wartosci[i][i] = 1;
        }
        return mat;
    }

    template<typename Func>
    static Macierz<T> wypelnianie(int rzedy, int kolumny, Func&& f)
    {
        Macierz<T> mat(rzedy, kolumny);
        for (int i = 0; i < rzedy; i++)
        {
            for (int j = 0; j < kolumny; j++)
            {
                mat.wartosci[i][j] = f();
            }
        }
        return mat;
    }

    //Dodawanie macierz+skalar
    Macierz<T> operator+(T skalar) const
    {
        Macierz<T> wynik(rzedy, kolumny);
        for (int i = 0; i < rzedy; i++)
        {
            for (int j = 0; j < kolumny; j++)
            {
                wynik.wartosci[i][j] = wartosci[i][j] + skalar;
            }
        }
        return wynik;
    }

    Macierz<T> operator+(const Macierz<T>& other) const
    {
        Macierz<T> wynik(rzedy, kolumny);
        for (int i = 0; i < rzedy; i++)
        {
            for (int j = 0; j < kolumny; j++)
            {
                wynik.wartosci[i][j] = wartosci[i][j] + other.wartosci[i][j];
            }
        }
        return wynik;
    }

    //Odejmowanie macierz-skalar
    Macierz<T> operator-(T skalar) const
    {
        Macierz<T> wynik(rzedy, kolumny);
        for (int i = 0; i < rzedy; i++)
        {
            for (int j = 0; j < kolumny; j++)
            {
                wynik.wartosci[i][j] = wartosci[i][j] - skalar;
            }
        }
        return wynik;
    }

    //Odejmowanie macierz-macierz
    Macierz<T> operator-(const Macierz<T>& other) const
    {
        Macierz<T> wynik(rzedy, kolumny);
        for (int i = 0; i < rzedy; i++)
        {
            for (int j = 0; j < kolumny; j++)
            {
                wynik.wartosci[i][j] = wartosci[i][j] - other.wartosci[i][j];
            }
        }
        return wynik;
    }

    //Mnozenie macierz*skalar
    Macierz operator*(T skalar
                      ){
        for(int i = 0; i < kolumny; i++)
        {
            for(int j = 0; j < rzedy; j++)
            {
                wartosci[i][j] *= skalar;
            }
        }
        return *this;
    }

};

