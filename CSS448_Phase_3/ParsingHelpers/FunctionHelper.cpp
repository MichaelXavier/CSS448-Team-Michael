#include "FunctionHelper.h"

FunctionHelper::FunctionHelper(const string& type_name) : TypeHelper(type_name) 
{
	returnType = NULL;
}

FunctionHelper::~FunctionHelper(void) {
   Parameter* tempParam = params.front();
   delete tempParam;
   tempParam = NULL;
   params.pop();
}

bool FunctionHelper::AddParameters(queue<Parameter*> params) {
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

bool FunctionHelper::AddParameter(Parameter* param) {
  if (param != NULL) {
    params.push(param);
    return true;
  } else {
    cout << "Error: cannot add a NULL parameter to Function" << typeName << endl;
    return false;
  }
}

bool FunctionHelper::sendToSt(STObject* st) {
  if (!validate()) {
    return false;
  }

  Function* proc = new Function(typeName);
  //Add dimensions
  while (!params.empty()) {
    Parameter* parameter = params.front();
	params.front() = NULL;

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

  if (st->insert(proc, function)) {
    return true;
  } else {
    delete proc;
    return false;
  }
}

