

#include <iostream>
#include <vector>
#include <string> 
std::vector <int> find_spaces(std::string text , std::string search) //program spisalem z zad2 znajduje on pozycje spacji lub innego dzielnika w tekscie 
{
    text += search; 
    std::vector <int> pierwszy;
    int position = 0;
    while ((position = text.find(search, position + 1)) != std::string::npos)
    {
        pierwszy.push_back(position);

    }
    return pierwszy;
};
std::vector <std::string> find_longest_word(std::string text, std::vector<int> spaces) //program zapisuje elementy miedzy znakami do vectora , spisany w 90% z zad 3
{ 
    std::vector <std::string> substr;
    int zakres_dol = 0, dlugosc = 0, a = 0, b = 0;
    for (int i = 0; i <= spaces.size() - 1; i++)
    {
        if (i < 1)
        {
            zakres_dol = -1;
            dlugosc = spaces[i] 

                ; 
        }
        if (i >= 1)
        {
            zakres_dol = spaces[i - 1];
            dlugosc = spaces[i] - spaces[i - 1] - 1;
        }
        

        substr.push_back(text.substr(zakres_dol + 1, dlugosc));

        // std::cout << substr[i] << std::endl;

    // std::cout << zakres_dol + 1 << "  "<<dlugosc << "  substr rozmiar "<<substr.size()<< std::endl;
    }
    return substr; 
}

int main()
{
    std::string search = ","; // element oddzielajacy slowa 
    //std::string input = "Ala ma kota kot jezdzi na Roombie "; //tekst  
    std::string input = "Mount Everest ,8848,1953"; 
    std::vector <std::string> slowa = find_longest_word(input, find_spaces(input, search));
    for (int i = 0; i < slowa.size(); i++)
    {
        std::cout << slowa[i] << std::endl; 
    }
}
//program jest zmodyfikowaną wersją programu w zad 3 , ponieważ tamten program pełnił również funkcje wymagane tutaj
