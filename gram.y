%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "tabid.h"
#include "node.h"

#ifndef YYERRCODE
#define YYERRCODE 256
#endif
#define YYDEBUG 1


int yylex();
int yyerror(char *s);
char *dupstr(const char*s);
static int checkints(Node *n1, Node *n2);
static int checksametype(Node *n1, Node *n2);
extern long lbl;

%}

%union {
	int i;
	char *s;
	Node *n;
}

%token <i> INTEGER CHAR
%token <s> IDENTIFIER CCHAR
%token PROGRAM MODULE START END VOID CONST NUMBER ARRAY STRING FUNCTION
%token PUBLIC FORWARD IF THEN ELSE ELIF FI FOR UNTIL STEP DO DONE
%token REPEAT STOP RETURN

%nonassoc IFX
%nonassoc ELSE

%nonassoc '[' ']' '(' ')'
%nonassoc AND UMINUS '?'
%right '^'
%left '*' '/' '%'
%left '+' '-'
%left '<' '>' LE GE
%left NE '='
%nonassoc '~'
%left '&'
%left '|'
%right ASSIGN

%type<n> declarations declaration body variable qualificator function
%type<n> literal literals literalscomma type ddone variables bodyvariables
%type<n> instructions instructioninit instructionfinal elseexp elifexp
%type<n> expression lvalue invocation args program module

%token AND OR LOAD INDEX ADDR NOT NIL VAR BVAR DECL DECLS LIT LITS LITSC INST
%token LVAL EXPR INV ARGS BODY VARS C
%token ADD

%%

file: program                  	{ printNode(uniNode(PROGRAM, $1), 0, (char**)yyname); IDprint(0,0);}
	| module											{	printNode(uniNode(MODULE, $1), 0, (char**)yyname); IDprint(0,0);}
	;

program: PROGRAM declarations START body END; { $$ = binNode(PROGRAM, $2, $4); }

module: MODULE declarations END;							{ $$ = uniNode(MODULE, $2); }

declarations:														{ $$ = nilNode(NIL);}
	| declarations ';' declaration				{ $$ = binNode(DECLS, $1, $3); }
	| declaration													{ $$ = uniNode(DECLS, $1);}
	;

declaration: function										{ $$ = uniNode(DECL, $1);}
	| qualificator variable								{ $$ = binNode(DECL, $1, $2);}
	| qualificator CONST variable							{ $$ = binNode(DECL, $1, $3);}
	| qualificator variable ASSIGN literals literalscomma { if (checksametype($2, $4)) $$ = quadNode(DECL, $1, $2, $4, $5); else yyerror("variables are not the same type.");}
	| qualificator CONST variable ASSIGN literals literalscomma { if (checksametype($3, $5)) $$ = quadNode(DECL, $1, $3, $5, $6); else yyerror("variables are not the same type.");}
	;

function: FUNCTION qualificator type IDENTIFIER{IDnew($3->info, $4, 0); IDpush();} variables ddone
						{ $$ = pentNode(FUNCTION, $2, $3, strNode(IDENTIFIER, $4), $5, $6);
							IDpop();}
	| FUNCTION qualificator type IDENTIFIER{IDnew($3->info, $4, 0); IDpush();} ddone
						{ $$ = pentNode(FUNCTION, $2, $3, strNode(IDENTIFIER, $4), nilNode(NIL), $5);
							IDpop();}
	| FUNCTION qualificator VOID IDENTIFIER{IDnew(VOID, $4, 0); IDpush();} variables ddone
						{ $$ = quadNode(VOID, $2, strNode(IDENTIFIER, $4), $5, $6);
							IDpop();}
	| FUNCTION qualificator VOID IDENTIFIER{IDnew(VOID, $4, 0); IDpush();} ddone
						{ $$ = quadNode(VOID, $2, strNode(IDENTIFIER, $4), nilNode(NIL), $5);
							IDpop();}
	;

ddone: DONE							{ $$ = nilNode(DONE);}
	| DO body							{ $$ = uniNode(DO, $2);}
	;

variable: type IDENTIFIER									{ IDnew($1->info, $2, 0); $$->info = $1->info;
																						$$ = triNode(VAR, $1, strNode(IDENTIFIER, $2), nilNode(NIL));}
	| type IDENTIFIER '[' INTEGER ']'				{ if(yylval.i > 0){IDnew($1->info, $2, 0); $$->info = $1->info;
																						$$ = triNode(VAR, $1, strNode(IDENTIFIER, $2), intNode(INTEGER, $4));}}
	;

variables: variable											{ $$ = binNode(VARS, $1, nilNode(NIL)); }
	| variables ';' variable								{ $$ = binNode(VARS, $1, $3); }
	;

bodyvariables:													{ $$ = nilNode(NIL); }
	| bodyvariables variable ';'  					{ $$ = binNode(BVAR, $1, $2); }
	;

type: NUMBER														{ $$ = nilNode(NUMBER); $$->info = NUMBER; }
	| STRING															{ $$ = nilNode(STRING); $$->info = STRING; }
	| ARRAY																{ $$ = nilNode(ARRAY); $$->info = ARRAY; }
	;

qualificator: 													{ $$ = nilNode(NIL);}
	| PUBLIC															{ $$ = nilNode(PUBLIC); }
	| FORWARD															{ $$ = nilNode(FORWARD); }
	;

body: bodyvariables instructions instructionfinal { $$ = triNode(BODY, $1, $2, $3);}
	;

literal: INTEGER											{$$ = intNode(INTEGER, $1); $$->info = NUMBER; $$->attrib = yylval.i;}
	| CHAR															{ $$ = intNode(CHAR, $1); $$->info = C;}
	| CCHAR															{ $$ = strNode(CCHAR, $1); $$->info = STRING;}
	;

literals: literal											{ $$ = binNode(LITS, nilNode(NIL), $1); $$->info = $1->info; $$->attrib = $1->attrib;}
	| literals literal									{ $$ = binNode(LITS, $1, $2); $$->info = $2->info; $$->attrib = $2->attrib;}
	;

literalscomma:												{ $$ = nilNode(NIL);}
	| literalscomma ',' literal					{ if($3->info != NUMBER) yyerror("array can only store numbers");  else {$$ = binNode(LITSC, $1, $3); $$->info = $3->info; $$->attrib = $3->attrib;}}
	;

instructions:														{ $$ = nilNode(NIL); }
	| instructions instructioninit				{ $$ = binNode(INST, $1, $2);}
	;

instructioninit: IF expression THEN instructions instructionfinal elifexp elseexp FI { $$ = pentNode(IF, $2, $4, $5, $6, $7);}
	| FOR expression UNTIL expression STEP expression DO instructions instructionfinal DONE { $$ = pentNode(FOR, $2, $4, $6, $8, $9);}
	| expression';'									{ $$ = uniNode(EXPR, $1);}
	| expression'!'									{ $$ = uniNode(EXPR, $1);}
	| lvalue '#' expression ';'			{ $$ = binNode('#', $1, $3);}
	;

instructionfinal:												{ $$ = nilNode(NIL); }
	| REPEAT															{ $$ = nilNode(REPEAT);}
	| STOP																{ $$ = nilNode(STOP);}
	| RETURN															{ $$ = nilNode(RETURN);}
	| RETURN expression										{ $$ = uniNode(RETURN, $2); $$->info = $2->info;}
	;

elifexp:																{ $$ = nilNode(NIL); }
	| elifexp ELIF expression THEN instructions instructionfinal		{ $$ = quadNode(ELIF, $1, $3, $5, $6);}
	;

elseexp:																{ $$ = nilNode(NIL); }
	| ELSE instructions instructionfinal	{ $$ = binNode(ELSE, $2, $3);}
	;

expression: lvalue									{ $$ = uniNode(LVAL, $1); $$->info = $1->info;}
	| literals 												{ $$ = uniNode(LIT, $1); $$->info = $1->info; $$->attrib = $1->attrib;}
	| '(' expression ')'							{ $$ = uniNode(EXPR, $2); $$->info = $2->info;}
	| '?'															{ $$ = nilNode('?'); $$->info = NUMBER;}
	| invocation											{ $$ = uniNode(INV, $1); $$->info = $1->info;}
	| '-' expression %prec UMINUS			{ $$ = uniNode(UMINUS, $2); $$->info = NUMBER;}
	| expression '^' expression 			{ $$ = binNode('^', $1, $3); $$->info = checknumbers($1, $3);}
	| expression '*' expression				{ $$ = binNode('*', $1, $3); $$->info = checknumbers($1, $3);}
	| expression '/' expression				{ if ($3->attrib != 0) {$$ = binNode('/', $1, $3); $$->info = checknumbers($1, $3);}}
	| expression '%' expression				{ $$ = binNode('%', $1, $3); $$->info = checknumbers($1, $3);}
	| expression '+' expression				{ $$ = binNode(ADD, $1, $3); $$->info = checksumop($1, $3);}
	| expression '-' expression				{ $$ = binNode('-', $1, $3); $$->info = checkdifop($1, $3);}
	| expression '<' expression				{ $$ = binNode('<', $1, $3);  $$->info = checknumberorstring($1, $3);}
	| expression '>' expression				{ $$ = binNode('>', $1, $3);  $$->info = checknumberorstring($1, $3);}
	| expression GE expression				{ $$ = binNode(GE, $1, $3);  $$->info = checknumberorstring($1, $3);}
	| expression LE expression				{ $$ = binNode(LE, $1, $3);  $$->info = checknumberorstring($1, $3);}
	| expression NE expression				{ $$ = binNode(NE, $1, $3); $$->info = checknumberorstring($1, $3);}
	| expression '=' expression				{ $$ = binNode('=', $1, $3); $$->info = checknumberorstring($1, $3);}
	| '~' expression									{ $$ = uniNode(NOT, $2); if($2->info != NUMBER) yyerror("arg must be a number!"); else $$->info = $2->info;}
	| expression '&' expression				{ $$ = binNode(AND, $1, $3); $$->info = checknumbers($1, $3);}
	| expression '|' expression				{ $$ = binNode(OR, $1, $3); $$->info = checknumbers($1, $3);}
	| lvalue ASSIGN expression				{ $$ = binNode(ASSIGN, $3, $1); $$->info = checksametype($3, $1);}
	;

	invocation: expression '(' args ')'			{ $$ = binNode(INV, $1, $3); $$->info = $1->info;}
	 ;

	lvalue: IDENTIFIER											{ if(IDfind($1, 0) > 0) { $$ = binNode(LVAL, strNode(IDENTIFIER, $1), nilNode(NIL)); $$->info = IDfind($1,0);} }
		| lvalue '[' expression ']'						{ if($1->info == ARRAY && $3->attrib > 0) {$$ = binNode(LVAL, $1, $3); $$->info = NUMBER; } else yyerror("arg must be array");}
		| '&' lvalue %prec ADDR								{ $$ = uniNode(ADDR, $2); $$->info = ARRAY;}
		;

	args: expression												{ $$ = binNode(ARGS, $1, nilNode(NIL)); $$->info = $1->info;}
		| args ',' expression									{ $$ = binNode(ARGS, $1, $3); $$->info = $1->info;}
		;

%%

char **yynames =
#if YYDEBUG > 0
         (char**)yyname;
#else
         0;
#endif

static int checknumbers(Node *n1, Node *n2) {
	if (n1->info != NUMBER || n2->info != NUMBER) {
		yyerror("arguments must be numbers.");
	}
	return NUMBER;
}

static int checknumberorstring(Node *n1, Node *n2){
	if( (n1->info == n2->info) && n1->info == NUMBER)
		return NUMBER;

	if( (n1->info == n2->info) && n1->info == STRING)
		return STRING;

	return 0;
}

static int checksumop(Node *n1, Node *n2) {

	if (n1->info == NUMBER && n2->info == NUMBER)
		return NUMBER;

	if ((n1->info == ARRAY && n2->info == NUMBER) || n1->info == NUMBER && n2->info == ARRAY)
		return NUMBER;

	else
		return 0;
}

static int checkdifop(Node *n1, Node *n2) {

	if (n1->info == NUMBER && n2->info == NUMBER)
		return NUMBER;

	if ((n1->info == ARRAY && n2->info == NUMBER) || n1->info == NUMBER && n2->info == ARRAY)
		return NUMBER;

	if (n1->info == ARRAY && n2->info == ARRAY)
		return NUMBER;

	else
		return 0;
}

static int checksametype(Node *n1, Node *n2) {
	if(n2->attrib == 0) {
		return 1;
	}

	if( n1->info != n2->info)
		return 0;
	return n1->info;
}
