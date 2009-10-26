#include "RecordField.h"
RecordField::RecordField(const string& name) : IdentRecord(name) {
}

RecordField::~RecordField(void) {
}


void RecordField::display(int depth) {
  printIndent(depth);
	cout << identName << " " << typePtr->getName();
}
