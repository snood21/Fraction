#include "fractions.h"

namespace fractions
{
  //Set
  void Fraction::set_negative (const bool &negative)
  {
    this->negative = negative;
  }
  
  void Fraction::set_integer (const unsigned int &integer)
  {
    this->integer = integer;
  }
  
  void Fraction::set_numerator (const unsigned int &numerator)
  {
    this->numerator = numerator;
  }

  void Fraction::set_denominator (const unsigned int &denominator)
  {
    if (denominator == 0) this->denominator = 1;
    else this->denominator = denominator;
  }

  Fraction::Fraction()
  {
    set_negative (false);
    set_integer (0);
    set_numerator (0);
    set_denominator (1);
  }
  
  Fraction::Fraction (const int &integer)
  {
    if (integer<0)
      {
        set_negative (true);
        set_integer (-integer);
      }
    else
      {
        set_negative (false);
        set_integer (integer);
      }
    set_numerator (0);
    set_denominator (0);
  }
  
  Fraction::Fraction (const int &numerator, const unsigned int &denominator)
  {
    set_integer (0);
    if (numerator<0)
      {
        set_negative (true);
        set_numerator (-numerator);
      }
    else
      {
        set_negative (false);
        set_numerator (numerator);
      }
    set_denominator (denominator);
  }

  Fraction::Fraction (const int &integer, const unsigned int &numerator, const unsigned int &denominator)
  {
    if (integer<0)
      {
        set_negative (true);
        set_integer (-integer);
      }
    else
      {
        set_negative (false);
        set_integer (integer);
      }
    set_numerator (numerator);
    set_denominator (denominator);
  }

  Fraction::Fraction (const Fraction& other)
  {
    set_negative (other.negative);
    set_integer (other.integer);
    set_numerator (other.numerator);
    set_denominator (other.denominator);
  }
  //Get
  bool Fraction::get_negative () const
  {
    return negative;
  }
  
  unsigned int Fraction::get_integer() const
  {
    return integer;
  }
  
  unsigned int Fraction::get_numerator () const
  {
    return numerator;
  }

  unsigned int Fraction::get_denominator () const
  {
    return denominator;
  }
  //Operators
  Fraction& Fraction::operator= (const Fraction& other)
  {
    set_negative (other.negative);
    set_integer (other.integer);
    set_numerator (other.numerator);
    set_denominator (other.denominator);
    return *this;
  }

  Fraction Fraction::operator- () const
  {
    Fraction opposite = *this;
    opposite.set_negative (!opposite.negative);
    return opposite;
  }
  
  Fraction& Fraction::operator++()
  {
    int new_integer = get_negative ()?-1:1 * (int) integer+1;
    if (new_integer<0)
      {
        set_negative (true);
        set_integer (-new_integer);
      }
    else
      {
        set_negative (false);
        set_integer (new_integer);
      }
    return *this;
  }
  
  Fraction Fraction::operator++(int)
  {
    Fraction old = *this;
    int new_integer = get_negative ()?-1:1 * (int) integer+1;
    if (new_integer<0)
      {
        set_negative (true);
        set_integer (-new_integer);
      }
    else
      {
        set_negative (false);
        set_integer (new_integer);
      }
    return old;
  }
  
  Fraction& Fraction::operator--()
  {
    int new_integer = get_negative ()?-1:1 * (int) integer-1;
    if (new_integer<0)
      {
        set_negative (true);
        set_integer (-new_integer);
      }
    else
      {
        set_negative (false);
        set_integer (new_integer);
      }
    return *this;
  }
  
  Fraction Fraction::operator--(int)
  {
    Fraction old = *this;
    int new_integer = get_negative ()?-1:1 * (int) integer-1;
    if (new_integer<0)
      {
        set_negative (true);
        set_integer (-new_integer);
      }
    else
      {
        set_negative (false);
        set_integer (new_integer);
      }
    return old;
  }
  
  Fraction& Fraction::operator+=(const Fraction& other)
  {
    return *this = *this + other;
  }
  
  Fraction& Fraction::operator-=(const Fraction& other)
  {
    return *this = *this - other;
  }
  
  Fraction& Fraction::operator*=(const Fraction& other)
  {
    return *this = *this * other;
  }
  
  Fraction& Fraction::operator/=(const Fraction& other)
  {
    return *this = *this / other;
  }
  
  //Methods
  void Fraction::print ()
  {
    if (negative) std::cout << "-";
    if (integer) std::cout << integer;
    if (numerator)
      {
        if (integer) std::cout << "(";
        std::cout << numerator << "/" << denominator;
        if (integer) std::cout << ")";
      }
    std::cout << std::endl;
  }
  
  Fraction& Fraction::to_simple()
  {
    numerator += integer*denominator;
    integer = 0;
    return *this;
  }
  
  Fraction& Fraction::to_compound()
  {
    integer += numerator/denominator;
    numerator %= denominator;
    return *this;
  }
  
  Fraction Fraction::inverted() const
  {
    Fraction inverted = *this;
    inverted.to_simple ();
    std::swap(inverted.numerator, inverted.denominator);
    return inverted;
  }

  Fraction& Fraction::shrink ()
  {
    to_simple ();
    unsigned int nod = NOD (numerator, denominator);
    set_numerator (numerator / nod);
    set_denominator (denominator / nod);
    return *this;
  }
  
  double Fraction::decimal_view()
  {
    return (negative?-1:1) * ((double) numerator / denominator + integer);
  }

  unsigned int NOD (unsigned int a, unsigned int b)
  {
    while (a && b)
      if (a > b) a %= b;
      else b %= a;
    return a + b;
  }

  unsigned int NOC (unsigned int a, unsigned int b)
  {
    return a * b / NOD (a, b);
  }

  Fraction operator+ (Fraction left, Fraction right)
  {
    left.to_simple ();
    right.to_simple ();
    int denominator = NOC (left.get_denominator (), right.get_denominator ());
    
    return Fraction(
            (left.get_negative ()?-1:1) * (int) left.get_numerator () * denominator / (int) left.get_denominator ()
            + (right.get_negative ()?-1:1) * (int) right.get_numerator () * denominator / (int) right.get_denominator (),
            denominator
            ).shrink ().to_compound ();
  }

  Fraction operator- (const Fraction& left, const Fraction& right)
  {
    return left+(-right);
  }

  Fraction operator* (Fraction left, Fraction right)
  {
    left.to_simple ();
    right.to_simple ();
    return Fraction(
            (left.get_negative () == right.get_negative ()?1:-1) * left.get_numerator () * right.get_numerator (),
            left.get_denominator () * right.get_denominator ()
            ).shrink ().to_compound ();
  }
  Fraction operator/ (const Fraction& left, const Fraction& right)
  {
    return left * right.inverted ();
  }

  bool operator== (Fraction left, Fraction right)
  {
    left.to_simple ();
    right.to_simple ();
    return (left.get_negative ()?-1:1) * (int) left.get_numerator () * (int) right.get_denominator () == (right.get_negative ()?-1:1) * (int) left.get_denominator () * (int) right.get_numerator ();
  }

  bool operator!= (const Fraction& left, const Fraction& right)
  {
    return !(left == right);
  }
  
  bool operator> (Fraction left, Fraction right)
  {
    left.to_simple ();
    right.to_simple ();
    return (left.get_negative ()?-1:1) * (int) left.get_numerator () * (int) right.get_denominator () > (right.get_negative ()?-1:1) * (int) left.get_denominator () * (int) right.get_numerator ();
  }
  
  bool operator< (Fraction left, Fraction right)
  {
    left.to_simple ();
    right.to_simple ();
    return (left.get_negative ()?-1:1) * (int) left.get_numerator () * (int) right.get_denominator () < (right.get_negative ()?-1:1) * (int) left.get_denominator () * (int) right.get_numerator ();
  }
  
  bool operator>= (const Fraction& left, const Fraction& right)
  {
    return !(left < right);
  }
  
  bool operator<= (const Fraction& left, const Fraction& right)
  {
    return !(left > right);
  }
}