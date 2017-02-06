/**************************************************************
* programmer: Nicholas Fagan
* date: 2/5/2017
* assignment: HW 2 Polynomial template
* file: this is the driver for the polynomial template. two integer polynomials are created and filled with the coefficient arrays based on user input.
        the user then chooses to either multiply or add the polynomials. an option to exit the program is also given.
***************************************************************/

#include <iostream>
#include <cstdlib>

#include "Template_Class.h"

using namespace std;

int main()
{
    int input;
    int coefArray1[3]; //array to hold coefficients for the first polynomial
    int coefArray2[3]; //array to hold coefficients for the second polynomial

    cout << "Polynomial 1:\n"; //text to indicate which polynomial is being filled and initialization of functions to fill the arrays
    fillCoefArray(coefArray1);
    cout << "polynomial 2:\n";
    fillCoefArray(coefArray2);

    Polynomial<int> poly1(coefArray1[0], coefArray1[1], coefArray1[2]); //calls the class to create 2 polynomial objects
    Polynomial<int> poly2(coefArray2[0], coefArray2[1], coefArray2[2]); //constructor fills both polynomials with the coefficient arrays

    cout << "Enter 1 to multiply the polynomials, enter 2 to add the polynomials, 0 to exit\n"; //ask for a receive input for which task to perform
    cin >> input;
    cout << "\n\n";

    while(input != 0 && input != 1 && input != 2) //validation for task input
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
