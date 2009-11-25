#ifndef CONSTANT_H
#define CONSTANT_H
#include <iostream>
#include "IdentRecord.h"

class Constant : public IdentRecord {

public:
	Constant(const string& name);		
	~Constant(void);				

	void display(ostream& sout, int depth)const;

  void setConstFactor(int value) { i = value; type = "i"; }
  void setConstFactor(const string& value) { s = value; type = "s"; }
  void setConstFactor(bool value) { b = value; type = "b"; }
  void setConstFactor(IdentRecord* value) { ir = value; type = "ir"; }

  int getConstInt() { return i;}
  string getConstString() { return s;}
  bool getConstBool() {return b;}
  IdentRecord* getConstIR() {return ir;}
  string getConstType() {return type;}

private:
  int i;
  string s;
  bool b;
  IdentRecord* ir;

  string type;
};
#endif
