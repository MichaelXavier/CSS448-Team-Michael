// RecordHelper.h
// This class is used for storing information about RecordType objects from 'y' and
// eventually creating the RecordType object and adding it to the symbol table.
// Note: Lists of field names of fields declared on the same line, with the same type,
// are stored in currentFieldNames.  The type is set in currentFieldType.  
// Then, the fields are created with the current type and are added to the fields vector.
// Then, the currentFieldNames and currentFieldType are reset for the next line of fields.
// Helper objects are also used for code generation.

#ifndef RECORDHELPER_H
#define RECORDHELPER_H
#include <iostream>
#include <vector>
#include <string>
#include "../IdType.h"
#include "../IdentTypes/RecordType.h"
#include "TypeHelper.h"

extern void yyerror(const char *s);

class RecordHelper : public TypeHelper
{
public:
	RecordHelper(const string&);	// Constructor
	~RecordHelper();   // Destructor
	bool addFieldName(const string&);  // Adds a field name
	bool setCurrentFieldType(IdentRecord* type);  // Sets current field type
	bool addFields(STObject*);  // Adds fields to field vector
	IdentRecord* sendToSt(STObject*); // Creates a record object and sends to ST
	vector<RecordField*>* getRecordFields() {return &fields;} // Gets vector of record fields
	string getTypeName() {return typeName;} // Gets the name of the record

private:
	vector<string> currentFieldNames; // List of field names having the same type
	IdentRecord* currentFieldType;  // Stores the type for current list of fields
	vector<RecordField*> fields;  // List of field objects added to record
	void clearCurrentFieldNames(); // Clears the current field names
};
#endif
