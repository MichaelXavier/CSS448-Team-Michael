#include "Parameter.h"

Parameter::Parameter(const string& name) : IdentRecord(name) {
	passByRef = false;
}

Parameter::~Parameter(void) {
}

void Parameter::display(ostream& sout, int depth)const {
  if (typePtr == NULL) {
    //FIXME: just going to print the error and bail at this point
    sout << "Error: typePtr of " << identName << " not set" << endl;
    return;
  }

  printIndent(sout, depth);
	if(passByRef) {
		sout << "var ";
  }

	sout << identName << " " << typePtr->getName(); 
}
