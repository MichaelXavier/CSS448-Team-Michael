#ifndef CONSTANT_H
#define CONSTANT_H
#include <iostream>
#include "IdentRecord.h"

class Constant : public IdentRecord {

public:
	Constant(const string& name);		// Constructor
	~Constant(void);				// Destructor

	void display(ostream& sout, int depth)const;

  //TODO: not sure if this is the proper interface for constFactor
  void setConstFactor(int value) { constFactor = value; }

private:
	int constFactor;			// The integer value of the const, NOTE: may need to be a union
};
#endif
