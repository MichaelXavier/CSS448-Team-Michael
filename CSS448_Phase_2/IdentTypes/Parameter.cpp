#include "Parameter.h"

Parameter::Parameter(string ident)
{
	identName = ident;
	m_var = false;
}

void Parameter::display()
{
	if(m_var == true)
		cout << "var ";

	cout << identName << " " << typePtr->getName(); 
}
