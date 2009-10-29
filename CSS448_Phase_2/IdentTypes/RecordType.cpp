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

bool RecordType::insertField(RecordField* field) {
  if (hasConflictingFields(field)) {
    //cout << "conflicting param " << field->getName() << endl;//FIXME: debug
    return false;
  }
  members.push_back(field);
  return true;
}

bool RecordType::hasConflictingFields(const IdentRecord* field)const {
  //FIXME: debug
  /*cout << "begin field name dump: " << endl;
	for(unsigned int i = 0; i < members.size(); i++)
    cout << members[i]->getName() << endl;
  cout << "end field name dump: " << endl;*/
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
