#include "IdentRecord.h"


// Compares the this and parameter's ident name.
// Returns -1 if this identname > rhs identname, 0 if this identname == rhs identname,
// and 1 if this identname < rhs identname
int IdentRecord::strcmp(const IdentRecord& rhs)
{
	if(this->identName > rhs.identName)
		return -1;
	else if(this->identName == rhs.identName)
		return 0;
	else
		return 1;
}