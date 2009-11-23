#include "Constant.h"


// Constructor
Constant::Constant(const string& name) : IdentRecord(name) {
  constFactor = 0;
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
    sout << typedConst.i;
  } else if (type == "s") {
    sout << typedConst.s;
  } else if (type == "b") {
    sout << typedConst.b;
  } else if (type == "ir") {
    if (type == NULL) {
      //FIXME: if it's null, is it safe to assume it's nil
      sout << "Nil"; 
    } else {
      //Use depth 0 since we already printed padding
      typedConst.ir->display(sout, 0);
    }
  }
}
