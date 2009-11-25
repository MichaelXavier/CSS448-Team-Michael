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
  if (low.length == 1) {
    rangeLow = low[0];
  } else {
    cout << "Error: unable to set the lower bound with string that has length != 1: " << typeName;
  }
}
	
void SetHelper::setRangeHigh(int high)
{
  if (high.length == 1) {
    rangeHigh = high[0];
  } else {
    cout << "Error: unable to set the higher bound with string that has length != 1: " << typeName;
  }
}

bool SetHelper::sendToSt(STObject* st)
{	
  //FIXME: need to call validate, need to define validate. validate must call base class's validate. Reference ArrayHelper for more info
	IdentRecord* setRecord = new SetType(typeName);
	setRecord->setRange(rangeLow, rangeHigh);
	bool addedToST = st.insert(setRecord, settype);
	if(addedToST == false)
	{
		// handle error
	}
	return true;
}

