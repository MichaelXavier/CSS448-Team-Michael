#include "ScopeNode.h"

ScopeNode::ScopeNode(IdentRecord* root, ScopeNode* parent, int depth) {
  scopeRoot = root; 
  scopeDepth = depth; 
  parent = parentScope;  //Can be NULL
}

ScopeNode::~ScopeNode(void) {
  delete scopeRoot;//FIXME: unless we need it elsewhere?
}

bool ScopeNode::recordExists(IdentRecord* other)const {
  //TODO: null check
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
  //TODO: push_back on childScopes if its not null
  if (new_scope != NULL) {
    childScopes.push_back(new_scope);
  }
}


void ScopeNode::printScope(ostream& sout)
{
	map<string, IdentRecord*>::iterator it;
	for(it = records.begin(); it != records.end(); it++)
	{
		(*it).second->display(sout, scopeDepth);
	}
	
	for(unsigned int i = 0; i < childScopes.size(); i++)
	{
		childScopes[i]->printScope(sout);
	}
}
