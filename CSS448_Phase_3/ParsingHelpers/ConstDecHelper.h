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
	IdentRecord* sendToSt(STObject* st);
	bool setConstName(string name);
	void setConstObj(Constant* obj);

  string getConstName(void) { return constName; }
  //IdentRecord* getConstObj(void) { return constObj; }
private:
	string constName;
	IdentRecord* constObj;
    bool clean;
    bool validate(void); 
};
#endif

