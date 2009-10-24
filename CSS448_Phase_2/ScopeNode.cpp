ScopeNode::ScopeNode(IdentRecord* root, ScopeNode* parent) {
  scopeRoot = root; 
  parent = parentScope;//Can be NULL
}

ScopeNode::~ScopeNode(void) {
  delete scopeRoot;//FIXME: unless we need it elsewhere?
}

bool ScopeNode::recordExists(const IdentRecord* other)const {
  //TODO: null check
  return records.count(other.getName()) == 1;
}

void ScopeNode::insertRecord(IdentRecord* other) {
  if (other == NULL) {
    return;
  }
  if (scopeRoot->hasConflictingParams(other)) {
    //conflicts with parameter name
    //TODO: throw or return false?
    return;//remove after deciding above
  }
  if (recordExists(other)) {
    //conflicts with previously declared variable
    //TODO: throw or return false?
    return;//remove after deciding above
  }
  //check if key exists first
  records.insert(other->getName(), other);
}

void ScopeNode::insertScope(ScopeNode* new_scope) {
  //TODO: push_back on childScopes if its not null
  if (new_scope_root != NULL) {
    childScopes.push_back(new_scope);
  }
}
