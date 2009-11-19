#ifndef REALTYPE_H
#define REALTYPE_H
#include <iostream>
#include "IdentRecord.h"

// Standard type: Real
class RealType : public IdentRecord {
public:
	RealType(const string& name);
  ~RealType(void);
	void display(ostream& sout, int depth)const;					 // Displays data

private:
};
#endif
