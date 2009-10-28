ScopeNode::ScopeNode(IdentRecord* root, ScopeNode* parent, int depth) {
  scopeRoot = root; 
  scopeDepth = depth; 
  parent = parentScope;  //Can be NULL
}

ScopeNode::~ScopeNode(void) {
  delete scopeRoot;//FIXME: unless we need it elsewhere?
}

bool ScopeNode::recordExists(const IdentRecord* other)const {
  if (other == NULL) {
    return false;
  }
  //Check the current scope first
  if (records.count(other.getName()) == 1) {
    return true;
  } else if (parentScope == NULL) {
    return false;
  } else {
    return parentScope->recordExists(other);
  }
}

bool ScopeNode::insertRecord(IdentRecord* other) {
  if (other == NULL) {
    return false;
  }
  if (scopeRoot->hasConflictingParams(other)) {
    //conflicts with parameter name
    return false;
  }
  if (recordExists(other)) {
    //conflicts with previously declared variable
    return false;
  }
  // Tries to insert record into record map.  If a duplicate exists,
  // returns false, otherwise returns true
  pair<map<string, IdentRecord*>::iterator, bool> ret;
  ret = records.insert(other->getName(), other);
  return ret.second; // ret.second is true if duplicate was found,
					 // false otherwise

}

void ScopeNode::insertScope(ScopeNode* new_scope) {
  //TODO: push_back on childScopes if its not null
  if (new_scope_root != NULL) {
    childScopes.push_back(new_scope);
  }
}


void ScopeNode::printScope(ostream& sout)
{
	map<string, IdentRecord*>::iterator it;
	for(it = records.begin(); it != records.end(); it++)
	{
		(*it).second.print(sout, scopeDepth);
	}
	
	for(int i = 0; i < childScopes.size(); i++)
	{
		childScopes[i].printScope(sout);
	}
}
