#include "Procedure.h"

Procedure::Procedure(const string& name) : IdentRecord(name) {
}

Procedure::~Procedure(void) {
}

void Procedure::display(int depth)const {
  printIndent(depth);
	cout << identName;

	// possibly print parameters and objects within scope of function
}


