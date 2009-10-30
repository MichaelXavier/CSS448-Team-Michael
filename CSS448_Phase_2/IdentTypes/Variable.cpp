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
  //if its an anonymous array type which has no name, call display on it, otherwise
  //display the type identname
  //also skip the indent so it all prints inline
  if (typePtr->getName().size() == 0) {
    sout << identName;
    typePtr->display(sout, 0);
  } else {
    sout << identName << " " << typePtr->getName();
  }
}

void Variable::setTypePtr(IdentRecord* type) {
  if (type == NULL) {
    //FIXME: we can put a print error instead if we need to
    throw "Error: cannot set the pointer target of a PointerType to NULL";
    return;
  } else {
    typePtr = type;
  }
}
