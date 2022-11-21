#pragma once

#include <iostream>

namespace simple_fraction
{

  class Fraction
  {
    long long numerator;
    unsigned int denominator;
    //Set
    /*set_denominator сделан для проверки корректности данных, set_numerator для единообразия кода.
    По логике возможности произвольным образом менять значения отдельных переменных быть не должно, поэтому функция не в public-секции*/
    void set_numerator (const long long &numerator);
    void set_denominator (const unsigned int &denominator);
    unsigned int NOD (long long a, unsigned int b);
  public:
    //Constractors
    Fraction (const long long &numerator = 0, const unsigned int &denominator = 1);
    Fraction (const Fraction& other);
    //Get
    long long get_numerator () const;
    unsigned int get_denominator () const;
    //Operators
    Fraction& operator= (const Fraction& other);
    void operator- ();
    //Other functions
    void print ();
    void shrink ();
    double to_decimal();
  };

  unsigned int NOD (unsigned int a, unsigned int b);
  unsigned int NOC (unsigned int a, unsigned int b);
  Fraction operator+ (const Fraction& A, const Fraction& B);
  Fraction operator- (const Fraction& A, const Fraction& B);
  Fraction operator* (const Fraction& A, const Fraction& B);
  Fraction operator/ (const Fraction& A, const Fraction& B);
}