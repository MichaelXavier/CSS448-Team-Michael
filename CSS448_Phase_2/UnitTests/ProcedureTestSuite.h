//ProcedureTestSuite.h
#include <cxxtest/TestSuite.h>
#include "IdentRecordTestHelper.h"
#include "../IdentTypes/IdentRecord.h"
#include "../IdentTypes/Procedure.h"

using namespace std;

class ProcedureTestSuite : public CxxTest::TestSuite
{
public:
  void testInitialize(void) {
    string name("some_proc");
    Procedure* proc = new Procedure(name);
    TS_ASSERT(proc != NULL);
    TS_ASSERT_EQUALS(proc->getName(), name);
    delete proc;
  }

  void testStrCmp(void) {
    string name1("some_proc");
    string name2("other_proc");
    Procedure proc1(name1);
    Procedure proc2(name2);
    TS_ASSERT_DIFFERS(proc1.strcmp(proc2), 0);
  }

  void testCompareOutputs(void) {
    string name("some_proc");
    Procedure proc(name);
    stringstream& expected();
    expected << name << endl;
    compareOutput(proc, expected.str(), 0);
  }
private:
  COMPOUTPUTS
};

