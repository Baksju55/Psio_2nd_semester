#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

template <typename T>
class Histogram
{
private:
    std::vector<T> wektor;
    int precyzja = 20; 

public:
    Histogram(const std::vector<T>& data = std::vector<T>());

    void emplace(const T& v); 
    void emplace(const std::vector<T>& data);
   // void emplace(const std::vector<std::vector<T>>& data);
    void zmien_prezycje();
    void print();

    void clear();
   // void emplace(const float& v);
    void from_csv();

   // void emplace();
    
};

