#include "Procedure.h"

Procedure::Procedure(const string& name) : IdentRecord(name) {
}

Procedure::~Procedure(void) {
}

void Procedure::display(ostream& sout, int depth)const {
  printIndent(sout, depth);
	sout << identName << endl;

	for(unsigned int i = 0; i < parameters.size(); i++)
	{
		parameters[i]->display(sout, depth+1);
		sout << endl;
	}
}

bool Procedure::hasConflictingParams(const IdentRecord* record)const
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


bool Procedure::insertParameter(Parameter* parameter) {
  if (hasConflictingParams(parameter)) {
    return false;
  }
  parameters.push_back(parameter);
  return true;
}


