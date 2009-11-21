#include "SetHelper.h"	


void SetHelper::SetHelper(const string& type_name) : TypeHelper(type_name)
{
}


void SetHelper::~SetHelper(void)
{
}


void SetHelper::setRangeLow(int low)
{
	rangeLow = low;
}
	
void SetHelper::setRangeHigh(int high)
{
	rangeHigh = high;
}

bool SetHelper::sendToST(STObject* st)
{	
	IdentRecord* setRecord = new SetType(typeName);
	setRecord->setRange(rangeLow, rangeHigh);
	bool addedToST = st.insert(setRecord, settype);
	if(addedToST == false)
	{
		// handle error
	}
	return true;
}

