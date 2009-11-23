#ifndef CONSTANT_H
#define CONSTANT_H
#include <iostream>
#include "IdentRecord.h"

class Constant : public IdentRecord {

public:
	Constant(const string& name);		
	~Constant(void);				

	void display(ostream& sout, int depth)const;

  void setConstFactor(int value) { constFactor.i = value; type = "i"; }
  void setConstFactor(const string& value) { constFactor.s = value; type = "s"; }
  void setConstFactor(bool value) { constFactor.b = value; type = "b"; }
  void setConstFactor(IdentRecord* value) { constFactor.ir = value; type = "ir"; }

private:
  //Switched to using a union
  union typedConst {
    int i;
    string s;
    bool b;
    //FIXME: unsure about this
    IdentRecord* ir;
  } constFactor;
  
  string type;
};
#endif
