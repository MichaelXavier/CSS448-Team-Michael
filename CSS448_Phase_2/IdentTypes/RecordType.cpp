#include "RecordType.h"

RecordType::RecordType(const string& name) : IdentRecord(name) {
}

RecordType::~RecordType(void) {
}

void RecordType::display(ostream& sout, int depth)const {
  printIndent(sout, depth);
	sout << identName << endl;

	for(unsigned int i = 0; i < members.size(); i++)
	{
		members[i]->display(sout, depth+1);
		sout << endl;
	}
}

void RecordType::insertField(IdentRecord*, IdType) {
  //TODO: check fields list and make sure none of hte names conflict with the getName() of the field we are inserting
}
