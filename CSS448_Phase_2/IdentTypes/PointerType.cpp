#include "PointerType.h"

PointerType::PointerType(const string& name) : IdentRecord(name) {
}

PointerType::~PointerType(void) {
}

void PointerType::display(int depth)const {
  printIndent(depth);
  //FIXME
	//cout << identName << " " << pointsToObj->getName();
}

void Variable::setPointObj(IdentRecord* obj) {
  if (obj != NULL) {
    //FIXME: throw exception?
    return;
  } else {
    typePtr = obj;
  }
}
