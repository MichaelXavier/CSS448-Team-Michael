#ifndef PARAMETER_H
#define PARAMETER_H
#include <iostream>
#include "IdentRecord.h"

class Parameter : public IdentRecord {
public:
	Parameter(string);
	~Parameter();

	void display();
	void setTypePtr(IdentRecord* type) {typePtr = type;}
	void setVar(bool var) {m_var = var;}

private:
	IdentRecord* typePtr;
	bool m_var;	// var = 0 means pass by value, var = 1 means pass by reference
};
#endif
