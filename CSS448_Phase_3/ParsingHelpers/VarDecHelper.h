#define VARDECHELPER_H
#ifndef VARDECHELPER_H

#include <iostream>
#include <vector>
#include <string>
#include "IdType.h"
#include "../IdentRecords/Variable.h"

using namespace std;

class VarDecHelper()
{
public:
	VarDecHelper(void);
	~VarDecHelper(void);
	
	bool AddVar(const string&);
  //Pop a queue, on failure, clear the stack
	bool AddVars(queue<string&>&);
	bool SetMemberType(const string&);
	bool sendToSt(STObject* st);

private:
	vector<string> varNames;
	string memberType;
};

#endif
