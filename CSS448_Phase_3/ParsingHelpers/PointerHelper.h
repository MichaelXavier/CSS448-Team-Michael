// PointerHelper.h
// This class is used for storing information about PointerType objects from 'y' and
// eventually creating the PointerType object and adding it to the symbol table.
// Note: the type pointer of the pointer object is initially set to NULL and the
// pointer added to the symbol table.  string declared_type stores the name of the type
// the pointer will point to.  When the type is declared and the pointer is
// resolved, the typePtr is set to point to the type.
// Helper objects are also used for code generation.

#ifndef POINTERHELPER_H
#define POINTERHELPER_H

#include <iostream>
#include <queue>
#include <string>
#include "TypeHelper.h"
#include "../IdentTypes/ArrayType.h"

using namespace std;

extern void yyerror(const char *s);

class PointerHelper : public TypeHelper {
public:
  PointerHelper(const string& type_name);  // Constructor
  ~PointerHelper();						   // Destructor

  bool setTypePtr(IdentRecord* type);  // Sets type pointer
  bool setDeclaredType(const string& str); // Sets declared type
  IdentRecord* sendToSt(STObject* st); // Creates pointer object and sends it to the symbol table

  string getDeclaredType(void)const { return declared_type; } // Gets the declared type
  string getName() {return typeName;} // Gets name of pointer

private:
  bool validate(void);  // Error checking
  string declared_type;	// What pointer will point to
  IdentRecord* typePtr; // Type of object the pointer points to
};
#endif
