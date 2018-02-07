#pragma once
// #include <String>
#include "Token.h"
#include <fstream>
#include <string>




class ScannerClass{
public:
  ScannerClass(std::string filename);
  TokenClass GetNextToken();


private:
  std::ifstream mFin;

};
