#include "RecordType.h"
RecordType::RecordType(const string& name) : IdentRecord(name) {
}

RecordType::~RecordType(void) {
}

void RecordType::display(ostream& sout, int depth)const {
  printIndent(sout, depth);
	cout << identName;

	// possibly print list of fields for this record
}

void RecordType::insertField(IdentRecord*, IdType) {
  //TODO: check fields list and make sure none of hte names conflict with the getName() of the field we are inserting
}
