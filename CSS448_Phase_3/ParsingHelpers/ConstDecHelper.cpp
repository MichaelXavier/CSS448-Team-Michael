#include "ConstDecHelper.h"
/*FIXME: don't need a string constructor */
ConstDecHelper::ConstDecHelper(void) {// : TypeHelper(type_name) { 
  clean = true;
}
ConstDecHelper::~ConstDecHelper(void) {
  //TODO  
}

bool ConstDecHelper::setConstName(string name) {
	constName = name;
}void ConstDecHelper::setConstObj(Constant* obj){	constObj = new Constant(constName);	Constant* ptr = static_cast<Constant*>(constObj);	string constType = obj->getConstType();	if(constType == "s")		ptr->setConstFactor(obj->getConstString());	else if(constType == "b")		ptr->setConstFactor(obj->getConstBool());	else if(constType == "i")		ptr->setConstFactor(obj->getConstInt());}
IdentRecord* ConstDecHelper::sendToSt(STObject* st) {
  if (!validate()) {
    return NULL;
  }

  return st->insert(constObj, constant);
}

bool ConstDecHelper::validate(void) {
  return clean;
}

