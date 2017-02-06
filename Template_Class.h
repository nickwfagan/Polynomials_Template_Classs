/**************************************************************
* programmer: Nicholas Fagan
* date: 2/5/2017
* assignment: HW 2 Polynomial template
* file: This .h file holds the class template as well as the polynomial class. after the template is 3 functions, first multiplies two 2nd degree polynomials
*       second adds two 2nd degree polynomials, third fills the arrays that will hold the coefficients for each polynomial.
***************************************************************/

#ifndef TEMPLATE_CLASS_H_INCLUDED
#define TEMPLATE_CLASS_H_INCLUDED

#include <iostream>
using namespace std;

template<class T> //template for polynomial class
class Polynomial
{
public:
    Polynomial(T c1, T c2, T c3) //2nd degree polynomials hold 3 coefficients, constructor holds 3 numbers 1 for each
    {
        coefA = c1;
        coefB = c2;
        coefC = c3;
    }

    T getCoefA() //getter methods to call for printing out the polynomials
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

void multiplyPolys(Polynomial<int> poly1, Polynomial<int> poly2) //function to multiply the polynomials
{
    int firstCoefMultiplied[3]; //each coefficient in the first polynomial is multiplied by each coefficient in the second polynomial
    int secondCoefMultiplied[3];
    int thirdCoefMultiplied[3];
    int finalPoly[5]; //when combining two 2nd degree polynomials there will be an x^4, creating 5 coefficients total

    firstCoefMultiplied[0] = poly1.getCoefA() * poly2.getCoefA(); //the first coefficient of polynomial 1 is multiplied by each coefficient off polynomial 2
    firstCoefMultiplied[1] = poly1.getCoefA() * poly2.getCoefB();
    firstCoefMultiplied[2] = poly1.getCoefA() * poly2.getCoefC();

    secondCoefMultiplied[0] = poly1.getCoefB() * poly2.getCoefA(); //the second coefficient of polynomial 1 is multiplied by each coefficient off polynomial 2
    secondCoefMultiplied[1] = poly1.getCoefB() * poly2.getCoefB();
    secondCoefMultiplied[2] = poly1.getCoefB() * poly2.getCoefC();

    thirdCoefMultiplied[0] = poly1.getCoefC() * poly2.getCoefA(); //the third coefficient of polynomial 1 is multiplied by each coefficient off polynomial 2
    thirdCoefMultiplied[1] = poly1.getCoefC() * poly2.getCoefB();
    thirdCoefMultiplied[2] = poly1.getCoefC() * poly2.getCoefC();

    finalPoly[0] = firstCoefMultiplied[0]; //the coefficient of each matching degree of X is added
    finalPoly[1] = firstCoefMultiplied[1] + secondCoefMultiplied[0];
    finalPoly[2] = firstCoefMultiplied[2] + secondCoefMultiplied[1] + thirdCoefMultiplied[0];
    finalPoly[3] = secondCoefMultiplied[2] + thirdCoefMultiplied[1];
    finalPoly[4] = thirdCoefMultiplied[2];

    //Both polynomials are printed out
    cout << "polynomial 1 is " << poly1.getCoefA() << "X^2 + " << poly1.getCoefB() << "X + " << poly1.getCoefC() << "\n\n";
    cout << "polynomial 2 is " << poly2.getCoefA() << "X^2 + " << poly2.getCoefB() << "X + " << poly2.getCoefC() << "\n\n";

    //the multiplied polynomials are printed out, any coefficients of 0 are skipped, any negatives
    //are converted to positive and a - sign is put in front
    cout << "The polynomials multiplied = ";

    if(finalPoly[0] != 0)
    {
        cout << finalPoly[0] << "X^4 ";
    }
    if(finalPoly[1] != 0)
    {
        if(finalPoly[1] > 0)
        {
            cout << "+ ";
        }
        else
        {
            finalPoly[1] = finalPoly[1] * -1;
            cout << "- ";
        }
        cout << finalPoly[1] << "X^3 ";
    }
    if(finalPoly[2] != 0)
    {
        if(finalPoly[2] > 0)
        {
            cout << "+ ";
        }
        else
        {
            finalPoly[2] = finalPoly[2] * -1;
            cout << "- ";
        }
        cout << finalPoly[2] << "X^2 ";
    }
    if(finalPoly[3] != 0)
    {
        if(finalPoly[3] > 0)
        {
            cout << "+ ";
        }
        else
        {
            finalPoly[3] = finalPoly[3] * -1;
            cout << "- ";
        }
        cout << finalPoly[3] << "X ";
    }
    if(finalPoly[4] != 0)
    {
        if(finalPoly[4] > 0)
        {
            cout << "+ ";
        }
        else
        {
            finalPoly[4] = finalPoly[4] * -1;
            cout << "- ";
        }
        cout << finalPoly[4];
    }
    if(finalPoly[0] == 0 && finalPoly[1] == 0 && finalPoly[2] == 0 && finalPoly[3] == 0 && finalPoly[4] == 0)
    {
        cout <<"0";
    }
    cout << "\n\n";
}

void addPolys(Polynomial<int> poly1, Polynomial<int> poly2) //function to add polynomials
{
    int finalPoly[3]; //when two 2nd degree polynomials are added the solution will also have 3 coefficients

    finalPoly[0] = poly1.getCoefA() + poly2.getCoefA(); //the first coefficient of polynomial 1 is added to the first coefficient off polynomial 2
    finalPoly[1] = poly1.getCoefB() + poly2.getCoefB(); //the second coefficient of polynomial 1 is added to the second coefficient off polynomial 2
    finalPoly[2] = poly1.getCoefC() + poly2.getCoefC(); //the third coefficient of polynomial 1 is added to the third coefficient off polynomial 2

    //both polynomials are printed out fully
    cout << "polynomial 1 is " << poly1.getCoefA() << "X^2 + " << poly1.getCoefB() << "X + " << poly1.getCoefC() << "\n\n";
    cout << "polynomial 2 is " << poly2.getCoefA() << "X^2 + " << poly2.getCoefB() << "X + " << poly2.getCoefC() << "\n\n";

    cout << "The polynomials added = "; //the solution polynomial is printed, and coefficient of 0 is skipped
    if(finalPoly[0] != 0)
    {
        cout << finalPoly[0] << "X^2 + ";
    }
    if(finalPoly[1] != 0)
    {
        cout << finalPoly[1] << "X + ";
    }
    if(finalPoly[2] != 0)
    {
        cout << finalPoly[2];
    }
    if(finalPoly[0] == 0 && finalPoly[1] == 0 && finalPoly[2] == 0)
    {
        cout <<"0";
    }
    cout << "\n\n";
}

void fillCoefArray(int coefArray[]) //function to ask user to enter each coefficient
{

    cout << "\nenter the 3 coefficients for your polynomial:\n"; //3 coefficients are input, all can be input on one line separated by a space
    cin >> coefArray[0];
    while(!cin) //each input is validated as an integer, any non-integer input will produce an error message
    {
        cout << "That is not a valid input, please enter an integer\n";
        cin.clear();
        cin.ignore();
        cin >> coefArray[0];
    }

    cin >> coefArray[1];
    while(!cin)
    {
        cout << "That is not a valid input, please enter an integer\n";
        cin.clear();
        cin.ignore();
        cin >> coefArray[1];
    }

    cin >> coefArray[2];
    while(!cin)
    {
        cout << "That is not a valid input, please enter an integer\n";
        cin.clear();
        cin.ignore();
        cin >> coefArray[2];
    }

    cout << "\n";
}
#endif // TEMPLATE_CLASS_H_INCLUDED
