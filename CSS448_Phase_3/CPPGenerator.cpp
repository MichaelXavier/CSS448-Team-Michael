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
  *before_main << "#define True true" << endl
    << "#define False false" << endl
    << "#define Nil NULL" << endl //TODO: more?
    << "typedef int integer;" << endl
    << "typedef double real;" << endl
    << "typedef bool boolean;" << endl
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

void CPPGenerator::declareProc(const string& name, ProcedureHelper& helper) {
  ostringstream* oss = new ostringstream();
  queue<Parameter*> params = helper.getParams();
  *oss << "void " << name << " (";
  //if (params.empty()) { cout << "DEBUG: params on declareFunct is empty" << endl; }

  Parameter* param;
  while (!params.empty()) {
    param = params.front();
    IdentRecord* param_type = param->getTypePtr();
    if (param != NULL && param_type != NULL) {
      *oss << param_type->getName() << " " << param->getName(); 
    }
    params.pop();
    if (!params.empty()) {
      *oss << ", ";
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

void CPPGenerator::declareFunct(const string& name, FunctionHelper& helper) {
  ostringstream* oss = new ostringstream();
  queue<Parameter*> params = helper.getParams();
  IdentRecord* ret_type = helper.getReturnType();
  *oss << ret_type->getName() << " " << name << "(";
  //if (params.empty()) { cout << "DEBUG: params on declareFunct is empty" << endl; }

  Parameter* param;
  while (!params.empty()) {
    param = params.front();
    IdentRecord* param_type = param->getTypePtr();
    if (param != NULL && param_type != NULL) {
      *oss << param_type->getName() << " " << param->getName(); 
    }
    params.pop();
    if (!params.empty()) {
      *oss << ", ";
    }
  }
  *oss << ") {" << endl;

  //Push to function vector for later
  function_streams.push_back(oss);

  funct_stack.push(helper.getFunctPtr());

  //We are now in this function's scope
  scope_stack.push(oss);

  //set up the current stream to this scope
  cur_stream = oss;

  //Reset indent level for this scope
  indent_level = 1;

  //Declare function return variable
  printIndent();
  queue<string>ret_name;
  ret_name.push(funct_stack.top()->getName()); 
  declareVars(ret_name, ret_type);
}

void CPPGenerator::closeFunct(void) {
  if (!funct_stack.empty()) {
    printIndent();
    *cur_stream << "return " << funct_stack.top()->getName() << ";" << endl;
    funct_stack.pop();
  }
  //FIXME: experimental, add return statement
  closeScope();
}

void CPPGenerator::addInclude(const string& include) {
  //FIXME: error check?
  *before_main << "#include " << include << endl;
}

void CPPGenerator::declareConst(ConstDecHelper* ch, Constant* c) {
  //FIXME: this is a bit of a hack, if the current scope is main, define it up as a global
  if (c != NULL) {
    printIndent();
    ostringstream* out = (cur_stream == main) ? before_main : cur_stream;
    *out << "const "; 
    
    string constType = c->getConstType();
    
    if (constType == "s") {
      *out << "char* " << ch->getConstName() << " = " << c->getConstString();
    } else if(constType == "b") {
      *out << "bool " << ch->getConstName() << " = " << (c->getConstBool() ? "true" : "false");
    } else if(constType == "i") {
      *out << "int " << ch->getConstName() << " = " << c->getConstInt();
    }    
    *out << ";" << endl;
  }
}

void CPPGenerator::declareArray(ArrayHelper* arrayHelper) {
	string name = arrayHelper->getName();
	string typeName = arrayHelper->getType()->getName();
	vector<int>* ranges = arrayHelper->getRangeValues();

	printIndent();
	*before_main << "typedef " << typeName << " " << name << "[" << (*ranges)[0];
	for(int i = 1; i < ranges->size(); i++) {
		*before_main << "][" << (*ranges)[i];
	}
	*before_main << "];" << endl;

	delete ranges;
	ranges = NULL;
}

void CPPGenerator::declarePointer(PointerHelper* pointerHelper) {
	string declaredType = pointerHelper->getDeclaredType();
	string pointerName = pointerHelper->getName();

	if(declaredType != "integer" && declaredType != "boolean" 
		&& declaredType != "char" && declaredType != "real")
	{
		*before_main << "struct " << declaredType << ";\n";
	}
	*before_main << "typedef " << declaredType << "* " << pointerName << ";\n";
}

void CPPGenerator::declareRecord(RecordHelper* recordHelper) {
	vector<RecordField*>* recordFields = recordHelper->getRecordFields();

	*before_main << "struct " << recordHelper->getTypeName() << " {\n";
	for(int i = 0; i < recordFields->size(); i++)
	{
		*before_main << "   " << (*recordFields)[i]->getTypePtrName() << " ";
		*before_main << (*recordFields)[i]->getName() << ";\n";
	}
	*before_main << "};\n";

	recordFields = NULL;
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
	*cur_stream << "break;" << endl;
}

void CPPGenerator::writeCaseLabel(Constant* constant) {
  printIndent();
  *cur_stream <<  "case ";
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
	*cur_stream << ": " << endl;
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

void CPPGenerator::startFor(const string& expr) {
  printIndent();
  *cur_stream << "for(" << expr << "; ";
}

void CPPGenerator::completeFor(const string& iter, const string& expr, bool inc) {
	*cur_stream << iter << (inc ? " <= " : " >= ") << expr << "; " << iter << (inc ? "++" : "--") << ")";
}

void CPPGenerator::allocVar(const string& var) {
  printIndent();
  *cur_stream << "new " << var;// << ";" << endl;
}

void CPPGenerator::deallocVar(const string& var) {
  printIndent();
  *cur_stream << "delete " << var;// << ";" << endl;
}

void CPPGenerator::writeStr(string expression)
{
	*cur_stream << expression;
}

void CPPGenerator::writeStrWI(string expression)
{
	printIndent();
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
  //*cur_stream << ";" << endl;//DEBUG
}

void CPPGenerator::cinExpr(const string& expr, bool readln) {
  printIndent();
  *cur_stream << "cin >> " << expr;// << ";" << endl;
  if(readln) {
	  *cur_stream << "cin.ignore(1000, '\n');" << endl;
  }
}

void CPPGenerator::coutLn(void)
{
	printIndent();
	*cur_stream << "cout << endl";
}

void CPPGenerator::cinLn(void)
{
	printIndent();
	*cur_stream << "cin.ignore(1000, '\n')";//;" << endl;
}

void CPPGenerator::declareSetType(const string& name, int low, int high) {
  if (low <= high) {
    ostringstream oss;
    oss << "IntSet(" << low << ", " << high << ")";
    typeDef(name, oss.str());
  } else {
    cout << "Error: low range of set " << name << " is greater than the high range." << endl;
  }
}

void CPPGenerator::typeDef(const string& name, const string& body) {
  printIndent();
  *cur_stream << "typedef " << body << " " << name << ";" << endl;
}

void CPPGenerator::defineIO(queue<string> params) {
  //take up to the first 2 and #define them to cin, cout respectively
  //do input
  if (params.empty()) {
    return;
  }
  *before_main << "#define " << params.front() << " cin" << endl;
  params.pop();

  //do output if a param is there
  if (params.empty()) {
    return;
  }
  *before_main << "#define " << params.front() << " cout" << endl;
}

void CPPGenerator::callProc(const string& proc, const string& expr) {
  printIndent();
  *cur_stream << proc << '(' << expr << ')';//FIXME: semicolon?
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
