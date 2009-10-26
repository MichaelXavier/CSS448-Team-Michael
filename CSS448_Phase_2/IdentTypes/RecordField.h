#ifndef RECORDFIELD_H
#define RECORDFIELD_H
#include <iostream>
#include "IdentRecord.h"

using namespace std;

class RecordField : public IdentRecord {
public:
	RecordField(const string& name);
	~RecordField();

	void display(ostream& sout, int depth)const;					 // Displays data
	void setTypePtr(IdentRecord* ptr) {typePtr = ptr;}

private:
	IdentRecord* typePtr;

};
#endif
