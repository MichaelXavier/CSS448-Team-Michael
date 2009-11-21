#define PROGRAMHELPER_H
#ifndef PROGRAMHELPER_H

#include <iostream>
#include <vector>
#include <string>
#include "IdType.h"
#include "../IdentRecords/Program.h"

class ProgramHelper
{
public:
	ProgramHelper(const string&);
	~ProgramHelper(void);

	bool AddParameterName(const string&);
	Program* GetProgramObj(void);

private:
	string programName;
	vector<string> parameterNames;
};

#endif
