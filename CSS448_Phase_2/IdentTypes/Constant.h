#ifndef CONSTANT_H
#define CONSTANT_H
#include <iostream>
#include "IdentRecord.h"

class Constant : public IdentRecord {

public:
	Constant(const string& name);		
	~Constant(void);				

	void display(ostream& sout, int depth)const;

  void setConstFactor(int value) { constFactor = value; }

private:
	int constFactor; // The integer value of the const 
					 // NOTE: may need to be a union
};
#endif
