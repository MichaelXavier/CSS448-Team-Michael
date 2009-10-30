#include "PointerType.h"

PointerType::PointerType(const string& name, const string& declared) : IdentRecord(name) {
  declared_type = declared;
}

PointerType::~PointerType(void) {
}

void PointerType::display(ostream& sout, int depth)const {
  if (typePtr == NULL) {
    //FIXME: just going to print the error and bail at this point
    sout << "Error: typePtr of " << identName << " not set";
    return;
  }
  printIndent(sout, depth);
  sout << identName << " ^ " << typePtr->getName();
}

void PointerType::setPointObj(IdentRecord* obj) {
  if (obj == NULL) {
    //FIXME: we can put a print error instead if we need to
    cout << "Error: cannot set the pointer target of a PointerType to NULL" << endl;
    return;
  } else if (obj->getName() != declared_type) {
    cout << "Error: pointObj identifier name does not match the declared name" << endl;
  } else {
    typePtr = obj;
  }
}
