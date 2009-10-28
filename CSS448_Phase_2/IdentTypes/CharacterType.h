#ifndef CHARACTERTYPE_H
#define CHARACTERTYPE_H
#include <iostream>
#include "IdentRecord.h"

class CharacterType : public IdentRecord {
public:
	CharacterType(const string& name);		// Constructor
	~CharacterType(void);				// Destructor

	void display(ostream& sout, int depth)const;
};
#endif
