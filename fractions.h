#pragma once

#include <iostream>

namespace fractions
{
  class Fraction;
  unsigned int NOD (unsigned int a, unsigned int b);
  unsigned int NOC (unsigned int a, unsigned int b);
  Fraction operator+ (Fraction left, Fraction right);
  Fraction operator- (const Fraction& left, const Fraction& right);
  Fraction operator* (Fraction left, Fraction right);
  Fraction operator/ (const Fraction& left, const Fraction& right);
  bool operator== (Fraction left, Fraction right);
  bool operator!= (const Fraction& left, const Fraction& right);
  bool operator> (Fraction left, Fraction right);
  bool operator< (Fraction left, Fraction right);
  bool operator>= (const Fraction& left, const Fraction& right);
  bool operator<= (const Fraction& left, const Fraction& right);
  
  class Fraction
  {
    bool negative;
    unsigned int integer;
    unsigned int numerator;
    unsigned int denominator;
    void set_negative (const bool &negative);
    void set_integer (const unsigned int &integer);
    void set_numerator (const unsigned int &numerator);
    void set_denominator (const unsigned int &denominator);
  public:
    //Constractors
    Fraction();
    Fraction (const int &integer);
    Fraction (const int &numerator, const unsigned int &denominator);
    Fraction (const int &integer, const unsigned int &numerator, const unsigned int &denominator);
    Fraction (const Fraction& other);
    //Get
    bool get_negative () const;
    unsigned int get_integer () const;
    unsigned int get_numerator () const;
    unsigned int get_denominator () const;
    //Operators
    Fraction& operator= (const Fraction& other);
    Fraction operator- () const;
    Fraction& operator++();
    Fraction operator++(int);
    Fraction& operator--();
    Fraction operator--(int);
    Fraction& operator+=(const Fraction& other);
    Fraction& operator-=(const Fraction& other);
    Fraction& operator*=(const Fraction& other);
    Fraction& operator/=(const Fraction& other);
    //Methods
    void print ();
    Fraction& to_simple();
    Fraction& to_compound();
    Fraction inverted() const;
    Fraction& shrink ();
    double decimal_view();
  };
}