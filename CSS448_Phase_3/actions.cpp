#include "actions.h"

void startProgram(Program* newProg) {
  try {
    symTable = new STObject(newProg);
  } catch(char * err) {
    cout << "Error while setting up program: " << err << endl;
  }
}

void endProgram(void) {
  //symTable->printST();//FIXME: re we supposed to print?
  symTable->closeAllScopes();
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
    if (newTypePtr == NULL) {
      cout << "Error: newTypePtr argument passed to resolvePointers is NULL" << endl;
      return;
      //TODO: further error handling?
    }
    if (ptrs[i] == NULL) {
      cout << "Error: PointerType* NULL in ptrs argument to resolvePointers at index" << i << ". Skipping." << endl;
      continue;
      //TODO: further error handling?
    }
    if (newTypePtr->getName() == ptrs[i]->getDeclaredType()) {
      ptrs[i]->setPointObj(newTypePtr);
    }
    i++;
  }
}

void checkPointers(vector<PointerType*>& ptrs) {
  for(unsigned int i = 0; i < ptrs.size(); i++) {
    if (ptrs[i] == NULL) {
      cout << "Error: PointerType* NULL in ptrs argument to checkPointers at index" << i << ". Skipping." << endl;
      continue;
    }
    if(ptrs[i]->getTypePtr() == NULL)
    {
      cout << "Stray pointer found with name " << ptrs[i]->getName() << " and declared type " << ptrs[i]->getDeclaredType() << endl;
    }
  }
  ptrs.clear();
}

void dumpPointer(PointerType* ptr) {
  //TODO: need an ST method for this  
}

string convertSetExpr(const string& expr) {
  if (expr.length() == 0) {
    return "new IntSet()";
  }
  istringstream iss(expr);
  ostringstream oss;
  int i;
  while (!iss.eof() && iss >> i) {
    //oss << i;
    //range
    if (iss.peek() == '.') {
      iss.get();
      if (iss.peek() == '.') {
        iss.get();
        oss << "*(new IntSet(" << i << ", ";
        iss >> i;
        oss << i << "))";
      }
    } else {
      //just a single element
      oss << "*(new IntSet(" << i << "))";
    }

    //see if there's more
    if (iss.peek() == ',') {
      iss.get();
      oss << " + ";
    }
  }
  return oss.str();
}

string convertSingleQuote(const string& expr) {
  string ret(expr);
  if (ret[0] == '\'') {
    ret.replace(0, 1, "\"");
  }
  if (ret[ret.length() - 1] == '\'') {
    ret.replace(ret.length() - 1, 1, "\"");
  }
  return ret;
}
