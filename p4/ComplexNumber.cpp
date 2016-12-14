#include <iostream>
#include "ComplexNumber.h"

using namespace std;

/**
* The purpose of this default constructor is to create
* a complex number at the origin
*
* no parameters or returns
*/

ComplexNumber::ComplexNumber()
{
    real = 0;
    imag = 0;
}

/**
* The purpose of this method is to create a complex number when given
* a real part and an imaginary part
*
* @param two doubles, one for the real comp and one for the imaginary comp
* no returns
*/

ComplexNumber::ComplexNumber(double real_part, double imaginary_part)
{
    real = real_part;
    imag = imaginary_part;
}

void ComplexNumber::print(ostream& out) const 
{
	cout << this->real;
	cout << " + ";
	cout << this->imag;
	cout << "i";
}

ostream& operator <<(ostream& out, const ComplexNumber& n) 
{
	n.print(out);
	return out;
}


