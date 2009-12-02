#include "CPPGenerator.h"

CPPGenerator::CPPGenerator(ostream& out) : output(out) {
  before_main = new ostringstream();
  main = new ostringstream();
  cur_stream = main;
  scope_stack.push(main);
}

CPPGenerator::~CPPGenerator(void) {
  delete before_main;
  delete main;
  for (int i = 0; i < function_streams.size(); i++) {
    delete function_streams[i];
  }
}


void CPPGenerator::setup(void) {
  *before_main << "#include <iostream>" << endl 
    << "#typedef integer int" << endl
    << "#typedef real double" << endl
    << "#typedef boolean bool" << endl
    << "#define True true" << endl
    << "#define False false" << endl
    << "#define Nil NULL" << endl //TODO: more?
    << endl << "using namespace std;" << endl << endl;
    *main << "int main(void) {" << endl;
}

void CPPGenerator::teardown(void) {
  *main << "}" << endl;
}

void CPPGenerator::print(void) {
  closeAllScopes();
  output << before_main->str();
  for (unsigned int i = 0; i < function_streams.size(); i++) {
    output << function_streams[i]->str();
  }
  output << main->str();//FIXME: iterate through other streams?
}

void CPPGenerator::declareVars(queue<string> idents, IdentRecord* type) {
  if (type != NULL) {
    *cur_stream << type->getName() << " ";
    while (!idents.empty()) {
      *cur_stream << idents.front();
      idents.pop();
      if (!idents.empty()) {
        *cur_stream << ",";
      }
    }
    *cur_stream << ";" << endl;
  }
}

void CPPGenerator::declareProc(const string& name, queue<string> param_names) {
  declareFunct(name, param_names, "void");
}

//Sets current stream to function scope
void CPPGenerator::declareFunct(const string& name, queue<string> param_names, const string& ret_type) {
  ostringstream* oss = new ostringstream();
  //Build the function
  *oss << ret_type << " " << name << "(";
  while (!param_names.empty()) {
    *oss << param_names.front();
    param_names.pop();
    if (!param_names.empty()) {
      *oss << ",";
    }
  }
  *oss << ") {" << endl;

  //Push to function vector for later
  function_streams.push_back(oss);

  //We are now in this function's scope
  scope_stack.push(oss);

  //set up the current stream to this scope
  cur_stream = oss;
}

void CPPGenerator::closeScope(void) {
  //FIXME: is it safe to assume we will always end with a curly?
  cout << "DEBUG: closing scope" << endl;

  *cur_stream << "}" << endl;

  if (scope_stack.top() != main) {
    scope_stack.pop();
  }

  cur_stream = scope_stack.top();
}

void CPPGenerator::closeAllScopes(void) {
  while (scope_stack.top() != main && !scope_stack.empty()) {
    *scope_stack.top() << "}" << endl;
    scope_stack.pop();
  }
  cur_stream = main;
}
