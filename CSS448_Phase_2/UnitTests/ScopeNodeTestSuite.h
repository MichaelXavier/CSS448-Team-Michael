//ScopeNodeTestSuite.h
#include <cxxtest/TestSuite.h>
#include <iostream>
#include "../IdentTypes/IntegerType.h"
#include "../ScopeNode.h"
#include "IdentRecordTestHelper.h"

//FIXME: fails at the linker saying it can't figure out the integertype constructor
using namespace std;

class ScopeNodeTestSuite : public CxxTest::TestSuite 
{
public:
  void testInitialize(void) {
    /*string name("some_arr");
    ScopeNode* arr = new ScopeNode(name);
    TS_ASSERT(arr != NULL);
    TS_ASSERT_EQUALS(arr->getName(), name);
    delete arr;*/
  }

  void testDisplayIntArr(void) {
    /*string name("some_arr");
    ScopeNode arr(name);
    IntegerType* typePtr = new IntegerType("some_int");
    arr.setTypePtr(static_cast<IdentRecord*>(typePtr));
    string expected = "some_arr  some_int";
    compareOutput(arr, expected);
    delete typePtr;*/
  }

private:
  COMPOUTPUT
};

