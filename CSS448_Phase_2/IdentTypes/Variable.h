#ifndef VARIABLE_H
#define VARIABLE_H
#include <iostream>
#include "IdentRecord.h"

class Variable : public IdentRecord {
public:
	Variable(string);
	~Variable();

	void display();
	void setTypePtr(IdentRecord* type) {typePtr = type;}

private:
	IdentRecord* typePtr;
};
#endif
