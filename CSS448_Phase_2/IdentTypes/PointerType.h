#ifndef POINTERTYPE_H
#define POINTERTYPE_H
#include <iostream>
#include "IdentRecord.h"


// Note: not sure if this class is correct
class PointerType : public IdentRecord {
public:
	PointerType(string);
	~PointerType();
	
	void display();
	void setPointObj(IdentRecord* obj) {pointsToObj = obj;}

private:
	IdentRecord* pointsToObj;	// The object pointed to by the pointertype object

};
#endif
