#include "CPPGenerator.h"


// Constructor
// Sets up streams and sets main as the current stream
CPPGenerator::CPPGenerator(ostream& out) : output(out) {
  before_main = new ostringstream();
  main = new ostringstream();
  cur_stream = main;
  scope_stack.push(main);
  indent_level = 1;
}


// Destructor
// Deletes streams
CPPGenerator::~CPPGenerator(void) {
  delete before_main;
  delete main;
  for (int i = 0; i < function_streams.size(); i++) {
    delete function_streams[i];
  }
}


// setup
// Prints necessary #includes, #defines, and typedefs, and start of main
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


// teardown
// Closes the main function
void CPPGenerator::teardown(void) {
  *main << "}" << endl;
}


// print
// 
void CPPGenerator::print(void) {
  closeAllScopes();
  output << before_main->str();
  for (unsigned int i = 0; i < function_streams.size(); i++) {
    output << function_streams[i]->str();
  }
  output << main->str();//FIXME: iterate through other streams?
}


// declareVars
// Prints code for declaring variables.  Reads a list of variable identifiers
// and the variable type.
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


// declareProc
// Prints code for declaring a procedure, including parameters.  A ProcedureHelper
// object is used to help get the parameters.
void CPPGenerator::declareProc(const string& name, ProcedureHelper& helper) {
  ostringstream* oss = new ostringstream();
  queue<Parameter*> params = helper.getParams();

  // Prints the name of the procedure
  *oss << "void " << name << " (";

  // Prints the parameters
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


// declareFunct
// Prints code for declaring a procedure, including parameters.  Similar to declareProcedure(),
// except it prints a non-void return type.
void CPPGenerator::declareFunct(const string& name, FunctionHelper& helper) {
  ostringstream* oss = new ostringstream();
  queue<Parameter*> params = helper.getParams();
  IdentRecord* ret_type = helper.getReturnType();

  // Prints name and return type of function
  *oss << ret_type->getName() << " " << name << "(";

  // Prints function parameters
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


// closeFunct
// Closes a function and handles the return type.
void CPPGenerator::closeFunct(void) {
  if (!funct_stack.empty()) {
    printIndent();
    *cur_stream << "return " << funct_stack.top()->getName() << ";" << endl;
    funct_stack.pop();
  }
  //FIXME: experimental, add return statement
  closeScope();
}


// addInclude
//  Prints a #include statement
void CPPGenerator::addInclude(const string& include) {
  *before_main << "#include " << include << endl;
}


// declareConst
// Prints a constant declaration
void CPPGenerator::declareConst(ConstDecHelper* ch, Constant* c) {
  //FIXME: this is a bit of a hack, if the current scope is main, define it up as a global
  if (c != NULL) {
    printIndent();
    ostringstream* out = (cur_stream == main) ? before_main : cur_stream;
    *out << "const "; 
    
	// Gets the type of constant
    string constType = c->getConstType();
    
	// Prints constant depending on constant type
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


// declareArray
// Prints an array typedef
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


// declarePointer
// Prints a pointer typedef.  It is assumed that pointers only point to
// integers, booleans, chars, reals, and records.  If the pointer points to
// a record, a forward declaration of the record is printed.
void CPPGenerator::declarePointer(PointerHelper* pointerHelper) {
	string declaredType = pointerHelper->getDeclaredType();
	string pointerName = pointerHelper->getName();

	// Checks to see if the pointer points to a record
	if(declaredType != "integer" && declaredType != "boolean" 
		&& declaredType != "char" && declaredType != "real")
	{
		// Forward declaration
		*before_main << "struct " << declaredType << ";\n";
	}
	// Prints pointer typedef
	*before_main << "typedef " << declaredType << "* " << pointerName << ";\n";
}


// declareRecord
// Prints a record declaration.  The record is tranlated to C++ as a struct.
void CPPGenerator::declareRecord(RecordHelper* recordHelper) {
	vector<RecordField*>* recordFields = recordHelper->getRecordFields();

	*before_main << "struct " << recordHelper->getTypeName() << " {\n";
	// Print record fields
	for(int i = 0; i < recordFields->size(); i++)
	{
		*before_main << "   " << (*recordFields)[i]->getTypePtrName() << " ";
		*before_main << (*recordFields)[i]->getName() << ";\n";
	}
	*before_main << "};\n";

	recordFields = NULL;
}


// startIfExpr
// Prints start of if expression
void CPPGenerator::startIfExpr(void) {
  printIndent();
  *cur_stream << "if (";
}


// closeIfExpr
// Prints close of if expression
void CPPGenerator::closeIfExpr(void) {
  *cur_stream << ")";
}


// startElseExpr
// Prints start of else expression
void CPPGenerator::startElseExpr(void) {
  printIndent();
	*cur_stream << "else ";
  startBlock();
}


// startCase
// Prints start of Pascal case expression (switch in C++)
void CPPGenerator::startCase(void) {
  printIndent();
	*cur_stream << "switch(";
}


// breakCase
// Prints a break statement during a case
void CPPGenerator::breakCase(void) {
	printIndent();
	*cur_stream << "break;" << endl;
}


// writeCaseLabel
// Prints a C++ case label by translating a constant expression
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


// startWhile
// Prints start of a while loop
void CPPGenerator::startWhile(void) {
  printIndent();
  *cur_stream << "while(";
}


// startRepeat
// Prints the start of a do while loop (repeat loop in Pascal)
void CPPGenerator::startRepeat(void) {
  printIndent();
  *cur_stream << "do";
  startBlock();
}


// closeRepeat
// Closes do while loop
void CPPGenerator::closeRepeat(const string& expr) {
  endBlock();
  printIndent();
  *cur_stream << "while(!" << expr << ");" << endl;
}


// startFor
// Starts a for loop (initialize variable component)
void CPPGenerator::startFor(const string& expr) {
  printIndent();
  *cur_stream << "for(" << expr << "; ";
}


// completeFor
// Completes the first line of a for loop (check variable condition and increment/decrement variable components)
void CPPGenerator::completeFor(const string& iter, const string& expr, bool inc) {
	*cur_stream << iter << (inc ? " <= " : " >= ") << expr << "; " << iter << (inc ? "++" : "--") << ")";
}


// allocVar
// Prints new to allocate memory
void CPPGenerator::allocVar(const string& var) {
  printIndent();
  *cur_stream << "new " << var;// << ";" << endl;
}


// deallocVar
// Prints delete to de-allocate memory
void CPPGenerator::deallocVar(const string& var) {
  printIndent();
  *cur_stream << "delete " << var;// << ";" << endl;
}


// writeStr
// Writes a string to the current stream
void CPPGenerator::writeStr(string expression)
{
	*cur_stream << expression;
}


// writeStrWI
// Writes a string to the current stream and includes an indent
void CPPGenerator::writeStrWI(string expression)
{
	printIndent();
	*cur_stream << expression;
}


// startBlock
// Starts a new block by printing a '{' and increasing the indent level by 1
void CPPGenerator::startBlock(void) {
  *cur_stream << endl; 
  printIndent();
  *cur_stream << "{" << endl;
  indent_level++;
}


// endBlock
// Closes a block by printing a '}' and decreasing the indent level by 1
void CPPGenerator::endBlock(void) {
  indent_level--;
  printIndent();
  *cur_stream << "}" << endl;
}


// closeScope
void CPPGenerator::closeScope(void) {
  endBlock();

  if (scope_stack.top() != main && !scope_stack.empty()) {
    scope_stack.pop();
  }

  cur_stream = scope_stack.top();
}


// coutExpr
// Prints cout expression (corresponds to write and writeln in Pascal)
void CPPGenerator::coutExpr(const string& expr, bool newline) {
  printIndent();
  *cur_stream << "cout << " << expr;
  if (newline) {
    *cur_stream << " << endl";
  }
}


// cinExpr
// Prints cin expression (corresponds to read and readln in Pascal)
void CPPGenerator::cinExpr(const string& expr, bool readln) {
  printIndent();
  *cur_stream << "cin >> " << expr;// << ";" << endl;

  // If readln is true, then the first token is read and then the input
  // goes to the next line
  if(readln) {
	  *cur_stream << "cin.ignore(1000, '\n');" << endl;
  }
}


// coutLn
// Prints cout of an empty line
void CPPGenerator::coutLn(void)
{
	printIndent();
	*cur_stream << "cout << endl";
}


// cinLn
// Prints statement for going to the next input line
void CPPGenerator::cinLn(void)
{
	printIndent();
	*cur_stream << "cin.ignore(1000, '\n')";//;" << endl;
}


// declareSetType
// Prints declaration of a set object
void CPPGenerator::declareSetType(const string& name, int low, int high) {
  if (low <= high) {
    ostringstream oss;
    oss << "IntSet(" << low << ", " << high << ")";
    typeDef(name, oss.str());
  } else {
    ostringstream oss("Error: low range of set "); oss << name << " is greater than the high range.";
    yyerror(oss.str().c_str());
  }
}


// typeDef
// Prints a typedef
void CPPGenerator::typeDef(const string& name, const string& body) {
  printIndent();
  *cur_stream << "typedef " << body << " " << name << ";" << endl;
}


// defineIO
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


// callProc
void CPPGenerator::callProc(const string& proc, const string& expr) {
  printIndent();
  *cur_stream << proc << expr;//FIXME: semicolon?
}


// closeAllScopes
void CPPGenerator::closeAllScopes(void) {
  while (scope_stack.top() != main && !scope_stack.empty()) {
    //*scope_stack.top() << "}" << endl;
    //scope_stack.pop();
    closeScope();
  }
  cur_stream = main;
}


// printIndent
// Prints an indent, depending on current indent level
void CPPGenerator::printIndent(void) {
  for (int i = 0; i < indent_level; i++) {
    *cur_stream << "  ";
  }
}
