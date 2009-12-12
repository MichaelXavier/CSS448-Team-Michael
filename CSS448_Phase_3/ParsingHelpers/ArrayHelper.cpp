#include "ArrayHelper.h"
ArrayHelper::ArrayHelper(const string& type_name) : TypeHelper(type_name) {
  typePtr = NULL;
}
ArrayHelper::~ArrayHelper() {
	for(int i = 0; i < ranges.size(); i++) {
		delete ranges[i];
		ranges[i] = NULL;
	}
	ranges.clear();
}

vector<int>* ArrayHelper::getRangeValues()
{
	vector<int>* q = new vector<int>();
	for(int i = 0; i < ranges.size(); i++)
	{
		q->push_back(ranges[i]->high - ranges[i]->low);
	}
	return q;
}

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
IdentRecord* ArrayHelper::sendToSt(STObject* st) {
  if (!validate()) {
    return false;
  }

  IdentRecord* arr = new ArrayType(typeName);
  ArrayType* arr_temp = static_cast<ArrayType*>(arr);
 

  //Add dimensions
  for(int i = 0; i < ranges.size(); i++) {
	  Range* range = ranges[i];
	  if(range != NULL) {
		arr_temp->addDimension(range->low, range->high);
	  }
  }

  arr_temp->setTypePtr(typePtr);

  if (st->insert(arr, arraytype) != NULL) {
    return arr;
  } else {
    delete arr;
    return NULL;
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

