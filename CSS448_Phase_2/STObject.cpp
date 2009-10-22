STObject::STObject(void) {
  fillIdentTable();
  //TODO: initialize other stuff here
}

STObject::fillIdentTable(void) {
  identTable.push_back(new ArrayType());//FIXME: does vector deallocate?
  identTable.push_back(new IntegerType());
  identTable.push_back(new PointerType());
  identTable.push_back(new RealType());
  identTable.push_back(new RecordType());
  identTable.push_back(new SetType());
  identTable.push_back(new StringType());
  //TODO: are there more types?
}
