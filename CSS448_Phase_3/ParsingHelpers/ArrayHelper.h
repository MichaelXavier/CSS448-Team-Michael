#define ARRAYHELPER_H
#ifndef ARRAYHELPER_H
#include <iostream>
#include <queue>
#include <string>
#include "TypeHelper.h"
#include "IdType.h"
#include "../IdentRecords/ArrayType.h"

using namespace std;

class ArrayHelper : public TypeHelper {
public:
  ArrayHelper(const string& type_name);
  ~ArrayHelper();

  struct Range {
    int low;
    int high;
  }

  bool addDimension(int low; int high);

	bool setTypePtr(IdentRecord* type);

  bool sendToSt(STObject* st);

private:
  queue<Range*> ranges;

  bool validate(void);

  IdentRecord* typePtr;
};

#endif
