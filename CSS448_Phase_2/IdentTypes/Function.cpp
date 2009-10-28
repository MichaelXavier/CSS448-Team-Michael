#include "Function.h"

Function::Function(const string& name) : IdentRecord(name) {
  returnType = NULL;
}

Function::~Function(void) {
}

void Function::display(ostream& sout, int depth)const {
  printIndent(sout, depth);
  sout << identName << " ";
  //FIXME: what if return type is not set?
  if (returnType != NULL) {
    sout << returnType->getName();
  }
  sout << endl;
  for (unsigned int i = 0; i < parameters.size(); i++) {
    parameters[i]->display(sout, depth+1);//indent parameters one more place
  }
}

bool Function::insertParameter(Parameter* parameter) {
  if (hasConflictingParams(parameter)) {
    return false;
  }
  parameters.push_back(parameter);
  return true;
}

bool Function::hasConflictingParams(const Parameter* parameter)const {
  if (parameter != NULL) {
    for(unsigned int i = 0; i < parameters.size(); i++) {
      // Returns true if equal
      if(parameter->strcmp(*parameters[i]) == 0) {
        return true;
      }
    }
  }
	return false; // otherwise returns false
}
