#include "StateMachine.h"

StateMachineClass::StateMachineClass(){
  for(int i=0; i<LAST_STATE; i++)
  {
    for(int j=0; j<LAST_CHAR; j++)
    {
      mLegalMoves[i][j] = CANTMOVE_STATE;
    }
  }

  mLegalMoves[START_STATE][DIGIT_CHAR]= INTEGER_STATE;
	mLegalMoves[INTEGER_STATE][DIGIT_CHAR]= INTEGER_STATE;
  mLegalMoves[START_STATE][LCURLY_CHAR]= LCURLY_STATE;
  mLegalMoves[START_STATE][RCURLY_CHAR]= RCURLY_STATE;
  mLegalMoves[START_STATE][RPARAN_CHAR]= RPARAN_STATE;
  mLegalMoves[START_STATE][LPARAN_CHAR]= LPARAN_STATE;
  mLegalMoves[START_STATE][ASSIGNMENT_CHAR]= ASSIGNMENT_STATE;
  mLegalMoves[START_STATE][LETTER_CHAR]= IDENTIFIER_STATE;
  mLegalMoves[START_STATE][UNDERSCORE_CHAR]= IDENTIFIER_STATE;
  mLegalMoves[IDENTIFIER_STATE][LETTER_CHAR]= IDENTIFIER_STATE;
  mLegalMoves[IDENTIFIER_STATE][DIGIT_CHAR]= IDENTIFIER_STATE;
  mLegalMoves[IDENTIFIER_STATE][UNDERSCORE_CHAR]= IDENTIFIER_STATE;
  mLegalMoves[START_STATE][PLUS_CHAR]= PLUS_STATE;
  mLegalMoves[START_STATE][SEMICOLON_CHAR]= SEMICOLON_STATE;
  mLegalMoves[START_STATE][ENDFILE_CHAR]= ENDFILE_STATE;
  mLegalMoves[START_STATE][LESS_CHAR]= LESS_STATE;
  mLegalMoves[START_STATE][INSERTION_CHAR]= INSERTION_STATE;
  mLegalMoves[START_STATE][WHITESPACE_CHAR]= START_STATE;


  for(int i=0; i<LAST_STATE; i++)
	{
		mCorrespondingTokenTypes[i]=BAD_TOKEN;
	}
	mCorrespondingTokenTypes[IDENTIFIER_STATE] = IDENTIFIER_TOKEN;
	mCorrespondingTokenTypes[INTEGER_STATE] = INTEGER_TOKEN;
  mCorrespondingTokenTypes[LCURLY_STATE] = LCURLY_TOKEN;
  mCorrespondingTokenTypes[RCURLY_STATE] = RCURLY_TOKEN;
  mCorrespondingTokenTypes[ASSIGNMENT_STATE] = ASSIGNMENT_TOKEN;
  mCorrespondingTokenTypes[PLUS_STATE] = PLUS_TOKEN;
  mCorrespondingTokenTypes[SEMICOLON_STATE] = SEMICOLON_TOKEN;
  mCorrespondingTokenTypes[ENDFILE_STATE] = ENDFILE_TOKEN;
  mCorrespondingTokenTypes[LESS_STATE] = LESS_TOKEN;
  mCorrespondingTokenTypes[INSERTION_STATE] = INSERTION_TOKEN;



}

MachineState StateMachineClass::UpdateState(char currentCharacter,
TokenType & correspondingTokenType)
{
	// convert the input character into an input character type
	CharacterType charType = BAD_CHAR;

	if(isdigit(currentCharacter))
		charType = DIGIT_CHAR;
	if(isalpha(currentCharacter))
		charType = LETTER_CHAR;
	if(isspace(currentCharacter))
		charType = WHITESPACE_CHAR;
	if(currentCharacter=='+')
		charType = PLUS_CHAR;
	if(currentCharacter=='}')
    charType = RCURLY_CHAR;
  if(currentCharacter=='{')
    charType = LCURLY_CHAR;
  if(currentCharacter==')')
    charType = RPARAN_CHAR;
  if(currentCharacter=='(')
    charType = LPARAN_CHAR;
  if(currentCharacter=='=')
    charType = ASSIGNMENT_CHAR;
  if(currentCharacter==';')
    charType = ENDFILE_CHAR;
  if(currentCharacter=='<')
    charType = LESS_CHAR;

  correspondingTokenType = mCorrespondingTokenTypes[mCurrentState];
	mCurrentState = mLegalMoves[mCurrentState][charType];
	return mCurrentState;

}
