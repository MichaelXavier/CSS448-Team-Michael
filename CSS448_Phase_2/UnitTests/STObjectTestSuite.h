//STObjectTestSuite.h
#include <cxxtest/TestSuite.h>
#include <iostream>
#include "../IdentTypes/IntegerType.h"
#include "../STObject.h"
#include "IdentRecordTestHelper.h"

//FIXME: fails at the linker saying it can't figure out the integertype constructor
using namespace std;

class STObjectTestSuite : public CxxTest::TestSuite 
{
public:
  void testInitialize(void) {
    STObject st;
  }

  void testDisplayIntArr(void) {
  }

private:
  COMPOUTPUT
};
