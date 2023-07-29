

#include <iostream>
#include <vector>
#include <string>
#include <fstream> 
std::vector <int> find_spaces(std::string text) //program spisalem z zad2 znajduje on pozycje spacji lub innego dzielnika w tekscie 
{
    text += ",";
    std::vector <int> pierwszy;
    int position = 0;
    while ((position = text.find(",", position + 1)) != std::string::npos)
    {
        pierwszy.push_back(position);
    }
    return pierwszy;
};
std::vector <std::string> substr(std::string text) //program zapisuje elementy miedzy znakami do vectora , spisany w 90% z zad 3
{

    std::vector <int> spaces = find_spaces(text);
    std::vector <std::string> substr;
    int zakres_dol = 0, dlugosc = 0, a = 0, b = 0;
    for (int i = 0; i <= spaces.size() - 1; i++)
    {
        if (i < 1)
        {
            zakres_dol = -1;
            dlugosc = spaces[i];
        }
        if (i >= 1)
        {
            zakres_dol = spaces[i - 1];
            dlugosc = spaces[i] - spaces[i - 1] - 1;
        }
        substr.push_back(text.substr(zakres_dol + 1, dlugosc));

    }
    return substr;
} 
std::string to_string()
{
    std::string linia;
    std::fstream plik;
    std::string zawartosc;
    int a = 0;
    plik.open("C:/Users/wikto/Desktop/Programowanie/LABORATORIUM 2 SEM/LAB 002/ZAD 9/temp02-2020.CSV");
    if (plik.good() == true)
    {
        std::cout << "git" << std::endl;
    }
    else
    {
        std::cout << "nie udalo sie";
    }
    while (plik >> linia)
    {
        if (a > 2)
        {
            zawartosc += linia;
            zawartosc += ",";
        }
        // std::cout << linia << ' ' << std::endl;
        a++;
    }
    plik.close();
    //std::cout << " " << std::endl;
    //std::cout << zawartosc; 


    return zawartosc;
}
void pogoda()
{
    std::string dane;
    dane = to_string();
    std::vector <std::string> dane1; // predkosc dzwieku 
    std::vector <std::string> dane2; // godzina 
    std::vector <std::string> dane3; // predkosc dzwieku 
    std::vector <std::string> dane4; // temp dzwiekiem 
    std::vector <std::string> dane5; // cisnenie 
    std::vector <std::string> dane6; // temperatura 
    std::vector <std::string> dane7; // wilgotnosc 
    std::vector <std::string> dane8; // kompass 
    std::vector <std::string> dane9; // predkosc U-V
    std::vector <std::string> dane10; // preskosc wiatru 
    std::vector <std::string> dane11;
    std::vector <std::string> dane12;
    std::vector <std::string> dane13;
    std::vector <std::string> dane14;
    std::vector <std::string> abc = substr(dane);
    int a = 0, b = 0;
 /*   for (int i = 0; i < 200; i++)
   {
       std::cout << abc[i] << std::endl;
       std::cout << " i =" << i << std::endl;
   }*/
    for (int i = 0; i < abc.size(); i++)
    {
        if ((i - 24) % 13 == 0 && i > 20 )
        {
            dane3.push_back(abc[i]); 
        }
    }
 /*   for (int i = 0; i < 20; i++)
    {
        std::cout << dane3[i] << std::endl;
    }*/
    for (int i = 0; i < abc.size(); i++)
    {
        if ((i - 22) % 13 == 0 && i > 20 )
        {
            dane1.push_back(abc[i]);
        }
    }
  /*     for (int i = 0; i < 20; i++)
    {
        std::cout << dane1[i] << std::endl;
    }*/
       for (int i = 0; i < abc.size(); i++)
       {
           if ((i - 23) % 13 == 0 && i>20)
           {
               dane2.push_back(abc[i]);
           }
       }
    /*   for (int i = 0; i < 20; i++)
       {
           std::cout << dane2[i] << std::endl;
       }*/
       for (int i = 0; i < abc.size(); i++)
       {
           if ((i - 25) % 13 == 0 && i > 20)
           {
               dane4.push_back(abc[i]);
           }
       }
     /*  for (int i = 0; i < 20; i++)
       {
           std::cout << dane4[i] << std::endl;
       }*/
       for (int i = 0; i < abc.size(); i++)
       {
           if ((i - 26) % 13 == 0 && i > 20)
           {
               dane5.push_back(abc[i]);
           }
       }
     /*  for (int i = 0; i < 20; i++)
       {
           std::cout << dane5[i] << std::endl;
       }*/
       for (int i = 0; i < abc.size(); i++)
       {
           if ((i - 27) % 13 == 0 && i > 20)
           {
               dane6.push_back(abc[i]);
           }
       }
     /*  for (int i = 0; i < 20; i++)
       {
           std::cout << dane6[i] << std::endl;
       }*/
       for (int i = 0; i < abc.size(); i++)
       {
           if ((i - 28) % 13 == 0 && i > 20)
           {
               dane7.push_back(abc[i]);
           }
       }
      /* for (int i = 0; i < 20; i++)
       {
           std::cout << dane7[i] << std::endl;
       }*/
       for (int i = 0; i < abc.size(); i++)
       {
           if ((i - 29) % 13 == 0 && i > 20)
           {
               dane8.push_back(abc[i]);
           }
       }
     /*  for (int i = 0; i < 20; i++)
       {
           std::cout << dane8[i] << std::endl;
       }*/
       for (int i = 0; i < abc.size(); i++)
       {
           if ((i - 30) % 13 == 0 && i > 20)
           {
               dane9.push_back(abc[i]);
           }
       }
      /* for (int i = 0; i < 20; i++)
       {
           std::cout << dane9[i] << std::endl;
       }*/
       std::vector <float> float_dane6;
       float element;
       for (int i = 0; i < dane6.size(); i++) // zamiana vectora string na vector float 
       {
           element = std::stof(dane6[i]);
           float_dane6.push_back(element);
           // std::cout<<float_usd[i] << " zmiana na float" << std::endl; 
       }
       std::vector <float> sort = float_dane6; // w tym miejscu nie chcialo mi sie zmieniac wszedzie nazw z "sort" na "usd_daty" to zdefiniowalem nowy vektor 
       bool petla = false;
       int rozmiar = sort.size();
       int x = 0;
       while (petla == false)
       {

           for (int i = 0; i < rozmiar - 1; i++)
           {
               if (sort[i] > sort[i + 1])
               {
                   // std::cout << sort[i] << " " << sort[i + 1] << std::endl;
                   std::swap(sort[i], sort[i + 1]);
                   // std::cout << "zamieniam" << std::endl;
                   // std::cout << sort[i] << " " << sort[i + 1] << std::endl; // ukazuje w jaki sposb zostaja zmienione wartosci 
                  

               }
               else;
           }
           rozmiar = rozmiar - 1;
           if (x >= 50) //warunek zakonczenia petli , tzn jezeli zostala wykonana zmiana to x bedzie wieksze od 0 , jezeli nie to x = 0 ; 
           {
               petla = true;
           }
           x++;
       }
       //std::cout << "" << std::endl;
       float_dane6 = sort;
       std::cout << "NAJZIMNIEJSZA TEMPERATURA TO  " << float_dane6[0] << std::endl;
       std::cout << "NAJCIEPLEJSZA TEMPERATURA TO  " << float_dane6[float_dane6.size()-1] << std::endl;
       if (float_dane6.size() % 2 != 0)
       {
           int mediana = float_dane6.size() / 2 +1 ;
           std::cout << "MEDIANA TEMPERATUR TO " << float_dane6[mediana]; 
       }
       if (float_dane6.size() %2 == 0)
       {
           int rozmiar = float_dane6.size();
          std::cout << "MEDIANA TEMPERATUR TO " << (float_dane6[rozmiar - 1] + float_dane6[rozmiar]) / 2 << std::endl;  ;
       }
       
       
}
std::vector <float> bubble_sorting(std::vector <float> sort) // od najmniejszego do najwiekszego 
{
    bool petla = false;
    int rozmiar = sort.size();
    int x = 0;
    while (petla == false)
    {

        for (int i = 0; i < rozmiar - 1; i++)
        {
            if (sort[i] > sort[i + 1])
            {
                //std::cout << sort[i] << " " << sort[i + 1] << std::endl;
                std::swap(sort[i], sort[i + 1]);
                // std::cout << "zamieniam" << std::endl;
                // std::cout << sort[i] << " " << sort[i + 1] << std::endl; // ukazuje w jaki sposb zostaja zmienione wartosci 


            }
            else;
        }
        rozmiar = rozmiar - 1;
        if (x >= 50) //warunek zakonczenia petli , tzn jezeli zostala wykonana zmiana to x bedzie wieksze od 0 , jezeli nie to x = 0 ; 
        {
            petla = true;
        }
        x++;
    }
    // std::cout << "" << std::endl;
     //for (int i = 0; i < sort.size(); i++)
     //{
     //    std::cout << sort[i] << std::endl; 
     //}
    std::cout << "Minimalna wartosc temp to" << sort[0] << std::endl; 
    return sort;
}
int main()
{
    pogoda();
}
// !! Z UWAGI NA LIMIT PRZESYLANIA PLIKOW NA EKURSACH ZALACZAM PONIZEJ KOD DO ZAD 7 ;-) !! 
/*int binary_search(vector<double> collection, double search) {
    /*
    1) Sprawdź wartość środkową w kolekcji. Jeśli jest:
    * poszukiwaną wartością: koniec algorytmu
    * większa od poszukiwanej wartości: poszukiwany element znajduje się w pierwszej połowie kolekcji
    * mniejsza od poszukiwanej wartości: poszukiwany element znajduje się w drugiej połowie kolekcji
    2) Twój nowy zbiór to wybrana połowa.
    3) Wróć do kroku 1 z nowym zbiorem wejściowym, aż do znalezienia poszukiwanego elementu lub wyczerpania możliwości.
    */
    int searching_bound_min = 0;
    int searching_bound_max = collection.size() - 1;
    int shot;
    while (searching_bound_min != searching_bound_max) {
        shot = (searching_bound_min + searching_bound_max) / 2;
        // cout << shot << " <" << searching_bound_min << "; " << searching_bound_max << ">\n";
        if ((searching_bound_min + searching_bound_max) % 2 == 1) if (collection[shot-1] == search) return shot - 1; // if middle consists 2 numbers (set is even)
        if (collection[shot] == search) return shot;
        else if (collection[shot] < search) searching_bound_min = shot + 1;
        else if (collection[shot] > search) searching_bound_max = shot - 1;
    }
    return -1;
} */ 

