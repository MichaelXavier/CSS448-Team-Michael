#ifndef POINTERTYPE_H
#define POINTERTYPE_H
#include <iostream>
#include "IdentRecord.h"


// Note: not sure if this class is correct
class PointerType : public IdentRecord {
public:
	PointerType(const string& name, const string& declared);
	~PointerType(void);
	
	void display(ostream& sout, int depth)const;
	void setPointObj(IdentRecord* obj);

private:
  //Because pointers can be declared before their types are, it would seem that we need to also store the declared type for
  //The pointer so that it can be checked against the type of the object to which it points
	IdentRecord* typePtr;

  string declared_type;
};
#endif
