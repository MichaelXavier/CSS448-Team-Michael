#include "Constant.h"


// Constructor, sets the identifier name to the parameter value
Constant::Constant(string ident)
{
	identName = ident;
}

// Prints the identifier name and then the value stored in the constant
void Constant::display()
{
	cout << identName << " " << constFactor;
}