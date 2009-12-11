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
	bool setCurrentFieldType(IdentRecord* type);
	bool addFields(STObject*);
	IdentRecord* sendToSt(STObject*);
	vector<RecordField*>* getRecordFields() {return &fields;}
	string getTypeName() {return typeName;}

private:
	vector<string> currentFieldNames;
	IdentRecord* currentFieldType;
	vector<RecordField*> fields;
	void clearCurrentFieldNames();
};
#endif
