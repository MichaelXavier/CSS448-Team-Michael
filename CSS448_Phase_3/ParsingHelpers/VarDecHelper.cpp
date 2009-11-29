#include "VarDecHelper.h"

VarDecHelper::VarDecHelper(void)
{
}
VarDecHelper::~VarDecHelper(void)
{
}

bool VarDecHelper::AddVar(const string& name)
{
  if (name.length() > 0) {
    varNames.push_back(name);
    return true;
  } else {
    cout << "Error: cannot declare a zero-length variable name." << endl;
    return false;
  }
}
bool VarDecHelper::AddVars(queue<string>& idents) {
  while (!idents.empty()) {
    cout << "DEBUG: adding var to VarDecHelper queue: " << idents.front() << endl;
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

bool VarDecHelper::SetMemberType(IdentRecord* type)
{
  //TODO: validations
  typePtr = type;
	return true;
}
IdentRecord* VarDecHelper::sendToSt(STObject* st)
{
  Variable* varRecord;
	if(typePtr == NULL)
	{
		// error handling, type was not found in ST
    cout << "Error: variable missing type" << endl;
    return NULL;
	}
	else
	{
		for(int i = 0; i < varNames.size(); i++)
		{
			varRecord = new Variable(varNames[i]);
			varRecord->setTypePtr(typePtr);
	
			cout << "DEBUG: Inserting " << varNames[i] << endl;
			if(!st->insert(varRecord, variable))
			{
				// variable already exists, handle error
				cout << "Variable " << varNames[i] << " already exists and could not be inserted" << endl;
				delete varRecord;
				return NULL;
			}
		}
	}
  //Return the last one
	return varRecord;
}

