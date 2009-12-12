#ifndef CONSTANT_H
#define CONSTANT_H
#include <iostream>
#include <sstream>
#include "IdentRecord.h"

class Constant : public IdentRecord {

public:
	Constant(const string& name);		
	~Constant(void);				

	void display(ostream& sout, int depth)const;


  void setConstFactor(int value) { 
    i = value;
    type.clear();
    type = "i";
  }
  void setConstFactor(const string& value) {  
    s = value;
    type.clear();
    type = "s";
  }
  void setConstFactor(bool value) { b = value; type = "b"; }
  void setConstFactor(IdentRecord* value) { ir = value; type = "ir"; }

  int getConstInt(void) { return i;}
  string getConstString(void) { return s;}
  bool getConstBool(void) {return b;}
  IdentRecord* getConstIR(void) {return ir;}
  string getConstType(void) { return type;}

  string toString(void)const;

private:
  int i;
  string s;
  bool b;
  IdentRecord* ir;

  string type;
};
#endif
