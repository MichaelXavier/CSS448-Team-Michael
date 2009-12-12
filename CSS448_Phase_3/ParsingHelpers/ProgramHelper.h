// ProgramHelper.h
// This class is used for storing information about Program objects from 'y' and
// eventually creating the Program object returning a pointer to it.
// Helper objects are also used for code generation.

#ifndef PROGRAMHELPER_H
#define PROGRAMHELPER_H
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include "../IdType.h"
#include "../IdentTypes/Program.h"

extern void yyerror(const char *s);

class ProgramHelper
{
public:
	ProgramHelper(const string&);  // Constructor
	~ProgramHelper(void);		   // Destructor

	// Adds a parameter name to parameter queue
	bool AddParameterName(const string&);

    // Adds parameter names to parameter queue
	bool AddParameterNames(queue<string>&);

	// Creates a program object and returns a pointer to it
	Program* GetProgramObj(void); 
private:
	string programName;   // The name of the program object
	vector<string> parameterNames; // The program parameters
};
#endif
