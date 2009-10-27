#include "RecordField.h"
RecordField::RecordField(const string& name) : IdentRecord(name) {
}

RecordField::~RecordField(void) {
}


void RecordField::display(ostream& sout, int depth) const {
  printIndent(sout, depth);
	sout << identName << " " << typePtr->getName();
}
