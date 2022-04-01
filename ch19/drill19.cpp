#include "std_lib_facilities.h"

template<typename t>
struct S
{
private:
    t val;

public:
    S(t x)
    {
        val=x;
    }

    t get()const;

    t& get();

    void kiir()
    {
        cout<<val<<endl;
    }

    void operator=(const t& stemp)
    {
        val=stemp;
    }
};

template<typename t>
t S<t>::get()const
{
    return val;
}

template<typename t>
t& S<t>::get()
{
    return val;
}

template<typename t>
ostream& operator<<(ostream& os,S<t>& stemp)
{
    return os<<stemp.get();
}

template<typename t>
istream& operator>>(istream& is,S<t>& stemp)
{
    return is>>stemp.get();
}

void kiirvector(ostream& os,vector<int>vektor)
{
    for(int i=0;i<vektor.size();i++)
    {
        cout<<vektor[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    S<int>sint(42);
    sint.kiir();
    S<char>schar('C');
    schar.kiir();
    S<double>sdouble(4.2);
    sdouble.kiir();
    S<vector<int>>svector({32,21,5,12});
    kiirvector(cout,svector.get());

    cout<<endl;
    cout<<sint.get()<<endl;
    cout<<schar.get()<<endl;
    cout<<sdouble.get()<<endl;
    kiirvector(cout,svector.get());
    cout<<endl;

    cout<<"Adjon meg egy egész számot, egy karaktert és egy lebegőpontos számot!"<<endl;
    
    cin>>sint;
    cin>>schar;
    cin>>sdouble;
    cout<<endl;
    
    cout<<sint<<endl;
    cout<<schar<<endl;
    cout<<sdouble<<endl;

    return 0;
}