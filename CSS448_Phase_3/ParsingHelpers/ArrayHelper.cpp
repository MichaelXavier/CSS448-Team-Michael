#include "ArrayHelper.h"

ArrayHelper::ArrayHelper(const string& type_name) : TypeHelper(type_name) {
  typePtr = NULL;
}

ArrayHelper::~ArrayHelper(void) {
  while (!ranges.empty()) {
    Range* range = ranges.pop();
    if (range != NULL) { 
      delete range; 
    }
  }
}

bool ArrayHelper::addDimension(int low; int high) {
  if (!clean) { return false; }
  //Do not allow a range that goes in reverse
  if (low < high) {
    Range* range = new Range; 
    range->low = low;
    range->high = high;
    ranges.push(range);
  } else {
    clean = false; 
    cout << "Error: low range bound greater than higher range bound." << endl;
    return false;
  }
}

bool addDimension(const string& low; const string& high) {
  if (low.length() > 1 || low.length() <= 0) {
    cout << "Error: invalid size for range lower bound " << low << " given for array " << typeName << endl;
    return false;
  }
  if (high.length() > 1 || high.length() <= 0) {
    cout << "Error: invalid size for range high bound " << high << " given for array " << typeName << endl;
    return false;
  }
  return addDimension(low[0], high[0]);
}

bool ArrayHelper::setTypePtr(IdentRecord* type) {
  if (typePtr != NULL) {
    clean = false;
    cout << "Error: type already set." << endl;
    return false;
  } else if (type == NULL) {
    clean = false;
    cout << "Error: cannot set NULL typePtr." << endl;
    return false;
  } else {
    typePtr = type;
    return true;
  }
}

bool ArrayHelper::sendToSt(STObject* st) {
  if (!validate()) {
    return false;
  }

  ArrayType* arr = new ArrayType(typeName);
  //Add dimensions
  while (!ranges.empty()) {
    Range* range = ranges.pop();
    if (range != NULL) { 
      arr->addDimension(range->low, range->high);
      delete range; 
    }
  }
  
  arr->setTypePtr(typePtr);

  if (st->insert(arr, arraytype)) {
    return true;
  } else {
    delete arr;
    return false;
  }
}

bool ArrayHelper::validate(void) {
  TypeHelper::validate();
  if (typePtr == NULL) {
    clean = false;
    cout << "Error: cannot set NULL typePtr." << endl;
  }
  //TODO: more validations
  return clean;
}
