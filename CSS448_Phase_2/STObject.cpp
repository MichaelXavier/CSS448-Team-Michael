#include "STObject.h"

STObject::STObject(Program* root) {
  rootScope = NULL;//FIXME: see if valgrind stops complaining
  if (root == NULL) {
    throw "Cannot instantiate an STObject with a null Program root.";
  }
  fillIdentTable();
  currentScopeNumber = 0;
  //Create a root scope with no parent
	rootScope = new ScopeNode(root, NULL, currentScopeNumber);
  //Root is now the current scope
  currentScope = rootScope;
  //TODO: initialize other stuff here
}

STObject::~STObject(void) {
  if (rootScope != NULL) {
    delete rootScope;//Deletion will cascade recursively into the children
  }
}

//FIXME: this is perhaps taking over the responsibility of scopeEntry?
//it is setting the current scope to the new nested scope. perhaps we don't
//need scopeEntry or if we do, it will take 
bool STObject::insert(IdentRecord* new_rec, IdType type) {
  switch (type) {
    case function:
    case procedure:
      // FIXME: this may require something for handling the case
      // the new_rec identifier is already used by another
      // procedure, function, or program in a parent scope
      bool scopeCreated;
        scopeCreated = scopeEntry(new_rec, type);
      if (scopeCreated == true) {
        return true;
      } else {
        // This handles when a parent scope procedure/function/program has
        // the same identifier
        cout << "Error: id already in ST: \"" << new_rec->getName() << "\"\n"; 
        return false;
      }
      break;
    case program:
	  // Can only insert a new program and create a scope at root level
      if(currentScopeNumber == 0) {
        scopeEntry(new_rec, type);
        return true;
      } else {
        // If not at root level, returns false (can't insert Program type) 
        cout << "Error: cannot nest Program types: \"" << new_rec->getName() << "\"\n";
        return false;
      }
      break;
    default:
      bool recordInsert;
      recordInsert = currentScope->insertRecord(new_rec);
      if(recordInsert == true) {
        return true;
      } else {
        cout << "Error: id already in ST: \"" << new_rec->getName() << "\"\n";
        return false;
      }
      break;
  }
}


void STObject::printST(void) {
  //Print starting from the root
  rootScope->printScope(cout);
  //TODO: free scope memory
  //Start back up at the root scope
	currentScope = rootScope; // Sets the current scope 
							  // as root scope after printing ST
	currentScopeNumber = 0;
}


bool STObject::scopeEntry(IdentRecord* new_rec, IdType type) {
	currentScopeNumber++;
  //insert a new scope, set its parent as the current scope
	ScopeNode* nested_scope = new ScopeNode(new_rec, currentScope, currentScopeNumber);
	currentScope->insertScope(nested_scope);
	currentScope = nested_scope;
	return true; // FIXME: it would be necessary to return false if the 
				 // identifier for the procedure is the same as a parent
				 // scope procedure
}

IdentRecord* STObject::lookup(const string& name) {
  IdentRecord* retval = NULL;
  //Try currentScope which will go up to the root scope
  if (currentScope != NULL) {
    retval = currentScope->lookup(name);
    if (retval != NULL) {
      return retval;
    }
  }

  //FIXME: shouldn't have to do this, for debugging purposes, going to explicitly check the root
  if (rootScope != NULL) {
    retval = rootScope->lookup(name);
    if (retval != NULL) {
      return retval;
    }
  }

  //Try the SIT
  for(std::vector<IdentRecord*>::iterator it = identTable.begin(); it != identTable.end(); ++it) {
    if ((*it)->getName() == name) {
      return *it;
    }
  }
  cout << "DEBUG: Coudln't find type with name " << name << endl;//fixme: DEBUG
  //Didn't find it
  return NULL;
}

void STObject::fillIdentTable(void) {
  //fill in the SIT with primitives
  identTable.push_back(new IntegerType("integer"));
  identTable.push_back(new RealType("real"));
  identTable.push_back(new CharacterType("char"));
  identTable.push_back(new BooleanType("boolean"));
  identTable.push_back(new Constant("True"));
  identTable.push_back(new Constant("False"));
  identTable.push_back(new Procedure("WriteLn"));
  identTable.push_back(new Procedure("Write"));
  identTable.push_back(new Procedure("ReadLn"));
  identTable.push_back(new Procedure("Read"));
}
