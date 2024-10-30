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
# define YYDEBUG 1
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
    SWITCH = 273,                  /* SWITCH  */
    CASE = 274,                    /* CASE  */
    DEFAULT = 275,                 /* DEFAULT  */
    AND = 276,                     /* AND  */
    OR = 277,                      /* OR  */
    LOWER = 278,                   /* LOWER  */
    HIGHER = 279,                  /* HIGHER  */
    PLUS = 280,                    /* PLUS  */
    HYPHEN = 281,                  /* HYPHEN  */
    PROD = 282,                    /* PROD  */
    DIV = 283,                     /* DIV  */
    DIVINT = 284,                  /* DIVINT  */
    MOD = 285,                     /* MOD  */
    COMMA = 286,                   /* COMMA  */
    DOT = 287,                     /* DOT  */
    PERCENT = 288,                 /* PERCENT  */
    EQ = 289,                      /* EQ  */
    COMMENTLINE = 290,             /* COMMENTLINE  */
    MULTILINE = 291,               /* MULTILINE  */
    VAR = 292,                     /* VAR  */
    CONST = 293,                   /* CONST  */
    DEFINE = 294,                  /* DEFINE  */
    LISTCONTENT = 295,             /* LISTCONTENT  */
    VALUE = 296,                   /* VALUE  */
    LPAREN = 297,                  /* LPAREN  */
    STRINGQUOTE = 298,             /* STRINGQUOTE  */
    RPAREN = 299,                  /* RPAREN  */
    RSQUAREPAREN = 300,            /* RSQUAREPAREN  */
    LSQUAREPAREN = 301,            /* LSQUAREPAREN  */
    COLON = 302,                   /* COLON  */
    SEMICOLON = 303,               /* SEMICOLON  */
    INTEGER = 304,                 /* INTEGER  */
    SHORT = 305,                   /* SHORT  */
    LONG = 306,                    /* LONG  */
    LONG_LONG = 307,               /* LONG_LONG  */
    UNSIGNED_INT = 308,            /* UNSIGNED_INT  */
    UNSIGNED_SHORT = 309,          /* UNSIGNED_SHORT  */
    UNSIGNED_LONG = 310,           /* UNSIGNED_LONG  */
    UNSIGNED_LONG_LONG = 311,      /* UNSIGNED_LONG_LONG  */
    FLOAT = 312,                   /* FLOAT  */
    DOUBLE = 313,                  /* DOUBLE  */
    VOID = 314,                    /* VOID  */
    OPENCURLYBRACKET = 315,        /* OPENCURLYBRACKET  */
    CLOSECURLYBRACKET = 316,       /* CLOSECURLYBRACKET  */
    BOOLEAN = 317,                 /* BOOLEAN  */
    CHAR = 318,                    /* CHAR  */
    PRINTF = 319,                  /* PRINTF  */
    SCANF = 320,                   /* SCANF  */
    STRING = 321,                  /* STRING  */
    STRINGV = 322,                 /* STRINGV  */
    QUOTESTRING = 323,             /* QUOTESTRING  */
    TRUEVAL = 324,                 /* TRUEVAL  */
    FALSEVAL = 325,                /* FALSEVAL  */
    INTNUM = 326,                  /* INTNUM  */
    REALNUM = 327,                 /* REALNUM  */
    RETURN = 328,                  /* RETURN  */
    STRUCT = 329,                  /* STRUCT  */
    AMPERSAND = 330,               /* AMPERSAND  */
    EX = 331                       /* EX  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 78 "scanner.y"

    char * valString;
    int valInt;
    double valDouble;

#line 146 "scanner.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SCANNER_TAB_H_INCLUDED  */
