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

void SetHelper::setRangeLow(const string& low)
{
  if (low.length > 0) {
    rangeLow = low[0];
  } else {
    cout << "Error: unable to set the lower bound with zero-length string: " << typeName;
  }
}
	
void SetHelper::setRangeHigh(int high)
{
  if (high.length > 0) {
    rangeHigh = high[0];
  } else {
    cout << "Error: unable to set the higher bound with zero-length string: " << typeName;
  }
}

bool SetHelper::sendToSt(STObject* st)
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

