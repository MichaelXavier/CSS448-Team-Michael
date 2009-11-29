#ifndef TYPEHELPER_H
#define TYPEHELPER_H
#include <iostream>
#include <string>
#include "../IdType.h"
#include "../STObject.h"
using namespace std;
class TypeHelper {
public: 
  TypeHelper(const string& type_name);
  virtual ~TypeHelper(void);

  bool isClean(void)const { return clean; }
  virtual IdentRecord* sendToSt(STObject* st) = 0;
protected:
  string typeName;
  bool clean;
  virtual bool validate(void);
};
#endif
