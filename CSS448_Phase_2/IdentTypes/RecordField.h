#ifndef RECORDFIELD_H
#define RECORDFIELD_H
#include <iostream>
#include "IdentRecord.h"

using namespace std;

class RecordField : public IdentRecord {
public:
	RecordField(string);
	~RecordField();

	void display();					 // Displays data
	void setTypePtr(IdentRecord* ptr) {typePtr = ptr;}

private:
	IdentRecord* typePtr;

};
#endif
