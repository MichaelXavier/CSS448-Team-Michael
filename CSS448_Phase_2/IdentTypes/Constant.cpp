#include "Constant.h"

ConstantType::ConstantType(const string& name) : IdentRecord(name) {
}

ConstantType::~ConstantType(void) : IdentRecord() {
}

// Prints the identifier name and then the value stored in the constant
void Constant::display() {
	cout << identName << " " << constFactor;
}
