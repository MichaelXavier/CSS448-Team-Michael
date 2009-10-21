#ifndef STOBJECT_H
#define STOBJECT_H
#include <iostream>
#include "IdentRecord.h"

enum IdType {arraytype, pointertype, recordtype, settype,
             constant, variable, procedure, function, recordfield, parameter};

class STObject {

public:
  bool insert(IdentRecord*, IdType);//FIXME: not sure if union is an int??
  void printST(void) const;//FIXME: not sure if const, it calls scopexit which may modify internal state

private:
  void scopeEntry(void);//FIXME: args and return type
  void scopeExit(void);//FIXME: args and return type

};
#endif
