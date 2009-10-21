#ifndef SETTYPE_H
#define SETTYPE_H
#include <iostream>
#include "IdentRecord.h"

class SetType : public IdentRecord {
public:
	SetType(string);
	~SetType();

	void display();
	void setRange(int low, int high);	// Sets the range of the set

private:
	int m_low;
	int m_high;
};
#endif
