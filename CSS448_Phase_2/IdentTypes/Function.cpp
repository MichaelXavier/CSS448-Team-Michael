#include "Function.h"

Function::Function(const string& name) : IdentRecord(name) {
  returnType = NULL;
}

Function::~Function(void) {
  //Delete parameters
  for (unsigned int i = 0; i < parameters.size(); i++) {
    delete parameters[i];
  }
}

void Function::display(ostream& sout, int depth)const {
  //leading newline like in the sample output
  sout << endl;

  printIndent(sout, depth);
  sout << identName << " ";
  //FIXME: what if return type is not set?
  if (returnType != NULL) {
    sout << returnType->getName();
  }
  sout << endl;
  for (unsigned int i = 0; i < parameters.size(); i++) {
    parameters[i]->display(sout, depth+1);//indent parameters one more place
    sout << endl;
  }
}

bool Function::insertParameter(Parameter* parameter) {
  if (hasConflictingParams(parameter)) {
    //Print an error and exit
    cout << "Parameter already exists: " << parameter->getName() << endl;
    return false;
  }
  parameters.push_back(parameter);
  return true;
}

bool Function::hasConflictingParams(const IdentRecord* parameter)const {
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
