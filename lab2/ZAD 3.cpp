

#include <iostream>
#include <vector>
#include <string> 
std::vector <int> find_spaces(std::string text) //program spisalem z zad2 znajduje on pozycje spacji w tekscie 
{
    std::vector <int> pierwszy;
    int position = 0;
    while ((position = text.find(" ", position + 1)) != std::string::npos)
    {
        pierwszy.push_back(position);

    }
    return pierwszy;
}; 
std::string find_longest_word(std::string text , std:: vector<int> spaces ) //program zapisuje elementy miedzy spacjami do vectora 
{  //nastepnie program sprawdza rozmiar poszczegolnych el wektora 
    std::vector <std::string> substr;
    int zakres_dol = 0, dlugosc = 0 , a = 0 , b = 0 ; 
    for (int i = 0   ; i <= spaces.size() - 1  ; i++)
    {
             if (i < 1)
                {
                    zakres_dol = -1;
                    dlugosc = spaces[i + 1] - spaces[i];


                }
             if (i >= 1)
             {
                 zakres_dol = spaces[i - 1];
                 dlugosc = spaces[i] - spaces[i - 1];
             }
       
        substr.push_back(text.substr(zakres_dol  +1    , dlugosc ));
        
           // std::cout << substr[i] << std::endl;

       // std::cout << zakres_dol + 1 << "  "<<dlugosc << "  substr rozmiar "<<substr.size()<< std::endl;
    }
    std::string najdluzszy = "";
    
    for (int i = 0; i < substr.size(); i++ )
    {
        if (substr[i].size() >  najdluzszy.size()) 
        {
            najdluzszy = substr[i]; 

        }
       // std::cout << "rozmiar elementu " << i << " =" << substr[i].size() << std::endl; 
    }
    // std::cout <<najdluzszy << std::endl; 
    return najdluzszy; 
}

int main()
{
    std::string input = "Ala ma kota kot jezdzi na Roombie "; 
   /*
    std::vector <int> pos = find_spaces(input );
    for (int i = 0; i < pos.size(); i++)
    {
        std::cout << pos[i] << std::endl;
    };  */
   std::cout<< find_longest_word(input , find_spaces(input) ); 


    return 0;
}



