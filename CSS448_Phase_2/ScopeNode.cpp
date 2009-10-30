#include "ScopeNode.h"

ScopeNode::ScopeNode(IdentRecord* root, ScopeNode* parent, int depth) {
  scopeRoot = root; 
  scopeDepth = depth; 
  parentScope = parent;  //Can be NULL
}

ScopeNode::~ScopeNode(void) {
  delete scopeRoot;//FIXME: unless we need it elsewhere?
  //Free memory of IdentRecords in this scope
	map<string, IdentRecord*>::iterator it;
	for(it = records.begin(); it != records.end(); it++)
	{
		delete (*it).second;
	}
  //Recursively delete children
  for (unsigned int i = 0; i < childScopes.size(); i++) {
    delete childScopes[i];
  }
}

bool ScopeNode::recordExists(const IdentRecord* other)const {
  if (other == NULL) {
    return false;
  }
  return records.count(other->getName()) == 1;
}

bool ScopeNode::insertRecord(IdentRecord* other) {
  if (other == NULL) {
    return false;
  }
  if (scopeRoot->hasConflictingParams(other)) {
    //conflicts with parameter name
    //TODO: throw or return false?
    return false;
  }
  if (recordExists(other)) {
    //conflicts with previously declared variable
    //TODO: throw or return false?
    return false;
  }
  // Tries to insert record into record map.  If a duplicate exists,
  // returns false, otherwise returns true
  pair<map<string, IdentRecord*>::iterator, bool> ret;
  ret = records.insert(pair<string, IdentRecord*>(other->getName(), other));

  return ret.second; // ret.second is true if duplicate was found,
					 // false otherwise

}

void ScopeNode::insertScope(ScopeNode* new_scope) {
  if (new_scope != NULL) {
    childScopes.push_back(new_scope);
  }
}

void ScopeNode::printScope(ostream& sout) {
	scopeRoot->display(sout, scopeDepth);

	map<string, IdentRecord*>::iterator it;
	for(it = records.begin(); it != records.end(); it++)
	{
		(*it).second->display(sout, scopeDepth+1);
    sout << endl; //Newline at the end of each record.
	}
	
	for(unsigned int i = 0; i < childScopes.size(); i++)
	{
		childScopes[i]->printScope(sout);
	}
}

IdentRecord* ScopeNode::lookup(const string& name) {
  map<string, IdentRecord*>::iterator result = records.find(name);
  //Not found in current scope, check parent
  if (result == records.end()) {
    if (parentScope == NULL) {
      return NULL;
    } else {
      return parentScope->lookup(name);
    }
  } else {
    //Found it, return the value
    return result->second;
  }
}
