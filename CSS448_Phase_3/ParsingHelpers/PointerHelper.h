#define POINTERHELPER_H
#ifndef POINTERHELPER_H
#include <iostream>
#include <queue>
#include <string>
#include "TypeHelper.h"
#include "../IdentRecords/ArrayType.h"

using namespace std;

class PointerHelper : public TypeHelper {
public:
  PointerHelper(const string& type_name);
  ~PointerHelper();

	bool setTypePtr(IdentRecord* type);

  bool setDeclaredType(const string& str);

  bool sendToSt(STObject* st);

  string& getDeclaredType(void)const { return declared_type; }

private:
  queue<Range*> ranges;

  bool validate(void);

  string declared_type;

  IdentRecord* typePtr;
};

#endif
