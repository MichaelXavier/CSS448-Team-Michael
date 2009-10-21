#include "RecordField.h"

RecordField::RecordField(string ident)
{
	identName = ident;
}


void RecordField::display()
{
	cout << identName << " " << typePtr->getName();
}