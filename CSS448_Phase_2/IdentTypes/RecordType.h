#ifndef RECORDTYPE_H
#define RECORDTYPE_H
#include <iostream>
#include "IdentRecord.h"
#include "STObject.h"

using namespace std;

class RecordType : public IdentRecord {

public:
	RecordType(string);
	~RecordType();

	void display();
	void insertField(IdentRecord*, IdType);

private:

	// possibly a list of record fields
};
#endif
