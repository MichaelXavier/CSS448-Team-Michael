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

  /*void startConstDec(const string&);

  void setConstFactor(int i);

  void setConstFactor(const string& str);

  void setConstFactor(bool b);

  void setNullConstFactor(void);*/

  void closeScope(void);
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
};
#endif
