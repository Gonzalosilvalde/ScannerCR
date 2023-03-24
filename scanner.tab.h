/* A Bison parser, made by GNU Bison 3.8.2.  */

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
    VALUE = 291,                   /* VALUE  */
    LPAREN = 292,                  /* LPAREN  */
    STRINGQUOTE = 293,             /* STRINGQUOTE  */
    RPAREN = 294,                  /* RPAREN  */
    COLON = 295,                   /* COLON  */
    SEMICOLON = 296,               /* SEMICOLON  */
    INTEGER = 297,                 /* INTEGER  */
    FLOAT = 298,                   /* FLOAT  */
    EX = 299,                      /* EX  */
    OPENCURLYBRACKET = 300,        /* OPENCURLYBRACKET  */
    CLOSECURLYBRACKET = 301,       /* CLOSECURLYBRACKET  */
    BOOLEAN = 302,                 /* BOOLEAN  */
    CHAR = 303,                    /* CHAR  */
    STRING = 304,                  /* STRING  */
    STRINGV = 305,                 /* STRINGV  */
    QUOTESTRING = 306,             /* QUOTESTRING  */
    TRUEVAL = 307,                 /* TRUEVAL  */
    FALSEVAL = 308,                /* FALSEVAL  */
    INTNUM = 309,                  /* INTNUM  */
    REALNUM = 310,                 /* REALNUM  */
    RETURN = 311                   /* RETURN  */
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
#define VALUE 291
#define LPAREN 292
#define STRINGQUOTE 293
#define RPAREN 294
#define COLON 295
#define SEMICOLON 296
#define INTEGER 297
#define FLOAT 298
#define EX 299
#define OPENCURLYBRACKET 300
#define CLOSECURLYBRACKET 301
#define BOOLEAN 302
#define CHAR 303
#define STRING 304
#define STRINGV 305
#define QUOTESTRING 306
#define TRUEVAL 307
#define FALSEVAL 308
#define INTNUM 309
#define REALNUM 310
#define RETURN 311

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 31 "scanner.y"

    char * valString;
    int valInt;
    double valDouble;

#line 185 "scanner.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SCANNER_TAB_H_INCLUDED  */
