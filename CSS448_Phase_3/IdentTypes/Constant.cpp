#include "Constant.h"


// Constructor
Constant::Constant(const string& name) : IdentRecord(name) {
  i = 0;
  b = false;
  s = "";
  ir = NULL;
  type = "";
}


// Destructor
Constant::~Constant(void) {
}


// display
// Prints data
void Constant::display(ostream& sout, int depth)const {
  printIndent(sout, depth);
	sout << identName << " ";
  if (type == "i") {
    sout << i;
  } else if (type == "s") {
    sout << s;
  } else if (type == "b") {
    sout << b;
  } else if (type == "ir") {
    if (type == "") {
      //FIXME: if it's null, is it safe to assume it's nil
      sout << "Nil"; 
    } else {
      //Use depth 0 since we already printed padding
      ir->display(sout, 0);
    }
  }
}

string Constant::toString(void)const {
  ostringstream oss;
  if (type == "s") {
    oss << s;
  } else if(type == "b") {
    oss << (b ? "true" : "false");
  } else if(type == "i") {
    oss << i;
  }
  return oss.str();
}
