#include "actions.h"

void startProgram(const char* wat) {
  Program* newProg = new Program(name);
  symTable = new STObject(newProg);   // ST is created, Program inserted into ST
}

void endProgram(void) {
  //symTable.printST();//FIXME: create a method that closes the ST without printing
  //delete symTable;
}
