#include "RecordHelper.h"


RecordHelper::RecordHelper(const string& type_name) : TypeHelper(type_name)
{
}


RecordHelper::~RecordHelper()
{
}


bool RecordHelper::addFieldName(const string& str)
{
	currentFieldNames.push_back(str);
}


bool RecordHelper::setCurrentFieldType(IdentRecord* type)
{
	currentFieldType = type;
}


bool RecordHelper::addFields(STObject* st)
{
		RecordField* fieldRecord;
		for(int i = 0; i < currentFieldNames.size(); i++)
		{
			fieldRecord = new RecordField(currentFieldNames[i]);
			fieldRecord->setTypePtr(currentFieldType);
			fields.push_back(fieldRecord);
		}
		clearCurrentFieldNames(); // Clears list of fields so fields with a new type
							  // can be added
}
	

bool RecordHelper::sendToSt(STObject* st)
{
	IdentRecord* record = new RecordType(typeName);
	RecordType* record_temp = static_cast<RecordType*>(record);
	for(int i = 0; i < fields.size(); i++)
	{
		bool fieldWasAdded = record_temp->insertField(fields[i]);
		if(fieldWasAdded == false)
		{
			// error handling
		}
	}

	bool addedToST = st->insert(record, recordtype);
	if(addedToST == false)
	{
		// error handling
	}
	return true;
}


void RecordHelper::clearCurrentFieldNames()
{
	currentFieldNames.clear();
	currentFieldType = NULL;
}

