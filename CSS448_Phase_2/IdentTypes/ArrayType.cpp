#include "ArrayType.h"

ArrayType::ArrayType(const string& name) : IdentRecord(name) {
	dimensions = 0;
}

ArrayType::~ArrayType(void) {
}

void ArrayType::display(ostream& sout, int depth)const {
  if (typePtr == NULL) {
    //FIXME: just going to print the error and bail at this point
    sout << "Error: typePtr of " << identName << " not set";
    return;
  }

  printIndent(sout, depth);

  //Don't print if its an anonymous array type
  sout << identName << " ";

	for(int i = 0; i < dimensions; i++)
	{
		sout << ranges[i].low << ".." << ranges[i].high;
		if(i != dimensions-1)
			sout << ", ";
	}

	sout << " " << typePtr->getName();
}


void ArrayType::addDimension(int low, int high)
{
	dimensions++;
	ranges.push_back(Range());
	ranges[dimensions-1].low = low;
	ranges[dimensions-1].high = high;
}


void ArrayType::setTypePtr(IdentRecord* type)
{
	typePtr = type;
}
