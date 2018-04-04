
#pragma once

#include <vector>
#include <string>
#include "Symbol.h"
#include <cstdlib>

class Node;
class StartNode;
class ProgramNode;
class BlockNode;
class StatementGroupNode;
class StatementNode;
class DeclarationStatementNode;
class IdentifierNode;
class AssignmentStatementNode;
class ExpressionNode;
class CoutStatementNode;
class IntegerNode;
class DeclarationNodes;
class BinaryOperatorNode;
class PlusNode;
class MinusNode;
class TimesNode;
class DivideNode;
class LessNode;
class LessEqualNode;
class GreaterNode;
class GreaterEqualNode;
class EqualNode;
class NotEqualNode;




class Node {
public:
  virtual ~Node();

private:

};

class StartNode:public Node{
public:
  StartNode(ProgramNode *pn);
  virtual ~StartNode();

private:
  ProgramNode * mPN;
};

class ProgramNode:public Node{
public:
  ProgramNode(BlockNode *bn);
  virtual ~ProgramNode();

private:
  BlockNode * mBN;
};

class BlockNode:public Node{
public:
  BlockNode(StatementGroupNode  *sgn);
  virtual ~BlockNode();

private:
  StatementGroupNode  * mSGN;
};

class StatementGroupNode :public Node{
public:
  StatementGroupNode ();
  virtual ~StatementGroupNode();
  void AddStatement(StatementNode * sn);

private:
  std::vector<StatementNode*> mSGN;

};

class StatementNode : public Node{
};

class DeclarationStatementNode : public StatementNode{
public:
  DeclarationStatementNode(IdentifierNode   *in);
  virtual ~DeclarationStatementNode();

private:
  IdentifierNode  * mIN;
};

class AssignmentStatementNode  : public StatementNode{
public:
  AssignmentStatementNode(IdentifierNode   *in);
  AssignmentStatementNode(ExpressionNode   *en);
  ~AssignmentStatementNode();

private:
  IdentifierNode  * mIN;
  ExpressionNode  * mEN;
};


class CoutStatementNode : public StatementNode{
public:
  CoutStatementNode(ExpressionNode   *en);
  ~CoutStatementNode();

private:
  ExpressionNode  * mEN;
};

class ExpressionNode {
public:
  ExpressionNode();
  virtual int Evaluate() = 0;
  virtual ~ExpressionNode();
};

class IdentifierNode :public ExpressionNode{
public:
  IdentifierNode(std::string label);
  void DeclareVariable();
  void SetValue(int v);
  int GetIndex();
  virtual int Evaluate();
private:
  std::string mLabel;
  SymbolTableClass * mSymbolTable;
};

class IntegerNode :public ExpressionNode{
public:
  IntegerNode(int num);

private:
  int mNum;
};

class BinaryOperatorNode :public ExpressionNode{
public:
  BinaryOperatorNode(ExpressionNode * enl, ExpressionNode * enr);
  ~BinaryOperatorNode();
protected:
  ExpressionNode * mENL;
  ExpressionNode * mENR;
};

class PlusNode :public BinaryOperatorNode{
public:
  PlusNode(ExpressionNode * left, ExpressionNode * right);
  virtual int Evaluate();
};

class MinusNode : public BinaryOperatorNode
{
public:
	MinusNode(ExpressionNode * expressionOne, ExpressionNode * expressionTwo);
	virtual int Evaluate();
};

class TimesNode : public BinaryOperatorNode
{
	TimesNode(ExpressionNode * expressionOne, ExpressionNode * expressionTwo);
	virtual int Evaluate();
};
class DivideNode : public BinaryOperatorNode
{
	DivideNode(ExpressionNode * expressionOne, ExpressionNode * expressionTwo);
	virtual int Evaluate();
};
class LessNode : public BinaryOperatorNode
{
	LessNode(ExpressionNode * expressionOne, ExpressionNode * expressionTwo);
	virtual int Evaluate();
};
class LessEqualNode : public BinaryOperatorNode
{
	LessEqualNode(ExpressionNode * expressionOne, ExpressionNode * expressionTwo);
	virtual int Evaluate();
};
class GreaterNode : public BinaryOperatorNode
{
	GreaterNode(ExpressionNode * expressionOne, ExpressionNode * expressionTwo);
	virtual int Evaluate();
};
class GreaterEqualNode : public BinaryOperatorNode
{
	GreaterEqualNode(ExpressionNode * expressionOne, ExpressionNode * expressionTwo);
	virtual int Evaluate();
};
class EqualNode : public BinaryOperatorNode
{
	EqualNode(ExpressionNode * expressionOne, ExpressionNode * expressionTwo);
	virtual int Evaluate();
};
class NotEqualNode : public BinaryOperatorNode
{
	NotEqualNode(ExpressionNode * expressionOne, ExpressionNode * expressionTwo);
	virtual int Evaluate();
};
