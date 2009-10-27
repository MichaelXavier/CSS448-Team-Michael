#include "Constant.h"

Constant::Constant(const string& name) : IdentRecord(name) {
  constFactor = 0;//FIXME: not sure if this is what we want to do
}

Constant::~Constant(void) {
}

// Prints the identifier name and then the value stored in the constant
void Constant::display(ostream& sout, int depth)const {
  printIndent(sout, depth);
	sout << identName << " " << constFactor;
}
