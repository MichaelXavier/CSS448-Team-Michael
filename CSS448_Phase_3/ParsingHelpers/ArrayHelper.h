#ifndef ARRAYHELPER_H
#define ARRAYHELPER_H

#include <iostream>
#include <queue>
#include <string>
#include "TypeHelper.h"
#include "../IdentTypes/ArrayType.h"

using namespace std;

class ArrayHelper : public TypeHelper {
public:
  ArrayHelper(const string& type_name);
  ~ArrayHelper();

  bool addDimension(int low, int high);
  bool addDimension(const string& low, const string& high);

  bool setTypePtr(IdentRecord* type);

  bool sendToSt(STObject* st);

private:
  struct Range {
    int low;
    int high;
  };
  queue<Range*> ranges;

  bool validate(void);

  IdentRecord* typePtr;
};

#endif
