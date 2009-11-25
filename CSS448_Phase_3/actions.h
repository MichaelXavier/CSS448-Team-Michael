#include <iostream>
#include <string>
#include <sstream>
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
#include "ParsingHelpers/TypeDefHelper.h"
#include "ParsingHelpers/VarDecHelper.h"

using namespace std;

extern string s;
extern STObject* symTable;

void startProgram(Program* newProg);
void endProgram(void);
int strToInt(const string& str);
void resolvePointers(IdentRecord* newTypePtr, vector<PointerHelper*>& ptrs);
void checkPointers(vector<PointerHelper*>& ptrs);
