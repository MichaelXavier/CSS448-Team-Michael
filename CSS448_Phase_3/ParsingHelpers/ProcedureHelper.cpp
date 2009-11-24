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

bool ProcedureHelper::AddParameters(Queue<Parameter*> param_queue) {
  //TODO
}

bool ProcedureHelper::AddParameter(Parameter* param) {
  //TODO
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

bool ProcedureHelper::validate(void) {
  //TODO
}
