#include "Parameter.h"

Parameter::Parameter(const string& name) : IdentRecord(name) {
	passByRef = false;
}

Parameter::~Parameter(void) {
}

void Parameter::display(ostream& sout, int depth)const {
  printIndent(sout, depth);
	if(passByRef) {
		sout << "var ";
  }

	sout << identName << " " << typePtr->getName(); 
}
