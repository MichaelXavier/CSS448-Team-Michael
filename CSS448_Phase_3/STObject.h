// STObject.h
// The symbol table.  Contains scope nodes and a standard identifier table.

#ifndef STOBJECT_H
#define STOBJECT_H
#include <iostream>
#include <vector>
#include "IdType.h"
#include "ScopeNode.h"
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

using namespace std;

extern void yyerror(const char *s);

class STObject {

public:
  STObject(Program* root);
  ~STObject(void);

  IdentRecord* insert(IdentRecord*, IdType); // Inserts a new IdentRecord into ST
  void printST(void);	// Prints symbol table
  void closeAllScopes(void);

  // Loops up a name in the ST or SIT and returns a pointer to the IdentRecord
  IdentRecord* lookup(const string& name);  

  void scopeExit(void);	 // Exits current scope

private:
  ScopeNode* rootScope;		// Pointer to root scope 
  ScopeNode* currentScope;	// Pointer to current scope node
  int currentScopeNumber;   // The current scope number
  vector<IdentRecord*> identTable; // The standard identifier table (SIT)

  void fillIdentTable(void);	   // Function for filling the SIT
  bool scopeEntry(IdentRecord*, IdType); // Function for creating new scope
};
#endif

