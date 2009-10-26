#include "BooleanType.h"

BooleanType::BooleanType(const string& name) : IdentRecord(name) {
}

BooleanType::~BooleanType(void) {
}

void BooleanType::display(ostream& sout, int depth)const {
  printIndent(sout, depth);
  //TODO
}
