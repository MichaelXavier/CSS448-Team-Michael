#ifndef RECORDTYPE_H
#define RECORDTYPE_H
#include <iostream>
#include <list>//FIXME: might use a different lib elsewhere
#include "IdentRecord"

class RecordType : public IdentRecord {
public:

private:
  list<IdentRecord*> data_members;//FIXME: stab in the dark at the implementation
}
#endif
