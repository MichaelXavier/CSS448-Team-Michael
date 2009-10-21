#ifndef INTEGERTYPE_H
#define INTEGERTYPE_H
#include <iostream>
#include "IdentRecord"

class IntegerType : public IdentRecord {
public:

  //setter for the internal value
  //FIXME: lexical analzyer will presumably pass in a string which we must coerce to an integer
  //bool return type is not set in stone, might instead want to throw an exception if a string is
  //provided which cannot be coerced to an integer
  bool setValue(const string&);
private:
  int value;//FIXME: unsure as to whether or not this is the proper approach
}
#endif
