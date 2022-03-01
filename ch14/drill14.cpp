#include "std_lib_facilities.h"

class B1
{
    public:
        virtual void vf() { cout << "B1::vf()\n"; }
        void f() { cout << "B1::f()\n"; }
        virtual void pvf() = 0;
};

class D1 : public B1
{
    public:
        void vf() override { cout << "D1::vf()\n"; }
        void f() { cout << "D1::f()\n"; }
};

class D2 : public D1
{
    public:
        void pvf() override { cout << "D2::pvf()\n"; }
};

class B2
{
    public:
        virtual void pvf() = 0;
};

class D21 : public B2
{
    string s = "szoveg";
    public:
        void pvf() override { cout << s << endl; }
};

class D22 : public B2
{
    int i = 0;
    public:
        void pvf() override { cout << i << endl; }

};

void f(B2& b) { b.pvf(); }

int main()
{
    /*B1 b1;
    b1.vf();
    b1.f();

    D1 d1;
    d1.vf();
    d1.f();

    B1& ref {d1};
    ref.vf();
    ref.f();*/

    D2 d2;
    d2.vf();
    d2.f();
    d2.pvf();

    D21 d21;
    f(d21);

    D22 d22;
    f(d22);

    return 0;
}