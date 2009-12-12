// VarDecHelper.h
// This class is used for storing information about Variable objects from 'y' and
// eventually creating the Variable object and adding it to the symbol table.
// Helper objects are also used for code generation.


#ifndef VARDECHELPER_H
#define VARDECHELPER_H

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include "../IdType.h"
#include "../IdentTypes/Variable.h"
#include "../STObject.h"
using namespace std;

class VarDecHelper
{
public:
	VarDecHelper(void);  // Constructor
	~VarDecHelper(void); // Destructor
	
	bool AddVar(const string&); // A variable name is added to queue

  //Pop a queue, on failure, clear the stack
	bool AddVars(queue<string>&);  // Variable names are added to queue
	bool SetMemberType(IdentRecord*); // Variable type is set
	IdentRecord* sendToSt(STObject* st); // Creates variables and sends to ST
private:
	vector<string> varNames;	// List of variable names
	IdentRecord* typePtr;		// Variable type
};
#endif
