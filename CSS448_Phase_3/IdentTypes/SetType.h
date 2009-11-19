#ifndef SETTYPE_H
#define SETTYPE_H
#include <iostream>
#include "IdentRecord.h"

class SetType : public IdentRecord {
public:
	SetType(const string& name);
	~SetType();

	void display(ostream& sout, int depth)const;
	void setRange(int low, int high);	// Sets the range of the set

private:
	int m_low;	// Low of set range
	int m_high; // High of set range
};
#endif
