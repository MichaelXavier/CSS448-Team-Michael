#include <iostream>
#include <string>
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

#include "ParsingHelpers/arrayHelper.h"
#include "ParsingHelpers/constDecHelper.h"
#include "ParsingHelpers/functionHelper.h"
#include "ParsingHelpers/pointerHelper.h"
#include "ParsingHelpers/procedureHelper.h"
#include "ParsingHelpers/programHelper.h"
#include "ParsingHelpers/recordHelper.h"
#include "ParsingHelpers/setHelper.h"
#include "ParsingHelpers/typeDefHelper.h"
#include "ParsingHelpers/varDecHelper.h"

using namespace std;

extern string s;
extern STObject* symTable;

void startProgram(const string&);
void endProgram(void);
