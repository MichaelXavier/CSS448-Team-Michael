#include "Parameter.h"

PointerType::PointerType(const string& name) : IdentRecord(name) {
	passByRef = false;
}

PointerType::~PointerType(void) {
}

void Parameter::display(int depth)const {
  printIndent(depth);
	if(passByRef) {
		cout << "var ";
  }

	cout << identName << " " << typePtr->getName(); 
}
