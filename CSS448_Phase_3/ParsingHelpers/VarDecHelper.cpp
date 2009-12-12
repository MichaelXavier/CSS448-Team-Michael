#include "VarDecHelper.h"


// Constructor
VarDecHelper::VarDecHelper(void)
{
}


// Destructor
VarDecHelper::~VarDecHelper(void)
{
}


// AddVar
// A variable name is added to queue
bool VarDecHelper::AddVar(const string& name)
{
  if (name.length() > 0) {
    varNames.push_back(name);
    return true;
  } else {
    yyerror("Error: cannot declare a zero-length variable name.");
    return false;
  }
}


// AddVars
// Variable names are added to queue
bool VarDecHelper::AddVars(queue<string>& idents) {
  while (!idents.empty()) {
    if (!AddVar(idents.front())) {
      //clear the stack and bail
      while (!idents.empty()) {
        idents.pop();
      }
      return false;
    }
    idents.pop();
  }
  return true;
}


// SetMemberType
// Variable type is set
bool VarDecHelper::SetMemberType(IdentRecord* type)
{
  //TODO: validations
  typePtr = type;
	return true;
}


// sendToSt
// Creates variables and sends them to the symbol table/
IdentRecord* VarDecHelper::sendToSt(STObject* st)
{
  Variable* varRecord;
	if(typePtr == NULL)
	{
		// error handling, type was not found in ST
    yyerror("Error: variable missing type");
    return NULL;
	}
	else
	{
		for(int i = 0; i < varNames.size(); i++)
		{
			varRecord = new Variable(varNames[i]);
			varRecord->setTypePtr(typePtr);
	
			if(!st->insert(varRecord, variable))
			{
				// variable already exists, handle error
        ostringstream oss; oss << "Error: Variable " << varNames[i] << " already exists and could not be inserted";
        yyerror(oss.str().c_str());
				delete varRecord;
				return NULL;
			}
		}
	}
  //Return the last one
	return varRecord;
}

