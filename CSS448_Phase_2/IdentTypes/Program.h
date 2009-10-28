#ifndef PROCEDURE_H
#define PROCEDURE_H
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

	void display(ostream& sout, int depth)const;
	bool insertParameter(Parameter*);
	
  //calls strcmp on identrecord or operator==
  bool hasConflictingParams(const IdentRecord*)const;

private:
	// possibly a list of parameters
  vector<Parameter*> parameters;
};
#endif
