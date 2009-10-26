//ParameterTestSuite.h
#include <cxxtest/TestSuite.h>
#include "../IdentTypes/Parameter.h"

using namespace std;

class ParameterTestSuite : public CxxTest::TestSuite 
{
public:
  void testPlaceholder(void) {
    TS_ASSERT(true);
  }

private:
};

