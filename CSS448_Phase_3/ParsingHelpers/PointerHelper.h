#ifndef POINTERHELPER_H
#define POINTERHELPER_H

#include <iostream>
#include <queue>
#include <string>
#include "TypeHelper.h"
#include "../IdentTypes/ArrayType.h"
using namespace std;
class PointerHelper : public TypeHelper {
public:
  PointerHelper(const string& type_name);
  ~PointerHelper();

  bool setTypePtr(IdentRecord* type);
  bool setDeclaredType(const string& str);
  bool sendToSt(STObject* st);

  string getDeclaredType(void)const { return declared_type; }
  string getName() {return typeName;}
private:
  bool validate(void);
  string declared_type;
  IdentRecord* typePtr;
};
#endif
