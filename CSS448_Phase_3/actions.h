// actions.cpp
// Contains various functions that are used in 'y'

#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include "IdType.h"
#include "STObject.h"

#include "IdentTypes/IdentRecord.h"
#include "IdentTypes/ArrayType.h"
#include "IdentTypes/BooleanType.h"
#include "IdentTypes/CharacterType.h"
#include "IdentTypes/Constant.h"
#include "IdentTypes/Function.h"
#include "IdentTypes/IdentRecord.h"
#include "IdentTypes/IntegerType.h"
#include "IdentTypes/Parameter.h"
#include "IdentTypes/PointerType.h"
#include "IdentTypes/Procedure.h"
#include "IdentTypes/ProgramParameter.h"
#include "IdentTypes/RealType.h"
#include "IdentTypes/RecordField.h"
#include "IdentTypes/RecordType.h"
#include "IdentTypes/SetType.h"
#include "IdentTypes/Variable.h"

#include "ParsingHelpers/ArrayHelper.h"
#include "ParsingHelpers/ConstDecHelper.h"
#include "ParsingHelpers/FunctionHelper.h"
#include "ParsingHelpers/PointerHelper.h"
#include "ParsingHelpers/ProcedureHelper.h"
#include "ParsingHelpers/ProgramHelper.h"
#include "ParsingHelpers/RecordHelper.h"
#include "ParsingHelpers/SetHelper.h"
#include "ParsingHelpers/TypeHelper.h"
#include "ParsingHelpers/VarDecHelper.h"

using namespace std;

extern string s;  // string from lexical analyzer
extern STObject* symTable;  // pointer to the symbol table stored in 'y'
extern void yyerror(const char *s);

// Initializes the symbol table, with a program IdentRecord
void startProgram(Program* newProg);

// Closes all scopes and deletes the symbol table
void endProgram(void);

// Converts a string to an int
bool strToInt(string& str, int& target);

// Converts an int to a string
bool intToString(string& target, int& number);

// Checks if a type matches that of any unresolved pointers
// If so, the pointer is resolved
void resolvePointers(IdentRecord* newTypePtr, vector<PointerType*>& ptrs);

// Checks if there are any unresolved points
void checkPointers(vector<PointerType*>& ptrs);

//
void dumpPointer(PointerType* ptr);

// Converts a captured integer set expression to a printing format.
string convertSetExpr(const string& expr);

// Converts single quotes to double quotes
string convertSingleQuote(const string& expr);

// Converts double quotes to single quotes
string convertDoubleQuote(string& expr);

// Deletes single quotes around a string
void deleteSingleQuote(string& expr);

// Checks a string-type array range lower/upper bounds, returns if valid
bool validRange(const string& low, const string& high);
