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
  ScopeNode(IdentRecord*, ScopeNode* parent = NULL, int depth = 0);
  ~ScopeNode(void);
  bool recordExists(const IdentRecord* other)const;
  void insertRecord(IdentRecord* other);
  void insertScope(ScopeNode* new_scope);

  ScopeNode* getParent(void) { return parent; };//called on scope exit by th ST

  int getDepth(void)const { return scopeDepth; }
private:
  int scopeDepth = 0;
  //Base scope-creating IdentRecord which encompasses this scope
  //Would presumably be either a function on procedure, can be NULL for a toplevel
  //scope
  IdentRecord* scopeRoot;
  //TODO: figure out how to handle nested procedures which are not allowed in C++
  ScopeNode* parentScope;
  vector<ScopeNode*> childScopes;
  map<string, IdentRecord*> records;
}
