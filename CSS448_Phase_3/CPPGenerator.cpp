#include "CPPGenerator.h"

CPPGenerator::CPPGenerator(ostream& out) : output(out) {
  before_main = new ostringstream();
  main = new ostringstream();
  cur_stream = main;
  scope_stack.push(main);
  indent_level = 1;
}

CPPGenerator::~CPPGenerator(void) {
  delete before_main;
  delete main;
  for (int i = 0; i < function_streams.size(); i++) {
    delete function_streams[i];
  }
}


void CPPGenerator::setup(void) {
  addInclude("<iostream>");
  *before_main << "#typedef integer int" << endl
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
    printIndent();
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

  //Reset indent level for this scope
  indent_level = 1;
}

void CPPGenerator::addInclude(const string& include) {
  //FIXME: error check?
  *before_main << "#include " << include << endl;
}

void CPPGenerator::declareConst(ConstDecHelper* ch, Constant* c) {
  if (c != NULL) {
    printIndent();
    *cur_stream << "const "; 
    
    string constType = c->getConstType();
    
    if (constType == "s") {
      *cur_stream << "char* " << ch->getConstName() << " = " << c->getConstString();
    } else if(constType == "b") {
      *cur_stream << "bool " << ch->getConstName() << " = " << (c->getConstBool() ? "true" : "false");
    } else if(constType == "i") {
      *cur_stream << "int " << ch->getConstName() << " = " << c->getConstInt();
    }    
    *cur_stream << ";" << endl;
  }
}

void CPPGenerator::startIfExpr(void) {
  printIndent();
  *cur_stream << "if (";
}

void CPPGenerator::closeIfExpr(void) {
  *cur_stream << ")";
}

void CPPGenerator::startElseExpr(void) {
  printIndent();
	*cur_stream << "else ";
  startBlock();
}

void CPPGenerator::startCase(void) {
  printIndent();
	*cur_stream << "switch(";
}

void CPPGenerator::breakCase(void) {
  printIndent();
	*cur_stream << "break;";
}

void CPPGenerator::writeCaseLabel(Constant* constant) {
  printIndent();
  *cur_stream << endl << "case ";
	if(constant->getName() != "") {
     *cur_stream <<  constant->getName();
  } else { 
		if(constant->getConstType() == "i")
			*cur_stream << constant->getConstInt();
		else if(constant->getConstType() == "s")
			*cur_stream << "'" << constant->getConstString()[0] << "'";
		else if(constant->getConstType() == "b")
			*cur_stream << constant->getConstBool();
	}
	*cur_stream << ": ";
}

void CPPGenerator::startWhile(void) {
  printIndent();
  *cur_stream << "while(";
}

void CPPGenerator::startRepeat(void) {
  printIndent();
  *cur_stream << "do";
  startBlock();
}

void CPPGenerator::closeRepeat(const string& expr) {
  endBlock();
  printIndent();
  *cur_stream << "while(!" << expr << ");" << endl;
}

void CPPGenerator::startFor(const string& iter, const string& expr) {
  printIndent();
  *cur_stream << "for(" << iter << " = " << expr << "; ";
}

void CPPGenerator::completeFor(const string& iter, const string& expr, bool inc) {
  *cur_stream <<  expr << ";" << iter << (inc ? "++" : "--") << endl;
}

void CPPGenerator::allocVar(const string& var) {
  printIndent();
  *cur_stream << "new " << var << ";" << endl;
}

void CPPGenerator::deallocVar(const string& var) {
  printIndent();
  *cur_stream << "delete " << var << ";" << endl;
}

void CPPGenerator::writeStr(string expression)
{
  //printIndent();
	*cur_stream << expression;
}

void CPPGenerator::startBlock(void) {
  *cur_stream << endl; 
  printIndent();
  *cur_stream << "{" << endl;
  indent_level++;
}
void CPPGenerator::endBlock(void) {
  indent_level--;
  printIndent();
  *cur_stream << "}" << endl;
}

void CPPGenerator::closeScope(void) {
  //FIXME: is it safe to assume we will always end with a curly?
  //cout << "DEBUG: closing scope" << endl;

  //*cur_stream << "}" << endl;
  endBlock();

  if (scope_stack.top() != main && !scope_stack.empty()) {
    scope_stack.pop();
  }

  cur_stream = scope_stack.top();
}

void CPPGenerator::coutExpr(const string& expr, bool newline) {
  printIndent();
  *cur_stream << "cout << " << expr; 
  if (newline) {
    *cur_stream << " << endl";
  }
  *cur_stream << ";" << endl;
}

void CPPGenerator::cinExpr(const string& expr) {
  printIndent();
  *cur_stream << "cin >> " << expr << ";" << endl;
}

void CPPGenerator::closeAllScopes(void) {
  while (scope_stack.top() != main && !scope_stack.empty()) {
    //*scope_stack.top() << "}" << endl;
    //scope_stack.pop();
    closeScope();
  }
  cur_stream = main;
}

void CPPGenerator::printIndent(void) {
  for (int i = 0; i < indent_level; i++) {
    *cur_stream << "  ";
  }
}
