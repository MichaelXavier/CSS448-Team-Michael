#include "ProcedureHelper.h"

ProcedureHelper::ProcedureHelper(const string& type_name) : TypeHelper(type_name) {}

ProcedureHelper::~ProcedureHelper(void) {
  while (!params.empty()) {
   Parameter* tempParam = params.front();
   delete tempParam;
   tempParam = NULL;
   params.pop();
  }
}

bool ProcedureHelper::AddParameters(queue<Parameter*> params) {
  while (!params.empty()) {
    Parameter* param = params.front();
    if (!AddParameter(param)) {
      delete param;
      //clear the stack and bail
      while (!params.empty()) {
        param = params.front();
        delete param;
        params.pop();
      }
      return false;
    }
    params.pop();
  }
  return true;
}

bool ProcedureHelper::AddParameter(Parameter* param) {
  if (param != NULL) {
    params.push(param);
    return true;
  } else {
    cout << "Error: cannot add a NULL parameter to Procedure" << typeName << endl;
    return false;
  }
}

bool ProcedureHelper::sendToSt(STObject* st) {
  if (!validate()) {
    return false;
  }

  Procedure* proc = new Procedure(typeName);
    //Add dimensions
  while (!params.empty()) {
    Parameter* parameter = params.front();

    if (parameter != NULL) { 
      if (!proc->insertParameter(parameter)) {
        //Can't insert, bail out  
        cout << "Error: failed to insert parameter into Function " << typeName << endl;
        delete proc;
        delete parameter;
        while (!params.empty()) {
		  parameter = params.front();
		  delete parameter;
		  parameter = NULL;
          params.pop();
        }
        return false;
      }
	  params.pop();
    }
  }

  if (st->insert(proc, procedure)) {
    return true;
  } else {
    delete proc;
    return false;
  }
}
