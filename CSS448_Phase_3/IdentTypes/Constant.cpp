#include "Constant.h"


// Constructor
Constant::Constant(const string& name) : IdentRecord(name) {
  constFactor = 0;
}


// Destructor
Constant::~Constant(void) {
}


// display
// Prints data
void Constant::display(ostream& sout, int depth)const {
  printIndent(sout, depth);
	sout << identName << " " << constFactor;
}
