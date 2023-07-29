

#include <iostream>
#include <vector> 


std::vector <int> bubble_sort(std::vector <int> sort)
{  
    bool petla = false;
    int rozmiar = sort.size(); 
    int x = 0;
    while (petla == false )
    {
        x = 0;
        for (int i = 0; i < rozmiar - 1; i++)
        { 
            if (sort[i] > sort[i + 1])
            {
                std::cout << sort[i] << " " << sort[i + 1] << std::endl;
                std::swap(sort[i], sort[i + 1]); 
                std::cout << "zamieniam" << std::endl;
                std::cout << sort[i] << " " << sort[i + 1] << std::endl; // ukazuje w jaki sposb zostaja zmienione wartosci 
                x++; 

            }
            else;
        }
        rozmiar = rozmiar - 1;
        if (x == 0) //warunek zakonczenia petli , tzn jezeli zostala wykonana zmiana to x bedzie wieksze od 0 , jezeli nie to x = 0 ; 
        {
            petla = true; 
        }
    }
    std::cout << "" << std::endl;

    return sort ; 
}

int main()
{
    std::vector <int> liczby;
    for (int i = 0; i < 10; i++) // przypisuje na zmiane dodatnie lub ujemne wartosci do wektora 
    {
        liczby.push_back(pow(-1, i) * 2 * i);
        std::cout << liczby[i] << std::endl;
    }
    std::cout << "" << std::endl; 
    std::vector <int> liczby2;
   liczby2 =  bubble_sort(liczby); // wykonuje funkcje 
   for (int i = 0; i < liczby2.size(); i++)
   {
   std::cout<< liczby2[i] << std::endl;
   } 
}


