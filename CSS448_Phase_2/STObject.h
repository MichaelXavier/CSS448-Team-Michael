#ifndef STOBJECT_H
#define STOBJECT_H
#include <iostream>
#include "IdentTypes/IdentRecord.h"

class STObject {
public:
  bool insert(IdentRecord*, IdType);//FIXME: don't know how to resolve the externally-defined enum type here

  void printST(void)const;//FIXME: not sure if const, it calls scopexit which may modify internal state
private:

  void scopeEnter(void);//FIXME: args and return type

  void scopeExit(void);//FIXME: args and return type
}
#endif
