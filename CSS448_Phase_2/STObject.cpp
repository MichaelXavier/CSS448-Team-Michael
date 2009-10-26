STObject::STObject(void) {
  fillIdentTable();
  currentScopeNumber = 0;
  //TODO: initialize other stuff here
}

//FIXME: this is perhaps taking over the responsibility of scopeEntry?
//it is setting the current scope to the new nested scope. perhaps we don't
//need scopeEntry or if we do, it will take 
bool insert(IdentRecord* new_rec, IdType type) {
  switch (type) {
    case function:
    case procedure:
		// FIXME: this may require something for handling the case
		// the new_rec identifier is already used by another
		// procedure, function, or program in a parent scope
	  bool scopeCreated;
      scopeCreated = scopeEntry(new_rec, type);
	  if(scopeCreated == true)
		  return true;
	  else
	  {
		  // This handles when a parent scope procedure/function/program has
		  // the same identifier
		  cout << "Error: id already in ST: \"" << IdentRecord->getName() << "\"\n"; 
		  return false;
	  }
      break;
    case program:
	  // Can only insert a new program and create a scope at root level
	  if(currentScopeNumber == 0)
	  {
		  scopeEntry(new_rec, type);
	      return true;
	  }
	  // If not at root level, returns false (can't insert Program type) 
	  else
	  {
		  cout << "Error: cannot nest Program types: \"" << IdentRecord->getName() << "\"\n";
		  return false;
	  }
      break;
    default:
	  bool recordInsert;
      recordInsert = currentScope->insertRecord(new_rec);
	  if(recordInsert == true)
		  return true;
	  else
	  {
		  cout << "Error: id already in ST: \"" << IdentRecord->getName() << "\"\n";
		  return false;
	  }
	  break;
  }
}


void STObject::printST(void)
{
	ScopeNode* printScope;
	printScope = rootScope;
	rootScope->printScope();	
	currentScope = rootScope; // Sets the current scope 
							  // as root scope after printing ST
	currentScopeNumber = 1;
}


bool STObject::scopeEntry(IdentRecord* new_rec, IdType type)
{
	currentScopeNumber++;
	ScopeNode* nested_scope = new ScopeNode(new_rec, currentScopeNumber);
	currentScope->insertScope(nested_scope);
	current_scope = nested_scope;
	return true; // FIXME: it would be necessary to return false if the 
				 // identifier for the procedure is the same as a parent
				 // scope procedure
}

IdentRecord* STObject::lookup(const string& name) {
  if (currentScope != NULL) {
    return currentScope->lookup(name);
  } else if (rootScope !=NULL) {
    return rootScope->lookup(name);
  } else {
    return NULL;
  }
}


void STObject::fillIdentTable(void) {
  //fill in the SIT with primitives
  identTable.push_back(new IntegerType());
  identTable.push_back(new RealType());
  identTable.push_back(new CharacterType());
  //TODO: are there more types?
}
