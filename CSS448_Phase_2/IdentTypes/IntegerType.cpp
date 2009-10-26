#include "IntegerType.h"

IntegerType::IntegerType(const string& name) : IdentRecord(name) {
}

IntegerType::~IntegerType(void) {
}

void IntegerType::display(int depth)const {
  printIndent(depth);
  //FIXME
}
