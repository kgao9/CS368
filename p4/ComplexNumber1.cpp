///////////////////////////////////////////////////////////////////////////////
////                   ALL STUDENTS COMPLETE THESE SECTIONS
//// Main Class File:  main.cpp
//// File:             ComplexNumber.cpp
//// Semester:         CS368 Fall 2015
////
//// Author:           Kevin Gao
//// CS Login:         kgao
//// Lecturer's Name:  Okan
////
////////////////////// PAIR PROGRAMMERS COMPLETE THIS SECTION ////////////////////
////
//// Pair Partner:     Kenny Gao
//// Email:            kgao9@wisc.edu
//// CS Login:         kenny
//// Lecturer's Name:  look above, same one (Okan)
////
////////////////////// STUDENTS WHO GET HELP FROM OTHER THAN THEIR PARTNER //////
////                   fully acknowledge and credit all sources of help,
////                   other than Instructors and TAs.
////
//// Persons:          Identify persons by name, relationship to you, and email.
////                   Describe in detail the the ideas and help they provided.
////
//// Online sources:   avoid web searches to solve your problems, but if you do
////                   search, be sure to include Web URLs and description of 
////                   of any information you find.
////////////////////////////// 80 columns wide //////////////////////////////////

 /*
 * The purpose of this class is to implement ComplexNumber.h
 *
 *  @version Nov 24, 2015
 *  @author: Kevin Gao
 */

#include "ComplexNumber.h"
#include <iostream>
#include <cstdlib>

/**
* The purpose of this constructor is to create a complex number
* at the origin with real = 0 and imag = 0
*
* no parameters or returns
*/

ComplexNumber::ComplexNumber() 
{
    this->real = 0;
    this->imag = 0;
}

/**
* The purpose of this constructor is to create a complex number with
* a given real and imag components
*
* @param real component and imag component
* no return
*/

ComplexNumber::ComplexNumber(double real_part, double imaginary_part) 
{
    this->real = real_part;
    this->imag = imaginary_part;
}

/**
* The purpose of this constructor is to create a copy of a given complex number
*
* @param given copy
* no return
*/

ComplexNumber::ComplexNumber(const ComplexNumber& rhs) 
{
    this->real = rhs.real;
    this->imag = rhs.imag;
}

/**
* The purpose of this method is to print out the complex number in the following
* format: 'real' +/- 'imag'i
*
* @param the stream this method will use
* no return
*/  

void ComplexNumber::print(ostream& out) const 
{
    cout << this->real;
   
    //if negative, we need the -
    if(imag < 0)
    {
        cout << " - ";
        cout << this -> imag * -1;
        cout << "i";
    }

    //if positive, we need +
    else
    {
        cout << " + ";
        cout << this->imag;
        cout << "i";
    }
}

/**
* The purpose of this method is to compare two complex numbers
* returns true if the two numbers are equal; false otherwise
*
* @param complex number to compare with
* @return true if two numbers are equal; false otherwise
*/ 

bool ComplexNumber::equals(const ComplexNumber& rhs) const 
{
    return rhs.imag == this->imag && rhs.real == this->real;
}

/**
* The purpose of this copy operator is to set this complex number's
* values as the same as the given complex number's values
*
* @param the given complex number
* @return a complex number with the same values as the complex number given
*/  
const ComplexNumber& ComplexNumber::operator =(const ComplexNumber& rhs) 
{
    this->imag = rhs.imag;
    this->real = rhs.real;
    return *this;
}

/**
* The purpose of this method is to add a given complex number with the values
* this complex number has stored
*
* @param given complex number
* @return this complex number with the complex number's values added to its own
*/
 
const ComplexNumber& ComplexNumber::operator +=(const ComplexNumber& rhs) 
{
    this->imag += rhs.imag;
    this->real += rhs.real;
    return *this;
}

/**
* The purpose of this method is to subtract a given complex number with the values
* this complex number has stored
* 
* @param given complex number
* @return this complex number with this complex number's value minus the given complex
* number's values
*/

const ComplexNumber& ComplexNumber::operator -=(const ComplexNumber& rhs) 
{
    this->imag -= rhs.imag;
    this->real -= rhs.real;
    return *this;
}

/**
* The purpose of this method is to multiply a given complex number with itself
* 
* @param given complex number
* @return this complex number with new private parts
*/

const ComplexNumber& ComplexNumber::operator *=(const ComplexNumber& rhs) 
{
    double tempImag = this->imag;

    this->imag = this->imag * rhs.real + this->real * rhs.imag;
    this->real = this->real * rhs.real - tempImag * rhs.imag;
    return *this;
}

/**
* The purpose of this method is to add two complex numbers
* 
* @param 2 complex numbers
* @return their sum
*/

ComplexNumber operator +(const ComplexNumber& lhs, const ComplexNumber& rhs) 
{
    ComplexNumber result = ComplexNumber();
    result += lhs;
    result += rhs;

    return result;

}

/**
* The purpose of this method is to subtract two complex numbers
* 
* @param 2 complex numbers
* @return left number minus right number
*/

ComplexNumber operator -(const ComplexNumber& lhs, const ComplexNumber& rhs) 
{
    ComplexNumber result = ComplexNumber();
    result += lhs;
    result -= rhs;

    return result;
}

/**
* The purpose of this method is to multiply two complex numbers
* 
* @param two complex numbers
* @return their product
*/

ComplexNumber operator *(const ComplexNumber& lhs, const ComplexNumber& rhs) 
{
    ComplexNumber result = ComplexNumber();
    result += lhs;
    result *= rhs;
    return result;

}

/**
* THe purpose of this method is to see if two compelx numbers are equal
* 
* @param two complex numbers
* @return true if they are equal; false otherwise
*/

bool operator ==(const ComplexNumber& lhs, const ComplexNumber& rhs) 
{
    return lhs.equals(rhs);
}

/**
* The purpose of this method is to see if two complex numbers are not equal
*
* @param two complex numbers
* @return true if they are not equal; false otherwise
*/

bool operator !=(const ComplexNumber& lhs, const ComplexNumber& rhs) 
{
    return !lhs.equals(rhs);
}

/**
* The purpose of this method is to print out a complex number
* 
* @param stream used to print number out and complex number
* @return stream being used with number inside it
*/

ostream& operator <<(ostream& out, const ComplexNumber& n) 
{
    n.print(out);
    return out;
}

/**
* The purpose of this method is to scan in a complex number
* 
* @param stream being used and new complex number
* return stream with new complex number in it
*/

istream& operator >>(istream& in, ComplexNumber& n) 
{
    double real;
    double imag;
    char garbage;

    in >> real >> garbage >> imag;

    //flush stream
    std::cin.clear();
    std::cin.ignore();

    //if neg, store neg value
    if(garbage == '-')
    {
        imag *= -1;
    }

    ComplexNumber *newNumber = new ComplexNumber(real, imag);

    //create complement and a neg 1 vector
    ComplexNumber comp;
    ComplexNumber *opp = new ComplexNumber(-1,0);

    //get the complement of n
    comp = n * *opp;

    //now set n to 0 and add new number
    n += comp;
    n += *newNumber;

    //free vars
    delete opp;
    delete newNumber;

    //return stream
    return in;
}

