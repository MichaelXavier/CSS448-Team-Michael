#include "RecordType.h"


// Constructor
RecordType::RecordType(const string& name) : IdentRecord(name) {
	instanceName = "RecordType";
}


// Destructor
RecordType::~RecordType(void) {
  //Delete members
  for (unsigned int i = 0; i < members.size(); i++) {
    delete members[i];
  }
}

// display
// Prints data
void RecordType::display(ostream& sout, int depth)const {
  printIndent(sout, depth);
	sout << identName << endl;  // Prints record name

	// Prints record fields
	for(unsigned int i = 0; i < members.size(); i++)
	{
		members[i]->display(sout, depth+1);
    //Do not do a trailing newline
		if (i < members.size() - 1) {
      sout << endl;
    }
	}
}

// insertField
// Adds a field to list of fields stored in this record
bool RecordType::insertField(RecordField* field) {
  if (hasConflictingFields(field)) {
    //Print an error and exit
    cout << "Field already exists: " << field->getName() << endl;
    return false;
  }
  members.push_back(field);
  return true;
}


// hasConflictingFields
// Checks if identifier name of inserted field is the same as any
// of the identifier names of fields already stored in this record.
bool RecordType::hasConflictingFields(const IdentRecord* field)const {
	for(unsigned int i = 0; i < members.size(); i++)
	{
		// Returns true if equal
		if(field->strcmp(*(members[i])) == 0)
		{
			return true;
		}
	}
	return false; // otherwise returns false
}
