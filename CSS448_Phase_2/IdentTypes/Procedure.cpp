#include "Procedure.h"

Procedure::Procedure(const string& name) : IdentRecord(name) {
}

Procedure::~Procedure(void) {
}

void Procedure::display(ostream& sout, int depth)const {
  printIndent(sout, depth);
	sout << identName << endl;

	for(int i = 0; i < params.size(); i++) {
		params[i]->display(sout, depth+1);
		sout << endl;
	}
}

bool Procedure::hasConflictingParams(const IdentRecord* record)const {
	for(int i = 0; i < params.size(); i++) {
		// Returns true if equal
		if(*record == params[i]) {
			return true;
		}
	}
	return false; // otherwise returns false
}


