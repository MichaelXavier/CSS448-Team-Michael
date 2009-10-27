//FunctionTestSuite.h
#include <cxxtest/TestSuite.h>
#include "IdentRecordTestHelper.h"
#include "../IdentTypes/Function.h"
#include "../IdentTypes/IntegerType.h"
#include "../IdentTypes/RealType.h"

using namespace std;

class FunctionTestSuite : public CxxTest::TestSuite 
{
public:
  void testInitialize(void) {
    string name("some_funct");
    Function* funct = new Function(name);
    TS_ASSERT(funct != NULL);
    TS_ASSERT_EQUALS(funct->getName(), name);
    delete funct;
  }

  void testDisplay(void) {
    string name("some_funct");
    Function funct(name);
    ostringstream expected_stream;
    expected_stream << name << " " << endl;
    compareOutput(funct, expected_stream.str());

    //add return type and params
    IntegerType* ret = new IntegerType("int_type");
    funct.setReturnType(ret);
    Parameter* param1 = new Parameter("param1");
    RealType* param1type = new RealType("real_type");
    param1->setTypePtr(param1type);
    funct.insertParameter(param1, parameter, false);

    //rebuild expected
    expected_stream.str("");
    expected_stream << name << " " << "int_type" << endl << "   " << "param1 real_type" << endl ;

    delete param1;
    delete param1type;
    delete ret;
  }

private:

  COMPOUTPUT
};

