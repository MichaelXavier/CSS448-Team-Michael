#include "ConstDecHelper.h"

// Constructor
ConstDecHelper::ConstDecHelper(void) {
  clean = true;
}


// Destructor
ConstDecHelper::~ConstDecHelper(void) { 
}


// setConstName
// Sets name of constant object
bool ConstDecHelper::setConstName(string name) {
	constName = name;
}
// setConstObj
//Makes a copy of parameter Constant object and stores it
void ConstDecHelper::setConstObj(Constant* obj)
{
  constObj = new Constant(constName);
  Constant* ptr = static_cast<Constant*>(constObj);
  string constType = obj->getConstType();
  if(constType == "s") {
    ptr->setConstFactor(obj->getConstString());
  } else if(constType == "b") {
    ptr->setConstFactor(obj->getConstBool());
  } else if(constType == "i") { 
    ptr->setConstFactor(obj->getConstInt());
  }
}

// sendToSt
// Sends the stored Constant object to the symbol table
IdentRecord* ConstDecHelper::sendToSt(STObject* st) {
  if (!validate()) {
    return NULL;
  }

  return st->insert(constObj, constant);
}


// validate
// Error checking
bool ConstDecHelper::validate(void) {
  return clean;
}

