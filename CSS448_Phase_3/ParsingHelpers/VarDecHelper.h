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
	VarDecHelper(void);
	~VarDecHelper(void);
	
	bool AddVar(const string&);

  //Pop a queue, on failure, clear the stack
	bool AddVars(queue<string>&);
	bool SetMemberType(IdentRecord*);
	bool sendToSt(STObject* st);
private:
	vector<string> varNames;
	IdentRecord* typePtr;
};
#endif
