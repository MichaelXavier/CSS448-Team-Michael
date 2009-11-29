#include "SetHelper.h"	
SetHelper::SetHelper(const string& type_name) : TypeHelper(type_name)
{
}
SetHelper::~SetHelper(void)
{
}
bool SetHelper::setRange(int low, int high)
{
	if(low > high)
	{
		cout << "Error: low value is greater than high value for set" << endl;
		return false;
	}	rangeLow = low;
	rangeHigh = high;
	return true;
}

bool SetHelper::setRange(const string& low, const string& high)
{
	if (low.length() != 1) {
    cout << "Error: invalid size for range lower bound " << low << " given for set " << endl;
    return false;
  }
  if (high.length() != 1) {
    cout << "Error: invalid size for range high bound " << high << " given for set" << endl;
    return false;
  }
  return setRange(low[0], high[0]);
}

IdentRecord* SetHelper::sendToSt(STObject* st)
{	
  //FIXME: need to call validate, need to define validate. validate must call base class's validate. Reference ArrayHelper for more info

	IdentRecord* setRecord = new SetType(typeName);
	SetType* setRecordTemp = static_cast<SetType*>(setRecord);
	setRecordTemp->setRange(rangeLow, rangeHigh);
	setRecordTemp = NULL;
	if (st->insert(setRecord, settype) != NULL) {
    cout << "Error: Failed to insert set into ST " << typeName << endl;
    return NULL;
	}

	return setRecord;
}

