#pragma once


#include "Token.h"

enum MachineState {
	START_STATE, IDENTIFIER_STATE, INTEGER_STATE, CANTMOVE_STATE,
  LCURLY_STATE,RCURLY_STATE,RPARAN_STATE, LPARAN_STATE, ASSIGNMENT_STATE, PLUS_STATE,
  SEMICOLON_STATE,ENDFILE_STATE, LESS_STATE,INSERTION_STATE,
	LAST_STATE
	};

enum CharacterType {
	LETTER_CHAR, DIGIT_CHAR, WHITESPACE_CHAR, PLUS_CHAR, BAD_CHAR,
	RCURLY_CHAR,LCURLY_CHAR,RPARAN_CHAR, LPARAN_CHAR, ASSIGNMENT_CHAR,UNDERSCORE_CHAR,
  SEMICOLON_CHAR, ENDFILE_CHAR, LESS_CHAR, INSERTION_CHAR,
  LAST_CHAR
	};

  class StateMachineClass
  {
  public:
  	StateMachineClass();
  	MachineState UpdateState(char currentCharacter, TokenType &
  correspondingTokenType);


  private:
  	MachineState mCurrentState;

  	// The matrix of legal moves:
  	MachineState mLegalMoves[LAST_STATE][LAST_CHAR];

  	// Which end-machine-states correspond to which token types.
  	// (non end states correspond to the BAD_TOKEN token type)
  	TokenType mCorrespondingTokenTypes[LAST_STATE];
  };
