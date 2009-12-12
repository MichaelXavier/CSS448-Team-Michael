#ifndef ARRAYTYPE_H
#define ARRAYTYPE_H
#include <iostream>
#include <vector>
#include <queue>
#include "IdentRecord.h"

using namespace std;

class ArrayType : public IdentRecord {

public:
	ArrayType(const string& name);
	~ArrayType(void);

	void display(ostream& sout, int depth)const; // Displays data
	void addDimension(int, int); // Adds a dimension to the array
	void setTypePtr(IdentRecord*);   // Sets the type pointer

	queue<int>* getLowRangeValues(); // Returns a queue of low range values
									  // for each dimension

	int getNumberDimensions() { return dimensions;}

private:
	// The low and high values of an array dimension
	struct Range
	{
		int low;	// The low value of the range of an array dimension
		int high;   // The high value of the range of an array dimension
	};
	vector<Range> ranges;	// List of low and high range for each dimension
	int dimensions;			// The number of dimensions the array currently has
	
	IdentRecord* typePtr;	// Pointer to an object type
};
#endif
