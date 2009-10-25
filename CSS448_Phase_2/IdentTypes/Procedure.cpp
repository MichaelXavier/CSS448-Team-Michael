#include "Procedure.h"

Procedure::Procedure(const string& name) : IdentRecord(name) {
}

Procedure::~Procedure(void) : IdentRecord() {
}


void Procedure::display()
{
	cout << identName;

	// possibly print parameters and objects within scope of function
}


