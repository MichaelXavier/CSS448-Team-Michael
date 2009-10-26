//ArrayTypeTestSuite.h
#include <cxxtest/TestSuite.h>
#include "../IdentTypes/ArrayType.h"

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
private:
};

