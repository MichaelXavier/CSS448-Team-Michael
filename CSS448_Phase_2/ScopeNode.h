#ifndef STOBJECT_H
#define STOBJECT_H
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "IdentTypes/IdentRecord.h"

using namespace std;

class ScopeNode {
public:
  ScopeNode(void);
  ~ScopeNode(void);
  bool recordExists(const IdentRecord*)const;
  void insertScope(ScopeNode*);
  void insertRecord(IdentRecord*);

  ScopeNode* getParent(void) { return parent; };//called on scope exit by th ST
private:
  //Base scope-creating IdentRecord which encompasses this scope
  //Would presumably be either a function on procedure, can be NULL for a toplevel
  //scope
  IdentRecord* scopeRoot;
  //TODO: figure out how to handle nested procedures which are not allowed in C++
  ScopeNode* parentScope;
  vector<ScopeNode*> childScopes;
  map<string, IdentRecord*> records;
}
