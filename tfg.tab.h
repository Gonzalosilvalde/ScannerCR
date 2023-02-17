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

#ifndef YY_YY_TFG_TAB_H_INCLUDED
# define YY_YY_TFG_TAB_H_INCLUDED
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
    TK_IDENTIFICADOR = 258,        /* TK_IDENTIFICADOR  */
    TK_CADENA = 259,               /* TK_CADENA  */
    TK_ENTERO = 260,               /* TK_ENTERO  */
    TK_DOUBLE = 261,               /* TK_DOUBLE  */
    TK_POW = 262,                  /* TK_POW  */
    TK_SUMA = 263,                 /* TK_SUMA  */
    TK_RESTA = 264,                /* TK_RESTA  */
    TK_MULTIPLICACION = 265,       /* TK_MULTIPLICACION  */
    TK_DIVISION = 266,             /* TK_DIVISION  */
    TK_MODULO = 267,               /* TK_MODULO  */
    TK_IGUAL = 268,                /* TK_IGUAL  */
    TK_DIFERENTE = 269,            /* TK_DIFERENTE  */
    TK_MENOR = 270,                /* TK_MENOR  */
    TK_MAYOR = 271,                /* TK_MAYOR  */
    TK_MENOR_IGUAL = 272,          /* TK_MENOR_IGUAL  */
    TK_MAYOR_IGUAL = 273,          /* TK_MAYOR_IGUAL  */
    TK_AND = 274,                  /* TK_AND  */
    TK_OR = 275,                   /* TK_OR  */
    TK_NOT = 276,                  /* TK_NOT  */
    TK_IF = 277,                   /* TK_IF  */
    TK_ELSE = 278,                 /* TK_ELSE  */
    TK_WHILE = 279,                /* TK_WHILE  */
    TK_FOR = 280,                  /* TK_FOR  */
    TK_RETURN = 281,               /* TK_RETURN  */
    TK_INT = 282,                  /* TK_INT  */
    TK_CHAR = 283,                 /* TK_CHAR  */
    TK_VOID = 284                  /* TK_VOID  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define TK_IDENTIFICADOR 258
#define TK_CADENA 259
#define TK_ENTERO 260
#define TK_DOUBLE 261
#define TK_POW 262
#define TK_SUMA 263
#define TK_RESTA 264
#define TK_MULTIPLICACION 265
#define TK_DIVISION 266
#define TK_MODULO 267
#define TK_IGUAL 268
#define TK_DIFERENTE 269
#define TK_MENOR 270
#define TK_MAYOR 271
#define TK_MENOR_IGUAL 272
#define TK_MAYOR_IGUAL 273
#define TK_AND 274
#define TK_OR 275
#define TK_NOT 276
#define TK_IF 277
#define TK_ELSE 278
#define TK_WHILE 279
#define TK_FOR 280
#define TK_RETURN 281
#define TK_INT 282
#define TK_CHAR 283
#define TK_VOID 284

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 10 "tfg.y"

    int ival;
    double dval;
    char *sval;

#line 131 "tfg.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_TFG_TAB_H_INCLUDED  */
