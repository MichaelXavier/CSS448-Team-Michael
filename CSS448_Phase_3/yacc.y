%{
   /* handles simple arithmetic expressions */

   #include <stdio.h>
   #include <ctype.h>
   #include <math.h>

   int base;
   int divError;
%}

/* yacc declarations */ 
%start begin

%%   /* beginning of rules section */

begin : program
      ;

program:
     ;

identifier : letter
           | digit
           | letter identifier
           ; 

number : integer
       | real
       ;

integer : number
        | number integer
        ;

real : integer '.' integer
     | integer '.' integer exponent
     ;

exponent : e integer
         | e '+' integer
         | e '- integer
         ;

string : '"' character '"'
       | '\'' character '\''
       ;

%% 

extern void yyerror(char*);

/* ***  lexical analysis routine ***               */
/* return DIGIT for a digit, yylval = 0 through 9  */
/* all other characters are returned immediately   */
int yylex() {
    /*int c;

    while ((c = getchar()) == ' ')    { 
      //no body, skip blanks
    }

    //c is now nonblank
    if (isdigit(c)) {
        yylval = c - '0';
        return DIGIT;
    }
    return c;
  */
}

