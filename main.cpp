#include "fractions.h"

using namespace fractions;

int main ()
{
  setlocale (LC_ALL,"Russian");
  
  Fraction A;
  
  std::cout << "Введите простую дробь: ";
  std::cin >> A;
  std::cout << A << std::endl << std::endl;
    
  Fraction B = 2.75;
  std::cout << B << std::endl;
  B.shrink().to_compound();
  std::cout << B << std::endl;
    
  return 0;
}

