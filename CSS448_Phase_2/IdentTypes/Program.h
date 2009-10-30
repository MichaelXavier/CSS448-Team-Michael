#ifndef PROGRAM_H
#define PROGRAM_H
#include <iostream>
#include <vector>
#include "../IdType.h"
#include "IdentRecord.h"
#include "Parameter.h"

using namespace std;

class Program : public IdentRecord {
public:
	Program(const string& name);
	~Program(void);

	void display(ostream& sout, int depth)const;  // Prints data
	bool insertParameter(Parameter*);  // Adds a parameter to Program's 
									   // list of params
	
  // Checks to see if parameter's identifier name is the same as
  // any of the identifier names of parameters stored in this Procedure
  bool hasConflictingParams(const IdentRecord*)const;

private:
  vector<Parameter*> parameters; // List of Program's parameters
};
#endif
