#include "Procedure.h"

Procedure::Procedure(const string& name) : IdentRecord(name) {
}

Procedure::~Procedure(void) {
}

void Procedure::display(int depth)const {
  printIndent(depth);
	cout << identName << endl;

	for(int i = 0; i < params.size(); i++)
	{
		params[i].print(depth+1);
		cout << endl;
	}
}

bool Procedure::hasConflictingParams(const IdentRecord* record)const
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


