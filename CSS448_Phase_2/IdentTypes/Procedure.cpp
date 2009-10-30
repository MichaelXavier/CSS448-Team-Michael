#include "Procedure.h"

Procedure::Procedure(const string& name) : IdentRecord(name) {
}

Procedure::~Procedure(void) {
  //Delete parameters
  for (unsigned int i = 0; i < parameters.size(); i++) {
    delete parameters[i];
  }
}

void Procedure::display(ostream& sout, int depth)const {
  //leading newline like in the sample output
  sout << endl;

  printIndent(sout, depth);
	sout << identName << endl;

	for(unsigned int i = 0; i < parameters.size(); i++)
	{
		parameters[i]->display(sout, depth+1);
		sout << endl;
	}
}

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


bool Procedure::insertParameter(Parameter* parameter) {
  if (hasConflictingParams(parameter)) {
    //Print an error and exit
    cout << "Parameter already exists: " << parameter->getName() << endl;
    return false;
  }
  parameters.push_back(parameter);
  return true;
}


