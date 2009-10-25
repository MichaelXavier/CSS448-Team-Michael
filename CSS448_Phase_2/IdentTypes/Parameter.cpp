#include "Parameter.h"

PointerType::PointerType(const string& name) : IdentRecord(name) {
	passByRef = false;
}

PointerType::~PointerType(void) : IdentRecord() {
}

void Parameter::display()
{
	if(passByRef) {
		cout << "var ";
  }

	cout << identName << " " << typePtr->getName(); 
}
