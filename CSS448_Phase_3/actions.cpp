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
void resolvePointers(const string& name, vector<PointerHelper*>& ptrs) {
  PointerHelper* helper;
  for(unsigned int i = 0; i < ptrs.size(); i++) {
    if (name == ptrs[i]->getDeclaredType()) {
      helper = ptrs[i];
      //Delete the element in the helpers vector
      ptrs.erase(ptrs.begin()+i);
      IdentRecord* typePtr = st.lookup(name); 
      //Found it
      if (typePtr != NULL) {
        //setup the helper, insert it
        helper->setTypePtr(typePtr); 
        helper->sendToSt(symTable);
      } else {
        cout << "Error: name match found in pointer helper collection but it was not found in the ST: " << name << endl;
      }
      //Free the mem no matter what if it's a match
      delete helper;
      break;
    }
  }
}
