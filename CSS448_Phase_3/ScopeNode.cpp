#include "ScopeNode.h"


// Constructor
// Sets the root IdentRecord (a program, procedure, or function), the 
// parent scope, and the scope depth
ScopeNode::ScopeNode(IdentRecord* root, ScopeNode* parent, int depth) {
  scopeRoot = root; 
  scopeDepth = depth; 
  parentScope = parent;  //Can be NULL
}


// Destructor
// Deletes all ScopeNodes stored in ST
ScopeNode::~ScopeNode(void) {
  delete scopeRoot;
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


// recordExists
// Returns whether an IdentRecord exists in the records for this scope
bool ScopeNode::recordExists(const IdentRecord* other)const {
  if (other == NULL) {
    return false;
  }
  return records.count(other->getName()) == 1;
}



// insertRecord
// Inserts a record into the scope's map of records
bool ScopeNode::insertRecord(IdentRecord* other) {
  if (other == NULL) {
    cout << "Error: record is NULL" << endl;
    return false;
  }
  if (scopeRoot->hasConflictingParams(other)) {
    // Checks for parameters with the same identifier name
    cout << "Error: record has conflicting parameters" << endl;
    return false;
  }
  if (recordExists(other)) {
    // Checks for other variables in this scope with the same ident name
    cout << "Error: record already exists" << endl;;
    return false;
  }

  // Tries to insert record into record map.
  pair<map<string, IdentRecord*>::iterator, bool> ret;
  ret = records.insert(pair<string, IdentRecord*>(other->getName(), other));

  if (ret.second) { cout << "DEBUG: inserted record with name " << other->getName() << endl;}//DEBUG

  return ret.second; // Should return true if inserting IdentRecord into map
					 // was successful

}



// insertScope
// Adds a child scope to the list of child scopes
void ScopeNode::insertScope(ScopeNode* new_scope) {
  if (new_scope != NULL) {
    childScopes.push_back(new_scope);
  }
}


// printScope
// Prints scope information and prints each child scope's info (equivalent to
// pre-order print)
void ScopeNode::printScope(ostream& sout) {
	scopeRoot->display(sout, scopeDepth);   // Prints scope root


    // Prints each IdentRecord stored in scope (other than 
	// root)
	map<string, IdentRecord*>::iterator it;
	for(it = records.begin(); it != records.end(); it++)
	{
		IdentRecord* printTemp = (*it).second;
		printTemp->display(sout, scopeDepth+1);
		sout << endl; //Newline at the end of each record.
	}
	
	// Loops through and prints each child scope
	for(unsigned int i = 0; i < childScopes.size(); i++)
	{
		childScopes[i]->printScope(sout);
	}
}


// lookup
// Returns an IdentRecord in the current scope or parent scope if 
// such an IdentRecord of the matching name exists
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

