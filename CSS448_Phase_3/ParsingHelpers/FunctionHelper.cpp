#include "FunctionHelper.h"

FunctionHelper::FunctionHelper(const string& type_name) : TypeHelper(type_name) 
{
	returnType = NULL;
  funct_ptr = NULL;
}

FunctionHelper::~FunctionHelper(void) {
   /*Parameter* tempParam = params.front();
   delete tempParam;
   tempParam = NULL;
   params.pop();*///FIXME: causing a crash, looks like scopeNode deletes this
}

bool FunctionHelper::AddParameters(queue<Parameter*> params) {
  while (!params.empty()) {
    Parameter* param = params.front();
    if (!AddParameter(param)) {
      delete param;
      params.pop();
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

IdentRecord* FunctionHelper::sendToSt(STObject* st) {
  if (!validate()) {
    return NULL;
  }

  //preserve the params for use in cppgenerator
  queue<Parameter*> temp_params;

  Function* func = new Function(typeName);
  func->setReturnType(returnType);
  //Add dimensions
  while (!params.empty()) {
    Parameter* parameter = params.front();
    params.front() = NULL;

    if (parameter != NULL) { 
      if (!func->insertParameter(parameter)) {
        //Can't insert, bail out  
        cout << "Error: failed to insert parameter into Function " << typeName << endl;
        //delete func;//FIXME: crashing
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
  if (st->insert(func, function) != NULL) {
    funct_ptr = func; //FIXME: experimental
    return func;
  } else {
    delete func;
    return NULL;
  }
}

