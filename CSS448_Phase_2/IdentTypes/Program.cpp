#include "Program.h"

Program::Program(const string& name) : IdentRecord(name) {
}

Program::~Program(void) {
}

void Program::display(ostream& sout, int depth)const {
  printIndent(sout, depth);
	sout << identName << endl;

	for(unsigned int i = 0; i < parameters.size(); i++)
	{
		parameters[i]->display(sout, depth+1);
		sout << endl;
	}
}

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


bool Program::insertParameter(Parameter* parameter) {
  if (hasConflictingParams(parameter)) {
    return false;
  }
  parameters.push_back(parameter);
  return true;
}
