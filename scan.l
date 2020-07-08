%{
#include <stdlib.h>
#include <string.h>
#include "lib/node.h"
#include "y.tab.h"
char *dupstr(const char *s);
extern void yyerror(const char *msg);
int character(char *s);
%}

%x COM IN STR

%%
^("program")                BEGIN IN; return PROGRAM;
^("module")                 BEGIN IN; return MODULE;
<IN>^"end"                  BEGIN INITIAL; return END;

<IN>"$$".*                  ;/*comment*/

<COM>"$"                    BEGIN IN;
<COM>.|\n                   ;
<IN>"$"                     BEGIN COM;

<IN>"start"                 return START;
<IN>"void"                  return VOID;
<IN>"const"                 return CONST;
<IN>"number"                return NUMBER;
<IN>"array"                 return ARRAY;
<IN>"string"                return STRING;
<IN>"function"              return FUNCTION;
<IN>"public"                return PUBLIC;
<IN>"forward"               return FORWARD;
<IN>"if"                    return IF;
<IN>"then"                  return THEN;
<IN>"else"                  return ELSE;
<IN>"elif"                  return ELIF;
<IN>"fi"                    return FI;
<IN>"for"                   return FOR;
<IN>"until"                 return UNTIL;
<IN>"step"                  return STEP;
<IN>"do"                    return DO;
<IN>"done"                  return DONE;
<IN>"repeat"                return REPEAT;
<IN>"stop"                  return STOP;
<IN>"return"                return RETURN;
<IN>"<="			              return LE;
<IN>">="			              return GE;
<IN>"~="                    return NE;
<IN>":="                    return ASSIGN;


<IN>[A-Za-z][A-Za-z0-9_]*	{ yylval.s = dupstr(yytext); return IDENTIFIER; }

<IN>0|[1-9][0-9]*			{ errno = 0; yylval.i = strtol(yytext, 0, 10);
          if (errno == ERANGE || yylval.i < 0) yyerror("decimal overflow");
          return INTEGER; }
<IN>0[0-7]+           { errno = 0; yylval.i = strtol(yytext, 0, 8);
          if (errno == ERANGE || yylval.i < 0) yyerror("octal overflow");
          return INTEGER; }
<IN>0x[a-fA-F0-9]+    { errno = 0; yylval.i = strtol(yytext, 0, 16);
          if (errno == ERANGE || yylval.i < 0) yyerror("hexadecimal overflow");
          return INTEGER; }
<IN>0b[0|1]+          { errno = 0; yylval.i = strtol(yytext, 0, 2);
          if (errno == ERANGE || yylval.i < 0) yyerror("binary overflow");
          return INTEGER; }

<IN>\'\\([nrt\'\\]|([0-9a-fA-F]){1,2})\'   yylval.i = character(yytext+1); return CHAR;
<IN>\"([^"]|\.)*\"	              yylval.s = malloc(yyleng); *yylval.s = 0; REJECT;
<IN>\"			                      BEGIN STR;
<STR>\"			                      BEGIN IN; return CCHAR;
<STR>"\\n"                        strcat(yylval.s, "\n");
<STR>"\\t"                        strcat(yylval.s, "\t");
<STR>"\\r"                        strcat(yylval.s, "\r");
<STR>\\[\\\"]		                  strcat(yylval.s, yytext+1);
<STR>\\.                          yyerror("invalid sequence in string");
<STR>.|\n		                      strcat(yylval.s, yytext);

<IN>[-+*/%\^<>=|&~?#\[\]();!,] return *yytext;

<IN>[ \t\n\r]+		          ; /* ignore whitespace */
.|\n			                  ; /* ignore any character after "end"*/
%%
int yywrap(void) { return 1; }
char *getyytext() { return yytext; }

int character(char *s) {
  char hex[3] = "";

  if (s[0] == '\\') {
    if (s[1] == 'n') { return '\n';}
    if (s[1] == 'r') { return '\r';}
    if (s[1] == 't') { return '\t';}
    if (s[1] == '\'') { return '\'';}
    if (s[1] == '\\') { return '\\';}

    for (int i = 1; s[i] != '\'' && i < 3; i++){
      strncat(hex, &s[i], 1);
    }
  } else {
    return *s;
  }

  return strtol(hex, 0, 16);
}
