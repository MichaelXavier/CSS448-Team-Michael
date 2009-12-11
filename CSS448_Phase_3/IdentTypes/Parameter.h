#ifndef PARAMETER_H
#define PARAMETER_H
#include <iostream>
#include "IdentRecord.h"

class Parameter : public IdentRecord {
public:
	Parameter(const string& name);
	~Parameter(void);

	void display(ostream& sout, int depth)const;
	void setTypePtr(IdentRecord* type) {typePtr = type;}
	void setVar(bool var) {passByRef = var;}

  IdentRecord* getTypePtr(void) { return typePtr; }

private:
	IdentRecord* typePtr; // The data type of this parameter
	bool passByRef;	// var = 0 means pass by value, 
					// var = 1 means pass by reference
};
#endif
