#ifndef INTEGERTYPE_H
#define INTEGERTYPE_H
#include <iostream>
#include "IdentRecord"

class IntegerType : public IdentRecord {
	IntegerType(const string& name);
	~IntegerType(void);
public:

private:
  IdentType* typePtr;
}
#endif
