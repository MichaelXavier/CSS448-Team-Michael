#include "PointerHelper.h"


PointerHelper::PointerHelper(const string& type_name) : TypeHelper(type_name) {
  typePtr = NULL;
  declared_type = "";
}


PointerHelper::~PointerHelper() { 
}

bool PointerHelper::setTypePtr(IdentRecord* type) {
  if (typePtr != NULL) {
    clean = false;
    cout << "Error: typePtr already set." << endl;
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

bool PointerHelper::setDeclaredType(const string& declared) {
  if (declared_type.length() != 0) {
    clean = false;
    cout << "Error: declared_type already set." << endl;
    return false;
  } else if (declared.length() == 0) {
    clean = false;
    cout << "Error: cannot set empty declared_type." << endl;
    return false;
  } else {
    declared_type = declared;
    return true;
  }
}

bool PointerHelper::sendToSt(STObject* st) {
  if (!validate()) {
    return false;
  }

  PointerType* ptr = new PointerType(typeName, declared_type);
  
  ptr->setPointObj(typePtr);

  if (st->insert(ptr, pointertype)) {
    return true;
  } else {
    delete ptr;
    return false;
  }
}

bool PointerHelper::validate(void) {
  TypeHelper::validate();
  if (typePtr == NULL) {
    clean = false;
    cout << "Error: NULL typePtr for pointer type " << typeName << endl;
  }
  if (declared_type.length()) {
    clean = false;
    cout << "Error: empty declared type for " << typeName << endl;
  }
  return clean;
}

