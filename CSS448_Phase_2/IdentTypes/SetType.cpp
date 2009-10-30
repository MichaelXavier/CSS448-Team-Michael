#include "SetType.h"


// Constructor
SetType::SetType(const string& name) : IdentRecord(name) {
	m_low = -1;
	m_high = -1;
}


// Destructor
SetType::~SetType(void) {
}


// display
// Prints data
void SetType::display(ostream& sout, int depth)const {
  printIndent(sout, depth);
	sout << identName << " " << m_low << ".." << m_high;
}

// setRange
// Sets low and high of this SetType object's range
void SetType::setRange(int low, int high) {
	m_low = low;
	m_high = high;
}
