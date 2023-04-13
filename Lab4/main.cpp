#include "ctable.h"
#include "cmysmartpointer.h"
#include <cstdio>
#include <iostream>

int main (int argc, char *argv[])
{
  std::cout << "MOVE" << std::endl;

  CTable c1("1",5); 
  CTable c2("2",5); 
  CTable c3("3",5); 
  CTable c4("4",5); 

  c1 = std::move(std::move(c2) = std::move(std::move(c3) = std::move(c4)));

  std::cout << "COPY" << std::endl;

  CTable c11("1", 5);
  CTable c12("2", 5);
  CTable c13("3", 5);
  CTable c14("4", 5);

  c13 = c14;
  c12 = c13;
  c11 = c12;

  std::cout << "\n";

  int* pInt = new int (12);

  CMySmartPointer<int> pSmartInt(pInt);

  CMySmartPointer<int> dup_pSmartInt(pSmartInt);

  *dup_pSmartInt = 13;

  std::cout << *pInt << std::endl;

  return 0;
}
