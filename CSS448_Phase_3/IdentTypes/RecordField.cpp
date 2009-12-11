#include "RecordField.h"

// Constructor
RecordField::RecordField(const string& name) : IdentRecord(name) {
}

// Destructor
RecordField::~RecordField(void) {
}

// display
// Prints data
void RecordField::display(ostream& sout, int depth) const {
  if (typePtr == NULL) {
    sout << "Error: typePtr of " << identName << " not set";
    return;
  }

  printIndent(sout, depth);
	sout << identName << " " << typePtr->getName();
}


string RecordField::getTypePtrName()
{
	if(typePtr != NULL)
		return typePtr->getName();
	else
		return "Error: typePtr of field: " + identName + " is NULL\n";
}