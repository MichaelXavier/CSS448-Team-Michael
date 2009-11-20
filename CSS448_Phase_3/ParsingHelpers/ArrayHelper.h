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

  struct Range {
    int lower;
    int upper;
  }

  bool addRange(int lower; int upper);

  bool sendToSt(STObject* st);

private:
  queue<Range*> ranges;
};

#endif
