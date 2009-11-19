%{
  #include <iostream>
  #include <string>
  #include <sstream>
  #include "y.tab.h"
  using namespace std;
  string s;
  
  //FIXME: don't know what we're supposed to do with these errors
  const int MAX_ERRS = 256;
  string errors[MAX_ERRS];
  bool has_errors;
  int error_count = 0;

  void handleComment(void);
  void handleBraces(void);
  void addError(const char*, const char*);
  void printErrors(void);
%}

OPS   [ \t\n\r\(\)\[\]\+\-\/=\*;\.\,\:]
NOTOPS   [^ \t\n\r\(\)\[\]\+\-\/=\*;\.\,\:]
     
%%
"(*"                 { handleComment(); }
"{"                  { handleBraces(); }
and                  { return yand; }
array                { return yarray; }
:=                   { return yassign; }
begin                { return ybegin; }
\^                   { return ycaret; }
case                 { return ycase; }
:                    { return ycolon; }
,                    { return ycomma; }
const                { return yconst; }
dispose              { return ydispose; }
div                  { return ydiv; }
\/                   { return ydivide; }
do                   { return ydo; }
\.                   { return ydot; }
\.\.                 { return ydotdot; }
downto               { return ydownto; }
else                 { return yelse; }
end                  { return yend; }
=                    { return yequal; }
false                { return yfalse; }
for                  { return yfor; }
function             { return yfunction; }
>                    { return ygreater; }
>=                   { return ygreaterequal; }
if                   { return yif; }
in                   { return yin; }
"["                  { return yleftbracket; }
"("                  { return yleftparen; }
\<                   { return yless; }
\<=                  { return ylessequal; }
-                    { return yminus; }
mod                  { return ymod; }
\*                   { return ymultiply; }
new                  { return ynew; }
nil                  { return ynil; }
not                  { return ynot; }
\<>                  { return ynotequal; }
of                   { return yof; }
or                   { return yor; }
"+"                  { return yplus; }
procedure            { return yprocedure; }
program              { return yprogram; }
Read                 { return yread; }
ReadLn               { return yreadln; }
record               { return yrecord; }
repeat               { return yrepeat; }
"]"                  { return yrightbracket; }
")"                  { return yrightparen; }
;                    { return ysemicolon; }
set                  { return yset; }
'[^']*'|\"[^\"]*\"   { s = yytext; return ystring; } 
then                 { return ythen; }
to                   { return yto; }
true                 { return ytrue; }
type                 { return ytype; }
until                { return yuntil; }
var                  { return yvar; }
while                { return ywhile; }
Write                { return ywrite; }
WriteLn              { return ywriteln; }

[A-Za-z]+[A-Za-z0-9]*              { s = yytext; return yident; }
[0-9]+\.[0-9]+\e[+-]?[0-9]+        { s = yytext; return ynumber; }
[0-9]+\.[0-9]+\e[+-]?[0-9]+/{OPS}  { s = yytext; return ynumber; }
[0-9]+\.[0-9]+                     { s = yytext; return ynumber; }
[0-9]+                             { s = yytext; return ynumber; }
[0-9]+{NOTOPS}+                    { s = yytext; addError("Unknown string found:", yytext);return yunknown; }
[^ \t\n\r]                         { s = yytext; addError("Unknown string found:", yytext);return yunknown; }

[ \t\n\r]
%%

void handleComment(void) {
  //dump the comment to output
  cout << "/*";
  char ch;
  for (;;)
  {
    while ((ch = yyinput()) != '*' && ch != EOF) {
      cout << ch;
    }
    if (ch == '*')
    {
      char temp = yyinput();
      if (temp == ')') {
        break;
      } else {
        unput(temp);
        cout << ch;
      }
    } else if (ch == EOF) {
      break;
    }
  }
  //print the C-style close comment
  cout << "*/\n";
}
void handleBraces(void) {
  //dump the comment to output
  cout << "/*";
  char ch;
  for (;;)
  {
    if((ch = yyinput()) != '}' && ch != EOF) {
      cout << ch;
    }
  }
  //print the C-style close comment
  cout << "*/\n";
}

void addError(const char* text, const char* data) {
  if (error_count < MAX_ERRS - 1) {
    ostringstream out;
    out << text << ": " << data;
    errors[++error_count] = out.str();
    has_errors = true;
  } else {
    cout << "ERROR: Error list empty." << endl;
  }
}

void printErrors(void) {
  if (has_errors) {
    for (int i = 0; i < error_count; i++) {
      cout << errors[i] << endl;
    }
  }
}

int yywrap() {
  //printErrors();//FIXME: figure out how to indicate an error and not continue to yacc
  return 1;
}

