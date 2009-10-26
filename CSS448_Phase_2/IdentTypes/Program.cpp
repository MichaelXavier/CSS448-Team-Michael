#include "Program.h"

Program::Program(const string& name) : IdentRecord(name) {
}

Program::~Program(void) {
}

void Program::display(int depth)const {
  printIndent(depth);
	cout << identName << endl;

	for(int i = 0; i < params.size(); i++)
	{
		params[i].print(depth+1);
		cout << endl;
	}
}

bool Program::hasConflictingParams(const IdentRecord* record)const
{
	for(int i = 0; i < params.size(); i++)
	{
		// Returns true if equal
		if(record->strcmp(params[i] == 0)
		{
			return true;
		}
	}
	return false; // otherwise returns false
}
