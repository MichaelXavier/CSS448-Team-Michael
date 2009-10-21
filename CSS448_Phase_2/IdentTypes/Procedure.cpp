#include "Procedure.h"


Procedure::Procedure(string ident)
{
	identName = ident;
}


void Procedure::display()
{
	cout << identName;

	// possibly print parameters and objects within scope of function
}


