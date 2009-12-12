#include "ProgramHelper.h"


// Constructor
ProgramHelper::ProgramHelper(const string& name)
{
	programName = name;
}


// Destructor
ProgramHelper::~ProgramHelper(void)
{
}


// AddParameterName
// Adds a parameter name to the parameter queue
bool ProgramHelper::AddParameterName(const string& name)
{
  //Do not allow duplicate parameter names
	for(int i = 0; i < parameterNames.size(); i++)
	{
    if (parameterNames[i] == name) {
      ostringstream oss("ERROR: duplicate program parameter name "); oss << name;
      yyerror(oss.str().c_str());
      return false;
      }
	}
	parameterNames.push_back(name);
  return true;
}


// AddParameterNames
// Adds parameter names to the parameter queue
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


// GetProgramObj
// Creates a program object and returns a pointer to it
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

