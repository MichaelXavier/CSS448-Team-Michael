//FunctionTestSuite.h
#include <cxxtest/TestSuite.h>
#include "../IdentTypes/Function.h"

using namespace std;

class FunctionTestSuite : public CxxTest::TestSuite 
{
public:
  void testPlaceholder(void) {
    TS_ASSERT(true);
  }

private:
};

