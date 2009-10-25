#include "Function.h"

FunctionType::FunctionType(const string& name) : IdentRecord(name) {
  returnType = NULL;
}

FunctionType::~FunctionType(void) {
}
