#include "ProgramHelper.h"

ProgramHelper::ProgramHelper(const string& name)
{
	programName = name;
}

ProgramHelper::~ProgramHelper(void)
{
}


bool ProgramHelper::AddParameterName(const string& name)
{
  //Do not allow duplicate parameter names
	for(int i = 0; i < parameterNames.size(); i++)
	{
    if (parameterNames[i] == name) {
      cout << "ERROR: duplicate program parameter name " << name << endl;
      return false;
      }
	}
	parameterNames.push_back(name);
  return true;
}

bool ProgramHelper::AddParameterNames(queue<string>& idents) {
	while (!idents.empty()) {
    if (!AddParameterName(idents.front())) {
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

Program* ProgramHelper::GetProgramObj()
{
	Program* program = new Program(programName);

	ProgramParameter* param;
	for(int i = 0; i < parameterNames.size(); i++)
	{
		param = new ProgramParameter(parameterNames[i]);
		bool addedParam = program->insertParameter(param);
		if(addedParam == false)
		{
      //Delete the last parameter and program, which will delete the
      //successfully inserted parameters
      delete param;
      delete program;
      cout << "Failed to insert parameter to program" << endl;
      return NULL;
		}
	}

	return program;
}

