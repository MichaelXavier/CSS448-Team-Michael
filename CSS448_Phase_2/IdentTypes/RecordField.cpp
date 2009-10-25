#include "RecordField.h"
RecordField::RecordField(const string& name) : IdentRecord(name) {
}

RecordField::~RecordField(void) : IdentRecord() {
}


void RecordField::display()
{
	cout << identName << " " << typePtr->getName();
}
