#include "ArrayType.h"

// Constructor
ArrayType::ArrayType(const string& name) : IdentRecord(name) {
  dimensions = 0;
  instanceName = "ArrayType";
}


// Destructor
ArrayType::~ArrayType(void) {
}


// display
// Prints data
void ArrayType::display(ostream& sout, int depth)const {

	if (typePtr == NULL) {
	// typePtr must be set in order to display data
    sout << "Error: typePtr of " << identName << " not set";
    return;
  }

  printIndent(sout, depth);

  sout << identName << " ";

	for(int i = 0; i < dimensions; i++)
	{
		sout << ranges[i].low << ".." << ranges[i].high;
		if(i != dimensions-1)
			sout << ", ";
	}

	sout << " " << typePtr->getName();
}


// addDimension
// Adds a dimension with low and high ranges
void ArrayType::addDimension(int low, int high)
{
	dimensions++;
	ranges.push_back(Range());
	ranges[dimensions-1].low = low;
	ranges[dimensions-1].high = high;
}


// setTypePtr
void ArrayType::setTypePtr(IdentRecord* type)
{
	typePtr = type;
}


// Returns a vector of low range values for each dimension
queue<int>* ArrayType::getLowRangeValues()
{
	queue<int>* ret = new queue<int>();
	for(int i = 0; i < dimensions; i++) 
		ret->push(ranges[i].low);
	return ret;
}