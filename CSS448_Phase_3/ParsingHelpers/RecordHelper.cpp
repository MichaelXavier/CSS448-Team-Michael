#include "RecordHelper.h"


RecordHelper::RecordHelper(const string& type_name) : TypeHelper(type_name)
{
}


RecordHelper::~RecordHelper()
{
	currentFieldType = NULL;
}


bool RecordHelper::addFieldName(const string& str)
{
	currentFieldNames->push_back(str);
}


bool RecordHelper::setCurrentFieldType(const string& name)
{
	currentFieldType = name;
}


bool RecordHelper::addFields(STObject* st)
{
	IdentRecord fieldType = st->lookup(currentFieldType);

	if(fieldType == NULL)
	{
		// cout not find type, error handling
	}
	else
	{
		IdentRecord* fieldRecord;
		for(int i = 0; i < currentFieldNames.size(); i++)
		{
			fieldRecord = new RecordField(currentFieldNames[i]);
			fieldRecord->SetType(fieldType);
			fields.push_back(fieldRecord);
		}
		clearCurrentFields(); // Clears list of fields so fields with a new type
							  // can be added
	}
}
	

bool RecordHelper::sendToST(STObject* st)
{
	IdentRecord* record = new RecordType(typeName);
	for(int i = 0; i < fields.size(); i++)
	{
		bool fieldWasAdded = record->insertField(fields[i]);
		if(fieldWasAdded == false)
		{
			// error handling
		}
	}

	bool addedToST = st.insert(record);
	if(addedToST == false)
	{
		// error handling
	}
	return true;
}


void RecordHelper::clearCurrentFieldNames()
{
	currentFieldNames.clear();
	currentFieldType = "";
}