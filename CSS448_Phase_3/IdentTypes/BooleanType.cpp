#include "BooleanType.h"

BooleanType::BooleanType(const string& name) : IdentRecord(name) {
	instanceName = "BooleanType";
}

BooleanType::~BooleanType(void) {
}

void BooleanType::display(ostream& sout, int depth)const {
  printIndent(sout, depth);
}
