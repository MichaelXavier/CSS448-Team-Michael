#include "PointerHelper.h"

// Constructor
PointerHelper::PointerHelper(const string& type_name) : TypeHelper(type_name) {
  typePtr = NULL;
  declared_type = "";
}


// Destructor
PointerHelper::~PointerHelper() { 
}


// setTypePtr
// Sets type pointer.  The type pointer can't be set to NULL using
// this function and the type pointer can only be set if it is currently NULL
bool PointerHelper::setTypePtr(IdentRecord* type) {
  if (typePtr != NULL) {
    clean = false;
    yyerror("Error: typePtr already set.");
    return false;
  } else if (type == NULL) {
    clean = false;
    yyerror("Error: cannot set NULL typePtr.");
    return false;
  } else {
    typePtr = type;
    return true;
  }
}


// setDeclaredType
// Sets the declared type of the pointer.  The declared type can't be set to
// and empty string and can be set only once.
bool PointerHelper::setDeclaredType(const string& declared) {
  if (declared_type.length() != 0) {
    clean = false;
    yyerror("Error: declared_type already set.");
    return false;
  } else if (declared.length() == 0) {
    clean = false;
    yyerror("Error: cannot set empty declared_type.");
    return false;
  } else {
	  declared_type = declared;
    return true;
  }
}


// sendToSt
// Creates pointer object and sends it to the symbol table
IdentRecord* PointerHelper::sendToSt(STObject* st) {
  if (!validate()) {
    return NULL;
  }
  PointerType* ptr = new PointerType(typeName, declared_type);
  ptr->setPointObj(typePtr);

  if (st->insert(ptr, pointertype) != NULL) {
    return ptr;
  } else {
    delete ptr;
    return NULL;
  }
}


// validate
// Error checking.  Makes sure declared type is set and writes a warning if
// the typePtr is NULL
bool PointerHelper::validate(void) {
  TypeHelper::validate();
  if (typePtr == NULL) {
    clean = true;
    ostringstream oss; oss << "Warning: NULL typePtr for pointer type " << typeName;
    yyerror(oss.str().c_str());
  }
  if (declared_type.length() == 0) {
    clean = false;
    ostringstream oss; oss << "Error: empty declared type for " << typeName;
    yyerror(oss.str().c_str());
  }

  return clean;
}

