#ifndef PARAMETER_H
#define PARAMETER_H
#include <iostream>
#include "IdentRecord.h"

class Parameter : public IdentRecord {
public:
	Parameter(const string& name);
	~Parameter(void);

	void display(int depth)const;
	void setTypePtr(IdentRecord* type) {typePtr = type;}
	void setVar(bool var) {passByRef = var;}

private:
	IdentRecord* typePtr;
	bool passByRef;	// var = 0 means pass by value, var = 1 means pass by reference
};
#endif
