
#include <iostream>
#include <vector>


std::vector <int> find_all(std::string text, std::string a1)
{
    std::vector <int> pierwszy;
    int position = 0  ;
    while ((position = text.find(a1, position + 1)) != std::string::npos)
    {
        pierwszy.push_back(position); 

    }
    return pierwszy; 
}

int main()
{   
    std::string input = "Ala ma kota"; 
    std::vector <int> pos = find_all(input, "a");
    for (int i = 0; i < pos.size(); i++)
    {
        std::cout << pos[i] << std::endl; 
    }
}


