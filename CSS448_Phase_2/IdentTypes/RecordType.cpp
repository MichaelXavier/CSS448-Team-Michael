#include "RecordType.h"

RecordType::RecordType(string ident)
{
	identName = ident;
}

void RecordType::display()
{
	cout << identName;

	// possibly print list of fields for this record
}

void RecordType::insertField(IdentRecord*, IdType) {
  //TODO: check fields list and make sure none of hte names conflict with the getName() of the field we are inserting
}
