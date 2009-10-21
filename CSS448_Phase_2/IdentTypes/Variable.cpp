#include "Variable.h"


Variable::Variable(string ident)
{
	identName = ident;
}


void Variable::display()
{
	cout << identName << " " << typePtr->getName();
}