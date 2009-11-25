#ifndef RECORDHELPER_H
#define RECORDHELPER_H

#include <iostream>
#include <vector>
#include <string>
#include "../IdType.h"
#include "../IdentTypes/RecordType.h"
#include "TypeHelper.h"

class RecordHelper : public TypeHelper
{
public:
	RecordHelper(const string&);
	~RecordHelper();

	bool addFieldName(const string&);
	bool setCurrentFieldType(const string&);
	bool addFields(STObject*);
	
	bool sendToSt(STObject*);

private:

	vector<string> currentFieldNames;
	string currentFieldType;

	vector<RecordField*> fields;

	void clearCurrentFieldNames();
};

#endif
