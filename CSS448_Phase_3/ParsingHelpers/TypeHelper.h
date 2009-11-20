#define TYPEHELPER_H
#ifndef TYPEHELPER_H
#include <iostream>
#include <string>
#include "../STObject.h"

using namespace std;

class TypeHelper {
public: 

  TypeHelper(const string& type_name);
  virtual ~TypeHelper(void);

  bool isClean(void)const { return clean; }

  virtual bool sendToSt(STObject* st) = 0;

private:

  string typeName;
  bool clean;

};

#endif
