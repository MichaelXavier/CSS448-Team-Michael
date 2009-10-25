#ifndef STOBJECT_H
#define STOBJECT_H
#include <iostream>
#include <vector>
#include "IdentTypes/IdentRecord.h"
#include "IdentTypes/ArrayType.h"
#include "IdentTypes/BooleanType.h"
#include "IdentTypes/CharacterType.h"
#include "IdentTypes/Constant.h"
#include "IdentTypes/Function.h"
#include "IdentTypes/IdentRecord.h"
#include "IdentTypes/IntegerType.h"
#include "IdentTypes/Parameter.h"
#include "IdentTypes/PointerType.h"
#include "IdentTypes/Procedure.h"
#include "IdentTypes/RealType.h"
#include "IdentTypes/RecordField.h"
#include "IdentTypes/RecordType.h"
#include "IdentTypes/SetType.h"
#include "IdentTypes/Variable.h"

enum IdType {arraytype, pointertype, recordtype, settype,
             constant, variable, procedure, function, recordfield, parameter};

class STObject {
public:
  STObject(void);
  bool insert(IdentRecord*, IdType);//FIXME: not sure if union is an int??
  void printST(void) const;//FIXME: not sure if const, it calls scopexit which may modify internal state

private:
  ScopeNode* currentScope;

  vector<IdentRecord*> identTable;

  void fillIdentTable(void);

  void scopeEntry(void);//FIXME: args and return type
  void scopeExit(void);//FIXME: args and return type

};
#endif
