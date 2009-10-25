#ifndef PROCEDURE_H
#define PROCEDURE_H
#include <iostream>
#include "IdentRecord.h"
#include "STObject.h"

using namespace std;

class Procedure : public IdentRecord {
public:
	Procedure(const string& name);
	~Procedure(void);

	void display();
	void insertParameter(IdentRecord*, IdType);
	
  //calls strcmp on identrecord or operator==
  bool hasConflictingParams(const IdentRecord*)const;

private:
	// possibly a list of parameters
  vector<Parameter*> params;
};
#endif
