// FunctionHelper.h
// This class is used for storing information about Function objects from 'y' and
// eventually creating the Function object and adding it to the symbol table.
// Helper objects are also used for code generation.

#ifndef FUNCTIONHELPER_H
#define FUNCTIONHELPER_H
#include <iostream>
#include <queue>
#include <string>
#include "TypeHelper.h"
#include "../IdentTypes/Function.h"

using namespace std;

class FunctionHelper : public TypeHelper {
public:
  FunctionHelper(const string& type_name);  // Constructor
  ~FunctionHelper();   // Destructor
  bool AddParameters(queue<Parameter*> params); // Adds parameters to function
  bool AddParameter(Parameter* param); // Adds a parameter to the function
  bool SetReturnType(IdentRecord* ret) {returnType = ret;} // Sets function return type
  IdentRecord* sendToSt(STObject* st); // Creates function object and sends it to  the symbol table

  queue<Parameter*> getParams(void) { return params; } // Gets the parameter queue
  IdentRecord* getReturnType(void) { return returnType; } // Gets the function return type
  Function* getFunctPtr(void) { return funct_ptr; } // Returns a pointer to created function object

private:
  queue<Parameter*> params; // Queue of function parameters
  IdentRecord* returnType; // Function return type
  Function* funct_ptr;  // Points to created function object
};
#endif
