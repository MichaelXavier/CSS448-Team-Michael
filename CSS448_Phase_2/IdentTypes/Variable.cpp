#include "Variable.h"
Variable::Variable(const string& name) : IdentRecord(name) {
}

VariableType::~VariableType(void) {
}

void Variable::display(ostream& sout, int depth)const {
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
