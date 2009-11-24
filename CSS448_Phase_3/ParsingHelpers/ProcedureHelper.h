#define PROCEDUREHELPER_H
#ifndef PROCEDUREHELPER_H
#include <iostream>
#include <queue>
#include <string>
#include "TypeHelper.h"
#include "../IdentRecords/Procedure.h"

using namespace std;

class ProcedureHelper : public TypeHelper {
public:
  ProcedureHelper(const string& type_name);
  ~ProcedureHelper();

  bool AddParameters(Queue<Parameter*> params);
  bool AddParameter(Parameter* param);

  bool sendToSt(STObject* st);

private:

  Queue<Parameter*> params;
};

#endif
