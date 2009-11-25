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
}

int strToInt(const string& str) {
  istringstream iss(str);
  int ret;
  iss >> ret;
  return ret;
}

//Loop through pointers declared so far, see if any are supposed to point to this.
//If they are, set up the pointerhelper, insert and free the helpers memory
//Run it after every declaration (consider a flag for it later)
void resolvePointers(IdentRecord* newTypePtr, vector<PointerHelper*>& ptrs) {
  PointerHelper* helper;
  if (newTypePtr != NULL) {
    for(unsigned int i = 0; i < ptrs.size(); i++) {
      if (newTypePtr->getName() == ptrs[i]->getDeclaredType()) {
        helper = ptrs[i];
        //Delete the element in the helpers vector
        ptrs.erase(ptrs.begin()+i);
        //Found it
          //setup the helper, insert it
          helper->setTypePtr(newTypePtr); 
          helper->sendToSt(symTable);
        //Free the mem no matter what if it's a match
        delete helper;
        break;
      }
    }
  }
}

void checkPointers(vector<PointerHelper*>& ptrs) {
  PointerHelper* helper;
  for(unsigned int i = 0; i < ptrs.size(); i++) {
    helper = ptrs[i];
    cout << "Stray pointer found with name " << helper->getName() << " and declared type " helper->getDeclaredType() << endl;
    delete helper;
    ptrs.erase(ptrs.begin()+i);
  }
}
