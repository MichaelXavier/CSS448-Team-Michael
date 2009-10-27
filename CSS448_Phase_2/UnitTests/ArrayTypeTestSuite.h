//ArrayTypeTestSuite.h
#include <cxxtest/TestSuite.h>
#include <iostream>
#include "../IdentTypes/IntegerType.h"
#include "../IdentTypes/ArrayType.h"
#include "IdentRecordTestHelper.h"

//FIXME: fails at the linker saying it can't figure out the integertype constructor
using namespace std;

class ArrayTypeTestSuite : public CxxTest::TestSuite 
{
public:
  void testInitialize(void) {
    string name("some_arr");
    ArrayType* arr = new ArrayType(name);
    TS_ASSERT(arr != NULL);
    TS_ASSERT_EQUALS(arr->getName(), name);
    delete arr;
  }

  void testStrCmp(void) {
    string name1("some_arr");
    string name2("other_arr");
    ArrayType arr1(name1);
    ArrayType arr2(name2);
    TS_ASSERT_DIFFERS(arr1.strcmp(arr2), 0);
  }

  void testDisplayIntArr(void) {
    string name("some_arr");
    ArrayType arr(name);
    IntegerType* typePtr = new IntegerType("some_int");
    arr.setTypePtr(static_cast<IdentRecord*>(typePtr));
    /*string expected = "some_arr  some_int";
    compareOutput(arr, expected);
    delete typePtr;*/
  }

private:
  COMPOUTPUT
};

