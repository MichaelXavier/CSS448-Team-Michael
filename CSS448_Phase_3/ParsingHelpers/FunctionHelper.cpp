#include "FunctionHelper.h"


// Constructor
FunctionHelper::FunctionHelper(const string& type_name) : TypeHelper(type_name) 
{
	returnType = NULL;
  funct_ptr = NULL;
}


// Destructor
FunctionHelper::~FunctionHelper(void) {
}


// AddParameters
// Adds parameters to the parameter queue
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


// AddParameter
// Adds a parameter to the parameter queue
bool FunctionHelper::AddParameter(Parameter* param) {
  if (param != NULL) {
    params.push(param);
    return true;
  } else {
    ostringstream oss("Error: cannot add a NULL parameter to Function "); oss << typeName;
    yyerror(oss.str().c_str());
    return false;
  }
}


// sendToSt
// Creates function object and sends it to the symbol table
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
        ostringstream oss("Error: failed to insert parameter into Function "); oss << typeName;
        yyerror(oss.str().c_str());
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

