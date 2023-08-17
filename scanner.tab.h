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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 36 "scanner.y"

    char * valString;
    int valInt;
    double valDouble;

#line 135 "scanner.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SCANNER_TAB_H_INCLUDED  */
