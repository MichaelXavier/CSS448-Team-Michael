#include "actions.h"

void startProgram(const string& name) {
  Program* newProg = new Program(name);
  symTable = new STObject(newProg);
}

void endProgram(void) {
  symTable->printST();//FIXME: create a method that closes the ST without printing
  delete symTable;
}
