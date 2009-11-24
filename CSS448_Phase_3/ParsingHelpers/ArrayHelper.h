#define ARRAYHELPER_H
#ifndef ARRAYHELPER_H
#include <iostream>
#include <queue>
#include <string>
#include "TypeHelper.h"
#include "../IdentRecords/ArrayType.h"

using namespace std;

class ArrayHelper : public TypeHelper {
public:
  ArrayHelper(const string& type_name);
  ~ArrayHelper();

  bool addDimension(int low; int high);

	bool setTypePtr(IdentRecord* type);

  bool sendToSt(STObject* st);

private:
  queue<Range*> ranges;

  struct Range {
    int low;
    int high;
  }

  bool validate(void);

  IdentRecord* typePtr;
};

#endif
