%{
  #include <iostream>
  #include <string>
  #include "tokenconsts.h"
  using namespace std;
  string s;
%}

OPS   [ \t\n\r\(\)\[\]\+\-\/=\*;\.\,\:]
NOTOPS   [^ \t\n\r\(\)\[\]\+\-\/=\*;\.\,\:]
     
%%
"(*"          { 
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
"{"          { 
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
and                  { s = ""; return yand; }
array                { s = ""; return yarray; }
:=                   { s = ""; return yassign; }
begin                { s = ""; return ybegin; }
\^                   { s = ""; return ycaret; }
case                 { s = ""; return ycase; }
:                    { s = ""; return ycolon; }
,                    { s = ""; return ycomma; }
const                { s = ""; return yconst; }
dispose              { s = ""; return ydispose; }
div                  { s = ""; return ydiv; }
\/                   { s = ""; return ydivide; }
do                   { s = ""; return ydo; }
\.                   { s = ""; return ydot; }
\.\.                 { s = ""; return ydotdot; }
downto               { s = ""; return ydownto; }
else                 { s = ""; return yelse; }
end                  { s = ""; return yend; }
=                    { s = ""; return yequal; }
false                { s = ""; return yfalse; }
for                  { s = ""; return yfor; }
function             { s = ""; return yfunction; }
>                    { s = ""; return ygreater; }
>=                   { s = ""; return ygreaterequal; }
if                   { s = ""; return yif; }
in                   { s = ""; return yin; }
"["                  { s = ""; return yleftbracket; }
"("                  { s = ""; return yleftparen; }
\<                   { s = ""; return yless; }
\<=                  { s = ""; return ylessequal; }
-                    { s = ""; return yminus; }
mod                  { s = ""; return ymod; }
\*                   { s = ""; return ymultiply; }
new                  { s = ""; return ynew; }
nil                  { s = ""; return ynil; }
not                  { s = ""; return ynot; }
\<>                  { s = ""; return ynotequal; }
of                   { s = ""; return yof; }
or                   { s = ""; return yor; }
"+"                  { s = ""; return yplus; }
procedure            { s = ""; return yprocedure; }
program              { s = ""; return yprogram; }
Read                 { s = ""; return yread; }
ReadLn               { s = ""; return yreadln; }
record               { s = ""; return yrecord; }
repeat               { s = ""; return yrepeat; }
"]"                  { s = ""; return yrightbracket; }
")"                  { s = ""; return yrightparen; }
;                    { s = ""; return ysemicolon; }
set                  { s = ""; return yset; }
'[^']*'|\"[^\"]*\"   { s = yytext;return ystring; } 
then                 { s = ""; return ythen; }
to                   { s = ""; return yto; }
true                 { s = ""; return ytrue; }
type                 { s = ""; return ytype; }
until                { s = ""; return yuntil; }
var                  { s = ""; return yvar; }
while                { s = ""; return ywhile; }
Write                { s = ""; return ywrite; }
WriteLn              { s = ""; return ywriteln; }

[A-Za-z]+[A-Za-z0-9]*              { s = yytext;return yident; }
[0-9]+\.[0-9]+\e[+-]?[0-9]+        { s = yytext;return ynumber; }
[0-9]+\.[0-9]+\e[+-]?[0-9]+/{OPS}  { s = yytext;return ynumber; }
[0-9]+\.[0-9]+                     { s = yytext;return ynumber; }
[0-9]+                             { s = yytext;return ynumber; }
[0-9]+{NOTOPS}+                    { s = yytext;return yunknown; }
[^ \t\n\r]                         { s = yytext; return yunknown; }

[ \t\n\r]
%%

int yywrap() {
  return 1;
}

