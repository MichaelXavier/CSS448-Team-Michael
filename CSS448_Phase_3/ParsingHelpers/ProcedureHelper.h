#ifndef PROCEDUREHELPER_H
#define PROCEDUREHELPER_H
#include <iostream>
#include <queue>
#include <string>
#include "TypeHelper.h"
#include "../IdentTypes/Procedure.h"
using namespace std;

class ProcedureHelper : public TypeHelper {
public:
  ProcedureHelper(const string& type_name);
  ~ProcedureHelper();
  bool AddParameters(queue<Parameter*> params);
  bool AddParameter(Parameter* param);
  IdentRecord* sendToSt(STObject* st);

  queue<Parameter*> getParams(void) { return params; }
private:
  queue<Parameter*> params;
};
#endif

