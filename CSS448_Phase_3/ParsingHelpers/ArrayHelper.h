// ArrayHelper.h
// This class is used for storing information about ArrayType objects from 'y' and
// eventually creating the ArrayType object and adding it to the symbol table.
// Helper objects are also used for code generation.

#ifndef ARRAYHELPER_H
#define ARRAYHELPER_H

#include <iostream>
#include <vector>
#include <string>
#include "TypeHelper.h"
#include "../IdentTypes/ArrayType.h"

using namespace std;

class ArrayHelper : public TypeHelper {
public:
  ArrayHelper(const string& type_name); // Constructor
  ~ArrayHelper();		// Destructor

  bool addDimension(int low, int high); // Adds a dimension to the array
  bool addDimension(const string& low, const string& high); // Adds a dimension to the array

  bool setTypePtr(IdentRecord* type); // Sets the type pointer of the array

  // Creates an ArrayType object and sends it to the symbol table.
  IdentRecord* sendToSt(STObject* st);

  // Returns a vector of dimension range values (high - low)
  vector<int>* getRangeValues();

  string getName() { return typeName; } // Gets name of ArrayType object name linked to ArrayHelper
  IdentRecord* getType() { return typePtr; } // Gets the type of ArrayType

private:
	// Struct that holds range values
  struct Range {
    int low;
    int high;
  };

  // Vector containing range values for each dimension
  vector<Range*> ranges;

  // Error handling
  bool validate(void);

  // The type of array
  IdentRecord* typePtr;
};

#endif

