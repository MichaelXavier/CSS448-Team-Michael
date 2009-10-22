#ifndef IDENTRECORD_H
#define IDENTRECORD_H
#include <iostream>
#include <string>

using namespace std;

class IdentRecord {
public:
	int strcmp(const IdentRecord& rhs);	// Compares the this and parameter's ident name
	virtual void display() = 0;			// Displays data held in record, pure virtual
	string getName() {return identName;} // Returns the identifier name

protected:
	string identName;					// The name of the identifier
};
#endif
