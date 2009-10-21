#ifndef REALTYPE_H
#define REALTYPE_H
#include <iostream>
#include "IdentRecord"

class RealType : public IdentRecord {
public:

  //setter for the internal value
  //FIXME: lexical analzyer will presumably pass in a string which we must coerce to an double
  //bool return type is not set in stone, might instead want to throw an exception if a string is
  //provided which cannot be coerced to an double
  bool setValue(const string&);
private:
  double value;//FIXME: unsure as to whether or not this is the proper approach
}
#endif
