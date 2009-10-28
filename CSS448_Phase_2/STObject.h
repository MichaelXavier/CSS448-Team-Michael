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
#include "IdentTypes/Program.h"
#include "IdentTypes/RealType.h"
#include "IdentTypes/RecordField.h"
#include "IdentTypes/RecordType.h"
#include "IdentTypes/SetType.h"
#include "IdentTypes/Variable.h"
#include "IdType.h"
#include "ScopeNode.h"

using namespace std;

class STObject {

public:
  //Constructor requires a program pointer to act as the root scope
  STObject(Program* root);
  bool insert(IdentRecord*, IdType); // Inserts a new IdentRecord into ST
  void printST(void);	// Prints symbol table

  IdentRecord* lookup(const string& name);

private:
  ScopeNode* rootScope;		// Pointer to root scope 
  ScopeNode* currentScope;	// Pointer to current scope node
  int currentScopeNumber;   // The current scope number
  vector<IdentRecord*> identTable; // The standard identifier table (SIT)

  void fillIdentTable(void);	   // Function for filling the SIT
  bool scopeEntry(IdentRecord*, IdType); // Function for creating new scope
  void scopeExit(void);	 // Exits current scope
};
#endif
