//Phase1TestSuite.h
#include <cxxtest/TestSuite.h>
#include <cstdio>
#include <fstream>
#include <string>
#include "tokennames.h"
#include "lex.h"

using namespace std;

extern int yylex();    // extern says they will be defined elsewhere
extern string s;

class Phase1TestSuite : public CxxTest::TestSuite 
{
public:
    void testSimpleCase(void) {
      checkAgainstExpected("ll.txt", "expected_ll.txt");
    }

    void testAddOutput(void) {
      checkAgainstExpected("../Sample Pascal/add.p", "ExpectedOutputs/add-output");
    }

    void testArrayOutput(void) {
      checkAgainstExpected("../Sample Pascal/array.p", "ExpectedOutputs/array-output");
    }

    void testCaseOutput(void) {
      checkAgainstExpected("../Sample Pascal/case.p", "ExpectedOutputs/case-output");
    }

    void testIfOutput(void) {
      checkAgainstExpected("../Sample Pascal/if.p", "ExpectedOutputs/if-output");
    }

    void testListOutput(void) {
      checkAgainstExpected("../Sample Pascal/list.p", "ExpectedOutputs/list-output");
    }

    void testNestedprocsOutput(void) {
      checkAgainstExpected("../Sample Pascal/nestedprocs.p", "ExpectedOutputs/nestedprocs-output");
    }

    void testSetOutput(void) {
      checkAgainstExpected("../Sample Pascal/set.p", "ExpectedOutputs/set-output");
    }

    void testSimplestOutput(void) {
      checkAgainstExpected("../Sample Pascal/simplest.p", "ExpectedOutputs/simplest-output");
    }

    void testSimplest2Output(void) {
      checkAgainstExpected("../Sample Pascal/simplest2.p", "ExpectedOutputs/simplest2-output");
    }

private:
    void checkAgainstExpected(const char* input_file, const char* expected_file) {
      //setup the input stream
      FILE* input = fopen(input_file, "r");

      if (input == NULL) {
        throw "Input file could not be opened.";
      }

      yyrestart(input);
      //change the lex buffer to the input file
      /*YY_BUFFER_STATE new_buffer = yy_create_buffer(input, 1024);
      yy_switch_to_buffer(new_buffer);*/

      //setup the expected stream
      ifstream expected(expected_file);

      if (!expected) {
        fclose(input);
        throw "Expected file could not be opened.";
      }

      int token;
      string expected_token, expected_data;
      while ((token = yylex()) != 0) {
        string expected_line;
        //get a line from the input file
        expected >> token >> expected_token;

        //peek and eat whitespace
        while (expected.peek() == ' ') { expected.get(); }

        if (getline(expected, expected_data)) {

          //TS_WARN(expected_token);//DEBUG
          //TS_WARN(expected_data);//DEBUG
          //assert the tok, which is the most important
          TS_ASSERT_EQUALS(getTokenName(token), expected_token);
          //assert the data captured, might have issues with whitespace
          TS_ASSERT_EQUALS(s, expected_data);
        }

        //Clear the string that holds the data
        s = "";
      }

      //close the input files
      fclose(input);
      expected.close();
    }
};

