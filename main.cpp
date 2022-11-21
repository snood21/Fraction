#include <iostream>
#include "fractions.h"

using namespace simple_fraction;

int main ()
{
  setlocale (LC_ALL,"Russian");
  
  Fraction A = Fraction(1,4);
  
  Fraction B = Fraction(1,2);
  
  A.print ();
  std::cout << "Десятичное представление: " <<A.to_decimal () << std::endl;
  
  B.print ();
  std::cout << "Десятичное представление: " <<B.to_decimal () << std::endl;
  
  Fraction C = A+B;
  C.print ();
  std::cout << "Десятичное представление: " <<C.to_decimal () << std::endl;
    
  C = A-B;
  C.print ();
  std::cout << "Десятичное представление: " <<C.to_decimal () << std::endl;
  
  C = A*B;
  C.print ();
  std::cout << "Десятичное представление: " <<C.to_decimal () << std::endl;
  
  C = A/B;
  C.print ();
  std::cout << "Десятичное представление: " <<C.to_decimal () << std::endl;
  
  return 0;
}

