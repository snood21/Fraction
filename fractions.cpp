#include "fractions.h"

namespace simple_fraction
{
  //Set
  /*set_denominator сделан для проверки корректности данных, set_numerator для единообразия кода.
  По логике возможности произвольным образом менять значения отдельных переменных быть не должно, поэтому функция не в public-секции*/
  void Fraction::set_numerator (const long long &numerator)
  {
    this->numerator = numerator;
  }

  void Fraction::set_denominator (const unsigned int &denominator)
  {
    if (denominator == 0) this->denominator = 1; //по идее, должно вызываться какое-то исключение и объект создаваться не должен, но пока не знаю, как реализовать
    else this->denominator = denominator;
  }

  unsigned int Fraction::NOD (long long a, unsigned int b)
  {
    a = (a < 0) ? -a : a;
    while (a && b)
      if (a > b) a %= b;
      else b %= a;
    return a + b;
  }

  Fraction::Fraction (const long long &numerator, const unsigned int &denominator)
  {
    set_numerator (numerator);
    set_denominator (denominator);
  }

  Fraction::Fraction (const Fraction& other)
  {
    set_numerator (other.numerator);
    set_denominator (other.denominator);
  }
  //Get
  long long Fraction::get_numerator () const
  {
    return this->numerator;
  }

  unsigned int Fraction::get_denominator () const
  {
    return this->denominator;
  }
  //Operators
  Fraction& Fraction::operator= (const Fraction& other)
  {
    set_numerator (other.numerator);
    set_denominator (other.denominator);
    return *this;
  }

  void Fraction::operator- ()
  {
    set_numerator (-this->numerator);
  }
  //Other functions
  void Fraction::print ()
  {
    std::cout << this->numerator << "/" << this->denominator << std::endl;
  }

  void Fraction::shrink ()
  {
    unsigned int nod = NOD (this->numerator, this->denominator);
    set_numerator (this->numerator / nod);
    set_denominator (this->denominator / nod);
  }
  
  double Fraction::to_decimal()
  {
    return (double) this->numerator/this->denominator;
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

  Fraction operator+ (const Fraction& A, const Fraction& B)
  {
    unsigned int denominator = NOC (A.get_denominator (), B.get_denominator ());
    long long numerator = (A.get_numerator ()*(denominator / A.get_denominator ()) + B.get_numerator ()*(denominator / B.get_denominator ()));
    Fraction C = Fraction (numerator, denominator);
    C.shrink ();
    return C;
  }

  Fraction operator- (const Fraction& A, const Fraction& B)
  {
    unsigned int denominator = NOC (A.get_denominator (), B.get_denominator ());
    long long numerator = (A.get_numerator ()*(denominator / A.get_denominator ()) - B.get_numerator ()*(denominator / B.get_denominator ()));
    Fraction C = Fraction (numerator, denominator);
    C.shrink ();
    return C;
  }

  Fraction operator* (const Fraction& A, const Fraction& B)
  {
    Fraction C = Fraction (A.get_numerator () * B.get_numerator (), A.get_denominator () * B.get_denominator ());
    C.shrink ();
    return C;
  }

  Fraction operator/ (const Fraction& A, const Fraction& B)
  {
    Fraction C = Fraction (A.get_numerator () * B.get_denominator (), A.get_denominator () * B.get_numerator ());
    C.shrink ();
    return C;
  }
}