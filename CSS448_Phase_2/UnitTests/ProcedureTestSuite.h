//ProcedureTestSuite.h
#include <cxxtest/TestSuite.h>
#include "../IdentTypes/Procedure.h"

using namespace std;

class ProcedureTestSuite : public CxxTest::TestSuite 
{
public:
  void testInitialize(void) {
    Procedure* proc = new Procedure("some_proc");
    TS_ASSERT(proc != NULL);
  }
private:
};

