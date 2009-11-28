#include "TypeHelper.h"

TypeHelper::TypeHelper(const string& type_name) {
  typeName = type_name;
  clean = (typeName.length() > 0);
}
TypeHelper::~TypeHelper(void) {
  //nothing to do here
}
bool TypeHelper::validate(void) {
  if (typeName.length() == 0) {
    clean = false;
    cout << "Error: empty TypeName." << endl;
  }
  return clean;
}
