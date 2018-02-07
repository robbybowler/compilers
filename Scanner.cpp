

#include "Scanner.h"
#include <cstdlib>
#include <iostream>
#include "StateMachine.h"


ScannerClass::ScannerClass(std::string filename){
  mFin.open(filename);
  if(!mFin){
    exit(1);
  }
}



TokenClass ScannerClass::GetNextToken(){
  StateMachineClass stateMachine;
  TokenType t;
  std::string lexeme;
  MachineState UpdatedState = START_STATE;
  do{
    char c = mFin.get();
    lexeme += c;
    UpdatedState = stateMachine.UpdateState(c,t);
    if (UpdatedState == START_STATE){
      lexeme = "";
    }
  }while(UpdatedState != CANTMOVE_STATE);
  mFin.unget();
  lexeme.pop_back();
  TokenClass tc(t,lexeme);
  tc.CheckReserved();
  return tc;

}
