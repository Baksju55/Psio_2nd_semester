
#include <iostream>
#include <vector> 
#include <fstream>
#include <string>
std::vector <float> bubble_sorting(std::vector <float> sort)
{  
    bool petla = false;
    int rozmiar = sort.size(); 
    int x = 0;
    while (petla == false )
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
        if (x >= 50 ) //warunek zakonczenia petli , tzn jezeli zostala wykonana zmiana to x bedzie wieksze od 0 , jezeli nie to x = 0 ; 
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

    return sort ; 
}
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
    plik.open("C:/Users/wikto/Desktop/Programowanie/LABORATORIUM 2 SEM/LAB 002/ZAD8/kursy_usd_eur.csv");
    if (plik.good() == true)
    {
        std::cout << "git"<<std::endl ;
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
void to_eur()
{
    std::string eur;
    eur = to_string();
    std::vector <std::string> euro;
    std::vector <std::string> euro_daty;
    std::vector <std::string> abc = substr(eur);
    int a = 0, b = 0;
    //for (int i = 0; i < abc.size(); i++)
    //{
    //    std::cout << abc[i] << std::endl;
    //}
    int c = 0;
    for (int i =1; i < abc.size(); i++)
    {   
        if (i % 2 == 0 && i%4 != 0)
        {
            euro.push_back(abc[i-1]); 
       }         
    }
 /*   for (int i = 0; i < euro.size(); i++)
    {
        std::cout << euro[i] << std::endl; 
    }*/

    for (int i = 0; i < abc.size(); i++)
    {
        if (i % 4 == 0)
        {
            euro_daty.push_back(abc[i]);
           // std::cout << euro_daty[euro_daty.size()-1] << std::endl;

        }
       
    }
    std::vector <float> float_eur;
    float element;
    for (int i = 0; i < euro.size(); i++) // zamiana vectora string na vector float 
    {
        element = std::stof(euro[i]);
        float_eur.push_back(element);
        // std::cout<<float_usd[i] << " zmiana na float" << std::endl; 
    }

    std::vector <float> sort = float_eur; // w tym miejscu nie chcialo mi sie zmieniac wszedzie nazw z "sort" na "usd_daty" to zdefiniowalem nowy vektor 
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
                std::swap(euro_daty[i], euro_daty[i + 1]);

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
    float_eur = sort;
    std::cout << "TOP 10 KURSOW USD" << std::endl;  //!!! Najwidoczniej powalily mi sie kolejnosci i funkcja do euro liczy USD 
    for (int i = float_eur.size() - 1; i > euro.size() - 11; i = i - 1)
    {
        std::cout << "Kurs wynosil " << float_eur[i] << " Dnia " << euro_daty[i] << std::endl;
    }
    std::string data = "";
    float liczba = 3.9011; 
    for (int i = 0; i < float_eur.size(); i++)
    {
        if (float_eur[i] == liczba)
        {
            data = euro_daty[i];
        }
    }
    std::cout << "Kurs dolara rowny 3.9011 , byl dnia " << data << std::endl;

}
void to_usd()
{
    std::string usda;
    usda = to_string();
    std::vector <std::string> usd;
    std::vector <std::string> usd_daty;
    std::vector <std::string> abc = substr(usda);
    int a = 0, b = 0;
   /* for (int i = 0; i < abc.size(); i++)
    {
        std::cout << abc[i] << std::endl;
    }*/

    int c = 0;
    for (int i = 1; i < abc.size(); i++)
    {
        if ( (i-3)%4 == 0)
        {
            usd.push_back(abc[i-1]);
        }
    }
   /* for (int i = 0; i < usd.size(); i++)
    {
        std::cout << usd[i] << std::endl;
    }
*/
    for (int i = 0; i < abc.size(); i++)
    {
        if (i % 4 == 0)
        {
            usd_daty.push_back(abc[i]);
           // std::cout << usd_daty[usd_daty.size() - 1] << std::endl;

        }

    }
    std::vector <float> float_usd; 
    float element;
    for (int i = 0; i < usd.size(); i++) // zamiana vectora string na vector float 
    {
        element = std::stof(usd[i]); 
        float_usd.push_back(element);
        // std::cout<<float_usd[i] << " zmiana na float" << std::endl; 
    }
    
    std::vector <float> sort = float_usd; // w tym miejscu nie chcialo mi sie zmieniac wszedzie nazw z "sort" na "usd_daty" to zdefiniowalem nowy vektor 
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
                std::swap(usd_daty[i], usd_daty[i + 1]); 

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
    float_usd = sort; 
    std::cout << "TOP 10 KURSOW EURO" << std::endl; //!!! Najwidoczniej powalily mi sie kolejnosci i funkcja do usd liczy euro 
    for (int i = float_usd.size() - 1; i > usd.size() - 11 ; i = i - 1)
    {
        std::cout << "Kurs wynosil " << float_usd[i] << " Dnia " << usd_daty[i] << std::endl; 
    }

}



int main()
{
    to_eur(); 
    to_usd(); 
}
