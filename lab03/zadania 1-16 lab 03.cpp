ZAD1 
#include <iostream>
#include <vector>
#include <random>
#include <ctime>
int randomInt(int min = -20, int max = 20) {
  static std::default_random_engine e{static_cast<long unsigned int>(time(0))};
  std::uniform_int_distribution<int> d{min, max};
  return d(e);
}
std::vector <int> random (int n)
{    std::vector <int> rand ;
    for(int i = 0 ; i<n ; i++)
        rand.emplace_back( randomInt(-20,20) );

  return rand ;
}


int main()
{
    std::vector <int> rand ;
    int n ;
    std::cin>>n ; std::cin.ignore();
    rand = random(n) ;
    for(int i = 0 ; i < rand.size() ; i++)
    {
        std::cout<<rand[i]<<std::endl;
    }
    for(auto x = rand.begin() ; x!= rand.end() ; x++)
    {
        std::cout<<*x<<std::endl;
    }
    int n1 ;
    std::cin>>n1 ;
    for( auto x = rand.begin() ; x!= rand.end() ; x++)
    {
        if(*x == n1)
        {
            std::cout<<"Usuwam element "<<*x<<std::endl;
            rand.erase(x);

        }
    }
    return 0;
}

ZAD2



#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <string>
#include <list>
int randomInt(int min = -20, int max = 20) {
  static std::default_random_engine e{static_cast<long unsigned int>(time(0))};
  std::uniform_int_distribution<int> d{min, max};
  return d(e);
}
std::list<int> random (int n)
{    std::list<int> rand  ;
     int x = 0 ;
    for(int i = 0 ; i<n ; i++)
    {
        x = randomInt(-20,20) ;
        rand.emplace_back(x);
    }
  return rand ;
}
int main()
{
    std::list <int> rand ;
    int n ;
    std::cin>>n ; std::cin.ignore();
    rand = random(n) ;
    for(auto x = rand.begin() ; x!= rand.end() ; x++)
    {
        std::cout<<*x<<std::endl;
    }
    int n1 ;
    std::cin>>n1 ;
    auto it = find(rand.begin() , rand.end() , n1) ;
    if (it != rand.end())
    {
        std::cout<<"Usuwam element "<<*it<<std::endl;
        rand.erase(it) ;
    }
    return 0;
}




ZAD03
//metody find użyłem wczesniej dlaego pomijam to zadanie  




ZAD04
#include <iostream>
#include <vector>
#include <random>
#include <ctime>
int randomInt(int min = -20, int max = 20) {
  static std::default_random_engine e{static_cast<long unsigned int>(time(0))};
  std::uniform_int_distribution<int> d{min, max};
  return d(e);
}
std::vector <int> random (int n)
{    std::vector <int> rand ;
    for(int i = 0 ; i<n ; i++)
        rand.emplace_back( randomInt(-20,20) );

  return rand ;
}


int main()
{
    std::vector <int> rand ;
    int n ;
    std::cin>>n ; std::cin.ignore();
    rand = random(n) ;
    for(auto x = rand.begin() ; x!= rand.end() ; x++)
    {
        std::cout<<*x<<std::endl;
    }
    auto ix = std::min_element(rand.begin() , rand.end() ) ;
    auto iy = std::max_element(rand.begin() , rand.end() ) ;
    std::cout<<"Najmniejszy element "<<*ix<<std::endl;
    std::cout<<"Najwiekszy  element "<<*iy<<std::endl;
    auto iz = std::minmax_element(rand.begin() , rand.end());
    std::cout<<"Najmniejszy element minmax"<<*iz.first<<std::endl;
    std::cout<<"Najwiekszy  element minmax"<<*iz.second<<std::endl;
    return 0;
}


ZAD05
#include <iostream>
#include <vector>
#include <random>
#include <ctime>
int randomInt(int min = -20, int max = 20) {
  static std::default_random_engine e{static_cast<long unsigned int>(time(0))};
  std::uniform_int_distribution<int> d{min, max};
  return d(e);
}
std::vector <int> random (int n)
{    std::vector <int> rand ;
    for(int i = 0 ; i<n ; i++)
        rand.emplace_back( randomInt(-20,20) );

  return rand ;
}


int main()
{
    std::vector <int> rand ;
    int n ;
    std::cin>>n ; std::cin.ignore();
    rand = random(n) ;
    for(auto x = rand.begin() ; x!= rand.end() ; x++)
    {
        std::cout<<*x<<std::endl;
    } ;
    std::cout<<std::endl;
    std::sort(rand.begin(),rand.end() );
    for(auto x = rand.begin() ; x!= rand.end() ; x++)
    {
        std::cout<<*x<<std::endl;
    };
     std::cout<<std::endl;
    std::sort(rand.begin(),rand.end() , [] (int a , int b) { return a > b ; } ) ;
    for(auto x = rand.begin() ; x!= rand.end() ; x++)
    {
        std::cout<<*x<<std::endl;
    } ;
     std::cout<<std::endl;
     std::sort(rand.begin(),rand.end() , [] (int a , int b) { return abs(a) > abs(b) ; } ) ;
     for(auto x = rand.begin() ; x!= rand.end() ; x++)
     {
         std::cout<<*x<<std::endl;
     } ;
      std::cout<<std::endl;
    return 0;
}
ZAD06

#include <random>
#include <iostream>
#include <ctime>
#include <string>
#include <list>
int randomInt(int min = -20, int max = 20) {
  static std::default_random_engine e{static_cast<long unsigned int>(time(0))};
  std::uniform_int_distribution<int> d{min, max};
  return d(e);
}
std::list<int> random (int n)
{    std::list<int> rand  ;
     int x = 0 ;
    for(int i = 0 ; i<n ; i++)
    {
        x = randomInt(-20,20) ;
        rand.emplace_back(x);
    }
  return rand ;
}
int main()
{
    std::list <int> rand ;
    int n ;
    std::cin>>n ; std::cin.ignore();
    rand = random(n) ;
    for(auto x = rand.begin() ; x!= rand.end() ; x++)
    {
        std::cout<<*x<<std::endl;
    }
    int n2 ;
    std::cin>>n2 ;
    auto it  = std::count(rand.begin(), rand.end() , n2 ) ;
    std::cout<<"Elementow "<<n<<" Jest "<<it<<std::endl;
    return 0;
}

ZAD07 

#include <iostream>
#include <vector>
enum class TypRosliny { Owoc, Warzywo };

struct Roslina {
    TypRosliny typ;
    std::string nazwa;
};

using Koszyk = std::vector<Roslina>;



int main()
{   Koszyk koszyk;
    koszyk.emplace_back(TypRosliny::Owoc , "Jablko") ;  //1
    Roslina banan { TypRosliny::Owoc, "Banan" };
    koszyk.push_back(banan); //2
    Koszyk koszyk2  // 3
    {
        {TypRosliny::Warzywo , "Ziemniak"} ,
        {TypRosliny::Owoc , "KIWI"} ,

    } ;

    return 0;
}

ZAD08 
#include <iostream>
#include <vector>

enum class TypRosliny { Owoc, Warzywo };

struct Roslina {
    TypRosliny typ;
    std::string nazwa;
};

using Koszyk = std::vector<Roslina>;

std::ostream& operator<<(std::ostream &out, const Roslina &roslina) {
    out << roslina.nazwa << " (";
    if (roslina.typ == TypRosliny::Owoc) {
        out << "owoc";
    } else {
        out << "warzywo";
    }
    out << ")";
    return out;
}

std::ostream& operator<<(std::ostream &out, const Koszyk &koszyk) {
    out << "W koszyku znajduja sie nastepujace rosliny:"<<std::endl;
    for (const auto &roslina : koszyk) {
        out << "- " << roslina << std::endl;
    }
    return out;
}

int main() {
    Koszyk koszyk = {
        {TypRosliny::Owoc, "Jablko"},
        {TypRosliny::Owoc, "Pomarancza"},
        {TypRosliny::Warzywo, "Marchewka"},
        {TypRosliny::Warzywo, "Cebula"},
        {TypRosliny::Warzywo, "Ziemniak"}
    };

    std::cout << koszyk << std::endl;
    return 0;
}

ZAD09
#include <iostream>
#include <vector>

enum class TypRosliny { Owoc, Warzywo };

struct Roslina {
    TypRosliny typ;
    std::string nazwa;
};

using Koszyk = std::vector<Roslina>;

std::ostream& operator<<(std::ostream &out, const Roslina &roslina) {
    out << roslina.nazwa << " (";
    if (roslina.typ == TypRosliny::Owoc) {
        out << "owoc";
    } else {
        out << "warzywo";
    }
    out << ")";
    return out;
}

std::ostream& operator<<(std::ostream &out, const Koszyk &koszyk) {
    out << "W koszyku znajduja sie nastepujace rosliny:"<<std::endl;
    for (const auto &roslina : koszyk) {
        out << "- " << roslina << std::endl;
    }
    return out;
}
bool czy_jest_gruszka(const Koszyk &koszyk)
{
    auto x =  std::find_if(koszyk.begin() , koszyk.end() , [] (Roslina nazwa ) {return nazwa.nazwa == "Gruszka" ; }) ;


    return x!= koszyk.end() ;
}

int main() {
    Koszyk koszyk = {
        {TypRosliny::Owoc, "Jablko"},
        {TypRosliny::Owoc, "Pomarancza"},
        {TypRosliny::Warzywo, "Marchewka"},
        {TypRosliny::Warzywo, "Cebula"},
        {TypRosliny::Warzywo, "Ziemniak"},
        {TypRosliny::Owoc , "Gruszka"}
    };

    std::cout << koszyk << std::endl;
    if ( czy_jest_gruszka(koszyk) == true)
    {
        std::cout<<"Znajduje sie gruszka"<<std::endl;
    }
    else
    {
        std::cout<<"Nie znajduje sie gruszka"<<std::endl;
    }
    return 0;
}

ZAD10
#include <iostream>
#include <vector>
#include <algorithm>
enum class TypRosliny { Owoc, Warzywo };

struct Roslina {
    TypRosliny typ;
    std::string nazwa;
};

using Koszyk = std::vector<Roslina>;

std::ostream& operator<<(std::ostream &out, const Roslina &roslina) {
    out << roslina.nazwa << " (";
    if (roslina.typ == TypRosliny::Owoc) {
        out << "owoc";
    } else {
        out << "warzywo";
    }
    out << ")";
    return out;
}

std::ostream& operator<<(std::ostream &out, const Koszyk &koszyk) {
    out << "W koszyku znajduja sie nastepujace rosliny:"<<std::endl;
    for (const auto &roslina : koszyk) {
        out << "- " << roslina << std::endl;
    }
    return out;
}
bool same_owoce(Koszyk koszyk)
{   auto x = 0 ;
    x = std::any_of(koszyk.begin(),koszyk.end(),[] (Roslina cos) { return cos.typ == TypRosliny::Owoc ; }   ) ;


    return x != 0 ;
}
bool same_warzywa (Koszyk koszyk)
{   auto x = 0 ;
    x = std::any_of(koszyk.begin(),koszyk.end(),[] (Roslina cos) { return cos.typ == TypRosliny::Warzywo ; }   ) ;


    return x != 0 ;
}
bool koszyk_mieszany (Koszyk koszyk)
{   auto x = 0 ;
    auto x2 = 0 ;
    x = std::any_of(koszyk.begin(),koszyk.end(),[] (Roslina cos) { return cos.typ == TypRosliny::Warzywo ; }   ) ;
    x2 = std::any_of(koszyk.begin(),koszyk.end(),[] (Roslina cos) { return cos.typ == TypRosliny::Owoc ; }    ) ;

    return x == x2 ;
}



int main() {
    Koszyk koszyk = {
        {TypRosliny::Owoc, "Jablko"},
        {TypRosliny::Owoc, "Pomarancza"},
        {TypRosliny::Warzywo, "Marchewka"},
        {TypRosliny::Warzywo, "Cebula"},
        {TypRosliny::Warzywo, "Ziemniak"},
        {TypRosliny::Owoc , "Gruszka"}
    };
if( koszyk_mieszany(koszyk) == true)
{
    std::cout<<"Koszyk jest mieszany"<<std::endl;
}
else if (same_owoce(koszyk) == true )
{
    std::cout<<"Koszyk ma same owoce"<<std::endl;
}
else if (same_warzywa(koszyk) == true )
{
    std::cout<<"Koszyk ma same warzywa"<<std::endl;
}
else
{
    std::cout<<"Koszyk jest pusty"<<std::endl;
}
    return 0;
}

ZAD11
#include <iostream>
#include <vector>
#include <algorithm>
enum class TypRosliny { Owoc, Warzywo };

struct Roslina {
    TypRosliny typ;
    std::string nazwa;
};

using Koszyk = std::vector<Roslina>;

std::ostream& operator<<(std::ostream &out, const Roslina &roslina) {
    out << roslina.nazwa << " (";
    if (roslina.typ == TypRosliny::Owoc) {
        out << "owoc";
    } else {
        out << "warzywo";
    }
    out << ")";
    return out;
}

std::ostream& operator<<(std::ostream &out, const Koszyk &koszyk) {
    out << "W koszyku znajduja sie nastepujace rosliny:"<<std::endl;
    for (const auto &roslina : koszyk) {
        out << "- " << roslina << std::endl;
    }
    return out;
}
int zlicz_owoce(Koszyk koszyk)
{

    auto x = std::count_if(koszyk.begin(),koszyk.end(), [] (Roslina cos ){return cos.typ == TypRosliny::Owoc ;}) ;

    return x  ;
}
int zlicz_warzywa(Koszyk koszyk)
{

    auto x = std::count_if(koszyk.begin(),koszyk.end(), [] (Roslina cos ){return cos.typ == TypRosliny::Warzywo ;}) ;

    return x  ;
}



int main() {
    Koszyk koszyk = {
        {TypRosliny::Owoc, "Jablko"},
        {TypRosliny::Owoc, "Pomarancza"},
        {TypRosliny::Warzywo, "Marchewka"},
        {TypRosliny::Warzywo, "Cebula"},
        {TypRosliny::Warzywo, "Ziemniak"},
        {TypRosliny::Warzywo, "Marchewka"},
        {TypRosliny::Owoc , "Gruszka"}
    };
    std::cout<<"Owocow jest "<<zlicz_owoce(koszyk)<<std::endl;
    std::cout<<"Warzyw jest "<<zlicz_warzywa(koszyk)<<std::endl;
    return 0;
}

ZAD12 
#include <iostream>
#include <vector>
#include <algorithm>


enum class TypRosliny { Owoc, Warzywo };

struct Roslina {
    TypRosliny typ;
    std::string nazwa;
};

using Koszyk = std::vector<Roslina>;

std::ostream& operator<<(std::ostream &out, const Roslina &roslina) {
    out << roslina.nazwa << " (";
    if (roslina.typ == TypRosliny::Owoc) {
        out << "owoc";
    } else {
        out << "warzywo";
    }
    out << ")";
    return out;
}


std::ostream& operator<<(std::ostream &out, const Koszyk &koszyk) {
    out << "W koszyku znajduja sie nastepujace rosliny:"<<std::endl;
    for (const auto &roslina : koszyk) {
        out << "- " << roslina << std::endl;
    }
    return out;
}
void usun_zaczynajace_sie_od(std::string x  , Koszyk& koszyk) // funkcja usuwa elementy "klasy" warzywo lub owoc
{


    if(x == "Warzywo")
    {
   koszyk.erase(std::remove_if(koszyk.begin() , koszyk.end() ,  [](const Roslina x){return x.typ == TypRosliny::Warzywo ; } ) , koszyk.end() ) ;

   std::cout<<"Usuwam warzywa"<<std::endl;
      // std::cout<<koszyk<<std::endl;
    }
    if(x== "Owoc")
    {
     std::cout<<"Usuwam owoce"<<std::endl;
  koszyk.erase(std::remove_if(koszyk.begin() , koszyk.end() ,  [](const Roslina x){return x.typ == TypRosliny::Owoc ; } ) , koszyk.end() )  ;
    }

}
void usun_zaczynajace_sie_od_2(std::string x  , Koszyk& koszyk) //funkcja usuwa nazwe ale nie usuwa elementu
{


    if(x == "Warzywo")
    {
   std::remove_if(koszyk.begin() , koszyk.end() ,  [](const Roslina x){return x.typ == TypRosliny::Warzywo ; } ) ;

   std::cout<<"Usuwam warzywa"<<std::endl;
      // std::cout<<koszyk<<std::endl;
    }
    if(x== "Owoc")
    {
     std::cout<<"Usuwam owoce"<<std::endl;
  std::remove_if(koszyk.begin() , koszyk.end() ,  [](const Roslina x){return x.typ == TypRosliny::Owoc ; } )  ;
    }

}
void usun_zaczynajace_sie_od_3( Koszyk& koszyk , std::string y) // funkcja usuwa elementy zaczynajace sie na dana litere
{



   koszyk.erase(std::remove_if(koszyk.begin() , koszyk.end() ,  [y](const Roslina x){
       std::string x2 = x.nazwa.substr(0 , 1) ;
       return x2 == y ; } ) , koszyk.end() ) ;

   std::cout<<"Usuwam wszystko na litere "<<y<<std::endl;


}





int main()
    {
    Koszyk koszyk =
    {
        {TypRosliny::Owoc, "Jablko"},
        {TypRosliny::Owoc, "Pomarancza"},
        {TypRosliny::Warzywo, "Marchewka"},
        {TypRosliny::Warzywo, "Cebula"},
        {TypRosliny::Warzywo, "Ziemniak"},
        {TypRosliny::Owoc , "Gruszka"}
    };
    std::string x = "Warzywo";
    std::cout<<koszyk<<std::endl;
    usun_zaczynajace_sie_od_3( koszyk , "J") ;
    std::cout<<koszyk<<std::endl;
    std::vector <int> cda ;
return 0 ;
}
;


ZAD13 
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>


enum class TypRosliny { Owoc, Warzywo };

struct Roslina {
    TypRosliny typ;
    std::string nazwa;
};

using Koszyk = std::vector<Roslina>;

std::ostream& operator<<(std::ostream &out, const Roslina &roslina) {
    out << roslina.nazwa << " (";
    if (roslina.typ == TypRosliny::Owoc) {
        out << "owoc";
    } else {
        out << "warzywo";
    }
    out << ")";
    return out;
}


std::ostream& operator<<(std::ostream &out, const Koszyk &koszyk) {
    out << "W koszyku znajduja sie nastepujace rosliny:"<<std::endl;
    for (const auto &roslina : koszyk) {
        out << "- " << roslina << std::endl;
    }
    return out;
}
bool operator<(const Roslina &r1, const Roslina &r2)
{
   if( r1.nazwa < r2.nazwa)
       return 1 ;
   else
       return 0 ;

} ;


int main()
    {
    Koszyk koszyk =
    {
        {TypRosliny::Owoc, "Jablko"},
        {TypRosliny::Owoc, "Pomarancza"},
        {TypRosliny::Warzywo, "Marchewka"},
        {TypRosliny::Warzywo, "Cebula"},
        {TypRosliny::Warzywo, "Ziemniak"},
        {TypRosliny::Owoc , "Gruszka"}
    };
    std::cout<<koszyk<<std::endl;

     return 0 ;
}
;


ZAD14
include <iostream>
#include <vector>
#include <algorithm>
#include <set>


enum class TypRosliny { Owoc, Warzywo };

struct Roslina {
    TypRosliny typ;
    std::string nazwa;
};

using Koszyk = std::vector<Roslina>;

std::ostream& operator<<(std::ostream &out, const Roslina &roslina) {
    out << roslina.nazwa << " (";
    if (roslina.typ == TypRosliny::Owoc) {
        out << "owoc";
    } else {
        out << "warzywo";
    }
    out << ")";
    return out;
}


std::ostream& operator<<(std::ostream &out, const Koszyk &koszyk) {
    out << "W koszyku znajduja sie nastepujace rosliny:"<<std::endl;
    for (const auto &roslina : koszyk) {
        out << "- " << roslina << std::endl;
    }
    return out;
}
bool operator<(const Roslina &r1, const Roslina &r2)
{
   if( r1.nazwa < r2.nazwa)
       return 1 ;
   else
       return 0 ;

} ;


int main()
    {
    Koszyk koszyk =
    {
        {TypRosliny::Owoc, "Jablko"},
        {TypRosliny::Owoc, "Pomarancza"},
        {TypRosliny::Warzywo, "Marchewka"},
        {TypRosliny::Warzywo, "Cebula"},
        {TypRosliny::Warzywo, "Ziemniak"},
        {TypRosliny::Owoc , "Gruszka"}
    };
    std::cout<<koszyk<<std::endl;
    Koszyk koszyk2 =
    {
        {TypRosliny::Owoc , "Kiwi"} ,
        {TypRosliny::Warzywo , "Chrzan"} ,
        {TypRosliny::Owoc, "Pomarancza"},
        {TypRosliny::Warzywo, "Marchewka"}
    };
    std::cout<<koszyk2<<std::endl;
    std::sort(koszyk.begin(), koszyk.end());
    std::sort(koszyk2.begin(), koszyk2.end());
    Koszyk koszyk_wspolne;
    Koszyk koszyk_rozne ;
    Koszyk koszyk_rozne2 ;
    std::set_intersection(koszyk.begin(), koszyk.end(),
                   koszyk2.begin(), koszyk2.end() ,std::back_inserter(koszyk_wspolne) ) ;


    std::cout<<"Wspolne elementy koszykow :"<<koszyk_wspolne ;
    std::set_difference(koszyk.begin() , koszyk.end() , koszyk2.begin() , koszyk2.end() ,std::inserter(koszyk_rozne , koszyk_rozne.end()) ) ;
    std::set_difference(koszyk2.begin() , koszyk2.end() , koszyk.begin() , koszyk.end() ,std::inserter(koszyk_rozne2 , koszyk_rozne2.end()) ) ;
    for (auto i : koszyk_rozne2)
    {
        koszyk_rozne.emplace_back(i) ;
    }
    std::cout<<"Rozne elementy koszykow :"<<koszyk_rozne ;
     return 0 ;
}
;

ZAD15 
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>


enum class TypRosliny { Owoc, Warzywo };

struct Roslina {
    TypRosliny typ;
    std::string nazwa;
};

using Koszyk = std::vector<Roslina>;

std::ostream& operator<<(std::ostream &out, const Roslina &roslina) {
    out << roslina.nazwa << " (";
    if (roslina.typ == TypRosliny::Owoc) {
        out << "owoc";
    } else {
        out << "warzywo";
    }
    out << ")";
    return out;
}


std::ostream& operator<<(std::ostream &out, const Koszyk &koszyk) {
    out << "W koszyku znajduja sie nastepujace rosliny:"<<std::endl;
    for (const auto &roslina : koszyk) {
        out << "- " << roslina << std::endl;
    }
    return out;
}
bool operator<(const Roslina &r1, const Roslina &r2)
{
   if( r1.nazwa < r2.nazwa)
       return 1 ;
   else
       return 0 ;

} ;


int main()
    {
    Koszyk koszyk =
    {
        {TypRosliny::Owoc, "Jablko"},
        {TypRosliny::Owoc, "Pomarancza"},
        {TypRosliny::Warzywo, "Marchewka"},
        {TypRosliny::Warzywo, "Cebula"},
        {TypRosliny::Warzywo, "Ziemniak"},
        {TypRosliny::Owoc , "Gruszka"}
    };
    std::cout<<koszyk<<std::endl;
    Koszyk koszyk2 =
    {
        {TypRosliny::Owoc , "Kiwi"} ,
        {TypRosliny::Warzywo , "Chrzan"} ,
        {TypRosliny::Owoc, "Pomarancza"},
        {TypRosliny::Warzywo, "Marchewka"}
    };
    std::cout<<koszyk2<<std::endl;
    std::sort(koszyk.begin(), koszyk.end());
    std::sort(koszyk2.begin(), koszyk2.end());
    Koszyk koszyk_wspolny ;
   std::set_union(koszyk.begin() , koszyk.end() , koszyk2.begin() , koszyk2.end() , std::back_inserter(koszyk_wspolny) )  ;
   std::cout<< koszyk_wspolny ;
     return 0 ;
}
;

ZAD16
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
    plik.open("C:/Users/wikto/Desktop/Programowanie/LABORATORIUM 2 SEM/LAB003/zad16kursy_usd_eur.csv");
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

        for (int i = 0; i < rozmiar ; i++)
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

KONIEC. 