#ifndef FUNCTION_H
#define FUNCTION_H
#include <iostream>
#include <vector>
#include "IdentRecord"

class Function : public IdentRecord {
public:
	Function(const string& name);		// Constructor
	~Function(void);				// Destructor

	void insertParameter(IdentRecord*, IdType);

  //calls strcmp on identrecord or operator==
  bool hasConflictingParams(const IdentRecord*)const;

  setReturnType(const IdentRecord*);
private:
  IdentRecord* returnType;
  vector<Parameter*> parameters;//FIXME: this implementation not set in stone
}
#endif
