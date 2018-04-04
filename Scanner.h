#pragma once
// #include <String>
#include "Token.h"
#include <fstream>
#include <string>

class ScannerClass{
public:
  ScannerClass(std::string filename);
  TokenClass GetNextToken();
  int GetLineNumber();


private:
  std::ifstream mFin;
  int mLineNumber;
};
