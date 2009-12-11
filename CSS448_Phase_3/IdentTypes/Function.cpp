#include "Function.h"


// Constructor
Function::Function(const string& name) : IdentRecord(name) {
  returnType = NULL;
}


// Destructor
Function::~Function(void) {
  //Delete parameters
  for (unsigned int i = 0; i < parameters.size(); i++) {
    delete parameters[i];
  }
}


// display
// Prints data
void Function::display(ostream& sout, int depth)const {
  //leading newline like in the sample output
  sout << endl;

  printIndent(sout, depth); // Prints indent
  sout << identName << " "; // Prints identifier name of function
 
  if (returnType != NULL) { // Prints return type of function
    sout << returnType->getName();
  }
  sout << endl;

  // Prints parameters of function
  for (unsigned int i = 0; i < parameters.size(); i++) {
    parameters[i]->display(sout, depth+1);//indent parameters one more place
    sout << endl;
  }
}


// insertParameter
// Adds a parameter to be stored in the function's list of parameters.
bool Function::insertParameter(Parameter* parameter) {
    // Checks to see if inserted parameter has the same identifier name
	// as any of the parameters currently stored in this function
	if (hasConflictingParams(parameter)) {
    //Print an error and exit
    cout << "Parameter already exists: " << parameter->getName() << endl;
    return false;
  }
	// If no conflicting parameter names, then add parameter to function
  parameters.push_back(parameter);
  return true;
}


// hasConflictingParams
// Checks to see if the parameter's identifier name is the same as any
// of the parameter identifier names already stored in this function
bool Function::hasConflictingParams(const IdentRecord* parameter)const {
  if (parameter != NULL) {
    for(unsigned int i = 0; i < parameters.size(); i++) {
      // Returns true if equal
      if(parameter->strcmp(*parameters[i]) == 0) {
        return true;
      }
    }
  }
	return false; // otherwise returns false
}


// lookupParameter
// Returns a pointer to a parameter if it is stored in parameters
IdentRecord* Function::lookupParameter(const string& str) const
{
	for(int i = 0; i < parameters.size(); i++)
	{
		if(parameters[i]->getName() == str)
			return (IdentRecord*)parameters[i];
	}
	return NULL;
}