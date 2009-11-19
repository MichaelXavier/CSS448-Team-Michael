#include "Parameter.h"


// Constructor
Parameter::Parameter(const string& name) : IdentRecord(name) {
	passByRef = false;
}

// Destructor
Parameter::~Parameter(void) {
}

// display
// Prints data
void Parameter::display(ostream& sout, int depth)const {
  if (typePtr == NULL) {
	  // Can only print if typePtr is set
    sout << "Error: typePtr of " << identName << " not set" << endl;
    return;
  }

  printIndent(sout, depth); 
	if(passByRef) {
		sout << "var ";
  }

	sout << identName << " " << typePtr->getName(); 
}
