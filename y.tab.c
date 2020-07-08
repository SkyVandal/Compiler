/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "gram.y"
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

#line 24 "gram.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	int i;
	char *s;
	Node *n;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 55 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define INTEGER 257
#define CHAR 258
#define IDENTIFIER 259
#define CCHAR 260
#define PROGRAM 261
#define MODULE 262
#define START 263
#define END 264
#define VOID 265
#define CONST 266
#define NUMBER 267
#define ARRAY 268
#define STRING 269
#define FUNCTION 270
#define PUBLIC 271
#define FORWARD 272
#define IF 273
#define THEN 274
#define ELSE 275
#define ELIF 276
#define FI 277
#define FOR 278
#define UNTIL 279
#define STEP 280
#define DO 281
#define DONE 282
#define REPEAT 283
#define STOP 284
#define RETURN 285
#define IFX 286
#define AND 287
#define UMINUS 288
#define LE 289
#define GE 290
#define NE 291
#define ASSIGN 292
#define OR 293
#define LOAD 294
#define INDEX 295
#define ADDR 296
#define NOT 297
#define NIL 298
#define VAR 299
#define BVAR 300
#define DECL 301
#define DECLS 302
#define LIT 303
#define LITS 304
#define LITSC 305
#define INST 306
#define LVAL 307
#define EXPR 308
#define INV 309
#define ARGS 310
#define BODY 311
#define VARS 312
#define C 313
#define ADD 314
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,   23,   24,    1,    1,    1,    2,    2,    2,
    2,    2,   25,    6,   26,    6,   27,    6,   28,    6,
   11,   11,    4,    4,   12,   12,   13,   13,   10,   10,
   10,    5,    5,    5,    3,    7,    7,    7,    8,    8,
    9,    9,   14,   14,   15,   15,   15,   15,   15,   16,
   16,   16,   16,   16,   18,   18,   17,   17,   19,   19,
   19,   19,   19,   19,   19,   19,   19,   19,   19,   19,
   19,   19,   19,   19,   19,   19,   19,   19,   19,   19,
   21,   20,   20,   20,   22,   22,
};
static const YYINT yylen[] = {                            2,
    1,    1,    5,    3,    0,    3,    1,    1,    2,    3,
    5,    6,    0,    7,    0,    6,    0,    7,    0,    6,
    1,    2,    2,    5,    1,    3,    0,    3,    1,    1,
    1,    0,    1,    1,    3,    1,    1,    1,    1,    2,
    0,    3,    0,    2,    8,   10,    2,    2,    4,    0,
    1,    1,    1,    2,    0,    6,    0,    3,    1,    1,
    3,    1,    1,    2,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    2,    3,    3,    3,
    4,    1,    4,    2,    1,    3,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    1,    2,    0,   33,   34,    0,    7,
    0,    8,    0,    0,   27,    0,    0,   29,   31,   30,
    0,    0,    4,    0,    0,    0,    0,    6,    0,    0,
    0,    0,    0,    3,    0,    0,    0,   36,   37,   38,
   39,    0,    0,    0,    0,    0,    0,   28,   82,    0,
    0,   51,   52,    0,    0,   62,    0,    0,    0,    0,
   44,   35,    0,    0,   63,    0,   40,    0,    0,   25,
    0,   27,   21,   20,    0,   16,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   47,
   48,    0,    0,    0,    0,    0,   24,    0,   18,   22,
   14,   43,    0,   61,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   79,
    0,   80,    0,   42,   26,    0,    0,   81,    0,   83,
   49,   55,    0,    0,    0,    0,   43,    0,    0,   43,
    0,    0,   45,    0,   58,   43,    0,    0,   46,   56,
};
static const YYINT yydgoto[] = {                          3,
    9,   10,   26,   70,   11,   12,   41,   60,   68,   22,
   74,   71,   27,   36,   61,   62,  149,  145,   63,   78,
   65,  116,    4,    5,   46,   47,   44,   45,
};
static const YYINT yysindex[] = {                      -152,
 -147, -147,    0,    0,    0,  -99,    0,    0,   -8,    0,
 -138,    0,  -41, -235,    0, -147,  -56,    0,    0,    0,
 -279, -242,    0, -237, -222, -212,  -56,    0, -219, -204,
  -34,    0,    0,    0,   16,  489, -204,    0,    0,    0,
    0, -204, -172,  -56, -120,  -56, -120,    0,    0,   29,
   29,    0,    0,   29,   29,    0,   29,   29,  -19, -204,
    0,    0,  432,  -32,    0, -204,    0,   61,   21,    0,
  -53,    0,    0,    0,  -53,    0,  569,  -76,  600,  933,
  611,  945,  -18,   53,   29,   29,   29,   29,   29,   29,
   29,   29,   29,   29,   29,   29,   29,   29,   29,    0,
    0,   29,   29,   29,   61, -204,    0,  -56,    0,    0,
    0,    0,   29,    0,  933,   -6,  945,  565,  565,  565,
  -37,  -37,  -22,  -22,  -22,  -22,  -18,  -18,   27,    0,
  666,    0,  802,    0,    0,  489,  867,    0,   29,    0,
    0,    0,   29,  933,  -96,  878,    0,   29, -137,    0,
  489,  904,    0,  489,    0,    0, -129,  489,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
  134,   67,    0,    0,    0,  -73,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -110,    0,    0,    0,    0,
  -38,    0,    0,    0,    0,    0, 1158,    0,   62,    0,
    9,  -92,   91,    0,    0,   80,    0,    0,    0,    0,
    0,   44,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   -1,    0,    0,    0,    0,    0,    3,
    0,    0,    0,  443,    0,   44,    0,   82,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   39,    0,   35,
    0, 1067,  105,  -33,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   84,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   49,    0, 1121, 1001, 1039, 1094,
  840,  977,  402,  476,  506,  542,  141,  177,   75,    0,
    0,    0,    0,    0,    0,   20,    0,    0,    0,    0,
    0,    0,    0,  163,  -90,    0,    0,    0,    0,    0,
  -86,    0,    0,  -85,    0,    0,    0,   20,    0,    0,
};
static const YYINT yygindex[] = {                         0,
  203,  192,  155,  143,  226,    0,  -11,   41,  167,  231,
   -5,  204,    0,   59,    0,  -47,    0,    0, 1369,  374,
    0,    0,    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 1517
static const YYINT yytable[] = {                         84,
   98,   84,  104,   84,   84,  108,   84,   84,   84,   84,
   84,   84,   30,   84,  102,   98,   31,   16,   59,   98,
    9,   32,   92,   97,   93,   84,   84,   84,   84,   24,
   67,   18,   19,   20,  138,   60,   33,  139,   97,   60,
   60,   76,   60,   60,   60,   60,   60,   60,   67,   60,
   16,   34,   38,   39,   67,   40,   43,   53,  102,   84,
   84,   60,   60,   60,   60,  109,   59,   23,   55,  111,
   42,   59,   37,   57,   48,   59,   59,   66,   59,   59,
   59,   59,   59,   59,   69,   59,   99,   41,  142,   85,
   84,   56,   85,   54,  134,   60,   60,   59,   59,   59,
   59,   99,   41,  155,  106,   99,  157,   78,    1,    2,
  160,   78,   78,  107,   78,   78,   78,   78,   78,   78,
   10,   78,    6,    7,    8,    5,   60,   17,   18,   19,
   20,   59,   59,   78,   78,   78,   78,   77,   50,  153,
   11,   77,   12,  102,   77,   77,   77,   77,   77,   77,
   99,   77,  159,   21,   58,   32,   32,   32,   32,   29,
   72,   73,   59,   77,   77,   77,   77,   78,   78,   35,
  136,    7,    8,   75,   17,   17,   17,   75,  147,  148,
   75,   75,   75,   75,   75,   75,   57,   75,   19,   19,
   50,   32,    5,   32,   32,   32,   50,   77,   77,   75,
   75,   75,   75,   86,   13,  151,   86,   28,  154,   76,
   18,   19,   20,   76,  158,  103,   76,   76,   76,   76,
   76,   76,   23,   76,    9,    9,  110,   72,   73,   84,
   84,   14,  105,   75,   75,   76,   76,   76,   76,   49,
   84,   84,   84,   84,   25,   84,   84,   84,   84,   75,
  135,   94,   95,   96,   15,   84,   84,   84,   84,  103,
    0,   53,   53,    0,    0,   60,   60,    0,   96,   76,
   76,   23,   23,   53,   53,   53,   60,   60,   60,   60,
   53,   60,   60,   60,   60,   38,   39,   49,   40,   23,
   23,   60,   60,   60,   50,   50,   50,   54,   54,    0,
   23,   59,   59,    0,    0,    0,   41,   41,    0,   54,
   54,   54,   59,   59,   59,   59,   54,   59,   59,   59,
   59,    0,    0,    0,   10,   10,    0,   59,   59,   59,
    5,    0,   32,   32,   32,   32,    0,   78,   78,    0,
    0,    0,   50,   50,   11,   11,   12,   12,   78,   78,
   78,   78,    0,   78,   78,   78,   78,   13,   13,   13,
    0,    0,    0,   78,   78,   78,    0,   77,   77,    0,
    0,   15,   15,    0,    0,    0,    0,    0,   77,   77,
   77,   77,    0,   77,   77,   77,   77,    0,    0,    0,
    0,    0,    0,   77,   77,   77,    5,    0,    0,   32,
   32,   32,   32,   75,   75,    0,    0,    0,    0,   64,
    0,    0,    0,    0,   75,   75,   75,   75,    0,   75,
   75,   75,   75,    0,    0,    0,    0,    0,    0,   75,
   75,   75,   84,    0,   71,    0,    0,    0,   71,   76,
   76,   71,   71,   71,   71,   71,   71,    0,   71,    0,
   76,   76,   76,   76,    0,   76,   76,   76,   76,    0,
   71,   71,    0,   71,  101,   76,   76,   76,   89,   98,
    0,   85,    0,   87,   90,   59,   91,    0,   88,   59,
   59,    0,   59,    0,   59,   59,    0,   59,    0,   59,
  100,   92,   97,   93,   71,   71,    0,    0,    0,    0,
    0,   59,   59,   59,   59,    0,    0,    0,   72,   64,
    0,    0,   72,    0,    0,   72,   72,   72,   72,   72,
   72,    0,   72,    0,   64,   86,   59,   64,   55,    0,
    0,   64,    0,   57,   72,   72,   59,   72,   74,    0,
    0,    0,   74,    0,    0,   74,   74,   74,   74,   74,
   74,   56,   74,    0,    0,   99,    0,    0,    0,    0,
    0,    0,    0,    0,   74,   74,   59,   74,   72,   72,
    0,    0,    0,    0,   73,    0,    0,    0,   73,    0,
    0,   73,   73,   73,   73,   73,   73,    0,   73,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   74,   74,
   73,   73,   98,   73,    0,   89,   98,   90,   85,   91,
   87,   90,    0,   91,   58,   88,    0,    0,    0,    0,
    0,    0,    0,    0,   92,   97,   93,    0,   92,   97,
   93,    0,    0,    0,   73,   73,   89,   98,    0,   85,
    0,   87,   90,    0,   91,    0,   88,   89,   98,    0,
   85,  114,   87,   90,    0,   91,    0,   88,    0,   92,
   97,   93,   86,    0,   71,   71,    0,    0,    0,    0,
   92,   97,   93,    0,    0,   71,   71,   71,   71,    0,
   71,   71,   71,   71,    0,    0,    0,    0,   99,    0,
   71,   71,   99,   86,    0,    0,    0,    0,    0,    0,
    0,    0,   89,   98,   86,   85,    0,   87,   90,    0,
   91,    0,   88,    0,    0,    0,    0,    0,    0,    0,
   94,   95,   96,   99,    0,   92,   97,   93,    0,    0,
    0,   59,   59,   59,   99,    0,    0,    0,   72,   72,
    0,    0,    0,    0,    0,   38,   39,   49,   40,   72,
   72,   72,   72,    0,   72,   72,   72,   72,  140,   86,
    0,   50,    0,    0,   72,   72,   51,    0,   74,   74,
    0,   52,   53,   54,    0,    0,    0,    0,    0,   74,
   74,   74,   74,    0,   74,   74,   74,   74,    0,   99,
    0,    0,    0,    0,   74,   74,    0,    0,    0,    0,
    0,    0,    0,    0,   73,   73,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   73,   73,   73,   73,    0,
   73,   73,   73,   73,    0,    0,    0,    0,    0,    0,
   73,   73,    0,    0,    0,    0,    0,    0,   89,   98,
    0,   85,  112,   87,   90,    0,   91,    0,   88,    0,
    0,    0,    0,   94,   95,   96,    0,   94,   95,   96,
  141,   92,   97,   93,    0,    0,    0,    0,    0,    0,
    0,    0,   69,    0,    0,    0,   69,    0,  113,   69,
   69,   69,   69,   69,   69,    0,   69,    0,   94,   95,
   96,    0,    0,    0,    0,   86,    0,    0,   69,   94,
   95,   96,    0,   89,   98,    0,   85,    0,   87,   90,
    0,   91,    0,   88,   89,   98,    0,   85,    0,   87,
   90,    0,   91,    0,   88,   99,   92,   97,   93,    0,
    0,    0,   69,   69,    0,    0,    0,   92,   97,   93,
   89,   98,    0,   85,    0,   87,   90,    0,   91,    0,
   88,    0,    0,    0,   94,   95,   96,    0,    0,    0,
   86,    0,    0,   92,   97,   93,    0,    0,    0,   89,
   98,   86,   85,    0,   87,   90,    0,   91,    0,   88,
    0,   89,   98,    0,    0,    0,   87,   90,    0,   91,
   99,   88,   92,   97,   93,    0,    0,   86,    0,    0,
    0,   99,    0,    0,   92,   97,   93,    0,    0,   70,
    0,    0,    0,   70,    0,    0,   70,   70,   70,   70,
   70,   70,    0,   70,    0,    0,   86,   99,    0,    0,
    0,    0,    0,   66,    0,   70,    0,   66,   86,    0,
   66,   66,   66,    0,   66,    0,    0,   66,    0,    0,
    0,    0,    0,    0,    0,    0,   99,    0,    0,   66,
    0,    0,    0,    0,    0,    0,    0,    0,   99,   70,
   70,   67,    0,    0,    0,   67,    0,    0,   67,   67,
   67,    0,   67,    0,    0,   67,    0,    0,    0,    0,
   94,   95,   96,   66,   66,    0,    0,   67,    0,   64,
    0,    0,   69,   69,    0,    0,   64,   64,    0,    0,
   64,    0,    0,   69,   69,   69,   69,    0,   69,   69,
   69,   69,    0,    0,    0,   64,   68,    0,    0,    0,
   68,   67,   67,   68,   68,   68,    0,   68,    0,    0,
   68,    0,    0,    0,    0,    0,  143,    0,    0,    0,
    0,    0,   68,   65,    0,   94,   95,   96,  150,   64,
   65,   65,    0,    0,   65,    0,   94,   95,   96,    0,
    0,    0,    0,    0,    0,    0,    0,  156,    0,   65,
    0,    0,    0,    0,    0,    0,   68,   68,    0,    0,
    0,    0,   94,   95,   96,   43,    0,   43,    0,    0,
    0,    0,   43,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   65,    0,    0,   43,    0,    0,    0,
   43,   94,   95,   96,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   94,   95,   96,    0,    0,    0,   70,
   70,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   70,   70,   70,   70,    0,   70,   70,   70,   70,    0,
    0,    0,    0,   66,   66,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   66,   66,   66,   66,    0,   66,
   66,   66,   66,   43,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   67,   67,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   67,   67,   67,   67,    0,   67,   67,   67,
   67,    0,    0,    0,    0,    0,    0,    0,    0,   64,
   64,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   64,   64,   64,   64,    0,   64,   64,   64,   64,    0,
    0,    0,    0,    0,    0,    0,   68,   68,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   68,   68,   68,
   68,    0,   68,   68,   68,   68,    0,    0,    0,    0,
    0,    0,    0,   65,   65,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   65,   65,   65,   65,    0,   65,
   65,   65,   65,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   43,   43,   43,   43,   77,   79,
   43,   43,   80,   81,    0,   82,   83,    0,    0,    0,
   43,    0,    0,    0,    0,   43,    0,    0,    0,    0,
   43,   43,   43,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  115,  117,  118,  119,  120,  121,  122,
  123,  124,  125,  126,  127,  128,  129,  130,    0,    0,
  131,  132,  133,    0,    0,    0,    0,    0,    0,    0,
    0,  137,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  144,    0,    0,
    0,  146,    0,    0,    0,    0,  152,
};
static const YYINT yycheck[] = {                         33,
   38,   35,   35,   37,   38,   59,   40,   41,   42,   43,
   44,   45,  292,   47,   91,   38,  259,   59,   38,   38,
   59,  259,   60,   61,   62,   59,   60,   61,   62,  265,
   42,  267,  268,  269,   41,   33,  259,   44,   61,   37,
   38,   47,   40,   41,   42,   43,   44,   45,   60,   47,
   59,  264,  257,  258,   66,  260,   91,   59,   91,   93,
   94,   59,   60,   61,   62,   71,   38,   59,   40,   75,
   30,   33,  292,   45,   59,   37,   38,   37,   40,   41,
   42,   43,   44,   45,  257,   47,  124,   44,  136,   41,
  124,   63,   44,   59,  106,   93,   94,   59,   60,   61,
   62,  124,   59,  151,   44,  124,  154,   33,  261,  262,
  158,   37,   38,   93,   40,   41,   42,   43,   44,   45,
   59,   47,  270,  271,  272,   59,  124,  266,  267,  268,
  269,   93,   94,   59,   60,   61,   62,   33,   59,  277,
   59,   37,   59,   91,   40,   41,   42,   43,   44,   45,
  124,   47,  282,   11,  126,  266,  267,  268,  269,   17,
  281,  282,  124,   59,   60,   61,   62,   93,   94,   27,
  112,  271,  272,   33,  267,  268,  269,   37,  275,  276,
   40,   41,   42,   43,   44,   45,  277,   47,  281,  282,
  277,  265,   59,  267,  268,  269,  282,   93,   94,   59,
   60,   61,   62,   41,    2,  147,   44,   16,  150,   33,
  267,  268,  269,   37,  156,  292,   40,   41,   42,   43,
   44,   45,  264,   47,  263,  264,   72,  281,  282,  263,
  264,    6,   66,   93,   94,   59,   60,   61,   62,  259,
  274,  275,  276,  277,   14,  279,  280,  281,  282,   46,
  108,  289,  290,  291,  263,  289,  290,  291,  292,  292,
   -1,  263,  264,   -1,   -1,  263,  264,   -1,  291,   93,
   94,  263,  264,  275,  276,  277,  274,  275,  276,  277,
  282,  279,  280,  281,  282,  257,  258,  259,  260,  281,
  282,  289,  290,  291,  275,  276,  277,  263,  264,   -1,
  292,  263,  264,   -1,   -1,   -1,  263,  264,   -1,  275,
  276,  277,  274,  275,  276,  277,  282,  279,  280,  281,
  282,   -1,   -1,   -1,  263,  264,   -1,  289,  290,  291,
  264,   -1,  266,  267,  268,  269,   -1,  263,  264,   -1,
   -1,   -1,  263,  264,  263,  264,  263,  264,  274,  275,
  276,  277,   -1,  279,  280,  281,  282,  267,  268,  269,
   -1,   -1,   -1,  289,  290,  291,   -1,  263,  264,   -1,
   -1,  281,  282,   -1,   -1,   -1,   -1,   -1,  274,  275,
  276,  277,   -1,  279,  280,  281,  282,   -1,   -1,   -1,
   -1,   -1,   -1,  289,  290,  291,  263,   -1,   -1,  266,
  267,  268,  269,  263,  264,   -1,   -1,   -1,   -1,   36,
   -1,   -1,   -1,   -1,  274,  275,  276,  277,   -1,  279,
  280,  281,  282,   -1,   -1,   -1,   -1,   -1,   -1,  289,
  290,  291,   59,   -1,   33,   -1,   -1,   -1,   37,  263,
  264,   40,   41,   42,   43,   44,   45,   -1,   47,   -1,
  274,  275,  276,  277,   -1,  279,  280,  281,  282,   -1,
   59,   60,   -1,   62,   33,  289,  290,  291,   37,   38,
   -1,   40,   -1,   42,   43,   33,   45,   -1,   47,   37,
   38,   -1,   40,   -1,   42,   43,   -1,   45,   -1,   47,
   59,   60,   61,   62,   93,   94,   -1,   -1,   -1,   -1,
   -1,   59,   60,   61,   62,   -1,   -1,   -1,   33,  136,
   -1,   -1,   37,   -1,   -1,   40,   41,   42,   43,   44,
   45,   -1,   47,   -1,  151,   94,   38,  154,   40,   -1,
   -1,  158,   -1,   45,   59,   60,   94,   62,   33,   -1,
   -1,   -1,   37,   -1,   -1,   40,   41,   42,   43,   44,
   45,   63,   47,   -1,   -1,  124,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   59,   60,  124,   62,   93,   94,
   -1,   -1,   -1,   -1,   33,   -1,   -1,   -1,   37,   -1,
   -1,   40,   41,   42,   43,   44,   45,   -1,   47,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   93,   94,
   59,   60,   38,   62,   -1,   37,   38,   43,   40,   45,
   42,   43,   -1,   45,  126,   47,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   60,   61,   62,   -1,   60,   61,
   62,   -1,   -1,   -1,   93,   94,   37,   38,   -1,   40,
   -1,   42,   43,   -1,   45,   -1,   47,   37,   38,   -1,
   40,   41,   42,   43,   -1,   45,   -1,   47,   -1,   60,
   61,   62,   94,   -1,  263,  264,   -1,   -1,   -1,   -1,
   60,   61,   62,   -1,   -1,  274,  275,  276,  277,   -1,
  279,  280,  281,  282,   -1,   -1,   -1,   -1,  124,   -1,
  289,  290,  124,   94,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   37,   38,   94,   40,   -1,   42,   43,   -1,
   45,   -1,   47,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  289,  290,  291,  124,   -1,   60,   61,   62,   -1,   -1,
   -1,  289,  290,  291,  124,   -1,   -1,   -1,  263,  264,
   -1,   -1,   -1,   -1,   -1,  257,  258,  259,  260,  274,
  275,  276,  277,   -1,  279,  280,  281,  282,   93,   94,
   -1,  273,   -1,   -1,  289,  290,  278,   -1,  263,  264,
   -1,  283,  284,  285,   -1,   -1,   -1,   -1,   -1,  274,
  275,  276,  277,   -1,  279,  280,  281,  282,   -1,  124,
   -1,   -1,   -1,   -1,  289,  290,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  263,  264,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  274,  275,  276,  277,   -1,
  279,  280,  281,  282,   -1,   -1,   -1,   -1,   -1,   -1,
  289,  290,   -1,   -1,   -1,   -1,   -1,   -1,   37,   38,
   -1,   40,  274,   42,   43,   -1,   45,   -1,   47,   -1,
   -1,   -1,   -1,  289,  290,  291,   -1,  289,  290,  291,
   59,   60,   61,   62,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   33,   -1,   -1,   -1,   37,   -1,  279,   40,
   41,   42,   43,   44,   45,   -1,   47,   -1,  289,  290,
  291,   -1,   -1,   -1,   -1,   94,   -1,   -1,   59,  289,
  290,  291,   -1,   37,   38,   -1,   40,   -1,   42,   43,
   -1,   45,   -1,   47,   37,   38,   -1,   40,   -1,   42,
   43,   -1,   45,   -1,   47,  124,   60,   61,   62,   -1,
   -1,   -1,   93,   94,   -1,   -1,   -1,   60,   61,   62,
   37,   38,   -1,   40,   -1,   42,   43,   -1,   45,   -1,
   47,   -1,   -1,   -1,  289,  290,  291,   -1,   -1,   -1,
   94,   -1,   -1,   60,   61,   62,   -1,   -1,   -1,   37,
   38,   94,   40,   -1,   42,   43,   -1,   45,   -1,   47,
   -1,   37,   38,   -1,   -1,   -1,   42,   43,   -1,   45,
  124,   47,   60,   61,   62,   -1,   -1,   94,   -1,   -1,
   -1,  124,   -1,   -1,   60,   61,   62,   -1,   -1,   33,
   -1,   -1,   -1,   37,   -1,   -1,   40,   41,   42,   43,
   44,   45,   -1,   47,   -1,   -1,   94,  124,   -1,   -1,
   -1,   -1,   -1,   33,   -1,   59,   -1,   37,   94,   -1,
   40,   41,   42,   -1,   44,   -1,   -1,   47,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  124,   -1,   -1,   59,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  124,   93,
   94,   33,   -1,   -1,   -1,   37,   -1,   -1,   40,   41,
   42,   -1,   44,   -1,   -1,   47,   -1,   -1,   -1,   -1,
  289,  290,  291,   93,   94,   -1,   -1,   59,   -1,   33,
   -1,   -1,  263,  264,   -1,   -1,   40,   41,   -1,   -1,
   44,   -1,   -1,  274,  275,  276,  277,   -1,  279,  280,
  281,  282,   -1,   -1,   -1,   59,   33,   -1,   -1,   -1,
   37,   93,   94,   40,   41,   42,   -1,   44,   -1,   -1,
   47,   -1,   -1,   -1,   -1,   -1,  280,   -1,   -1,   -1,
   -1,   -1,   59,   33,   -1,  289,  290,  291,  281,   93,
   40,   41,   -1,   -1,   44,   -1,  289,  290,  291,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  274,   -1,   59,
   -1,   -1,   -1,   -1,   -1,   -1,   93,   94,   -1,   -1,
   -1,   -1,  289,  290,  291,   38,   -1,   40,   -1,   -1,
   -1,   -1,   45,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   93,   -1,   -1,   59,   -1,   -1,   -1,
   63,  289,  290,  291,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  289,  290,  291,   -1,   -1,   -1,  263,
  264,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  274,  275,  276,  277,   -1,  279,  280,  281,  282,   -1,
   -1,   -1,   -1,  263,  264,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  274,  275,  276,  277,   -1,  279,
  280,  281,  282,  126,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  263,  264,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  274,  275,  276,  277,   -1,  279,  280,  281,
  282,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  263,
  264,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  274,  275,  276,  277,   -1,  279,  280,  281,  282,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  263,  264,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  274,  275,  276,
  277,   -1,  279,  280,  281,  282,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  263,  264,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  274,  275,  276,  277,   -1,  279,
  280,  281,  282,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  257,  258,  259,  260,   50,   51,
  263,  264,   54,   55,   -1,   57,   58,   -1,   -1,   -1,
  273,   -1,   -1,   -1,   -1,  278,   -1,   -1,   -1,   -1,
  283,  284,  285,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   85,   86,   87,   88,   89,   90,   91,
   92,   93,   94,   95,   96,   97,   98,   99,   -1,   -1,
  102,  103,  104,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  113,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  139,   -1,   -1,
   -1,  143,   -1,   -1,   -1,   -1,  148,
};
#define YYFINAL 3
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 314
#define YYUNDFTOKEN 345
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,"'#'",0,"'%'","'&'",0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,
0,0,0,0,0,0,0,0,"';'","'<'","'='","'>'","'?'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,"'['",0,"']'","'^'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,"'|'",0,"'~'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"INTEGER","CHAR",
"IDENTIFIER","CCHAR","PROGRAM","MODULE","START","END","VOID","CONST","NUMBER",
"ARRAY","STRING","FUNCTION","PUBLIC","FORWARD","IF","THEN","ELSE","ELIF","FI",
"FOR","UNTIL","STEP","DO","DONE","REPEAT","STOP","RETURN","IFX","AND","UMINUS",
"LE","GE","NE","ASSIGN","OR","LOAD","INDEX","ADDR","NOT","NIL","VAR","BVAR",
"DECL","DECLS","LIT","LITS","LITSC","INST","LVAL","EXPR","INV","ARGS","BODY",
"VARS","C","ADD",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : file",
"file : program",
"file : module",
"program : PROGRAM declarations START body END",
"module : MODULE declarations END",
"declarations :",
"declarations : declarations ';' declaration",
"declarations : declaration",
"declaration : function",
"declaration : qualificator variable",
"declaration : qualificator CONST variable",
"declaration : qualificator variable ASSIGN literals literalscomma",
"declaration : qualificator CONST variable ASSIGN literals literalscomma",
"$$1 :",
"function : FUNCTION qualificator type IDENTIFIER $$1 variables ddone",
"$$2 :",
"function : FUNCTION qualificator type IDENTIFIER $$2 ddone",
"$$3 :",
"function : FUNCTION qualificator VOID IDENTIFIER $$3 variables ddone",
"$$4 :",
"function : FUNCTION qualificator VOID IDENTIFIER $$4 ddone",
"ddone : DONE",
"ddone : DO body",
"variable : type IDENTIFIER",
"variable : type IDENTIFIER '[' INTEGER ']'",
"variables : variable",
"variables : variables ';' variable",
"bodyvariables :",
"bodyvariables : bodyvariables variable ';'",
"type : NUMBER",
"type : STRING",
"type : ARRAY",
"qualificator :",
"qualificator : PUBLIC",
"qualificator : FORWARD",
"body : bodyvariables instructions instructionfinal",
"literal : INTEGER",
"literal : CHAR",
"literal : CCHAR",
"literals : literal",
"literals : literals literal",
"literalscomma :",
"literalscomma : literalscomma ',' literal",
"instructions :",
"instructions : instructions instructioninit",
"instructioninit : IF expression THEN instructions instructionfinal elifexp elseexp FI",
"instructioninit : FOR expression UNTIL expression STEP expression DO instructions instructionfinal DONE",
"instructioninit : expression ';'",
"instructioninit : expression '!'",
"instructioninit : lvalue '#' expression ';'",
"instructionfinal :",
"instructionfinal : REPEAT",
"instructionfinal : STOP",
"instructionfinal : RETURN",
"instructionfinal : RETURN expression",
"elifexp :",
"elifexp : elifexp ELIF expression THEN instructions instructionfinal",
"elseexp :",
"elseexp : ELSE instructions instructionfinal",
"expression : lvalue",
"expression : literals",
"expression : '(' expression ')'",
"expression : '?'",
"expression : invocation",
"expression : '-' expression",
"expression : expression '^' expression",
"expression : expression '*' expression",
"expression : expression '/' expression",
"expression : expression '%' expression",
"expression : expression '+' expression",
"expression : expression '-' expression",
"expression : expression '<' expression",
"expression : expression '>' expression",
"expression : expression GE expression",
"expression : expression LE expression",
"expression : expression NE expression",
"expression : expression '=' expression",
"expression : '~' expression",
"expression : expression '&' expression",
"expression : expression '|' expression",
"expression : lvalue ASSIGN expression",
"invocation : expression '(' args ')'",
"lvalue : IDENTIFIER",
"lvalue : lvalue '[' expression ']'",
"lvalue : '&' lvalue",
"args : expression",
"args : args ',' expression",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 203 "gram.y"

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
#line 756 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 62 "gram.y"
	{ printNode(uniNode(PROGRAM, yystack.l_mark[0].n), 0, (char**)yyname); IDprint(0,0);}
break;
case 2:
#line 63 "gram.y"
	{	printNode(uniNode(MODULE, yystack.l_mark[0].n), 0, (char**)yyname); IDprint(0,0);}
break;
case 3:
#line 66 "gram.y"
	{ yyval.n = binNode(PROGRAM, yystack.l_mark[-3].n, yystack.l_mark[-1].n); }
break;
case 4:
#line 68 "gram.y"
	{ yyval.n = uniNode(MODULE, yystack.l_mark[-1].n); }
break;
case 5:
#line 70 "gram.y"
	{ yyval.n = nilNode(NIL);}
break;
case 6:
#line 71 "gram.y"
	{ yyval.n = binNode(DECLS, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 7:
#line 72 "gram.y"
	{ yyval.n = uniNode(DECLS, yystack.l_mark[0].n);}
break;
case 8:
#line 75 "gram.y"
	{ yyval.n = uniNode(DECL, yystack.l_mark[0].n);}
break;
case 9:
#line 76 "gram.y"
	{ yyval.n = binNode(DECL, yystack.l_mark[-1].n, yystack.l_mark[0].n);}
break;
case 10:
#line 77 "gram.y"
	{ yyval.n = binNode(DECL, yystack.l_mark[-2].n, yystack.l_mark[0].n);}
break;
case 11:
#line 78 "gram.y"
	{ if (checksametype(yystack.l_mark[-3].n, yystack.l_mark[-1].n)) yyval.n = quadNode(DECL, yystack.l_mark[-4].n, yystack.l_mark[-3].n, yystack.l_mark[-1].n, yystack.l_mark[0].n); else yyerror("variables are not the same type.");}
break;
case 12:
#line 79 "gram.y"
	{ if (checksametype(yystack.l_mark[-3].n, yystack.l_mark[-1].n)) yyval.n = quadNode(DECL, yystack.l_mark[-5].n, yystack.l_mark[-3].n, yystack.l_mark[-1].n, yystack.l_mark[0].n); else yyerror("variables are not the same type.");}
break;
case 13:
#line 82 "gram.y"
	{IDnew(yystack.l_mark[-1].n->info, yystack.l_mark[0].s, 0); IDpush();}
break;
case 14:
#line 83 "gram.y"
	{ yyval.n = pentNode(FUNCTION, yystack.l_mark[-5].n, yystack.l_mark[-4].n, strNode(IDENTIFIER, yystack.l_mark[-3].s), yystack.l_mark[-2].n, yystack.l_mark[-1].n);
							IDpop();}
break;
case 15:
#line 85 "gram.y"
	{IDnew(yystack.l_mark[-1].n->info, yystack.l_mark[0].s, 0); IDpush();}
break;
case 16:
#line 86 "gram.y"
	{ yyval.n = pentNode(FUNCTION, yystack.l_mark[-4].n, yystack.l_mark[-3].n, strNode(IDENTIFIER, yystack.l_mark[-2].s), nilNode(NIL), yystack.l_mark[-1].n);
							IDpop();}
break;
case 17:
#line 88 "gram.y"
	{IDnew(VOID, yystack.l_mark[0].s, 0); IDpush();}
break;
case 18:
#line 89 "gram.y"
	{ yyval.n = quadNode(VOID, yystack.l_mark[-5].n, strNode(IDENTIFIER, yystack.l_mark[-3].s), yystack.l_mark[-2].n, yystack.l_mark[-1].n);
							IDpop();}
break;
case 19:
#line 91 "gram.y"
	{IDnew(VOID, yystack.l_mark[0].s, 0); IDpush();}
break;
case 20:
#line 92 "gram.y"
	{ yyval.n = quadNode(VOID, yystack.l_mark[-4].n, strNode(IDENTIFIER, yystack.l_mark[-2].s), nilNode(NIL), yystack.l_mark[-1].n);
							IDpop();}
break;
case 21:
#line 96 "gram.y"
	{ yyval.n = nilNode(DONE);}
break;
case 22:
#line 97 "gram.y"
	{ yyval.n = uniNode(DO, yystack.l_mark[0].n);}
break;
case 23:
#line 100 "gram.y"
	{ IDnew(yystack.l_mark[-1].n->info, yystack.l_mark[0].s, 0); yyval.n->info = yystack.l_mark[-1].n->info;
																						yyval.n = triNode(VAR, yystack.l_mark[-1].n, strNode(IDENTIFIER, yystack.l_mark[0].s), nilNode(NIL));}
break;
case 24:
#line 102 "gram.y"
	{ if(yylval.i > 0){IDnew(yystack.l_mark[-4].n->info, yystack.l_mark[-3].s, 0); yyval.n->info = yystack.l_mark[-4].n->info;
																						yyval.n = triNode(VAR, yystack.l_mark[-4].n, strNode(IDENTIFIER, yystack.l_mark[-3].s), intNode(INTEGER, yystack.l_mark[-1].i));}}
break;
case 25:
#line 106 "gram.y"
	{ yyval.n = binNode(VARS, yystack.l_mark[0].n, nilNode(NIL)); }
break;
case 26:
#line 107 "gram.y"
	{ yyval.n = binNode(VARS, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 27:
#line 110 "gram.y"
	{ yyval.n = nilNode(NIL); }
break;
case 28:
#line 111 "gram.y"
	{ yyval.n = binNode(BVAR, yystack.l_mark[-2].n, yystack.l_mark[-1].n); }
break;
case 29:
#line 114 "gram.y"
	{ yyval.n = nilNode(NUMBER); yyval.n->info = NUMBER; }
break;
case 30:
#line 115 "gram.y"
	{ yyval.n = nilNode(STRING); yyval.n->info = STRING; }
break;
case 31:
#line 116 "gram.y"
	{ yyval.n = nilNode(ARRAY); yyval.n->info = ARRAY; }
break;
case 32:
#line 119 "gram.y"
	{ yyval.n = nilNode(NIL);}
break;
case 33:
#line 120 "gram.y"
	{ yyval.n = nilNode(PUBLIC); }
break;
case 34:
#line 121 "gram.y"
	{ yyval.n = nilNode(FORWARD); }
break;
case 35:
#line 124 "gram.y"
	{ yyval.n = triNode(BODY, yystack.l_mark[-2].n, yystack.l_mark[-1].n, yystack.l_mark[0].n);}
break;
case 36:
#line 127 "gram.y"
	{yyval.n = intNode(INTEGER, yystack.l_mark[0].i); yyval.n->info = NUMBER; yyval.n->attrib = yylval.i;}
break;
case 37:
#line 128 "gram.y"
	{ yyval.n = intNode(CHAR, yystack.l_mark[0].i); yyval.n->info = C;}
break;
case 38:
#line 129 "gram.y"
	{ yyval.n = strNode(CCHAR, yystack.l_mark[0].s); yyval.n->info = STRING;}
break;
case 39:
#line 132 "gram.y"
	{ yyval.n = binNode(LITS, nilNode(NIL), yystack.l_mark[0].n); yyval.n->info = yystack.l_mark[0].n->info; yyval.n->attrib = yystack.l_mark[0].n->attrib;}
break;
case 40:
#line 133 "gram.y"
	{ yyval.n = binNode(LITS, yystack.l_mark[-1].n, yystack.l_mark[0].n); yyval.n->info = yystack.l_mark[0].n->info; yyval.n->attrib = yystack.l_mark[0].n->attrib;}
break;
case 41:
#line 136 "gram.y"
	{ yyval.n = nilNode(NIL);}
break;
case 42:
#line 137 "gram.y"
	{ if(yystack.l_mark[0].n->info != NUMBER) yyerror("array can only store numbers");  else {yyval.n = binNode(LITSC, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = yystack.l_mark[0].n->info; yyval.n->attrib = yystack.l_mark[0].n->attrib;}}
break;
case 43:
#line 140 "gram.y"
	{ yyval.n = nilNode(NIL); }
break;
case 44:
#line 141 "gram.y"
	{ yyval.n = binNode(INST, yystack.l_mark[-1].n, yystack.l_mark[0].n);}
break;
case 45:
#line 144 "gram.y"
	{ yyval.n = pentNode(IF, yystack.l_mark[-6].n, yystack.l_mark[-4].n, yystack.l_mark[-3].n, yystack.l_mark[-2].n, yystack.l_mark[-1].n);}
break;
case 46:
#line 145 "gram.y"
	{ yyval.n = pentNode(FOR, yystack.l_mark[-8].n, yystack.l_mark[-6].n, yystack.l_mark[-4].n, yystack.l_mark[-2].n, yystack.l_mark[-1].n);}
break;
case 47:
#line 146 "gram.y"
	{ yyval.n = uniNode(EXPR, yystack.l_mark[-1].n);}
break;
case 48:
#line 147 "gram.y"
	{ yyval.n = uniNode(EXPR, yystack.l_mark[-1].n);}
break;
case 49:
#line 148 "gram.y"
	{ yyval.n = binNode('#', yystack.l_mark[-3].n, yystack.l_mark[-1].n);}
break;
case 50:
#line 151 "gram.y"
	{ yyval.n = nilNode(NIL); }
break;
case 51:
#line 152 "gram.y"
	{ yyval.n = nilNode(REPEAT);}
break;
case 52:
#line 153 "gram.y"
	{ yyval.n = nilNode(STOP);}
break;
case 53:
#line 154 "gram.y"
	{ yyval.n = nilNode(RETURN);}
break;
case 54:
#line 155 "gram.y"
	{ yyval.n = uniNode(RETURN, yystack.l_mark[0].n); yyval.n->info = yystack.l_mark[0].n->info;}
break;
case 55:
#line 158 "gram.y"
	{ yyval.n = nilNode(NIL); }
break;
case 56:
#line 159 "gram.y"
	{ yyval.n = quadNode(ELIF, yystack.l_mark[-5].n, yystack.l_mark[-3].n, yystack.l_mark[-1].n, yystack.l_mark[0].n);}
break;
case 57:
#line 162 "gram.y"
	{ yyval.n = nilNode(NIL); }
break;
case 58:
#line 163 "gram.y"
	{ yyval.n = binNode(ELSE, yystack.l_mark[-1].n, yystack.l_mark[0].n);}
break;
case 59:
#line 166 "gram.y"
	{ yyval.n = uniNode(LVAL, yystack.l_mark[0].n); yyval.n->info = yystack.l_mark[0].n->info;}
break;
case 60:
#line 167 "gram.y"
	{ yyval.n = uniNode(LIT, yystack.l_mark[0].n); yyval.n->info = yystack.l_mark[0].n->info; yyval.n->attrib = yystack.l_mark[0].n->attrib;}
break;
case 61:
#line 168 "gram.y"
	{ yyval.n = uniNode(EXPR, yystack.l_mark[-1].n); yyval.n->info = yystack.l_mark[-1].n->info;}
break;
case 62:
#line 169 "gram.y"
	{ yyval.n = nilNode('?'); yyval.n->info = NUMBER;}
break;
case 63:
#line 170 "gram.y"
	{ yyval.n = uniNode(INV, yystack.l_mark[0].n); yyval.n->info = yystack.l_mark[0].n->info;}
break;
case 64:
#line 171 "gram.y"
	{ yyval.n = uniNode(UMINUS, yystack.l_mark[0].n); yyval.n->info = NUMBER;}
break;
case 65:
#line 172 "gram.y"
	{ yyval.n = binNode('^', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = checknumbers(yystack.l_mark[-2].n, yystack.l_mark[0].n);}
break;
case 66:
#line 173 "gram.y"
	{ yyval.n = binNode('*', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = checknumbers(yystack.l_mark[-2].n, yystack.l_mark[0].n);}
break;
case 67:
#line 174 "gram.y"
	{ if (yystack.l_mark[0].n->attrib != 0) {yyval.n = binNode('/', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = checknumbers(yystack.l_mark[-2].n, yystack.l_mark[0].n);}}
break;
case 68:
#line 175 "gram.y"
	{ yyval.n = binNode('%', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = checknumbers(yystack.l_mark[-2].n, yystack.l_mark[0].n);}
break;
case 69:
#line 176 "gram.y"
	{ yyval.n = binNode(ADD, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = checksumop(yystack.l_mark[-2].n, yystack.l_mark[0].n);}
break;
case 70:
#line 177 "gram.y"
	{ yyval.n = binNode('-', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = checkdifop(yystack.l_mark[-2].n, yystack.l_mark[0].n);}
break;
case 71:
#line 178 "gram.y"
	{ yyval.n = binNode('<', yystack.l_mark[-2].n, yystack.l_mark[0].n);  yyval.n->info = checknumberorstring(yystack.l_mark[-2].n, yystack.l_mark[0].n);}
break;
case 72:
#line 179 "gram.y"
	{ yyval.n = binNode('>', yystack.l_mark[-2].n, yystack.l_mark[0].n);  yyval.n->info = checknumberorstring(yystack.l_mark[-2].n, yystack.l_mark[0].n);}
break;
case 73:
#line 180 "gram.y"
	{ yyval.n = binNode(GE, yystack.l_mark[-2].n, yystack.l_mark[0].n);  yyval.n->info = checknumberorstring(yystack.l_mark[-2].n, yystack.l_mark[0].n);}
break;
case 74:
#line 181 "gram.y"
	{ yyval.n = binNode(LE, yystack.l_mark[-2].n, yystack.l_mark[0].n);  yyval.n->info = checknumberorstring(yystack.l_mark[-2].n, yystack.l_mark[0].n);}
break;
case 75:
#line 182 "gram.y"
	{ yyval.n = binNode(NE, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = checknumberorstring(yystack.l_mark[-2].n, yystack.l_mark[0].n);}
break;
case 76:
#line 183 "gram.y"
	{ yyval.n = binNode('=', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = checknumberorstring(yystack.l_mark[-2].n, yystack.l_mark[0].n);}
break;
case 77:
#line 184 "gram.y"
	{ yyval.n = uniNode(NOT, yystack.l_mark[0].n); if(yystack.l_mark[0].n->info != NUMBER) yyerror("arg must be a number!"); else yyval.n->info = yystack.l_mark[0].n->info;}
break;
case 78:
#line 185 "gram.y"
	{ yyval.n = binNode(AND, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = checknumbers(yystack.l_mark[-2].n, yystack.l_mark[0].n);}
break;
case 79:
#line 186 "gram.y"
	{ yyval.n = binNode(OR, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = checknumbers(yystack.l_mark[-2].n, yystack.l_mark[0].n);}
break;
case 80:
#line 187 "gram.y"
	{ yyval.n = binNode(ASSIGN, yystack.l_mark[0].n, yystack.l_mark[-2].n); yyval.n->info = checksametype(yystack.l_mark[0].n, yystack.l_mark[-2].n);}
break;
case 81:
#line 190 "gram.y"
	{ yyval.n = binNode(INV, yystack.l_mark[-3].n, yystack.l_mark[-1].n); yyval.n->info = yystack.l_mark[-3].n->info;}
break;
case 82:
#line 193 "gram.y"
	{ if(IDfind(yystack.l_mark[0].s, 0) > 0) { yyval.n = binNode(LVAL, strNode(IDENTIFIER, yystack.l_mark[0].s), nilNode(NIL)); yyval.n->info = IDfind(yystack.l_mark[0].s,0);} }
break;
case 83:
#line 194 "gram.y"
	{ if(yystack.l_mark[-3].n->info == ARRAY && yystack.l_mark[-1].n->attrib > 0) {yyval.n = binNode(LVAL, yystack.l_mark[-3].n, yystack.l_mark[-1].n); yyval.n->info = NUMBER; } else yyerror("arg must be array");}
break;
case 84:
#line 195 "gram.y"
	{ yyval.n = uniNode(ADDR, yystack.l_mark[0].n); yyval.n->info = ARRAY;}
break;
case 85:
#line 198 "gram.y"
	{ yyval.n = binNode(ARGS, yystack.l_mark[0].n, nilNode(NIL)); yyval.n->info = yystack.l_mark[0].n->info;}
break;
case 86:
#line 199 "gram.y"
	{ yyval.n = binNode(ARGS, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = yystack.l_mark[-2].n->info;}
break;
#line 1308 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
