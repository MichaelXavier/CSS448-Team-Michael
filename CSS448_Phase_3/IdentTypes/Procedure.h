#ifndef PROCEDURE_H
#define PROCEDURE_H
#include <iostream>
#include <vector>
#include "../IdType.h"
#include "IdentRecord.h"
#include "Parameter.h"

using namespace std;

class Procedure : public IdentRecord {
public:
	Procedure(const string& name);
	~Procedure(void);

	void display(ostream& sout, int depth)const; // Prints data
	bool insertParameter(Parameter*);  // Adds a parameter to list of params
	
  // Checks to see if parameter's identifier name is the same as
  // any of the identifier names of parameters stored in this Procedure
  bool hasConflictingParams(const IdentRecord* parameter)const;

  // Returns a pointer to a parameter if it is stored in parameters
  IdentRecord* lookupParameter(const string&) const;

private:
  vector<Parameter*> parameters;  // List of procedure parameters
};
#endif
