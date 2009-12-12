// ProcedureHelper.h
// This class is used for storing information about Procedure objects from 'y' and
// eventually creating the Procedure object and adding it to the symbol table.
// Helper objects are also used for code generation.

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
  ProcedureHelper(const string& type_name); // Constructor
  ~ProcedureHelper();					    // Destructor
  bool AddParameters(queue<Parameter*> params); // Adds parameters to procedure
  bool AddParameter(Parameter* param); // Adds a parameter to procedure
  IdentRecord* sendToSt(STObject* st); // Creates a procedure object and sends it to the symbol table

  queue<Parameter*> getParams(void) { return params; } // Gets the parameter queue
private:
  queue<Parameter*> params; // Queue of procedure parameters
};
#endif

