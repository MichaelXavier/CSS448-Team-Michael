#ifndef CONSTANT_H
#define CONSTANT_H
#include <iostream>
#include "IdentRecord.h"

class Constant : public IdentRecord {

public:
	Constant(string ident);		// Constructor
	~Constant();				// Destructor

	void display();

private:
	int constFactor;			// The integer value of the const, NOTE: may need to be a union
};
#endif
