#include "PointerType.h"


// Constructor
PointerType::PointerType(const string& name, const string& declared) : IdentRecord(name) {
  declared_type = declared;
}

// Destructor
PointerType::~PointerType(void) {
}


// display
// Prints data
void PointerType::display(ostream& sout, int depth)const {
  if (typePtr == NULL) {
    // typePtr must be set in order to print data
    sout << "Error: typePtr of " << identName << " not set";
    return;
  }
  printIndent(sout, depth);
  sout << identName << " ^ " << typePtr->getName();
}


// setPointObj
// Sets typePtr and checks if obj's identifier matches declared_type
void PointerType::setPointObj(IdentRecord* obj) {
  if (obj == NULL) {
    cout << "Error: cannot set the pointer target of a PointerType to NULL" << endl;
    return;
  } else if (obj->getName() != declared_type) {
    cout << "Error: pointObj identifier name does not match the declared name" << endl;
  } else {
    typePtr = obj;
  }
}
