/* A Bison parser, made by GNU Bison 3.8.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SCANNER_TAB_H_INCLUDED
# define YY_YY_SCANNER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    WHILE = 258,                   /* WHILE  */
    FOR = 259,                     /* FOR  */
    DO = 260,                      /* DO  */
    TO = 261,                      /* TO  */
    DOWNTO = 262,                  /* DOWNTO  */
    WRITE = 263,                   /* WRITE  */
    ENDL = 264,                    /* ENDL  */
    READ = 265,                    /* READ  */
    READLN = 266,                  /* READLN  */
    PROGRAM = 267,                 /* PROGRAM  */
    BEG = 268,                     /* BEG  */
    END = 269,                     /* END  */
    IF = 270,                      /* IF  */
    THEN = 271,                    /* THEN  */
    ELSE = 272,                    /* ELSE  */
    AND = 273,                     /* AND  */
    OR = 274,                      /* OR  */
    LOWER = 275,                   /* LOWER  */
    HIGHER = 276,                  /* HIGHER  */
    PLUS = 277,                    /* PLUS  */
    HYPHEN = 278,                  /* HYPHEN  */
    PROD = 279,                    /* PROD  */
    DIV = 280,                     /* DIV  */
    DIVINT = 281,                  /* DIVINT  */
    MOD = 282,                     /* MOD  */
    COMMA = 283,                   /* COMMA  */
    DOT = 284,                     /* DOT  */
    EQ = 285,                      /* EQ  */
    COMMENTLINE = 286,             /* COMMENTLINE  */
    MULTILINE = 287,               /* MULTILINE  */
    VAR = 288,                     /* VAR  */
    CONST = 289,                   /* CONST  */
    DEFINE = 290,                  /* DEFINE  */
    LISTCONTENT = 291,             /* LISTCONTENT  */
    VALUE = 292,                   /* VALUE  */
    LPAREN = 293,                  /* LPAREN  */
    STRINGQUOTE = 294,             /* STRINGQUOTE  */
    RPAREN = 295,                  /* RPAREN  */
    RSQUAREPAREN = 296,            /* RSQUAREPAREN  */
    LSQUAREPAREN = 297,            /* LSQUAREPAREN  */
    COLON = 298,                   /* COLON  */
    SEMICOLON = 299,               /* SEMICOLON  */
    INTEGER = 300,                 /* INTEGER  */
    SHORT = 301,                   /* SHORT  */
    LONG = 302,                    /* LONG  */
    UNSIGNED_INT = 303,            /* UNSIGNED_INT  */
    UNSIGNED_SHORT = 304,          /* UNSIGNED_SHORT  */
    UNSIGNED_LONG = 305,           /* UNSIGNED_LONG  */
    FLOAT = 306,                   /* FLOAT  */
    DOUBLE = 307,                  /* DOUBLE  */
    OPENCURLYBRACKET = 308,        /* OPENCURLYBRACKET  */
    CLOSECURLYBRACKET = 309,       /* CLOSECURLYBRACKET  */
    BOOLEAN = 310,                 /* BOOLEAN  */
    CHAR = 311,                    /* CHAR  */
    STRING = 312,                  /* STRING  */
    STRINGV = 313,                 /* STRINGV  */
    QUOTESTRING = 314,             /* QUOTESTRING  */
    TRUEVAL = 315,                 /* TRUEVAL  */
    FALSEVAL = 316,                /* FALSEVAL  */
    INTNUM = 317,                  /* INTNUM  */
    REALNUM = 318,                 /* REALNUM  */
    RETURN = 319,                  /* RETURN  */
    EX = 320                       /* EX  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define WHILE 258
#define FOR 259
#define DO 260
#define TO 261
#define DOWNTO 262
#define WRITE 263
#define ENDL 264
#define READ 265
#define READLN 266
#define PROGRAM 267
#define BEG 268
#define END 269
#define IF 270
#define THEN 271
#define ELSE 272
#define AND 273
#define OR 274
#define LOWER 275
#define HIGHER 276
#define PLUS 277
#define HYPHEN 278
#define PROD 279
#define DIV 280
#define DIVINT 281
#define MOD 282
#define COMMA 283
#define DOT 284
#define EQ 285
#define COMMENTLINE 286
#define MULTILINE 287
#define VAR 288
#define CONST 289
#define DEFINE 290
#define LISTCONTENT 291
#define VALUE 292
#define LPAREN 293
#define STRINGQUOTE 294
#define RPAREN 295
#define RSQUAREPAREN 296
#define LSQUAREPAREN 297
#define COLON 298
#define SEMICOLON 299
#define INTEGER 300
#define SHORT 301
#define LONG 302
#define UNSIGNED_INT 303
#define UNSIGNED_SHORT 304
#define UNSIGNED_LONG 305
#define FLOAT 306
#define DOUBLE 307
#define OPENCURLYBRACKET 308
#define CLOSECURLYBRACKET 309
#define BOOLEAN 310
#define CHAR 311
#define STRING 312
#define STRINGV 313
#define QUOTESTRING 314
#define TRUEVAL 315
#define FALSEVAL 316
#define INTNUM 317
#define REALNUM 318
#define RETURN 319
#define EX 320

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 36 "scanner.y"

    char * valString;
    int valInt;
    double valDouble;

#line 203 "scanner.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

#if !defined yyerror && !defined YYERROR_IS_DECLARED
void yyerror (const char *msg);
#endif
#if !defined yylex && !defined YYLEX_IS_DECLARED
int yylex (void);
#endif

int yyparse (void);


#endif /* !YY_YY_SCANNER_TAB_H_INCLUDED  */
