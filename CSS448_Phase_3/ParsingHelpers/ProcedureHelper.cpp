#include "ProcedureHelper.h"

ProcedureHelper::ProcedureHelper(const string& type_name) : TypeHelper(type_name) {}

ProcedureHelper::~ProcedureHelper(void) {
  while (!parameters.empty()) {
    Parameter* parameter = parameters.pop();
    if (parameter != NULL) { 
      delete parameter; 
    }
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
  if (parameter != NULL) {
    parameters.push_back(param);
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
  while (!parameters.empty()) {
    Parameter* parameter = parameters.pop();
    if (parameter != NULL) { 
      if (!proc->insertParameter(parameter)) {
        //Can't insert, bail out  
        cout << "Error: failed to insert parameter into procedure " << typeName << endl;
        delete proc;
        delete parameter;
        while (!parameters.empty()) {
          parameter = parameters.front();
          delete parameter;
          parameter = parameters.pop();
        }
        return false;
      }
    }
  }

  if (st->insert(arr, procedure)) {
    return true;
  } else {
    delete proc;
    return false;
  }
}
