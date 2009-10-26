#include "Parameter.h"

PointerType::PointerType(const string& name) : IdentRecord(name) {
	passByRef = false;
}

PointerType::~PointerType(void) {
}

void Parameter::display(ostream& sout, int depth)const {
  printIndent(sout, depth);
	if(passByRef) {
		sout << "var ";
  }

	sout << identName << " " << typePtr->getName(); 
}
