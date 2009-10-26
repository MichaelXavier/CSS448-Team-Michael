#ifndef CHARACTERTYPE_H
#define CHARACTERTYPE_H
#include <iostream>
#include "IdentRecord"

class CharacterType : public IdentRecord {
public:
	Character(const string& name);		// Constructor
	~Character(void);				// Destructor

	void display(int depth)const;

private:
}
#endif
