#ifndef FUNCTION_H
#define FUNCTION_H
#include <iostream>
#include <list>
#include "IdentRecord"

class Function : public IdentRecord {
public:

private:
  IdentRecord* returnType;
  List<IdentRecord*> parameters;//FIXME: this implementation not set in stone
}
#endif
