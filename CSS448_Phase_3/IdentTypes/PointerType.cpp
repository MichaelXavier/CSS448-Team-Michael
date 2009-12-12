#include "PointerType.h"


// Constructor
PointerType::PointerType(const string& name, const string& declared) : IdentRecord(name) {
  declared_type = declared;
  instanceName = "PointerType";
}

// Destructor
PointerType::~PointerType(void) {
}


// display
// Prints data
void PointerType::display(ostream& sout, int depth)const {
  if (typePtr == NULL) {
    // typePtr must be set in order to print data
    ostringstream oss("Error: typePtr of "); oss << identName << " not set";
    yyerror(oss.str().c_str());
    return;
  }
  printIndent(sout, depth);
  sout << identName << " ^ " << typePtr->getName();
}


// setPointObj
// Sets typePtr and checks if obj's identifier matches declared_type
void PointerType::setPointObj(IdentRecord* obj) {
  if (obj == NULL) {
    yyerror("Warning: setting the  pointer target of a PointerType to NULL");
    typePtr = NULL;
  } else if (obj->getName() != declared_type) {
    yyerror("Error: pointObj identifier name does not match the declared name");
  } else {
    typePtr = obj;
  }
}
