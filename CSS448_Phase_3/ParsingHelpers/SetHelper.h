#ifndef SETHELPER_H
#define SETHELPER_H
#include <iostream>
#include <vector>
#include <string>
#include "../IdType.h"
#include "../IdentTypes/SetType.h"
#include "TypeHelper.h"

class SetHelper : public TypeHelper
{
public:
	SetHelper(const string&);
	~SetHelper(void);
	void setRangeLow(int);
	void setRangeHigh(int);
	bool setRange(int, int);
	bool setRange(const string&, const string&);
	IdentRecord* sendToSt(STObject*);
private:
	int rangeLow;
	int rangeHigh;
};
#endif

