#ifndef POINTERTYPE_H
#define POINTERTYPE_H
#include <iostream>
#include "IdentRecord.h"

extern void yyerror(const char *s);

class PointerType : public IdentRecord {
public:
	PointerType(const string& name, const string& declared);
	~PointerType(void);
	
	void display(ostream& sout, int depth)const;
	void setPointObj(IdentRecord* obj);	// Sets typePtr and checks if
									  // obj's identifier matches declared_type
	string getDeclaredType() {return declared_type;}
	IdentRecord* getTypePtr() { return typePtr;}

private:
	IdentRecord* typePtr; // The data type of this object

    string declared_type;	// This is used to make sure that typePtr
							// matches the initial parameter in the
							// constructor.
};
#endif
