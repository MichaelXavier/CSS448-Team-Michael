STObject::STObject(void) {
  fillIdentTable();
  //TODO: initialize other stuff here
}

STObject::fillIdentTable(void) {
  /*identTable.push_back(new ArrayType());//FIXME: does vector deallocate?
  identTable.push_back(new IntegerType());
  identTable.push_back(new PointerType());
  identTable.push_back(new RealType());
  identTable.push_back(new RecordType());
  identTable.push_back(new SetType());
  identTable.push_back(new StringType());*/
  //TODO: are there more types?
}

//FIXME: this is perhaps taking over the responsibility of scopeEntry?
//it is setting the current scope to the new nested scope. perhaps we don't
//need scopeEntry or if we do, it will take 
bool insert(IdentRecord* new_rec, IdType type) {
  switch (type) {
    case function:
    case procedure:
      //Create a new node, set the current node as the parent scope
      ScopeNode* nested_scope = new ScopeNode(new_rec, currentScope);//FIXME:
      currentScope->insertScope(nested_scope);
      current_scope = nested_scope
      break;
    case program://not sure if nested programs are allowed
        //throw exception
      break;
    default:
      currentScope->insertRecord(new_rec)
  }
}
