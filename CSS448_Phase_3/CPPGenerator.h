#ifndef CPPGENERATOR_H
#define CPPGENERATOR_H
#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <vector>
#include "IdentTypes/IdentRecord.h"

using namespace std;

class CPPGenerator {
public:
  CPPGenerator(ostream&);
  ~CPPGenerator(void);

  void setup(void);

  void teardown(void);

  void print(void);

  void declareVars(queue<string> idents, IdentRecord* type);

  void declareFunct(string, queue<string>, IdentRecord*);

  void closeScope(void);
private:
  void changeStream(ostringstream*);

  ostringstream* cur_stream;
  //FIXME: consider stack of streams for scope?
  
  ostringstream* before_main;
  ostringstream* main;
  vector<ostringstream*>function_streams;
  ostream& output; 
};
#endif
