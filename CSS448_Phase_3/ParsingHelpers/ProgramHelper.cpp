#include "ProgramHelper.h"

ProgramHelper::ProgramHelper(const string& name)
{
	programName = name;
}

ProgramHelper::~ProgramHelper()
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
    parameterNames.push_back(name);
  }
  return true;
}

Program* ProgramHelper::GetProgramObj()
{
	Program* program = new Program(programName);

	IdentRecord* param;
	for(int i = 0; i < parameterNames.size(); i++)
	{
		param = new Parameter(parameterNames[i]);
		if(!program.insertParameter(param))
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
