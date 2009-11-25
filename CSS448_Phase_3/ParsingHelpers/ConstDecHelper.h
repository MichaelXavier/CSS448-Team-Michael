/*#ifndef CONSTDECHELPER_H
#define CONSTDECHELPER_H

#include <iostream>
#include <string>
#include "../IdType.h"
#include "../IdentTypes/Constant.h"
#include "../STObject.h"

using namespace std;

class ConstDecHelper
{
public:
	ConstDecHelper(void);
	~ConstDecHelper(void);
	
  //FIXME: constfactors can be strings, numbers, true, false, nil, or idents
	bool AddConst(Constant* val);
	bool sendToSt(STObject* st);

private:
	vector<Constant*> consts;
};
#endif
*/

#ifndef CONSTDECHELPER_H
#define CONSTDECHELPER_H

#include <iostream>
#include <string>
#include "../IdType.h"
#include "../IdentTypes/Constant.h"
#include "../STObject.h"

using namespace std;

class ConstDecHelper
{
public:
	ConstDecHelper(void);
	~ConstDecHelper(void);
	
  //FIXME: constfactors can be strings, numbers, true, false, nil, or idents
	bool sendToSt(STObject* st);

	int getConstInt() {return i;}
	bool getConstBool() {return b;}
	string getConstString() {return s;}
	string getConstType() {return type;}

private:
	int i;
	bool b;
	string s;
	
	string type;
};
#endif

