#include "Constant.h"

ConstantType::ConstantType(const string& name) : IdentRecord(name) {
}

ConstantType::~ConstantType(void) {
}

// Prints the identifier name and then the value stored in the constant
void Constant::display(int depth)const {
  printIndent(depth);
	cout << identName << " " << constFactor;
}
