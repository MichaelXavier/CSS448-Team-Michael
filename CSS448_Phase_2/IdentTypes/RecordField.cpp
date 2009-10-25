#include "RecordField.h"
RecordField::RecordField(const string& name) : IdentRecord(name) {
}

RecordField::~RecordField(void) {
}


void RecordField::display()
{
	cout << identName << " " << typePtr->getName();
}
