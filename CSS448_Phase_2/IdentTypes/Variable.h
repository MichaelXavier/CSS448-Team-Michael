#ifndef VARIABLE_H
#define VARIABLE_H
#include <iostream>
#include "IdentRecord"

class Variable : public IdentRecord {
public:

private:
  //TODO: figure out how we want to store type
  IdentRecord* value;//FIXME: not sure if this is how we will implement it
  string name;//FIXME: not sure if we should use a string or char* or something else
}
#endif
