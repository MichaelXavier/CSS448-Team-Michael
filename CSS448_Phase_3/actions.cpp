#include "actions.h"

void startProgram(Program* newProg) {
  try {
    symTable = new STObject(newProg);
  } catch(char * err) {
    cout << "Error while setting up program: " << err << endl;
  }
}

void endProgram(void) {
  symTable->printST();//FIXME: re we supposed to print?
  delete symTable;
  symTable = NULL;
}

bool strToInt(string& str, int& target) {
  istringstream iss(str);
  if (iss >> target) {
    return true;
  } else {
    cout << "Error: unable to parse an int out of string " << str << " in call to strToInt" << endl;
  }
}

//Loop through pointers declared so far, see if any are supposed to point to this.
void resolvePointers(IdentRecord* newTypePtr, vector<PointerType*>& ptrs) {
	vector<PointerType*>::iterator it;
	int i = 0;
  for(it = ptrs.begin(); it != ptrs.end(); it++) {
	if (newTypePtr->getName() == ptrs[i]->getDeclaredType()) {
		ptrs[i]->setPointObj(newTypePtr);
	}
	i++;
  }
}

void checkPointers(vector<PointerType*>& ptrs) {
  for(unsigned int i = 0; i < ptrs.size(); i++) {
	if(ptrs[i]->getTypePtr() == NULL)
	{
		cout << "Stray pointer found with name " << ptrs[i]->getName() << " and declared type " << ptrs[i]->getDeclaredType() << endl;
	}
  }
  ptrs.clear();
}
