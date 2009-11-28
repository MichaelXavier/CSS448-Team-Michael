#include "ArrayHelper.h"
ArrayHelper::ArrayHelper(const string& type_name) : TypeHelper(type_name) {
  typePtr = NULL;
}
ArrayHelper::~ArrayHelper() {
  while (!ranges.empty()) {
    Range* tempRange = ranges.front();
	delete tempRange;
	tempRange = NULL;
    ranges.pop();
    }
}
bool ArrayHelper::addDimension(int low, int high) {
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

bool ArrayHelper::addDimension(const string& low, const string& high) {
  if (low.length() != 1) {
    cout << "Error: invalid size for range lower bound " << low << " given for array " << typeName << endl;
    return false;
  }
  if (high.length() != 1) {
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
    cout << "DEBUG: type successfully set for " << typeName << endl;
    typePtr = type;
    return true;
  }
}
bool ArrayHelper::sendToSt(STObject* st) {
  if (!validate()) {
    return false;
  }

  IdentRecord* arr = new ArrayType(typeName);
  ArrayType* arr_temp = static_cast<ArrayType*>(arr);
  
  //Add dimensions
  while (!ranges.empty()) {
    Range* range = ranges.front();
    if (range != NULL) { 
      arr_temp->addDimension(range->low, range->high);
	  delete range;
	  range = NULL;
      ranges.pop();
    }
  }
  arr_temp->setTypePtr(typePtr);

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
    cout << "Error: NULL typePtr for array type " << typeName << endl;
  }
  //TODO: more validations
  return clean;
}

