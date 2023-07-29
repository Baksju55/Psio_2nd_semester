

#include <iostream>
#include <vector>
#include <string> 
#include <cstring>

std::vector <int> find_spaces(std::string text, std::string search) //program spisalem z zad2 znajduje on pozycje spacji lub innego dzielnika w tekscie 
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
std::string find_and_replace(std::string input, std::string find, std::string replace)
{ 
    std::vector <std::string> text_sub;
   text_sub = find_longest_word(input, find_spaces(input, " ")); 
   int res = -1; 
   for (int i = 0; i < text_sub.size(); i++)
   {
      res = find.compare(text_sub[i]); // porownanie 2 inputow , jezeli jest = 0 znaczy ze sa identyczne 
       if ( res == 0 )
       {
           text_sub[i].clear() ; //czyscimy okreslony element vektora
           text_sub[i] = replace; // ustawiamy nowa wartosc do danego elementu 
          // std::cout << "Zamieniono " << find << " z " << replace << std::endl; 
          //  std::cout << text_sub[i]<<std::endl; 
       }
       
   }
   std::string output = ""; 
   for (int i = 0; i < text_sub.size() ; i++) //skladamy z powrotem stringa z vectora , z spacja miedzy elementami 
   {
       output += text_sub[i];
       output += " "; 
   }
   return output ;
}


int main()
{
    std::string input = "Ala ma kota, kot zjadl Ale!";
    std::string output = find_and_replace(input, "kot", "hefalump"); 
     std::cout << output << std::endl; 
}

