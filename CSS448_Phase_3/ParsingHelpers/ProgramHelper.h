#ifndef PROGRAMHELPER_H
#define PROGRAMHELPER_H

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include "../IdType.h"
#include "../IdentTypes/Program.h"

class ProgramHelper
{
public:
	ProgramHelper(const string&);
	~ProgramHelper(void);

	bool AddParameterName(const string&);
  //Pop a queue, on failure, clear the stack
	bool AddParameterNames(queue<string>&);
	Program* GetProgramObj(void);

private:
	string programName;
	vector<string> parameterNames;
};

#endif
