#include "Procedure.h"


// Constructor
Procedure::Procedure(const string& name) : IdentRecord(name) {
}


// Destructor
Procedure::~Procedure(void) {
  //Delete parameters
  for (unsigned int i = 0; i < parameters.size(); i++) {
    delete parameters[i];
  }
}


// display
// Prints data
void Procedure::display(ostream& sout, int depth)const {
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
// any of the identifier names of parameters stored in this Procedure
bool Procedure::hasConflictingParams(const IdentRecord* parameter)const
{
	for(unsigned int i = 0; i < parameters.size(); i++)
	{
		// Returns true if equal
		if(parameter->strcmp(*parameters[i]) == 0)
		{
			return true;
		}
	}
	return false; // otherwise returns false
}


// insertParameter
// Adds a parameter to the Procedure's parameter list, as long as
// no conflicting parameter identifier names exist.
bool Procedure::insertParameter(Parameter* parameter) {
  if (hasConflictingParams(parameter)) {
    //Print an error and exit
    cout << "Parameter already exists: " << parameter->getName() << endl;
    return false;
  }
  parameters.push_back(parameter);
  return true;
}


// lookupParameter
// Returns a pointer to a parameter if it is stored in parameters
IdentRecord* Procedure::lookupParameter(const string& str) const
{
	for(int i = 0; i < parameters.size(); i++)
	{
		if(parameters[i]->getName() == str)
			return (IdentRecord*)parameters[i];
	}
	return NULL;
}
