#include "ArrayHelper.h"

// Constructor
ArrayHelper::ArrayHelper(const string& type_name) : TypeHelper(type_name) {
  typePtr = NULL;
}


// Destructor
// Deletes vector of ranges
ArrayHelper::~ArrayHelper() {
	for(int i = 0; i < ranges.size(); i++) {
		delete ranges[i];
		ranges[i] = NULL;
	}
	ranges.clear();
}


// getRangeValues
// Returns a vector of dimension range values (high - low)
vector<int>* ArrayHelper::getRangeValues()
{
	vector<int>* q = new vector<int>();
	for(int i = 0; i < ranges.size(); i++)
	{
		q->push_back(ranges[i]->high - ranges[i]->low);
	}
	return q;
}


// addDimension
// Adds a dimension to the array
bool ArrayHelper::addDimension(int low, int high) {
  if (!clean) { return false; }
  //Do not allow a range that goes in reverse
  if (low < high) {
    Range* range = new Range; 
    range->low = low;
    range->high = high;
    ranges.push_back(range);
  } else {
    clean = false; 
    cout << "Error: low range bound greater than higher range bound." << endl;
    return false;
  }
}


// addDimension
// Adds a dimension to the array.  Takes string parameters, makes sure that strings correspond to a character.
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


// setTypePtr
// Sets the type pointer of the array
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

// sentToSt
// Creates an ArrayType object from stored data and adds the object to the symbol table.
IdentRecord* ArrayHelper::sendToSt(STObject* st) {
  if (!validate()) {
    return false;
  }

  // Creates an ArrayType object
  IdentRecord* arr = new ArrayType(typeName);
  ArrayType* arr_temp = static_cast<ArrayType*>(arr);
 

  //Add dimensions
  for(int i = 0; i < ranges.size(); i++) {
	  Range* range = ranges[i];
	  if(range != NULL) {
		arr_temp->addDimension(range->low, range->high);
	  }
  }

  // Sets type pointer of ArrayType object
  arr_temp->setTypePtr(typePtr);

  // ArrayType object is added to the symbol table
  if (st->insert(arr, arraytype) != NULL) {
    return arr;
  } else {
    delete arr;
    return NULL;
  }
}


// validate
// Error checking.  Makes sure type pointer of array is set.
bool ArrayHelper::validate(void) {
  TypeHelper::validate();
  if (typePtr == NULL) {
    clean = false;
    cout << "Error: NULL typePtr for array type " << typeName << endl;
  }
  //TODO: more validations
  return clean;
}

