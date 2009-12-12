// CPPGenerator.h
// This class is called from 'y' to generate code

#ifndef CPPGENERATOR_H
#define CPPGENERATOR_H
#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <stack>
#include <vector>
#include "IdentTypes/IdentRecord.h"
#include "IdentTypes/Constant.h"
#include "ParsingHelpers/ConstDecHelper.h"
#include "ParsingHelpers/ArrayHelper.h"
#include "ParsingHelpers/PointerHelper.h"
#include "ParsingHelpers/RecordHelper.h"
#include "ParsingHelpers/FunctionHelper.h"
#include "ParsingHelpers/ProcedureHelper.h"

extern void yyerror(const char *s);

using namespace std;

class CPPGenerator {
public:
  CPPGenerator(ostream&); // Constructor
  ~CPPGenerator(void);    // Destructor

  // Prints necessary #includes, #defines, and typedefs, and start of main
  void setup(void);

// Closes the main function
  void teardown(void);

  void print(void);

  // Prints code for declaring variables.
  void declareVars(queue<string> idents, IdentRecord* type);

  void declareProc(const string&, queue<string>);
  void declareProc(const string&, ProcedureHelper&); // Prints code for declaring a procedure
  void declareFunct(const string&, FunctionHelper&); // Prints code for declaring a function
  void closeFunct(void); // Closes a function and handles the return type

  // Prints a #include statement
  void addInclude(const string&);

  // Prints a constant declaration
  void declareConst(ConstDecHelper*, Constant*); 
  
  void declareArray(ArrayHelper*);		// Prints an array typedef
  void declarePointer(PointerHelper*);  // Prints a pointer typedef
  void declareRecord(RecordHelper*);    // Prints a record declaration (struct)

  void startIfExpr(void);	// Prints start of if expression
  void closeIfExpr(void);	// Prints close of if expression
  void startElseExpr(void);	// Prints start of else expression

  void startCase(void);	 // Prints start of Pascal case expression (switch in C++)
  void breakCase(void);  // Prints a break statement during a case
  void writeCaseLabel(Constant*);	// Prints a C++ case label

  void startWhile(void);	// Prints start of a while loop

  void startRepeat(void);	// Prints the start of a do while loop (repeat loop in Pascal)
  void closeRepeat(const string&);	// Closes do while loop

  void startFor(const string&);	// Starts a for loop
  void completeFor(const string&, const string&, bool);	  // Completes the first line of a for loop

  void allocVar(const string&);	  // Prints new to allocate memory
  void deallocVar(const string&); // Prints delete to de-allocate memory

  void writeStr(string);		// Writes a string to the current stream
  void writeStrWI(string);		// Writes a string to the current stream and includes an indent

  void startBlock(void); // Starts a new block by printing a '{' and increasing the indent level by 1
  void endBlock(void);   // Closes a block by printing a '}' and decreasing the indent level by 1

  void closeScope(void);

  void coutExpr(const string&, bool newline = false);	// Prints cout expression
  void cinExpr(const string&, bool readln = false);     // Prints cin expression
  void coutLn(void);	// Prints empty line
  void cinLn(void);     // Goes to next line of input

  void declareSetType(const string&, int, int); // Prints declaration of a set object

  void defineIO(queue<string>);

  void callProc(const string&, const string&);
private:
  void typeDef(const string&, const string&);   // Writes a typedef

  void popScope(void);

  void closeAllScopes(void);

  ostringstream* cur_stream;
  //FIXME: consider stack of streams for scope?
  
  ostringstream* before_main;
  ostringstream* main;
  stack<ostringstream*>scope_stack;
  stack<Function*>funct_stack;
  vector<ostringstream*>function_streams;
  ostream& output; 

  void printIndent(void);  // Prints an indent, depending on current indent level

  int indent_level;
};
#endif
