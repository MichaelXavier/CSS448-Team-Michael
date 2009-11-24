#include "VarDecHelper.h"

void VarDecHelper::VarDecHelper(void)
{
}


VarDecHelper::~VarDecHelper(void)
{
	typePtr = NULL;
}
	
bool VarDecHelper::AddVar(string& name)
{
	varNames.push_back(name);
}

bool VarDecHelper::AddVars(Queue<string&>& idents) {
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


bool VarDecHelper::SetMemberType(const string& name)
{
	memberType = name;
	return true;
}


bool VarDecHelper::sendToST(STObject* st)
{
	IdentRecord* type = st.lookup(memberType);
	if(type == NULL)
	{
		// error handling, type was not found in ST
	}
	else
	{
		IdentRecord* varRecord;
		for(int i = 0; i < varNames.size(); i++)
		{
			varRecord = new Variable(varNames[i]);
			bool addedToST = st.insert(varRecord, variable);
			if(addedToST == false)
			{
				// variable already exists, handle error
			}
		}
	}
	return true;
}

