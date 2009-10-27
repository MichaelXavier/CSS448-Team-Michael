#ifndef STOBJECT_H
#define STOBJECT_H
#include <iostream>
#include <vector>
#include "../IdType"
#include "ScopeNode"
#include "IdentTypes/IdentRecord"
#include "IdentTypes/ArrayType"
#include "IdentTypes/BooleanType"
#include "IdentTypes/CharacterType"
#include "IdentTypes/Constant"
#include "IdentTypes/Function"
#include "IdentTypes/IdentRecord"
#include "IdentTypes/IntegerType"
#include "IdentTypes/Parameter"
#include "IdentTypes/PointerType"
#include "IdentTypes/Procedure"
#include "IdentTypes/RealType"
#include "IdentTypes/RecordField"
#include "IdentTypes/RecordType"
#include "IdentTypes/SetType"
#include "IdentTypes/Variable"

class STObject {

public:
  STObject(void);
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
