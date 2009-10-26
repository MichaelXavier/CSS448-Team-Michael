#include "RealType.h"

RealType::RealType(const string& name) : IdentRecord(name) {
}

RealType::~RealType(void) {
}

void RealType::display(ostream& sout, int depth)const {
  printIndent(sout, depth);
  //TODO
}
