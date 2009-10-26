#include "Variable.h"
Variable::Variable(const string& name) : IdentRecord(name) {
}

VariableType::~VariableType(void) {
}

void Variable::display(int depth)const {
  printIndent(depth);
	cout << identName << " " << typePtr->getName();
}

void Variable::setTypePtr(IdentRecord* type) {
  if (type != NULL) {
    //FIXME: throw exception?
    return;
  } else {
    typePtr = type;
  }
}
