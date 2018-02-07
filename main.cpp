

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
  tc = scanner.GetNextToken();

  // do{
  std::cout << tc << std::endl;
  // }while();
  // while(true){
  //
  //   if (tc == ENDFILE_TOKEN){
  //     break;
  //   }
  // }

}
