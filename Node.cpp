#include "Node.h"

Node::~Node(){

}

StartNode::StartNode(ProgramNode * pn){
  mPN = pn;
}

StartNode::~StartNode(){
  delete mPN;
}
ProgramNode::ProgramNode(BlockNode *bn){
  mBN = bn;
}
ProgramNode::~ProgramNode(){
  delete mBN;
}
BlockNode::BlockNode(StatementGroupNode  *sgn){
  mSGN = sgn;
}
BlockNode::~BlockNode(){
  delete mSGN;
}
StatementGroupNode::StatementGroupNode(){
}
void StatementGroupNode::AddStatement(StatementNode * sn){
  mSGN.push_back(sn);
}
StatementGroupNode::~StatementGroupNode(){
  for(int i= 0; i < mSGN.size(); i++){
    delete mSGN[i];
  }
}
DeclarationStatementNode::DeclarationStatementNode(IdentifierNode *in){
  mIN = in;
}
DeclarationStatementNode::~DeclarationStatementNode(){
  delete mIN;
}
AssignmentStatementNode::AssignmentStatementNode(IdentifierNode   *in){
  mIN = in;
}
AssignmentStatementNode::AssignmentStatementNode(ExpressionNode   *en){
  mEN = en;
}
AssignmentStatementNode::~AssignmentStatementNode(){
  delete mIN;
  delete mEN;
}
CoutStatementNode::CoutStatementNode(ExpressionNode *en){
  mEN = en;
}
CoutStatementNode::~CoutStatementNode(){
  delete mEN;
}
ExpressionNode::ExpressionNode(){
}
ExpressionNode::~ExpressionNode(){

}

IntegerNode::IntegerNode(int num){
  mNum = num;
}
IdentifierNode::IdentifierNode(std::string label){
  mLabel = label;
}
void IdentifierNode::DeclareVariable(){
  mSymbolTable->AddEntry(mLabel);
}
void IdentifierNode::SetValue(int v){
  mSymbolTable->SetValue(mLabel, v);
}
int IdentifierNode::GetIndex(){
  return mSymbolTable->GetIndex(mLabel);
}
int IdentifierNode::Evaluate(){
  return mSymbolTable->GetValue(mLabel);
}
BinaryOperatorNode::BinaryOperatorNode(ExpressionNode * enl, ExpressionNode * enr){
  enl = mENL;
  enr = mENR;
}
BinaryOperatorNode::~BinaryOperatorNode(){
  delete mENL;
  delete mENR;
}
PlusNode::PlusNode(ExpressionNode * left, ExpressionNode * right): BinaryOperatorNode(left, right){

}
int PlusNode::Evaluate()
{
	return mENL->Evaluate() + mENR->Evaluate();
}
int MinusNode::Evaluate()
{
	return mENL->Evaluate() - mENR->Evaluate();
}

TimesNode::TimesNode(ExpressionNode * expressionOne, ExpressionNode * expressionTwo) : BinaryOperatorNode(expressionOne, expressionTwo)
{
}

int TimesNode::Evaluate()
{
	return mENL->Evaluate() * mENR->Evaluate();
}

DivideNode::DivideNode(ExpressionNode * expressionOne, ExpressionNode * expressionTwo) : BinaryOperatorNode(expressionOne, expressionTwo)
{
}

int DivideNode::Evaluate()
{
	return mENL->Evaluate() / mENR->Evaluate();
}

LessNode::LessNode(ExpressionNode * expressionOne, ExpressionNode * expressionTwo) : BinaryOperatorNode(expressionOne, expressionTwo)
{
}

int LessNode::Evaluate()
{
	return mENL->Evaluate() < mENR->Evaluate();
}

LessEqualNode::LessEqualNode(ExpressionNode * expressionOne, ExpressionNode * expressionTwo) : BinaryOperatorNode(expressionOne, expressionTwo)
{
}

int LessEqualNode::Evaluate()
{
	return mENL->Evaluate() <= mENR->Evaluate();
}

GreaterNode::GreaterNode(ExpressionNode * expressionOne, ExpressionNode * expressionTwo) : BinaryOperatorNode(expressionOne, expressionTwo)
{
}

int GreaterNode::Evaluate()
{
	return mENL->Evaluate() > mENR->Evaluate();
}

GreaterEqualNode::GreaterEqualNode(ExpressionNode * expressionOne, ExpressionNode * expressionTwo) : BinaryOperatorNode(expressionOne, expressionTwo)
{
}

int GreaterEqualNode::Evaluate()
{
	return mENL->Evaluate() >= mENR->Evaluate();
}

EqualNode::EqualNode(ExpressionNode * expressionOne, ExpressionNode * expressionTwo) : BinaryOperatorNode(expressionOne, expressionTwo)
{
}

int EqualNode::Evaluate()
{
	return mENL->Evaluate() == mENR->Evaluate();
}

NotEqualNode::NotEqualNode(ExpressionNode * expressionOne, ExpressionNode * expressionTwo) : BinaryOperatorNode(expressionOne, expressionTwo)
{
}

int NotEqualNode::Evaluate()
{
	return mENL->Evaluate() != mENR->Evaluate();
}
