#include "TypeHelper.h"


// Constructor
// The name of object that will be created is set
TypeHelper::TypeHelper(const string& type_name) {
  typeName = type_name;
  clean = (typeName.length() > 0);
}


// Destructor 
TypeHelper::~TypeHelper(void) {
}


// validate
// Error checking.  Makes sure object's name is set
bool TypeHelper::validate(void) {
  if (typeName.length() == 0) {
    clean = false;
    yyerror("Error: empty TypeName.");
  }
  return clean;
}
