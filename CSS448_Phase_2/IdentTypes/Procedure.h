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

	void display(ostream& sout, int depth)const;
	bool insertParameter(Parameter*);
	
  //calls strcmp on identrecord or operator==
  bool hasConflictingParams(const IdentRecord* parameter)const;

private:
	// possibly a list of parameters
  vector<Parameter*> parameters;
};
#endif
