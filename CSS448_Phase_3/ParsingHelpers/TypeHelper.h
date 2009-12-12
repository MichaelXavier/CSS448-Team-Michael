// TypeHelper.h
// This is an abstract class that contains some of the functionality used
// in other helper objects.  Some of the helper objects inherit
// from the TypeHelper class.  string typeName refers to the name of the object
// that will be created by the helper object.

#ifndef TYPEHELPER_H
#define TYPEHELPER_H
#include <iostream>
#include <string>
#include "../IdType.h"
#include "../STObject.h"

using namespace std;

extern void yyerror(const char *s);

class TypeHelper {
public: 
  TypeHelper(const string& type_name); // Constructor
  virtual ~TypeHelper(void);	// Destructor

  bool isClean(void)const { return clean; } // Error checking

  // Creates object and sends to ST
  virtual IdentRecord* sendToSt(STObject* st) = 0;

protected:
  string typeName; // Name of object that will be created
  bool clean;
  virtual bool validate(void); // Error checking
};
#endif
