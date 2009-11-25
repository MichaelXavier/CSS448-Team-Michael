#include "ConstDecHelper.h"
ConstDecHelper::ConstDecHelper(const string& type_name) : TypeHelper(type_name) { 
  //TODO  
}

ConstDecHelper::~ConstDecHelper(void) {
  //TODO  
}

bool ConstDecHelper::addConst(Constant* val) {
  if (val != NULL) {
    consts.push_back(val);
  } else {
    cout << "Error: null Constant* given to ConstDecHelper " << typeName << endl;
  }
}

bool ConstDecHelper::sendToSt(STObject* st) {
  if (!validate()) {
    return false;
  }
  for (unsigned int i = 0; i < consts.size(); i++) {
    //If at any point there's a failure, stop, error and return false
    if (!st->insert(consts[i], constant)) {
      cout << "Error: failed to insert a constant " << consts[i]->getName() << "into ST inside ConstDecHelper " << typeName << " at vector index " << i << ". Aborting." << endl;
      return false;
    }
  }
  return false;
}

bool ConstDecHelper::validate(void) {
  TypeHelper::validate();
  //look for redefinitions with n^2 comparison
  Constant* cur;
  for(unsigned int i = 0; i < consts.size(); i++) {
    cur = consts[i];
    if (cur == NULL) {
      clean = false;
      cout << "NULL Constant* found in ConstDecHelper " << typeName << " at vector index " << i << endl;
      continue;
    }
    for(unsigned int j = 0; j < consts.size(); j++) {
      if (consts[j] != NULL && consts[i]->getName() == consts[j]->getName()) {
        clean = false;
        cout << "Error: Conflicting Constant declaration found with name " << consts[i] << " found in ConstDecHelper " << typeName << "at vector indices " << i << " and " << j << endl; 
      }
    }
  }
  return clean;
}

