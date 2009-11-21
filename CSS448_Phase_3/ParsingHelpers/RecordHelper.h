#define RECORDHELPER_H
#ifndef RECORDHELPER_H

#include <iostream>
#include <vector>
#include <string>
#include "IdType.h"
#include "../IdentRecords/RecordType.h"

class RecordHelper : TypeHelper
{
public:
	RecordHelper(const string&);
	~RecordHelper();

	bool addFieldName(const string&);
	bool setCurrentFieldType(const string&);
	bool addFields(STObject*);
	
	bool sendToST(STObject*);

private:

	vector<string> currentFieldNames;
	string currentFieldType;

	vector<IdentRecord*> fields;

	void clearCurrentFields();
}

#endif
