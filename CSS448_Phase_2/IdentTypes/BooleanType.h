#ifndef BOOLEANTYPE_H
#define BOOLEANTYPE_H
#include <iostream>
#include "IdentRecord"

class BooleanType : public IdentRecord {
public:
  BooleanType(const string& name);
	~BooleanType(void);				// Destructor

	void display(ostream& sout, int depth)const;
private:
}
#endif
