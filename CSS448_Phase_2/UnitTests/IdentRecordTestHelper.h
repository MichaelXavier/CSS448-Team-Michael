//IdentRecordTestHelper.h
#include <sstream>
#include "../IdentTypes/IdentRecord.h"

#define COMPOUTPUT void compareOutput(const IdentRecord& record, const string& expected, int depth=0) {\
  ostringstream output;\
  record.display(output, depth);\
  TS_ASSERT_EQUALS(output.str(), expected);\
}

