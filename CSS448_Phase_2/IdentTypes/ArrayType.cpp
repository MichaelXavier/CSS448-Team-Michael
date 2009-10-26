#include "ArrayType.h"

ArrayType::ArrayType(const string& name) : IdentRecord(name) {
	dimensions = 0;
}

ArrayType::~ArrayType(void) {
}

void ArrayType::display(int depth)const {
  printIndent(depth);
	cout << identName << " ";
	for(int i = 0; i < dimensions; i++)
	{
		cout << ranges[i].low << ".." << ranges[i].high;
		if(i != dimensions-1)
			cout << ",";
	}

	cout << " " << typePtr->getName();
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
