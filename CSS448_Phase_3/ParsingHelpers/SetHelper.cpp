#include "SetHelper.h"	

// Constructor
SetHelper::SetHelper(const string& type_name) : TypeHelper(type_name)
{
}


// Destructor
SetHelper::~SetHelper(void)
{
}


// setRange
// Sets low and high range values of set
bool SetHelper::setRange(int low, int high)
{
	if(low > high)
	{
    yyerror("Error: low value is greater than high value for set");
		return false;
	}
  rangeLow = low;
	rangeHigh = high;
	return true;
}


// setRange
// Sets low and high range values of set
bool SetHelper::setRange(const string& low, const string& high)
{
	if (low.length() != 1) {
    ostringstream oss("Error: invalid size for range lower bound "); oss << low << " given for set ";
    yyerror(oss.str().c_str());
    return false;
  }
  if (high.length() != 1) {
    ostringstream oss("Error: invalid size for range high bound "); oss << high << " given for set ";
    yyerror(oss.str().c_str());
    return false;
  }
  return setRange(low[0], high[0]);
}


// sendToSt
// Creates a set object and sends to ST
IdentRecord* SetHelper::sendToSt(STObject* st)
{	
  //FIXME: need to call validate, need to define validate. validate must call base class's validate. Reference ArrayHelper for more info

	IdentRecord* setRecord = new SetType(typeName);
	SetType* setRecordTemp = static_cast<SetType*>(setRecord);
	setRecordTemp->setRange(rangeLow, rangeHigh);
	setRecordTemp = NULL;
  setRecord = st->insert(setRecord, settype);
	if (setRecord == NULL) {
    ostringstream oss("Error: Failed to insert set into ST "); oss << typeName;
    yyerror(oss.str().c_str());
	}

	return setRecord;
}

