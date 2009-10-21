#include "SetType.h"

SetType::SetType(string ident)
{
	identName = ident;
	m_low = -1;
	m_high = -1;
}

void SetType::display()
{
	cout << identName << " " << m_low << ".." << m_high;
}


void SetType::setRange(int low, int high)
{
	m_low = low;
	m_high = high;
}