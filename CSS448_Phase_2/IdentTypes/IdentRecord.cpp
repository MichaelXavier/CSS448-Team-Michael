#include "IdentRecord.h"

IdentRecord::IdentRecord(const string& name) {
  identName = name;
}

IdentRecord::~IdentRecord(void) {
  //TODO
}

// Compares the this and parameter's ident name.
// Returns -1 if this identname > rhs identname, 0 if this identname == rhs identname,
// and 1 if this identname < rhs identname
int IdentRecord::strcmp(const IdentRecord& rhs)const {
	if(this->identName > rhs.identName)
		return -1;
	else if(this->identName == rhs.identName)
		return 0;
	else
		return 1;
}

bool IdentRecord::operator<(const IdentRecord& rhs)const {
  return strcmp(rhs) == 1;
}

void IdentRecord::printIndent(ostream& sout, int depth)const {
  for(int i = 0; i < depth; i++) {
    sout << "   ";
  }
}
