#ifndef PROCEDURE_H
#define PROCEDURE_H
#include <iostream>
#include <vector>
#include "IdentRecord"
#include "Parameter"

using namespace std;

class Program : public IdentRecord {
public:
	Program(const string& name);
	~Program(void);

	void display(ostream& sout, int depth)const;
	void insertParameter(IdentRecord*, IdType);
	
  //calls strcmp on identrecord or operator==
  bool hasConflictingParams(const IdentRecord*)const;

private:
	// possibly a list of parameters
  vector<Parameter*> params;
};
#endif
