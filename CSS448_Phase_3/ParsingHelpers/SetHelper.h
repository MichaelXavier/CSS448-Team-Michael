// SetHelper.h
// This class is used for storing information about SetType objects from 'y' and
// eventually creating the SetType object and adding it to the symbol table.
// Helper objects are also used for code generation.

#ifndef SETHELPER_H
#define SETHELPER_H
#include <iostream>
#include <vector>
#include <string>
#include "../IdType.h"
#include "../IdentTypes/SetType.h"
#include "TypeHelper.h"

extern void yyerror(const char *s);

class SetHelper : public TypeHelper
{
public:
	SetHelper(const string&); // Constructor
	~SetHelper(void);		  // Destructor
	void setRangeLow(int);    
	void setRangeHigh(int);
	bool setRange(int, int);  // Sets low and high range values of set
	bool setRange(const string&, const string&); // Sets low and high range values of set
	IdentRecord* sendToSt(STObject*);  // Creates a set object and sends to ST
	
private:
	int rangeLow;		// Low range value of set
	int rangeHigh;		// High range value of set
};
#endif

