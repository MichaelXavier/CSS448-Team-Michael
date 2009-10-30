#ifndef BOOLEANTYPE_H
#define BOOLEANTYPE_H
#include <iostream>
#include "IdentRecord.h"

// Standard type: Boolean
class BooleanType : public IdentRecord {
public:
  BooleanType(const string& name);
	~BooleanType(void);	

	void display(ostream& sout, int depth)const;
private:
};
#endif
