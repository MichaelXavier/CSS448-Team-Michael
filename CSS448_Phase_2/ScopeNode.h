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
  bool recordExists(IdentRecord* other)const;
  bool insertRecord(IdentRecord* other);
  void insertScope(ScopeNode* new_scope);
  void printScope(ostream& sout);

  ScopeNode* getParent(void) { return parentScope; };//called on scope exit by th ST

  int getDepth(void)const { return scopeDepth; }

  IdentRecord* lookup(const string& name);
private:
  int scopeDepth;
  //Base scope-creating IdentRecord which encompasses this scope
  //Would presumably be either a function on procedure, can be NULL for a toplevel
  //scope
  IdentRecord* scopeRoot;
  //TODO: figure out how to handle nested procedures which are not allowed in C++
  ScopeNode* parentScope;
  vector<ScopeNode*> childScopes;
  map<string, IdentRecord*> records;
};
#endif
