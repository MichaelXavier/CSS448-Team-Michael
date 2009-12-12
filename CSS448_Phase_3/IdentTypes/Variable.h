#ifndef VARIABLE_H
#define VARIABLE_H
#include <iostream>
#include "IdentRecord.h"

class Variable : public IdentRecord {
public:
	Variable(const string& name);
	~Variable(void);

	void display(ostream& sout, int depth)const;
	void setTypePtr(IdentRecord* type);
	IdentRecord* getTypePtr() {return typePtr;}

private:
	IdentRecord* typePtr;
};
#endif
