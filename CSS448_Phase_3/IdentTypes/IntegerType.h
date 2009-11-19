#ifndef INTEGERTYPE_H
#define INTEGERTYPE_H
#include <iostream>
#include "IdentRecord.h"


// Standard type: Integer
class IntegerType : public IdentRecord {
public:
	IntegerType(const string& name);
	~IntegerType(void);
	void display(ostream& sout, int depth)const;
};
#endif
