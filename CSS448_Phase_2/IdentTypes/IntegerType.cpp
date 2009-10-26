#include "IntegerType.h"

IntegerType::IntegerType(const string& name) : IdentRecord(name) {
}

IntegerType::~IntegerType(void) {
}

void IntegerType::display(ostream& sout, int depth)const {
  printIndent(sout, depth);
  //FIXME
}
