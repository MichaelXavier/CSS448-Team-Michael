#include "Variable.h"

// Constructor
Variable::Variable(const string& name) : IdentRecord(name) {
	instanceName = "Variable";
}


// Destructor
Variable::~Variable(void) {
}


// display
// Prints data
void Variable::display(ostream& sout, int depth)const {
  if (typePtr == NULL) {
    sout << "Error: typePtr of " << identName << " not set";
    return;
  }
  printIndent(sout, depth);
  //if its an anonymous array type which has no name, call display on it, otherwise
  //display the type identname
  //also skip the indent so it all prints inline
  if (typePtr->getName().size() == 0) {
    sout << identName;
   // typePtr->display(sout, 0);
  } else {
    sout << identName << " " << typePtr->getName();
  }
}


// setTypePtr
void Variable::setTypePtr(IdentRecord* type) {
  if (type == NULL) {
    throw "Error: cannot set the pointer target of a PointerType to NULL";
    return;
  } else {
    typePtr = type;
  }
}
