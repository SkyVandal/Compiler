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
extern YYSTYPE yylval;
