#ifndef FUNCTION_H
#define FUNCTION_H
#include <iostream>
#include <vector>
#include "../IdType.h"
#include "IdentRecord.h"
#include "Parameter.h"

class Function : public IdentRecord {
public:
	Function(const string& name);		// Constructor
	~Function(void);				// Destructor

	bool insertParameter(Parameter*);

  //calls strcmp on identrecord or operator==
  bool hasConflictingParams(const Parameter*)const;

  void setReturnType(IdentRecord* ret) { returnType = ret; }

	void display(ostream& sout, int depth)const;
private:
  IdentRecord* returnType;
  vector<Parameter*> parameters;//FIXME: this implementation not set in stone
};
#endif
