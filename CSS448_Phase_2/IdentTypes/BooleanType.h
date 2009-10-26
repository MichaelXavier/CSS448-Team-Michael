#ifndef BOOLEANTYPE_H
#define BOOLEANTYPE_H
#include <iostream>
#include "IdentRecord"

class BooleanType : public IdentRecord {
public:
  BooleanType(const string& name);
	~BooleanType(void);				// Destructor

	void display(int depth)const;
private:
}
#endif
