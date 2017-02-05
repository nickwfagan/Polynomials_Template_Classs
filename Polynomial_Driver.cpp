#include <iostream>
#include <cstdlib>

#include "Template_Class.h"

using namespace std;

void fillCoefArray(int coefArray[])
{
    for(int i = 0; i < 3; i++)
    {
        cout << "\nenter the next coefficient for your polynomial:\n";
        cin >> coefArray[i];
    }

    cout << "\n";
}
void multiplyPolys(Polynomial<int> poly1, Polynomial<int> poly2)
{
    int firstCoefMultiplied[3];
    int secondCoefMultiplied[3];
    int thirdCoefMultiplied[3];
    int finalPoly[5];

    firstCoefMultiplied[0] = poly1.getCoefA() * poly2.getCoefA();
    firstCoefMultiplied[1] = poly1.getCoefA() * poly2.getCoefB();
    firstCoefMultiplied[2] = poly1.getCoefA() * poly2.getCoefC();

    secondCoefMultiplied[0] = poly1.getCoefB() * poly2.getCoefA();
    secondCoefMultiplied[1] = poly1.getCoefB() * poly2.getCoefB();
    secondCoefMultiplied[2] = poly1.getCoefB() * poly2.getCoefC();

    thirdCoefMultiplied[0] = poly1.getCoefC() * poly2.getCoefA();
    thirdCoefMultiplied[1] = poly1.getCoefC() * poly2.getCoefB();
    thirdCoefMultiplied[2] = poly1.getCoefC() * poly2.getCoefC();

    finalPoly[0] = firstCoefMultiplied[0];
    finalPoly[1] = firstCoefMultiplied[1] + secondCoefMultiplied[0];
    finalPoly[2] = firstCoefMultiplied[2] + secondCoefMultiplied[1] + thirdCoefMultiplied[0];
    finalPoly[3] = secondCoefMultiplied[2] + thirdCoefMultiplied[1];
    finalPoly[4] = thirdCoefMultiplied[2];

    cout << "\n";
    cout << "polynomial 1 is " << poly1.getCoefA() << "X^2 + " << poly1.getCoefB() << "X + " << poly1.getCoefC() << "\n\n";
    cout << "polynomial 2 is " << poly2.getCoefA() << "X^2 + " << poly2.getCoefB() << "X + " << poly2.getCoefC() << "\n\n";

    cout << "The polynomials multiplied = " << finalPoly[0] << "X^4 + " << finalPoly[1] << "X^3 + " << finalPoly[2] << "X^2 + " << finalPoly[3] << "X + " << finalPoly[4] <<  "\n";
}
void addPolys(Polynomial<int> poly1, Polynomial<int> poly2)
{
    int finalPoly[3];

    finalPoly[0] = poly1.getCoefA() + poly2.getCoefA();
    finalPoly[1] = poly1.getCoefB() + poly2.getCoefB();
    finalPoly[2] = poly1.getCoefC() + poly2.getCoefC();

    cout << "\n";
    cout << "polynomial 1 is " << poly1.getCoefA() << "X^2 + " << poly1.getCoefB() << "X + " << poly1.getCoefC() << "\n\n";
    cout << "polynomial 2 is " << poly2.getCoefA() << "X^2 + " << poly2.getCoefB() << "X + " << poly2.getCoefC() << "\n\n";

    cout << "The polynomials added = " << finalPoly[0] << "X^2 + " << finalPoly[1] << "X + " << finalPoly[2] <<"\n\n";
}
int main()
{
    int input;
    int coefArray1[3];
    int coefArray2[3];

    fillCoefArray(coefArray1);
    fillCoefArray(coefArray2);

    Polynomial<int> poly1(coefArray1[0], coefArray1[1], coefArray1[2]);
    Polynomial<int> poly2(coefArray2[0], coefArray2[1], coefArray2[2]);

    cout << "Enter 1 to multiply the polynomials, enter 2 to add the polynomials, 0 to exit\n";
    cin >> input;
    cout << "\n\n";

    while(input != 0 && input != 1 && input != 2)
    {
        cout << "That is not a valid input, enter 1 to multiply, 2 to add, or 0 to exit\n";
        cin >> input;
    }
    if(input == 1)
    {
        multiplyPolys(poly1, poly2);
    }
    else if(input == 2)
    {
        addPolys(poly1, poly2);
    }
    else if(input == 0)
    {
        exit(0);
    }
    return 0;
}
