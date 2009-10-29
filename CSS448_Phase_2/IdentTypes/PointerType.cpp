#include "PointerType.h"

PointerType::PointerType(const string& name) : IdentRecord(name) {
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
    throw "Error: cannot set the pointer target of a PointerType to NULL";
    return;
  } else {
    typePtr = obj;
  }
}
