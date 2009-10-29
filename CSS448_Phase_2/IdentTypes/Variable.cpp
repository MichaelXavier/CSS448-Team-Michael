#include "Variable.h"
Variable::Variable(const string& name) : IdentRecord(name) {
}

Variable::~Variable(void) {
}

void Variable::display(ostream& sout, int depth)const {
  if (typePtr == NULL) {
    //FIXME: just going to print the error and bail at this point
    sout << "Error: typePtr of " << identName << " not set";
    return;
  }
  printIndent(sout, depth);
	sout << identName << " " << typePtr->getName();
}

void Variable::setTypePtr(IdentRecord* type) {
  if (type != NULL) {
    //FIXME: throw exception?
    return;
  } else {
    typePtr = type;
  }
}
