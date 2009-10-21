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