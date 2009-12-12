#include "STObject.h"


// Constructor
// Note: it is necessary to have a Program object to set as the root scope
// when instantiating an STObject.  This also creates the standard identifier
// table.
STObject::STObject(Program* root) {
  rootScope = NULL;
  if (root == NULL) {
    throw "Cannot instantiate an STObject with a null Program root.";
  }
  fillIdentTable();  // Creates standard identifier table
  currentScopeNumber = 0;
  //Create a root scope with no parent
	rootScope = new ScopeNode(root, NULL, currentScopeNumber);
  //Root is now the current scope
  currentScope = rootScope;
}

// Destructor
// Recursively deletes all ScopeNodes and SIT
STObject::~STObject(void) {
  if (rootScope != NULL) {
    delete rootScope;//Deletion will cascade recursively into the children
  }
  //Clear the SIT
  for (unsigned int i = 0; i < identTable.size(); i++) {
    delete identTable[i];
  }
}

// insert
// This inserts an IdentRecord into the ST.  
IdentRecord* STObject::insert(IdentRecord* new_rec, IdType type) {
  if (new_rec == NULL) {
    yyerror("Error: cannot insert a NULL item into the ST ");
    return NULL;
  }
  ostringstream oss; //For errors
  switch (type) {
    case function:
      if (scopeEntry(new_rec, type)) {
        //Set up return variable. It is valid C++ to have a variable with the same name as a function in the function.
        Variable* var = new Variable(new_rec->getName());
        if (!currentScope->insertRecord(var)) {
          delete var;
        }
        return new_rec;
      } else {
        // This handles when a parent scope procedure/function/program has
        // the same identifier
        oss << "Error: id already in ST: \"" << new_rec->getName() << "\"";
        yyerror(oss.str().c_str());
        return NULL;
      }
      break;
    case procedure:
      if (scopeEntry(new_rec, type)) {
        return new_rec;
      } else {
        // This handles when a parent scope procedure/function/program has
        // the same identifier
        oss << "Error: id already in ST: \"" << new_rec->getName() << "\"";
        yyerror(oss.str().c_str());
        return NULL;
      }
      break;
    case program:
		// A program can't be inserted since this was already done when
		// the ST was created
        oss << "Error: cannot nest Program types: \"" << new_rec->getName() << "\"";
        yyerror(oss.str().c_str());
        return NULL;
      break;
    default:
	  // All other IdentRecord types are inserted into the current scope's
	  // records, if the identifier name doesn't already exist
      bool recordInsert;
      recordInsert = currentScope->insertRecord(new_rec);
      if(recordInsert == true) {
        return new_rec;
      } else {
        oss << "Error: id already in ST: \"" << new_rec->getName() << "\"";
        yyerror(oss.str().c_str());
        return NULL;
      }
      break;
  }
}


// printST
// Prints the symbol table by printing each ScopeNode (this
// is done recursively from ScopeNode::printScope).
// Afterwards, sets the current scope to the root scope.
// Note: ScopeNodes are not deleted after printST
void STObject::printST(void) {
  //Print starting from the root
  cout << "===================================================================" << endl;
  rootScope->printScope(cout);
  //Start back up at the root scope
  while(currentScopeNumber != 0)
  {
	  scopeExit();
  }

  closeAllScopes();
//	currentScope = rootScope; // Sets the current scope 
							  // as root scope after printing ST
//	currentScopeNumber = 0;

	cout << endl;
}

void STObject::closeAllScopes(void) {
  while(currentScopeNumber != 0)
  {
	  scopeExit();
  }
}

// scopeEntry
// Creates a new scope, adds it to the current scope's list of child scopes,
// and sets the current scope to the new scope.
bool STObject::scopeEntry(IdentRecord* new_rec, IdType type) {
	currentScopeNumber++;

  //insert a new scope, set its parent as the current scope
	ScopeNode* nested_scope = new ScopeNode(new_rec, currentScope, currentScopeNumber);
	currentScope->insertScope(nested_scope);
	currentScope = nested_scope;
	return true;
}

void STObject::scopeExit()
{
	if(currentScopeNumber != 0)
	{
		currentScope = currentScope->getParent();
		currentScopeNumber--;
	}
	else
		cout << "Can't call scopeExit on root (program)" << endl;
}


// lookup
// Checks the current scope and all parent scopes for the identifier name.
// Also, checks the SIT.  Afterwards, returns a pointer to the IdentRecord.
// If not found, prints an error message and returns NULL.
IdentRecord* STObject::lookup(const string& name) {
  IdentRecord* retval = NULL;
  //Try currentScope which will go up to the root scope
  if (currentScope != NULL) {
    retval = currentScope->lookup(name);
    if (retval != NULL) {
      return retval;
    }
  }

  //  Checks the root (note: for debugging purposes)
  if (rootScope != NULL) {
    retval = rootScope->lookup(name);
    if (retval != NULL) {
      return retval;
    }
  }

  // Checks the symbol table for the identifier name
  for(std::vector<IdentRecord*>::iterator it = identTable.begin(); it != identTable.end(); ++it) {
    if (name == (*it)->getName()) {
      return (*it);
    }
  }

  cout << "Couldn't find type with name " << name << endl;
  //Didn't find it
  return NULL;
}


// fillIdentTable
// Fills the SIT
void STObject::fillIdentTable(void) {
  //fill in the SIT with primitives
  identTable.push_back(new IntegerType("integer"));
  identTable.push_back(new RealType("real"));
  identTable.push_back(new CharacterType("char"));
  identTable.push_back(new BooleanType("boolean"));
  identTable.push_back(new Constant("True"));
  identTable.push_back(new Constant("False"));
  identTable.push_back(new Constant("Nil"));
  identTable.push_back(new Procedure("WriteLn"));
  identTable.push_back(new Procedure("Write"));
  identTable.push_back(new Procedure("ReadLn"));
  identTable.push_back(new Procedure("Read"));
}

