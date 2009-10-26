//VariableTestSuite.h
#include <cxxtest/TestSuite.h>
#include "../IdentTypes/Variable.h"

using namespace std;

class VariableTestSuite : public CxxTest::TestSuite 
{
public:
  void testPlaceholder(void) {
    TS_ASSERT(true);
  }

private:
};

