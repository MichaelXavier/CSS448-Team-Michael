#ifndef STRINGTYPE_H
#define STRINGTYPE_H
#include <iostream>
#include "IdentRecord"

class StringType : public IdentRecord {
public:

  //setter for the internal value
  bool setValue(const string&);
private:
  string value;//FIXME: unsure as to whether or not this is the proper approach
}
#endif
