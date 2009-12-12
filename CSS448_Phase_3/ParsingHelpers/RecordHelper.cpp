#include "RecordHelper.h"


// Constructor
RecordHelper::RecordHelper(const string& type_name) : TypeHelper(type_name)
{
}


// Destructor
RecordHelper::~RecordHelper()
{
}


// addFieldName
// Adds a field name
bool RecordHelper::addFieldName(const string& str)
{
	currentFieldNames.push_back(str);
}


// setCurrentFieldType
// Sets current field type
bool RecordHelper::setCurrentFieldType(IdentRecord* type)
{
	currentFieldType = type;
}


// addFields
// Adds fields to field vector
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


// sendToSt
// Creates a record object and sends to ST
IdentRecord* RecordHelper::sendToSt(STObject* st)
{
	IdentRecord* record = new RecordType(typeName);
	RecordType* record_temp = static_cast<RecordType*>(record);
	
	// Adds fields to record object
	for(int i = 0; i < fields.size(); i++)
	{
		if (!record_temp->insertField(fields[i])) {
      ostringstream oss; oss << "Error: Failed to insert field on record " << typeName;
      yyerror(oss.str().c_str());
      return NULL;
		}
	}
	// Sends record object to ST
	if (!st->insert(record, recordtype)) {
      ostringstream oss; oss << "Error: Failed to insert record to ST with name " << typeName;
      yyerror(oss.str().c_str());
      return NULL;
	}

	return record;
}


// clearCurrentFieldNames
// Clears the current field names
void RecordHelper::clearCurrentFieldNames()
{
	currentFieldNames.clear();
	currentFieldType = NULL;
}
