#include "ProcedureHelper.h"


// Constructor
ProcedureHelper::ProcedureHelper(const string& type_name) : TypeHelper(type_name) {}


// Destructor
ProcedureHelper::~ProcedureHelper(void) {
}


// AddParameters
// Adds parameters to the parameter queue
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


// AddParameter
// Adds a parameter to the parameter queue
bool ProcedureHelper::AddParameter(Parameter* param) {
  if (param != NULL) {
    params.push(param);
    return true;
  } else {
    cout << "Error: cannot add a NULL parameter to Procedure" << typeName << endl;
    return false;
  }
}


// sendToSt
// Creates a procedure object and sends it to the symbol table.
IdentRecord* ProcedureHelper::sendToSt(STObject* st) {
  if (!validate()) {
    return NULL;
  }

  //preserve the params for use in cppgenerator
  queue<Parameter*> temp_params;

  Procedure* proc = new Procedure(typeName);
    //Add dimensions
  while (!params.empty()) {
    Parameter* parameter = params.front();

    if (parameter != NULL) { 
      if (!proc->insertParameter(parameter)) {
        //Can't insert, bail out  
        cout << "Error: failed to insert parameter into Function " << typeName << endl;
        //delete proc;//FIXME: crashing
        //delete parameter;//FIXME: crashing
        params.pop();
        while (!params.empty()) {
          parameter = params.front();
          if (parameter != NULL) {
            //delete parameter;//FIXME: crashing
          }
          parameter = NULL;
          params.pop();
        }
        params = temp_params;
        return NULL;
      } else {
        temp_params.push(parameter);
        params.pop();
      }
    }
  }

  params = temp_params;
  if (st->insert(proc, procedure) != NULL) {
    return proc;
  } else {
    delete proc;
    return NULL;
  }
}
