#include <iostream>
#include <string>
#include "tokennames.h"
using namespace std;

extern int yylex();    // extern says they will be defined elsewhere
extern string s;

int main(void) {
   int token;
   for (;;) {
      token = yylex();
      if (token == 0) break;
      cout << token << "  " << getTokenName(token) << "  " << s << endl;
   }
   return 0;
}

