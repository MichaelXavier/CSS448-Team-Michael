#ifndef FUNCTIONHELPER_H
#define FUNCTIONHELPER_H
#include <iostream>
#include <queue>
#include <string>
#include "TypeHelper.h"
#include "../IdentTypes/Function.h"
using namespace std;
class FunctionHelper : public TypeHelper {
public:
  FunctionHelper(const string& type_name);
  ~FunctionHelper();
  bool AddParameters(queue<Parameter*> params);
  bool AddParameter(Parameter* param);
  bool SetReturnType(IdentRecord* ret) {returnType = ret;}
  IdentRecord* sendToSt(STObject* st);

  queue<Parameter*> getParams(void) { return params; }
  IdentRecord* getReturnType(void) { return returnType; }
  Function* getFunctPtr(void) { return funct_ptr; }
private:
  queue<Parameter*> params;
  IdentRecord* returnType;
  Function* funct_ptr;
};
#endif
