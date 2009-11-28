#ifndef PROGRAMPARAMETER_H
#define PROGRAMPARAMETER_H
#include <iostream>
#include "IdentRecord.h"

class ProgramParameter : public IdentRecord {
public:
	ProgramParameter(const string& name);
	~ProgramParameter(void);

	void display(ostream& sout, int depth)const;
};
#endif
