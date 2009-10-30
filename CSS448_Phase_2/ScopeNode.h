// ScopeNode.h
// Contains the information stored in one scope.

#ifndef SCOPENODE_H
#define SCOPENODE_H
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

  // Returns whether an IdentRecord exists in the records for this scope
  bool recordExists(const IdentRecord* other)const;

  // Inserts a record into the scope's map of records
  bool insertRecord(IdentRecord* other);

  // Adds a child scope to the list of child scopes
  void insertScope(ScopeNode* new_scope);

  // Prints scope information and prints each child scope's info
  void printScope(ostream& sout);

  // Returns an IdentRecord in the current scope or parent scope if 
  // such an IdentRecord of the matching name exists
  IdentRecord* lookup(const string& name);

  // Returns a pointer to the parent scope of this scope
  ScopeNode* getParent(void) { return parentScope; };//called on scope exit by th ST

  // Returns the depth of this scope
  int getDepth(void)const { return scopeDepth; }

private:
  int scopeDepth;     // The depth of this scope
  IdentRecord* scopeRoot;  // The root of this scope (it a program, procedure,
						   // or function
  ScopeNode* parentScope;  // A pointer to the parent scope
  vector<ScopeNode*> childScopes;  // A vector of child scopes
  map<string, IdentRecord*> records;  // A map of IdentRecord* stored
									  // in this scope
};
#endif
