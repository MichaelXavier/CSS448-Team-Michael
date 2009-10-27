//ConstantTestSuite.h
#include <cxxtest/TestSuite.h>
#include "IdentRecordTestHelper.h"
#include "../IdentTypes/Constant.h"

using namespace std;

class ConstantTestSuite : public CxxTest::TestSuite 
{
public:
  void testInitialize(void) {
    string name("some_constant");
    Constant* constant = new Constant(name);
    TS_ASSERT(constant != NULL);
    TS_ASSERT_EQUALS(constant->getName(), name);
    delete constant;
  }
  
  void testDisplay(void) {
    string name("some_constant");
    Constant constant(name);
    //try first with no constfactor
    compareOutput(constant, "some_constant 0");
    constant.setConstFactor(15);
    compareOutput(constant, "some_constant 15");
    constant.setConstFactor(-9);
    compareOutput(constant, "some_constant -9");
  }
private:

  COMPOUTPUT
};

