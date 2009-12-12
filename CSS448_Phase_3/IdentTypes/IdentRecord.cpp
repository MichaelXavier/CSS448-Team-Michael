#include "IdentRecord.h"

// Constructor
IdentRecord::IdentRecord(const string& name) {
  identName = name;
  instanceName = "IdentRecord";
}


// Destructor
IdentRecord::~IdentRecord(void) {
}


// strcmp
// Compares the this and parameter's ident name.
// Returns -1 if this identname > rhs identname, 0 if this identname == rhs identname,
// and 1 if this identname < rhs identname
int IdentRecord::strcmp(const IdentRecord& rhs)const {
	if(identName > rhs.identName)
		return -1;
	else if(identName == rhs.identName)
		return 0;
	else
		return 1;
}

// operator<
// Needed for map used in ScopeNode.  Comparison operator.
bool IdentRecord::operator<(const IdentRecord& rhs)const {
  return strcmp(rhs) == 1;
}


// operator==
// Needed for map used in ScopeNode.  Comparison operator.
bool IdentRecord::operator==(const IdentRecord& rhs)const {
  return strcmp(rhs) == 0;
}


// printIndent
// Prints specified indent.
void IdentRecord::printIndent(ostream& sout, int depth)const {
  for(int i = 0; i < depth; i++) {
    sout << "   ";
  }
}
