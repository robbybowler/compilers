

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include "Token.h"
#include "Scanner.h"
#include "StateMachine.h"

using namespace std;

int main(){

  TokenClass tc;
  ScannerClass scanner("test.txt");

  while(true){

   tc = scanner.GetNextToken();
   std::cout << tc << " " << scanner.GetLineNumber() << std::endl;
    if (tc.GetTokenType() == ENDFILE_TOKEN){
      break;
    }
  }
}
