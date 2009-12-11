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
    cout << "DEBUG: str const fact set to " << value << " " << s << endl;
    type.clear();
    type = "i";
    cout << "DEBUG: type set to " << type << endl;}
  void setConstFactor(const string& value) {  
    s = value;
    cout << "DEBUG: str const fact set to " << value << " " << s << endl;
    type.clear();
    type = "s";
    cout << "DEBUG: type set to " << type << endl; }
  void setConstFactor(bool value) { b = value; type = "b"; }
  void setConstFactor(IdentRecord* value) { ir = value; type = "ir"; }

  int getConstInt(void) { return i;}
  string getConstString(void) { return s;}
  bool getConstBool(void) {return b;}
  IdentRecord* getConstIR(void) {return ir;}
  string getConstType(void) { cout << "DEBUG: getConstType called." << endl; return type;}

  string toString(void)const;

private:
  int i;
  string s;
  bool b;
  IdentRecord* ir;

  string type;
};
#endif
