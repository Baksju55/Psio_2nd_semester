

#include <iostream>
#include <vector>
#include <algorithm> 
#include "Histogram.h" 
#include <complex> 
int main()
{
    std::vector<int> x{ 10, 15, 20 };
    Histogram<int> hist(x);
   // hist.print();
    std::vector<std::string> x2 {"chuj21" , "shdas" , "shd" , "chuj21"};
    Histogram<std::string> hist2(x2); 
    std::vector<float> x3{ 232.21 , 21.37 };
    Histogram<float> hist3{x3}; 

  // hist2.print(); 
 //  hist.from_csv();
  // hist.print(); 
  //hist2.from_csv();
  // hist2.print();
   std::cout << std::endl;
   hist3.from_csv();
   hist3.print(); 
   hist2.print();

    return 0;
}

