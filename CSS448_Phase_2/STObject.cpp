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
      scopeEntry(new_rec, type);
      break;
    case program://not sure if nested programs are allowed
        //throw exception
      break;
    default:
      currentScope->insertRecord(new_rec);
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
}


void STObject::scopeEntry(IdentRecord* new_rec, IdType type)
{
	currentScopeNumber++;
	ScopeNode* nested_scope = new ScopeNode(new_rec, currentScopeNumber);
	currentScope->insertScope(nested_scope);
	current_scope = nested_scope;
}



void STObject::fillIdentTable(void) {
  //fill in the SIT with primitives
  identTable.push_back(new IntegerType());
  identTable.push_back(new RealType());
  identTable.push_back(new CharacterType());
  //TODO: are there more types?
}
