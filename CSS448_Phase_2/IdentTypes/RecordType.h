#ifndef RECORDTYPE_H
#define RECORDTYPE_H
#include <iostream>
#include <vector>
#include "IdentRecord.h"
#include "RecordField.h"

using namespace std;

class RecordType : public IdentRecord {

public:
	RecordType(const string& name);
	~RecordType();

	void display(ostream& sout, int depth)const;
	bool insertField(RecordField* field);	// Add a field to record's list
											// of fields

	// Checks for conflicting fields
	bool hasConflictingFields(const IdentRecord* field) const;

private:
  vector<RecordField*> members;  // List of RecordFields stored in this record
};
#endif
