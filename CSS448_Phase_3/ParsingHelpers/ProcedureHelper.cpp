#include "ProcedureHelper.h"

ProcedureHelper::ProcedureHelper(const string& type_name) : TypeHelper(type_name) {}

ProcedureHelper::~ProcedureHelper(void) {
  /*while (!params.empty()) {
   Parameter* tempParam = params.front();
   delete tempParam;
   tempParam = NULL;
   params.pop();
  }*///FIXME: causing a crash, looks like scopeNode deletes this
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
