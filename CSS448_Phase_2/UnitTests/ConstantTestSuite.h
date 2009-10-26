//ConstantTestSuite.h
#include <cxxtest/TestSuite.h>
#include "../IdentTypes/Constant.h"

using namespace std;

class ConstantTestSuite : public CxxTest::TestSuite 
{
public:
  void testPlaceholder(void) {
    TS_ASSERT(true);
  }

private:
};

