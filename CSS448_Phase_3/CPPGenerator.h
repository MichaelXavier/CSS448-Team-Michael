#ifndef CPPGENERATOR_H
#define CPPGENERATOR_H
#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <stack>
#include <vector>
#include "IdentTypes/IdentRecord.h"
#include "IdentTypes/Constant.h"
#include "ParsingHelpers/ConstDecHelper.h"

using namespace std;

class CPPGenerator {
public:
  CPPGenerator(ostream&);
  ~CPPGenerator(void);

  void setup(void);

  void teardown(void);

  void print(void);

  void declareVars(queue<string> idents, IdentRecord* type);

  void declareProc(const string&, queue<string>);
  void declareFunct(const string&, queue<string>, const string&);

  void addInclude(const string&);

  void declareConst(ConstDecHelper*, Constant*);

  void startIfExpr(void);
  void closeIfExpr(void);
  void startElseExpr(void);

  void startCase(void);
  void breakCase(void);
  void writeCaseLabel(Constant*);

  void startWhile(void);

  void startRepeat(void);
  void closeRepeat(const string&);

  void startFor(const string&, const string&);
  void completeFor(const string&, const string&, bool);

  void allocVar(const string&);
  void deallocVar(const string&);

  void writeStr(string);

  void startBlock(void);
  void endBlock(void);

  void closeScope(void);

  void coutExpr(const string& expr, bool newline = false);
  void cinExpr(const string&);
private:
  void popScope(void);

  void closeAllScopes(void);

  ostringstream* cur_stream;
  //FIXME: consider stack of streams for scope?
  
  ostringstream* before_main;
  ostringstream* main;
  stack<ostringstream*>scope_stack;
  vector<ostringstream*>function_streams;
  ostream& output; 

  void printIndent(void);

  int indent_level;
};
#endif
