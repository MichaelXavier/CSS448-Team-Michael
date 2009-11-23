#define CONSTDECHELPER_H
#ifndef CONSTDECHELPER_H

#include <iostream>
#include <string>
#include "IdType.h"
#include "../IdentRecords/Constant.h"

using namespace std;

class ConstDecHelper()
{
public:
	ConstDecHelper(void);
	~ConstDecHelper(void);
	
  //FIXME: constfactors can be strings, numbers, true, false, nil, or idents
	bool AddConst(Constant* val);
	bool sendToST(STObject* st);

private:
	vector<Constant*> consts;
};
#endif
