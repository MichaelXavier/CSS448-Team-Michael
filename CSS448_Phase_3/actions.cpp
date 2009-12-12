#include "actions.h"


// startProgram
// Initializes the symbol table, with a program IdentRecord
void startProgram(Program* newProg) {
  try {
    symTable = new STObject(newProg);
  } catch(char * err) {
    yyerror("Error while setting up program: ");
  }
}


// endProgram
// Deletes symbol table, closes all scopes
void endProgram(void) {
  //symTable->printST();//FIXME: re we supposed to print?
  symTable->closeAllScopes();
  delete symTable;
  symTable = NULL;
}


// strToInt
// Converts a string to an int
bool strToInt(string& str, int& target) {
  istringstream iss(str);
  if (iss >> target) {
    return true;
  } else {
    ostringstream oss("Error: unable to parse an int out of string "); oss << str << " in call to strToInt";
    yyerror(oss.str().c_str());
  }
}


// intToString
// Converts an int to a string
bool intToString(string& target, int& number) {
  stringstream iss;
  if(iss << number) {
    target = "";
    iss >> target;
    return true;
  } else {
    yyerror("Error: unable to convert int to string ");
  }
}


// resolvePointers
// Checks if a type matches that of any unresolved pointers
// If so, the pointer is resolved
void resolvePointers(IdentRecord* newTypePtr, vector<PointerType*>& ptrs) {
	vector<PointerType*>::iterator it;
	int i = 0;
	// Cycles through all unresolved pointers
    for(it = ptrs.begin(); it != ptrs.end(); it++) {
    if (newTypePtr == NULL) {
      yyerror("Error: newTypePtr argument passed to resolvePointers is NULL");
      return;
      //TODO: further error handling?
    }
    if (ptrs[i] == NULL) {
      ostringstream oss("Error: PointerType* NULL in ptrs argument to resolvePointers at index "); oss << i << ". Skipping.";
      yyerror(oss.str().c_str());
      continue;
      //TODO: further error handling?
    }
	// If a pointer is found that should point to the newTypePtr type, the pointer is set to point
	// to newTypePtr
    if (newTypePtr->getName() == ptrs[i]->getDeclaredType()) {
      ptrs[i]->setPointObj(newTypePtr);
    }
    i++;
  }
}


// checkPointers
// Checks if there are any unresolved point
void checkPointers(vector<PointerType*>& ptrs) {
  for(unsigned int i = 0; i < ptrs.size(); i++) {
    if (ptrs[i] == NULL) {
      ostringstream oss("Error: PointerType* NULL in ptrs argument to checkPointers at index "); oss << i << ". Skipping.";
      yyerror(oss.str().c_str());
      continue;
    }
    if(ptrs[i]->getTypePtr() == NULL)
    {
      cout << "Stray pointer found with name " << ptrs[i]->getName() << " and declared type " << ptrs[i]->getDeclaredType() << endl;
    }
  }
  ptrs.clear();
}


// dumpPointer
void dumpPointer(PointerType* ptr) {
  //TODO: need an ST method for this  
}


// convertSetExpr
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


// convertSingleQuote
// Converts single quotes to double quotes
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


// convertDoubleQuote
// Converts double quotes to single quotes
string convertDoubleQuote(string & expr) {
  string ret(expr);
  if (ret[0] == '\"') {
    ret.replace(0, 1, "\'");
  }
  if (ret[ret.length() - 1] == '\"') {
    ret.replace(ret.length() - 1, 1, "\'");
  }
  return ret;
}


// deleteSingleQuote
// Deletes single quotes around a string
void deleteSingleQuote(string& expr) {
	if(expr[0] == '\'') {
		expr.replace(0,1,"");
	}
	if(expr[expr.length() - 1] == '\'') {
		expr.replace(expr.length() - 1, 1, "");
	}
}
