#include "ArrayType.h"

ArrayType::ArrayType(const string& name) : IdentRecord(name) {
	dimensions = 0;
}

ArrayType::~ArrayType(void) {
}

void ArrayType::display(ostream& sout, int depth)const {
  printIndent(sout, depth);
	sout << identName << " ";
	for(int i = 0; i < dimensions; i++)
	{
		sout << ranges[i].low << ".." << ranges[i].high;
		if(i != dimensions-1)
			sout << ",";
	}

	sout << " " << typePtr->getName();
}


void ArrayType::addDimension(int low, int high)
{
	dimensions++;
	ranges.reserve(dimensions);
	ranges[dimensions-1].low = low;
	ranges[dimensions-1].high = high;
}


void ArrayType::setTypePtr(IdentRecord* type)
{
	typePtr = type;
}
