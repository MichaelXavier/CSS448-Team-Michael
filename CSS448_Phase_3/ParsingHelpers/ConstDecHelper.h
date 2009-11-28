#ifndef CONSTDECHELPER_H
#define CONSTDECHELPER_H
#include <iostream>
#include <string>
#include <queue>
#include "../IdType.h"
#include "../IdentTypes/Constant.h"
#include "../STObject.h"
#include "TypeHelper.h"
using namespace std;

class ConstDecHelper// : public TypeHelper
{
public:
	//ConstDecHelper(const string& type_name);
	ConstDecHelper(void); //FIXME: added because there isn't really a need to name a "collection" of Constants
	~ConstDecHelper(void);
  //FIXME: constfactors can be strings, numbers, true, false, nil, or idents
	bool sendToSt(STObject* st);
	bool addConst(Constant* val);
private:
	
	vector<Constant*> consts;
    bool clean;
    bool validate(void); 
};
#endif

