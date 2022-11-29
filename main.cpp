#include <iostream>
#include "fractions.h"

using namespace fractions;

int main ()
{
  setlocale (LC_ALL,"Russian");
  
  Fraction A = Fraction(-1,1,3);
  
  Fraction B = Fraction(1,3);
  
  A.print ();
  std::cout << "Десятичное представление: " <<A.decimal_view () << std::endl;
  
  B.print ();
  std::cout << "Десятичное представление: " <<B.decimal_view () << std::endl;
  
  B++;
  B.print ();
  std::cout << "Десятичное представление: " <<B.decimal_view () << std::endl;
  
  Fraction C = A/B;
  C.print ();
  std::cout << "Десятичное представление: " <<C.decimal_view () << std::endl;
  
  std::cout << (A>B) << std::endl;
  
  return 0;
}

