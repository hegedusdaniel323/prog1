#include "std_lib_facilities.h"
#include "Matrix.h"
#include "MatrixIO.h"
#include <complex>

using namespace Numeric_lib;


//4. Write a program that takes ints from cin and outputs the sqrt() of each
//int, or "no square root" if sqrt(x) is illegal for some x (i.e., check your
//sqrt() return values).
void sqroot(){
    cout<<"Enter ints to calculate their square root!\n";
    int i;
    while(cin>>i){
        if(i<0){
            cout<<"no square root ("<<i<<")\n\n";
            break;
        }
        else{
            double d = sqrt(i);
            cout<<"square root of "<<i<<" = "<<d<<endl;
        }
    }
}

int main(){
    
    //1. Print the size of a char, a short, an int, a long, a float, a double, an
    //int*, and a double* (use sizeof, not <limits>).
    cout<<"Size of char: "<<sizeof(char)<<endl
        <<"Size of short: "<<sizeof(short)<<endl
        <<"Size of int: "<<sizeof(int)<<endl
        <<"Size of long: "<<sizeof(long)<<endl
        <<"Size of float: "<<sizeof(float)<<endl
        <<"Size of double: "<<sizeof(double)<<endl
        <<"Size of int*: "<<sizeof(int*)<<endl
        <<"Size of double*: "<<sizeof(double*)<<endl<<endl;


    //2. Print out the size as reported by sizeof of Matrix<int> a(10),
    //Matrix<int> b(100), Matrix<double> c(10), Matrix<int,2> d(10,10),
    //Matrix<int,3> e(10,10,10).
    Matrix<int> a(10);
    Matrix<int> b(100);
    Matrix<double> c(10);
    Matrix<int,2> d(10,10);
    Matrix<int,3> e(10,10,10);
    cout<<"Size of 'a' matrix: "<<sizeof(a)<<endl
        <<"Size of 'b' matrix: "<<sizeof(b)<<endl
        <<"Size of 'c' matrix: "<<sizeof(c)<<endl
        <<"Size of 'd' matrix: "<<sizeof(d)<<endl
        <<"Size of 'e' matrix: "<<sizeof(e)<<endl<<endl;
    
    //3. Print out the number of elements of each of the Matrixes from 2.
    cout<<"Number of elements:\na:\t"<<a.size()<<endl
        <<"b:\t"<<b.size()<<endl
        <<"c:\t"<<c.size()<<endl
        <<"d:\t"<<d.size()<<endl
        <<"e:\t"<<e.size()<<endl<<endl;;
    
    //4.
    sqroot();

    //5. Read ten floating-point values from input and put them into a
    // Matrix<double>. Matrix has no push_back() so be careful to handle an
    //attempt to enter a wrong number of doubles. Print out the Matrix.
    cout<<"Enter 10 doubles to fill the matrix!\n";
    Matrix<double> doubles(10);
    double dd;
    for(int i=0; i<doubles.size(); i++){
        while(!(cin>>dd)){
            cout<<"WRONG INPUT, enter a double: ";
            cin.clear();
            cin.ignore();
        }
        doubles[i] = dd;
    }
    cout<<"Elements of the matrix: "<<doubles<<endl<<endl;

    //6. Compute a multiplication table for [0,n)*[0,m) and represent it as a 2D
    //Matrix. Take n and m from cin and print out the table nicely (assume that
    //m is small enough that the results fit on a line).
    int n,m;
    cout<<"Enter the val of 'n' and 'm': ";
    cin>>n>>m;
    Matrix<int,2>multi_table(n,m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            multi_table(i,j) = (i+1)*(j+1);
            cout<<multi_table(i,j)<<'\t';
        }
        cout<<endl;
    }
    cout<<endl;

    //Read ten complex<double>s from cin (yes, cin supports >> for
    //complex) and put them into a Matrix. Calculate and output the sum of the
    //ten complex numbers.
    Matrix<complex<double>> m_comp(10);
    complex<double> comp;
    complex<double> sum;
    cout<<"Enter 10 complex numbers in (real,imaginary) format!\n";
    for(int i=0; i<m_comp.size(); i++){
        cin>>comp;
        m_comp[i] = comp;
        sum += m_comp[i];
    }
    cout<<sum<<endl<<endl;;

    //8. Read six ints into a Matrix<int,2> m(2,3) and print them out.
    Matrix<int,2> m1(2,3);
    cout<<"Enter six ints to fill the matrix!\n";
    for(int i=0; i<2; i++)
        for(int j=0; j<3; j++)
            cin>>m1(i,j);
    cout<<"The matrix:\n";
    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
            cout<<m1(i,j)<<'\t';
        }
        cout<<endl;
    }

    return 0;
}