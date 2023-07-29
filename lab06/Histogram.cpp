#include "Histogram.h"
#include <iostream> 
#include <algorithm>
template <typename T>
Histogram<T>::Histogram(const std::vector<T>& data)
{
	for (const auto& val : data)
	{
		wektor.emplace_back(val);
	}
}
template<>
Histogram<float>::Histogram(const std::vector<float>& data)
{
	for (const auto& val : data)
	{
		wektor.emplace_back(val);
	}
}
template<>
Histogram<int>::Histogram(const std::vector<int>& data)
{
	for (int i = 0; i < data.size(); i++)
	{
		wektor.emplace_back(data[i]);
	}
}
template <typename T>
void Histogram<T>::clear()
{
	wektor.clear();
	std::cout << "usuwam wektor T" << std::endl;
}
void Histogram<int>::clear()
{
	wektor.clear();
	std::cout << "usuwam wektor Int" << std::endl;
} void Histogram<double>::clear()
{
	wektor.clear();
	std::cout << "usuwam wektor Double" << std::endl;
}
void Histogram<float>::clear()
{
	wektor.clear();
	std::cout << "usuwam wektor Float" << std::endl;
}

template<>
Histogram<std::string>::Histogram(const std::vector<std::string>& data)
{
	for (const auto& val : data)
	{
		wektor.emplace_back(val);
	}
}
template<typename T>
void Histogram<T>::emplace(const T& v)
{
	wektor.emplace_back(v);
}

void Histogram<int>::emplace(const int& v)
{
	wektor.emplace_back(v);
}
void Histogram<std::string>::emplace(const std::string& v)
{
	wektor.emplace_back(v);
}
void Histogram<float>::emplace(const float& v)
{
	wektor.emplace_back(v);
}

template <typename T>
void Histogram<T>::emplace(const std::vector<T>& data)
{
	wektor.insert(wektor.end(), data.begin(), data.end());
}


template<typename T>
void Histogram<T>::print()
{

	std::vector<T> cos;
	for (auto a : wektor)
	{
		std::cout << a << std::endl;
	}
	if (wektor.empty() == true)
	{
		std::cout << "wektor pusty" << std::endl;
	}
	for (auto a : wektor)
	{
		if (std::count(cos.begin(), cos.end(), a) == 0)
		{
			int x = std::count(wektor.begin(), wektor.end(), a);
			std::cout << "elementow " << a << " jest " << x << std::endl;
			cos.emplace_back(a);

		}
	}
}
template<typename T>
void Histogram<T>::from_csv()
{
	T linia;
	std::fstream plik;
	plik.open("C:/Users/wikto/Desktop/Programowanie/LABORATORIUM 2 SEM/LAB006/zad01/dane.csv");
	if (plik.good() == true)
	{
		std::cout << "plik git T" << std::endl;
	}
	else
	{
		std::cout << "nie udalo sie" << std::endl;
	}
	while (plik >> linia)
	{
		wektor.push_back(linia);
		std::cout << std::endl;
		std::cout << "Dodaje " << linia << std::endl;
		std::cout << std::endl;
	}
	plik.close();
}
void Histogram<std::string>::from_csv()
{
	std::string linia;
	std::fstream plik;
	plik.open("C:/Users/wikto/Desktop/Programowanie/LABORATORIUM 2 SEM/LAB006/zad01/dane.csv");
	if (plik.good() == true)
	{
		std::cout << "plik git string" << std::endl;
	}
	else
	{
		std::cout << "nie udalo sie" << std::endl;
	}
	while (plik >> linia)
	{
		wektor.push_back(linia);
		std::cout << std::endl;
		std::cout << "Dodaje " << linia << std::endl;
		std::cout << std::endl;
	}
	plik.close();
}
void Histogram<int>::from_csv()
{
	int linia;
	std::fstream plik;
	plik.open("C:/Users/wikto/Desktop/Programowanie/LABORATORIUM 2 SEM/LAB006/zad01/dane.csv");
	if (plik.good() == true)
	{
		std::cout << "plik git int" << std::endl;
	}
	else
	{
		std::cout << "nie udalo sie" << std::endl;
	}
	while (plik >> linia)
	{
		wektor.push_back(linia);
		std::cout << std::endl;
		std::cout << "Dodaje " << linia << std::endl;
		std::cout << std::endl;
	}
	plik.close();
}
void Histogram<float>::from_csv()
{
	float linia;
	std::fstream plik;
	plik.open("C:/Users/wikto/Desktop/Programowanie/LABORATORIUM 2 SEM/LAB006/zad01/dane.csv");
	if (plik.good() == true)
	{
		std::cout << "plik git float" << std::endl;
	}
	else
	{
		std::cout << "nie udalo sie" << std::endl;
	}
	while (plik >> linia)
	{
		wektor.push_back(linia);
		std::cout << std::endl;
		std::cout << "Dodaje " << linia << std::endl;
		std::cout << std::endl;
	}
	plik.close();
}
template class Histogram<int>;
void Histogram<std::string>::print()
{
	std::vector<std::string> cos;
	for (auto a : wektor)
	{
		std::cout << a << std::endl;
	}
	if (wektor.empty() == true)
	{
		std::cout << "wektor pusty" << std::endl;
	}
	for (auto a : wektor)
	{
		if (std::count(cos.begin(), cos.end(), a) == 0)
		{
			int x = std::count(wektor.begin(), wektor.end(), a);
			std::cout << "elementow " << a << " jest " << x << std::endl;
			cos.emplace_back(a);

		}
	}
}
void Histogram<float>::print()
{
	std::sort(wektor.begin(), wektor.end(), [](float a, float b) {return a < b; });
	std::vector<float> cos;
	for (auto a : wektor)
	{
		std::cout << a << std::endl;
	}
	if (wektor.empty() == true)
	{
		std::cout << "wektor pusty" << std::endl;
	}
	for (auto a : wektor)
	{
		if (std::count(cos.begin(), cos.end(), a) == 0)
		{
			int x = std::count(wektor.begin(), wektor.end(), a);
			std::cout << "elementow " << a << " jest " << x << std::endl;
			cos.emplace_back(a);

		}
	}
}