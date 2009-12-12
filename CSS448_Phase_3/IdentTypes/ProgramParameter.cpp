#include "ProgramParameter.h"


// ConstrProgramuctor
ProgramParameter::ProgramParameter(const string& name) : IdentRecord(name) {
	instanceName = "ProgramParameter";
}

// Destructor
ProgramParameter::~ProgramParameter(void) {
}

// display
// Prints data
void ProgramParameter::display(ostream& sout, int depth)const {
  printIndent(sout, depth); 
	sout << identName << " "; 
}
