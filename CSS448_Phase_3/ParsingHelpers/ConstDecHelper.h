// ConstantHelper.h
// This class is used for storing information about Constant objects from 'y' and
// eventually creating the Constant object and adding it to the symbol table.
// Helper objects are also used for code generation.

#ifndef CONSTDECHELPER_H
#define CONSTDECHELPER_H
#include <iostream>
#include <string>
#include <queue>
#include "../IdType.h"
#include "../IdentTypes/Constant.h"
#include "../STObject.h"
#include "TypeHelper.h"
using namespace std;

class ConstDecHelper
{
public:
	ConstDecHelper(void);	// Constructor
	~ConstDecHelper(void);  // Destructor

	// Sends the stored Constant object to the symbol table
	IdentRecord* sendToSt(STObject* st);

	bool setConstName(string name);	// Sets name of constant object
	string getConstName(void) { return constName; }  // Gets name of constant object
	
	// Makes a copy of parameter Constant object and stores it
	void setConstObj(Constant* obj);

private:
	string constName; // Name of constant
	IdentRecord* constObj; // Store Constant
    bool clean;
    bool validate(void);  // Error checking
};
#endif

