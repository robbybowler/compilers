#include "Symbol.h"
#include <cstdlib>
#include <iostream>


int main(){
  SymbolTableClass s;

  s.AddEntry("hello");

  s.SetValue("hello", 10);
  std::cout.flush();

  std::cout << s.GetValue("hello") << " working";
  return 0;
}
