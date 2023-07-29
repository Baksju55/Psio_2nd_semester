#include <iostream>

using namespace std;
bool is_palindrome(string a )
{
    int b = a.size() - 1 ;
    bool pal = true;
    for(int i=0 ; i< b/2 ; i++)
    {
        if (a[i] == a[b-i])
        {
            ;
        }
        else
        {
            pal = false ;
        }
        // cout<<a[i]<<" "<<a[b-i]<<endl;
    }


    if(pal == true)
        cout<<"jest palindromem";
    if(pal == false)
        cout<<"nie jest palindromem";


    return pal ;
}

int main()
{    string a = "racecar" ;
    is_palindrome(a) ;
    return 0;
}
