#include "Function.h"

Function::Function(const string& name) : IdentRecord(name) {
  returnType = NULL;
}

Function::~Function(void) {
}

Function::display(ostream& sout, int depth)const {
  printIndent(sout, depth);
  //TODO
}


bool Function::hasConflictingParams(const IdentRecord* record)const
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
