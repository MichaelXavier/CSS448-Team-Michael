#ifndef RECORDTYPE_H
#define RECORDTYPE_H
#include <iostream>
#include "IdentRecord.h"
#include "../STObject.h"

using namespace std;

class RecordType : public IdentRecord {

public:
	RecordType(const string& name);
	~RecordType();

	void display(ostream& sout, int depth)const;
	void insertField(IdentRecord*, IdType);

private:
  vector<RecordField*> members;
};
#endif
