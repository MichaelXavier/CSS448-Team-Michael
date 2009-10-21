#ifndef PROCEDURE_H
#define PROCEDURE_H
#include <iostream>
#include "IdentRecord.h"
#include "STObject.h"

using namespace std;

class Procedure : public IdentRecord {
public:
	Procedure(string);
	~Procedure();

	void display();
	void insertParameter(IdentRecord*, IdType);
	

private:
	// possibly a list of parameters
};
#endif
