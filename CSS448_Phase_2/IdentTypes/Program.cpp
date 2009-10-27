#include "Program.h"

Program::Program(const string& name) : IdentRecord(name) {
}

Program::~Program(void) {
}

void Program::display(ostream& sout, int depth)const {
  printIndent(sout, depth);
	sout << identName << endl;

	for(unsigned int i = 0; i < params.size(); i++)
	{
		params[i]->display(sout, depth+1);
		sout << endl;
	}
}

bool Program::hasConflictingParams(const IdentRecord* record)const
{
	for(unsigned int i = 0; i < params.size(); i++)
	{
		// Returns true if equal
		if(record->strcmp(*params[i]) == 0)
		{
			return true;
		}
	}
	return false; // otherwise returns false
}

void Program::insertParameter(IdentRecord* param)
{
	if(param != NULL)
	{
		Parameter* ptr = static_cast<Parameter*>(param);
		params.push_back(ptr);
	}
}