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
  if (obj != NULL) {
    //FIXME: throw exception?
    return;
  } else {
    typePtr = obj;
  }
}
