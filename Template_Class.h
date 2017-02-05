#ifndef TEMPLATE_CLASS_H_INCLUDED
#define TEMPLATE_CLASS_H_INCLUDED

#include <iostream>
using namespace std;

template<class T>
class Polynomial
{
public:
    Polynomial(T c1, T c2, T c3)
    {
        coefA = c1;
        coefB = c2;
        coefC = c3;
    }

    T getCoefA()
    {
        return coefA;
    }
    T getCoefB()
    {
        return coefB;
    }
    T getCoefC()
    {
        return coefC;
    }

private:
    T coefA, coefB, coefC;
};

#endif // TEMPLATE_CLASS_H_INCLUDED
