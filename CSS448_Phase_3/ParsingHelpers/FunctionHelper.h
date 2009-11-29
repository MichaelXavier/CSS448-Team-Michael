#ifndef FUNCTIONHELPER_H
#define FUNCTIONHELPER_H
#include <iostream>
#include <queue>
#include <string>
#include "TypeHelper.h"
#include "../IdentTypes/Procedure.h"
using namespace std;
class FunctionHelper : public TypeHelper {
public:
  FunctionHelper(const string& type_name);
  ~FunctionHelper();
  bool AddParameters(queue<Parameter*> params);
  bool AddParameter(Parameter* param);
  bool SetReturnType(IdentRecord* ret) {returnType = ret;}
  bool sendToSt(STObject* st);
private:
  queue<Parameter*> params;
  IdentRecord* returnType;
};
#endif
