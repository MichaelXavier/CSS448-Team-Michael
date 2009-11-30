#include "CPPGenerator.h"

CPPGenerator::CPPGenerator(ostream& out) : output(out) {
  before_main = new ostringstream();
  main = new ostringstream();
  cur_stream = main;
}

CPPGenerator::~CPPGenerator(void) {
  delete before_main;
  delete main;
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

//Sets current stream to function scope
void CPPGenerator::declareFunct(string name, queue<string> param_names, IdentRecord* ret_type) {
  cout << "DEBUG: declare funct called" << endl;
  if (ret_type != NULL) {
    ostringstream* oss = new ostringstream();
    //Build the function
    *oss << ret_type->getName() << " " << name << "(";
    while (!param_names.empty()) {
      *oss << param_names.front();
      param_names.pop();
      if (!param_names.empty()) {
        *oss << ",";
      }
    }
    *oss << ") {" << endl;

    function_streams.push_back(oss);

    //We are now in this function's scope
    //FIXME: this does not allow for nesting
    changeStream(oss);
  }
  cout << "DEBUG: declare funct done" << endl;
}

void CPPGenerator::closeScope(void) {
  //FIXME: is it safe to assume we will always end with a curly?
  *cur_stream << "}" << endl;
  changeStream(main);
}

void CPPGenerator::changeStream(ostringstream* oss) {
  if (cur_stream != oss) {
    //closeScope();
    cur_stream = oss;
  }
}
