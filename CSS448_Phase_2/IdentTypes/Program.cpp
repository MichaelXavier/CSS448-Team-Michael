#include "Program.h"


// Constructor
Program::Program(const string& name) : IdentRecord(name) {
}


// Destructor
Program::~Program(void) {
  //Delete parameters
  for (unsigned int i = 0; i < parameters.size(); i++) {
    delete parameters[i];
  }
}

// display
// Prints data
void Program::display(ostream& sout, int depth)const {
  //leading newline like in the sample output
  sout << endl;
  printIndent(sout, depth);
	sout << identName << endl;

	// Prints list of parameters
	for(unsigned int i = 0; i < parameters.size(); i++)
	{
		parameters[i]->display(sout, depth+1);
		sout << endl;
	}
}


// hasConflictingParams
// Checks to see if parameter's identifier name is the same as
// any of the identifier names of parameters stored in this Program
bool Program::hasConflictingParams(const IdentRecord* record)const
{
	for(unsigned int i = 0; i < parameters.size(); i++)
	{
		// Returns true if equal
		if(record->strcmp(*parameters[i]) == 0)
		{
			return true;
		}
	}
	return false; // otherwise returns false
}



// insertParameter
// Adds a parameter to the Program's parameter list, as long as
// no conflicting parameter identifier names exist.
bool Program::insertParameter(Parameter* parameter) {
  if (hasConflictingParams(parameter)) {
    return false;
  }
  parameters.push_back(parameter);
  return true;
}
