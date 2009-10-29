#include "RecordField.h"
RecordField::RecordField(const string& name) : IdentRecord(name) {
}

RecordField::~RecordField(void) {
}

void RecordField::display(ostream& sout, int depth) const {
  if (typePtr == NULL) {
    //FIXME: just going to print the error and bail at this point
    sout << "Error: typePtr of " << identName << " not set";
    return;
  }

  printIndent(sout, depth);
	sout << identName << " " << typePtr->getName();
}
