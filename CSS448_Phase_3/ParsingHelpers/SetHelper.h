#define SETHELPER_H
#ifndef SETHELPER_H

#include <iostream>
#include <vector>
#include <string>
#include "IdType.h"
#include "../IdentRecords/SetType.h"

class SetHelper : TypeHelper
{
public:
	SetHelper(const string&);
	~SetHelper(void);

	void setRangeLow(int);
	void setRangeHigh(int);

	bool sendToST(STObject*);

private:
	int rangeLow;
	int rangeHigh;
}

#endif
