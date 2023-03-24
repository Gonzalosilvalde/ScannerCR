/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "scanner.y"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include "list.h"

extern int yylex(void);

char outputName[100] = "salida.rs";
char sizeS[8] = "200";

//typeList será la tabla de tipos y constantes.
TypeList typelist;
//queue será la cola a través de la cual recogeremos y volcaremos las variables de los printf 
NodeList queue;

void yyerror(char const *);
char * getVariables(TypeList *);
char * getEndings(NodeList *);
char * getEndingsR(NodeList *);
char * getRef (int);
void deleteQuotes (char *);
void deleteCurly(char *);
void deleteNewLines(char *);


#line 100 "scanner.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "scanner.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_WHILE = 3,                      /* WHILE  */
  YYSYMBOL_FOR = 4,                        /* FOR  */
  YYSYMBOL_DO = 5,                         /* DO  */
  YYSYMBOL_TO = 6,                         /* TO  */
  YYSYMBOL_DOWNTO = 7,                     /* DOWNTO  */
  YYSYMBOL_WRITE = 8,                      /* WRITE  */
  YYSYMBOL_ENDL = 9,                       /* ENDL  */
  YYSYMBOL_READ = 10,                      /* READ  */
  YYSYMBOL_READLN = 11,                    /* READLN  */
  YYSYMBOL_PROGRAM = 12,                   /* PROGRAM  */
  YYSYMBOL_BEG = 13,                       /* BEG  */
  YYSYMBOL_END = 14,                       /* END  */
  YYSYMBOL_IF = 15,                        /* IF  */
  YYSYMBOL_THEN = 16,                      /* THEN  */
  YYSYMBOL_ELSE = 17,                      /* ELSE  */
  YYSYMBOL_AND = 18,                       /* AND  */
  YYSYMBOL_OR = 19,                        /* OR  */
  YYSYMBOL_LOWER = 20,                     /* LOWER  */
  YYSYMBOL_HIGHER = 21,                    /* HIGHER  */
  YYSYMBOL_PLUS = 22,                      /* PLUS  */
  YYSYMBOL_HYPHEN = 23,                    /* HYPHEN  */
  YYSYMBOL_PROD = 24,                      /* PROD  */
  YYSYMBOL_DIV = 25,                       /* DIV  */
  YYSYMBOL_DIVINT = 26,                    /* DIVINT  */
  YYSYMBOL_MOD = 27,                       /* MOD  */
  YYSYMBOL_COMMA = 28,                     /* COMMA  */
  YYSYMBOL_DOT = 29,                       /* DOT  */
  YYSYMBOL_EQ = 30,                        /* EQ  */
  YYSYMBOL_COMMENTLINE = 31,               /* COMMENTLINE  */
  YYSYMBOL_MULTILINE = 32,                 /* MULTILINE  */
  YYSYMBOL_VAR = 33,                       /* VAR  */
  YYSYMBOL_CONST = 34,                     /* CONST  */
  YYSYMBOL_DEFINE = 35,                    /* DEFINE  */
  YYSYMBOL_VALUE = 36,                     /* VALUE  */
  YYSYMBOL_LPAREN = 37,                    /* LPAREN  */
  YYSYMBOL_STRINGQUOTE = 38,               /* STRINGQUOTE  */
  YYSYMBOL_RPAREN = 39,                    /* RPAREN  */
  YYSYMBOL_COLON = 40,                     /* COLON  */
  YYSYMBOL_SEMICOLON = 41,                 /* SEMICOLON  */
  YYSYMBOL_INTEGER = 42,                   /* INTEGER  */
  YYSYMBOL_FLOAT = 43,                     /* FLOAT  */
  YYSYMBOL_EX = 44,                        /* EX  */
  YYSYMBOL_OPENCURLYBRACKET = 45,          /* OPENCURLYBRACKET  */
  YYSYMBOL_CLOSECURLYBRACKET = 46,         /* CLOSECURLYBRACKET  */
  YYSYMBOL_BOOLEAN = 47,                   /* BOOLEAN  */
  YYSYMBOL_CHAR = 48,                      /* CHAR  */
  YYSYMBOL_STRING = 49,                    /* STRING  */
  YYSYMBOL_STRINGV = 50,                   /* STRINGV  */
  YYSYMBOL_QUOTESTRING = 51,               /* QUOTESTRING  */
  YYSYMBOL_TRUEVAL = 52,                   /* TRUEVAL  */
  YYSYMBOL_FALSEVAL = 53,                  /* FALSEVAL  */
  YYSYMBOL_INTNUM = 54,                    /* INTNUM  */
  YYSYMBOL_REALNUM = 55,                   /* REALNUM  */
  YYSYMBOL_RETURN = 56,                    /* RETURN  */
  YYSYMBOL_YYACCEPT = 57,                  /* $accept  */
  YYSYMBOL_S = 58,                         /* S  */
  YYSYMBOL_comment = 59,                   /* comment  */
  YYSYMBOL_subcabecera = 60,               /* subcabecera  */
  YYSYMBOL_cabecera = 61,                  /* cabecera  */
  YYSYMBOL_constdef = 62,                  /* constdef  */
  YYSYMBOL_vardef = 63,                    /* vardef  */
  YYSYMBOL_type = 64,                      /* type  */
  YYSYMBOL_values = 65,                    /* values  */
  YYSYMBOL_programa = 66,                  /* programa  */
  YYSYMBOL_args = 67,                      /* args  */
  YYSYMBOL_lines_program = 68,             /* lines_program  */
  YYSYMBOL_line_program = 69,              /* line_program  */
  YYSYMBOL_contentWrite = 70,              /* contentWrite  */
  YYSYMBOL_assignation = 71,               /* assignation  */
  YYSYMBOL_exp = 72,                       /* exp  */
  YYSYMBOL_term = 73,                      /* term  */
  YYSYMBOL_operand = 74,                   /* operand  */
  YYSYMBOL_atom = 75                       /* atom  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   255

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  186

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   311


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   116,   116,   133,   137,   138,   143,   144,   147,   148,
     152,   163,   177,   186,   198,   214,   215,   216,   217,   218,
     224,   225,   226,   227,   228,   230,   235,   238,   241,   244,
     247,   250,   253,   256,   257,   263,   264,   268,   277,   285,
     286,   290,   291,   292,   293,   297,   300,   301,   302,   303,
     304,   305,   306,   307,   312,   321,   330,   348,   349,   357,
     389,   396,   399,   407,   415,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     445,   453
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "WHILE", "FOR", "DO",
  "TO", "DOWNTO", "WRITE", "ENDL", "READ", "READLN", "PROGRAM", "BEG",
  "END", "IF", "THEN", "ELSE", "AND", "OR", "LOWER", "HIGHER", "PLUS",
  "HYPHEN", "PROD", "DIV", "DIVINT", "MOD", "COMMA", "DOT", "EQ",
  "COMMENTLINE", "MULTILINE", "VAR", "CONST", "DEFINE", "VALUE", "LPAREN",
  "STRINGQUOTE", "RPAREN", "COLON", "SEMICOLON", "INTEGER", "FLOAT", "EX",
  "OPENCURLYBRACKET", "CLOSECURLYBRACKET", "BOOLEAN", "CHAR", "STRING",
  "STRINGV", "QUOTESTRING", "TRUEVAL", "FALSEVAL", "INTNUM", "REALNUM",
  "RETURN", "$accept", "S", "comment", "subcabecera", "cabecera",
  "constdef", "vardef", "type", "values", "programa", "args",
  "lines_program", "line_program", "contentWrite", "assignation", "exp",
  "term", "operand", "atom", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-61)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      11,    -6,    29,    28,   -11,   -61,   -61,   -61,   -61,    -7,
      10,     4,    28,   -61,   -61,   -61,   185,    79,     3,   -61,
     -61,   -61,   -61,   -61,   185,   185,    18,   -61,    20,    78,
     -61,   -61,     0,    27,   -61,   -61,   -61,   -61,   -61,    32,
     146,    35,   -61,    78,   -61,    34,    39,    31,    36,    48,
      50,   -61,   -61,   103,    64,    57,   -61,    58,    66,    59,
      90,    76,     7,   -61,   -61,    28,    85,    -4,   -61,   -61,
      67,    73,   175,   -61,    79,   139,    -4,    79,   175,   105,
      -4,    99,   175,   185,    -4,   161,    -4,    -4,   -61,   -61,
      98,   -61,   -61,   -13,    28,   -61,   -61,    28,    94,   102,
     107,   109,    12,   119,    -4,   129,   -61,   135,   -61,   138,
     -61,   -61,   185,   185,    28,   148,   118,   181,   -61,   -61,
      14,   149,   152,   -61,   -61,   -61,   -61,   -61,   185,   175,
     150,   165,   183,   155,    15,   -61,   175,   163,   -61,   180,
     188,    -4,   212,   -61,   -61,   -61,   184,   175,   -61,    -4,
     196,   195,   -61,   191,   197,   198,   -61,   -61,   190,   -61,
     142,   202,   -61,   -61,   213,   214,   215,   216,   -61,   -61,
     -61,   -61,    -4,   203,   204,   -61,   -61,   -61,   -61,   205,
     175,   175,   201,   206,   -61,   -61
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     5,     0,     9,     1,     3,     4,     0,
       0,     0,     5,     8,     6,     7,     0,     0,     0,    15,
      16,    19,    18,    17,     0,     0,     0,     2,     0,     0,
      34,    33,     0,     0,    24,    20,    21,    22,    23,     0,
       0,     0,    12,     0,    10,     0,     0,     0,     0,     0,
       0,    14,    13,     0,    36,     0,    11,     0,     0,     0,
       0,     0,     0,    49,    50,     5,     0,     0,    52,    51,
       0,     0,    38,    41,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    32,     0,     0,     0,     0,    80,    81,
       0,    60,    61,     0,     5,    37,    35,     5,     0,     0,
       0,     0,     0,     0,     0,     0,    30,     0,    63,     0,
      64,    53,    25,    31,     5,     0,     0,     0,    58,    57,
       0,     0,     0,    44,    59,    62,    27,    29,    26,     0,
       0,     0,     0,     0,     0,    39,     0,     0,    28,     0,
       0,     0,     0,    55,    56,    54,     0,     0,    48,     0,
       0,     0,    42,     0,     0,     0,    40,    43,     0,    47,
       0,     0,    78,    79,    73,    74,    65,    67,    69,    70,
      71,    72,    77,     0,     0,    75,    76,    66,    68,     0,
       0,     0,     0,     0,    46,    45
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -61,   -61,    -9,   237,   -61,   -14,   -12,   -16,    -5,   -19,
     177,   -57,   171,   -61,    96,   -60,   -61,   -61,   170
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     9,    12,     3,    68,    69,    70,    89,    27,
      49,    71,    72,   120,    73,   107,    91,   173,    92
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      26,    28,    24,    16,    25,    30,    31,    90,    26,    26,
      24,    24,    25,    25,     4,    95,    99,    40,    98,    85,
     103,   101,    81,     1,    39,    48,   109,   110,    42,     6,
      40,    13,     5,    86,   132,    46,   133,    41,    50,    10,
      87,    42,   134,    11,   122,    14,    88,    34,    35,    36,
      37,    38,    82,    29,    11,   135,    83,    43,    48,     7,
       8,   100,   118,   119,   106,   144,   145,    26,    32,    24,
      33,    25,   139,    44,    47,    51,    53,    19,    20,   146,
      52,   150,    21,    22,    23,   112,    54,    55,   113,   154,
     153,    56,    74,   126,   127,    76,    26,    26,    24,    24,
      25,    25,    75,    77,    78,   128,    57,    58,    59,   138,
      79,    60,    26,    80,    24,    84,    25,    93,    61,    94,
      62,    19,    20,   182,   183,   102,    21,    22,    23,    34,
      35,    36,    37,    38,    63,    64,   104,    17,    18,   111,
     114,   115,    57,    58,    59,    19,    20,    60,   130,    65,
      21,    22,    23,    66,    61,   117,    62,   116,   121,    67,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
      63,    64,   172,    17,    18,   123,   124,   125,    57,    58,
      59,    19,    20,    60,   131,    97,    21,    22,    23,    66,
      61,   137,    62,   129,   136,    67,    45,    34,    35,    36,
      37,    38,   141,   142,   140,   143,    63,    64,   147,    17,
      18,    88,    34,    35,    36,    37,    38,    19,    20,    17,
      18,   151,    21,    22,    23,    66,   148,    19,    20,   149,
     152,    67,    21,    22,    23,   155,   156,   157,   158,   159,
     160,   174,   179,   175,   176,   177,   178,   184,    15,   180,
     181,    96,   185,   105,   161,   108
};

static const yytype_uint8 yycheck[] =
{
      16,    17,    16,    12,    16,    24,    25,    67,    24,    25,
      24,    25,    24,    25,    20,    72,    76,    30,    75,    23,
      80,    78,    15,    12,    29,    41,    86,    87,    41,     0,
      30,    21,    38,    37,    20,    40,    22,    37,    43,    50,
      44,    41,    28,    50,   104,    41,    50,    51,    52,    53,
      54,    55,    45,    50,    50,    41,    65,    30,    74,    31,
      32,    77,    50,    51,    83,    50,    51,    83,    50,    83,
      50,    83,   129,    41,    39,    41,    45,    42,    43,   136,
      41,   141,    47,    48,    49,    94,    50,    39,    97,   149,
     147,    41,    28,   112,   113,    37,   112,   113,   112,   113,
     112,   113,    45,    37,    45,   114,     3,     4,     5,   128,
      20,     8,   128,    37,   128,    30,   128,    50,    15,    46,
      17,    42,    43,   180,   181,    20,    47,    48,    49,    51,
      52,    53,    54,    55,    31,    32,    37,    34,    35,    41,
      46,    39,     3,     4,     5,    42,    43,     8,    30,    46,
      47,    48,    49,    50,    15,    46,    17,    50,    39,    56,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      31,    32,    30,    34,    35,    46,    41,    39,     3,     4,
       5,    42,    43,     8,     3,    46,    47,    48,    49,    50,
      15,    39,    17,    45,    45,    56,    50,    51,    52,    53,
      54,    55,    37,    20,    54,    50,    31,    32,    45,    34,
      35,    50,    51,    52,    53,    54,    55,    42,    43,    34,
      35,     9,    47,    48,    49,    50,    46,    42,    43,    41,
      46,    56,    47,    48,    49,    39,    41,    46,    41,    41,
      50,    39,    39,    30,    30,    30,    30,    46,    11,    45,
      45,    74,    46,    82,   158,    85
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    12,    58,    61,    20,    38,     0,    31,    32,    59,
      50,    50,    60,    21,    41,    60,    59,    34,    35,    42,
      43,    47,    48,    49,    62,    63,    64,    66,    64,    50,
      66,    66,    50,    50,    51,    52,    53,    54,    55,    65,
      30,    37,    41,    30,    41,    50,    65,    39,    64,    67,
      65,    41,    41,    45,    50,    39,    41,     3,     4,     5,
       8,    15,    17,    31,    32,    46,    50,    56,    62,    63,
      64,    68,    69,    71,    28,    45,    37,    37,    45,    20,
      37,    15,    45,    59,    30,    23,    37,    44,    50,    65,
      72,    73,    75,    50,    46,    68,    67,    46,    68,    72,
      64,    68,    20,    72,    37,    69,    66,    72,    75,    72,
      72,    41,    59,    59,    46,    39,    50,    46,    50,    51,
      70,    39,    72,    46,    41,    39,    66,    66,    59,    45,
      30,     3,    20,    22,    28,    41,    45,    39,    66,    68,
      54,    37,    20,    50,    50,    51,    68,    45,    46,    41,
      72,     9,    46,    68,    72,    39,    41,    46,    41,    41,
      50,    71,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    30,    74,    39,    30,    30,    30,    30,    39,
      45,    45,    68,    68,    46,    46
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    57,    58,    59,    59,    59,    60,    60,    61,    61,
      62,    62,    63,    63,    63,    64,    64,    64,    64,    64,
      65,    65,    65,    65,    65,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    67,    67,    68,    68,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    70,    70,    70,    70,    70,    71,
      72,    73,    73,    73,    73,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      75,    75
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     1,     1,     0,     2,     2,     4,     2,
       4,     6,     3,     5,     5,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     8,     9,     9,    10,     9,
       8,     8,     7,     2,     2,     4,     2,     2,     1,     5,
       8,     1,     7,     8,     4,    15,    14,     9,     7,     1,
       1,     1,     1,     3,     3,     3,     3,     1,     1,     4,
       1,     1,     3,     2,     2,     1,     2,     1,     2,     1,
       1,     1,     1,     1,     1,     2,     2,     1,     1,     1,
       1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* S: cabecera comment subcabecera comment programa  */
#line 116 "scanner.y"
                                                      { 
                
                FILE *fp = fopen(outputName, "w");
				char * variables = getVariables(&typelist);
                
                if (fp!=NULL) {
                    fputs(strcat((yyvsp[-3].valString),"\n"),fp);
                    fputs(variables, fp);
                    fclose(fp);    
                }
                free((yyvsp[0].valString));
        }
#line 1575 "scanner.tab.c"
    break;

  case 3: /* comment: COMMENTLINE  */
#line 133 "scanner.y"
                     {
                deleteNewLines((yyvsp[0].valString));
                (yyval.valString) = (yyvsp[0].valString);
                }
#line 1584 "scanner.tab.c"
    break;

  case 4: /* comment: MULTILINE  */
#line 137 "scanner.y"
                    {;}
#line 1590 "scanner.tab.c"
    break;

  case 5: /* comment: %empty  */
#line 138 "scanner.y"
          {;}
#line 1596 "scanner.tab.c"
    break;

  case 6: /* subcabecera: STRINGV SEMICOLON  */
#line 143 "scanner.y"
                          {;}
#line 1602 "scanner.tab.c"
    break;

  case 7: /* subcabecera: STRINGV subcabecera  */
#line 144 "scanner.y"
                             {;}
#line 1608 "scanner.tab.c"
    break;

  case 8: /* cabecera: PROGRAM LOWER STRINGV HIGHER  */
#line 147 "scanner.y"
                                        {;}
#line 1614 "scanner.tab.c"
    break;

  case 9: /* cabecera: PROGRAM STRINGQUOTE  */
#line 148 "scanner.y"
                                       {;}
#line 1620 "scanner.tab.c"
    break;

  case 10: /* constdef: DEFINE STRINGV values SEMICOLON  */
#line 152 "scanner.y"
                                        {
                Node node;
                strcpy(node.name, (yyvsp[-2].valString));
                node.isConstant = 1;
                node.isValue = 1;
                node.type = 0;
                strcpy(node.value, (yyvsp[-1].valString));
                InsertElementT(&typelist, &node);
                free((yyvsp[-2].valString));
                free((yyvsp[-1].valString));
                }
#line 1636 "scanner.tab.c"
    break;

  case 11: /* constdef: CONST type STRINGV EQ values SEMICOLON  */
#line 163 "scanner.y"
                                                {
                Node node;
                strcpy(node.name, (yyvsp[-3].valString));
                node.isConstant = 1;
                node.isValue = 1;
                node.type = (yyvsp[-4].valInt);
                strcpy(node.value, (yyvsp[-1].valString));
                InsertElementT(&typelist, &node);
                free((yyvsp[-3].valString));
                free((yyvsp[-1].valString));
                }
#line 1652 "scanner.tab.c"
    break;

  case 12: /* vardef: type STRINGV SEMICOLON  */
#line 177 "scanner.y"
                               {
                Node node;
                strcpy(node.name, (yyvsp[-1].valString));
                node.type = (yyvsp[-2].valInt);
                node.isValue = 0;
                node.isConstant = 0;
                InsertElementT(&typelist, &node);
                free((yyvsp[-1].valString));
                }
#line 1666 "scanner.tab.c"
    break;

  case 13: /* vardef: type STRINGV EQ values SEMICOLON  */
#line 186 "scanner.y"
                                           {
                Node node;
                strcpy(node.name, (yyvsp[-3].valString));
                char value[10];
                node.isConstant = 0;
                node.isValue = 1;
                node.type = (yyvsp[-4].valInt);
                strcpy(node.value, (yyvsp[-1].valString));
                InsertElementT(&typelist, &node);
                free((yyvsp[-3].valString));
                free((yyvsp[-1].valString));
                }
#line 1683 "scanner.tab.c"
    break;

  case 14: /* vardef: type STRINGV EQ STRINGV SEMICOLON  */
#line 198 "scanner.y"
                                            {
                Node node;
                strcpy(node.name, (yyvsp[-3].valString));
                char value[10];
                node.isConstant = 0;
                node.isValue = 1;
                node.type = (yyvsp[-4].valInt);
                strcpy(node.value, (yyvsp[-1].valString));
                InsertElementT(&typelist, &node);
                free((yyvsp[-3].valString));
                free((yyvsp[-1].valString));
                }
#line 1700 "scanner.tab.c"
    break;

  case 15: /* type: INTEGER  */
#line 214 "scanner.y"
                {(yyval.valInt) = 0;}
#line 1706 "scanner.tab.c"
    break;

  case 16: /* type: FLOAT  */
#line 215 "scanner.y"
                {(yyval.valInt) = 1;}
#line 1712 "scanner.tab.c"
    break;

  case 17: /* type: STRING  */
#line 216 "scanner.y"
                 {(yyval.valInt) = 2;}
#line 1718 "scanner.tab.c"
    break;

  case 18: /* type: CHAR  */
#line 217 "scanner.y"
               {(yyval.valInt) = 3;}
#line 1724 "scanner.tab.c"
    break;

  case 19: /* type: BOOLEAN  */
#line 218 "scanner.y"
                  {(yyval.valInt) = 0;}
#line 1730 "scanner.tab.c"
    break;

  case 20: /* values: TRUEVAL  */
#line 224 "scanner.y"
                {(yyval.valString) = strdup("1");}
#line 1736 "scanner.tab.c"
    break;

  case 21: /* values: FALSEVAL  */
#line 225 "scanner.y"
                   {(yyval.valString) = strdup("0");}
#line 1742 "scanner.tab.c"
    break;

  case 22: /* values: INTNUM  */
#line 226 "scanner.y"
                 {(yyval.valString) = (yyvsp[0].valString);}
#line 1748 "scanner.tab.c"
    break;

  case 23: /* values: REALNUM  */
#line 227 "scanner.y"
                  {(yyval.valString) = (yyvsp[0].valString);}
#line 1754 "scanner.tab.c"
    break;

  case 24: /* values: QUOTESTRING  */
#line 228 "scanner.y"
                      {;}
#line 1760 "scanner.tab.c"
    break;

  case 25: /* programa: type STRINGV LPAREN RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET comment  */
#line 230 "scanner.y"
                                                                                               {
                ;
                
                
                }
#line 1770 "scanner.tab.c"
    break;

  case 26: /* programa: type STRINGV LPAREN args RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET comment  */
#line 235 "scanner.y"
                                                                                                  {
                ;
                }
#line 1778 "scanner.tab.c"
    break;

  case 27: /* programa: type STRINGV LPAREN RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET comment programa  */
#line 238 "scanner.y"
                                                                                                      {
                ;
                }
#line 1786 "scanner.tab.c"
    break;

  case 28: /* programa: type STRINGV LPAREN args RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET comment programa  */
#line 241 "scanner.y"
                                                                                                           {
                ;
                }
#line 1794 "scanner.tab.c"
    break;

  case 29: /* programa: type STRINGV LPAREN args RPAREN OPENCURLYBRACKET CLOSECURLYBRACKET comment programa  */
#line 244 "scanner.y"
                                                                                              {
                ;
                }
#line 1802 "scanner.tab.c"
    break;

  case 30: /* programa: type STRINGV LPAREN RPAREN OPENCURLYBRACKET CLOSECURLYBRACKET comment programa  */
#line 247 "scanner.y"
                                                                                         {
                ;
        }
#line 1810 "scanner.tab.c"
    break;

  case 31: /* programa: type STRINGV LPAREN args RPAREN OPENCURLYBRACKET CLOSECURLYBRACKET comment  */
#line 250 "scanner.y"
                                                                                      {
                ;
        }
#line 1818 "scanner.tab.c"
    break;

  case 32: /* programa: type STRINGV LPAREN RPAREN OPENCURLYBRACKET CLOSECURLYBRACKET comment  */
#line 253 "scanner.y"
                                                                                 {
                ;
        }
#line 1826 "scanner.tab.c"
    break;

  case 33: /* programa: vardef programa  */
#line 256 "scanner.y"
                          {;}
#line 1832 "scanner.tab.c"
    break;

  case 34: /* programa: constdef programa  */
#line 257 "scanner.y"
                            {;}
#line 1838 "scanner.tab.c"
    break;

  case 35: /* args: type STRINGV COMMA args  */
#line 263 "scanner.y"
                                {;}
#line 1844 "scanner.tab.c"
    break;

  case 36: /* args: type STRINGV  */
#line 264 "scanner.y"
                      {;}
#line 1850 "scanner.tab.c"
    break;

  case 37: /* lines_program: line_program lines_program  */
#line 268 "scanner.y"
                                   {
                char * final = malloc(strlen((yyvsp[-1].valString)) * sizeof(char) + strlen((yyvsp[0].valString)) * sizeof(char) + sizeof("\n") + 3);
                strcpy(final, (yyvsp[-1].valString));
                strcat(final, "\n");
                strcat(final, (yyvsp[0].valString));
                free((yyvsp[-1].valString));
                free((yyvsp[0].valString));
                (yyval.valString) = final;
                }
#line 1864 "scanner.tab.c"
    break;

  case 38: /* lines_program: line_program  */
#line 277 "scanner.y"
                       {
                (yyval.valString) = (yyvsp[0].valString);
                }
#line 1872 "scanner.tab.c"
    break;

  case 39: /* line_program: WRITE LOWER LOWER contentWrite SEMICOLON  */
#line 285 "scanner.y"
                                                 {;}
#line 1878 "scanner.tab.c"
    break;

  case 40: /* line_program: WRITE LOWER LOWER contentWrite LOWER LOWER ENDL SEMICOLON  */
#line 286 "scanner.y"
                                                                  {;}
#line 1884 "scanner.tab.c"
    break;

  case 41: /* line_program: assignation  */
#line 290 "scanner.y"
                      {;}
#line 1890 "scanner.tab.c"
    break;

  case 42: /* line_program: IF LPAREN exp RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET  */
#line 291 "scanner.y"
                                                                                                 {;}
#line 1896 "scanner.tab.c"
    break;

  case 43: /* line_program: ELSE IF LPAREN exp RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET  */
#line 292 "scanner.y"
                                                                                                      {;}
#line 1902 "scanner.tab.c"
    break;

  case 44: /* line_program: ELSE OPENCURLYBRACKET line_program CLOSECURLYBRACKET  */
#line 293 "scanner.y"
                                                               {;}
#line 1908 "scanner.tab.c"
    break;

  case 45: /* line_program: FOR LPAREN type STRINGV EQ INTNUM SEMICOLON exp SEMICOLON STRINGV operand RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET  */
#line 297 "scanner.y"
                                                                                                                                            {
                
                ;}
#line 1916 "scanner.tab.c"
    break;

  case 46: /* line_program: FOR LPAREN type STRINGV EQ INTNUM SEMICOLON exp SEMICOLON assignation RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET  */
#line 300 "scanner.y"
                                                                                                                                         {;}
#line 1922 "scanner.tab.c"
    break;

  case 47: /* line_program: DO OPENCURLYBRACKET lines_program CLOSECURLYBRACKET WHILE LPAREN exp RPAREN SEMICOLON  */
#line 301 "scanner.y"
                                                                                               {;}
#line 1928 "scanner.tab.c"
    break;

  case 48: /* line_program: WHILE LPAREN exp RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET  */
#line 302 "scanner.y"
                                                                                  {;}
#line 1934 "scanner.tab.c"
    break;

  case 49: /* line_program: COMMENTLINE  */
#line 303 "scanner.y"
                      {;}
#line 1940 "scanner.tab.c"
    break;

  case 50: /* line_program: MULTILINE  */
#line 304 "scanner.y"
                    {;}
#line 1946 "scanner.tab.c"
    break;

  case 51: /* line_program: vardef  */
#line 305 "scanner.y"
                 {;}
#line 1952 "scanner.tab.c"
    break;

  case 52: /* line_program: constdef  */
#line 306 "scanner.y"
                   {;}
#line 1958 "scanner.tab.c"
    break;

  case 53: /* line_program: RETURN exp SEMICOLON  */
#line 307 "scanner.y"
                               {;}
#line 1964 "scanner.tab.c"
    break;

  case 54: /* contentWrite: contentWrite COMMA QUOTESTRING  */
#line 312 "scanner.y"
                                       {
			deleteQuotes((yyvsp[0].valString));
			char * final = malloc ( strlen((yyvsp[-2].valString)) * sizeof(char) + strlen((yyvsp[0].valString)) * sizeof(char) +1);
			strcpy(final, (yyvsp[-2].valString));
			strcat(final, (yyvsp[0].valString));
			free((yyvsp[-2].valString));
			free((yyvsp[0].valString));
			(yyval.valString) = final;
		}
#line 1978 "scanner.tab.c"
    break;

  case 55: /* contentWrite: contentWrite PLUS STRINGV  */
#line 321 "scanner.y"
                                    {
			deleteQuotes((yyvsp[0].valString));
			char * final = malloc ( strlen((yyvsp[-2].valString)) * sizeof(char) + strlen((yyvsp[0].valString)) * sizeof(char) +1);
			strcpy(final, (yyvsp[-2].valString));
			strcat(final, (yyvsp[0].valString));
			free((yyvsp[-2].valString));
			free((yyvsp[0].valString));
			(yyval.valString) = final;
		}
#line 1992 "scanner.tab.c"
    break;

  case 56: /* contentWrite: contentWrite COMMA STRINGV  */
#line 330 "scanner.y"
                                             {
			if(!checkName(&typelist,(yyvsp[0].valString))) {
					printf("Error: Variable %s no declarada\n", (yyvsp[0].valString));
					yyclearin;
					exit(0); 
			}     
			NameNode node;
			strcpy(node.name, (yyvsp[0].valString));
			InsertElementN (&queue, &node);
			int type = SearchType(&typelist, (yyvsp[0].valString));
			char * typeref = malloc(strlen((yyvsp[-2].valString)) * sizeof(char) + sizeof("%lf") + 1);
			char * ty = getRef(type);
			strcpy(typeref, (yyvsp[-2].valString));
			strcat(typeref, ty);
			free((yyvsp[-2].valString));
			free(ty);
			(yyval.valString) = typeref;
		}
#line 2015 "scanner.tab.c"
    break;

  case 57: /* contentWrite: QUOTESTRING  */
#line 348 "scanner.y"
                      {;}
#line 2021 "scanner.tab.c"
    break;

  case 58: /* contentWrite: STRINGV  */
#line 349 "scanner.y"
                  {(yyval.valString) = strdup((yyvsp[0].valString));}
#line 2027 "scanner.tab.c"
    break;

  case 59: /* assignation: STRINGV EQ exp SEMICOLON  */
#line 357 "scanner.y"
                                 {
			if ((!checkName(&typelist, (yyvsp[-3].valString)))){
                        printf("Error: Variable %s no declarada\n", (yyvsp[-3].valString));
                        yyclearin;
                        exit(0);
                }
                if(checkConstant(&typelist, (yyvsp[-3].valString))) {
                        printf("Error: %s es una constante, no puedes reasignar su valor\n", (yyvsp[-3].valString));
                        yyclearin;
                        exit(0);  
                }
                if((((yyvsp[-1].valString)[0] == '\"') && ((yyvsp[-1].valString)[strlen((yyvsp[-1].valString))-1] == '\"')) || ((checkName(&typelist, (yyvsp[-1].valString))) && SearchType(&typelist, (yyvsp[-1].valString)))){
                        char * final = malloc(strlen((yyvsp[-3].valString)) * sizeof(char) + sizeof("strcpy(,)") + strlen((yyvsp[-1].valString)) * sizeof(char) + sizeof(";") + 1);
                        strcpy(final, "strcpy(");
                        strcat(final, (yyvsp[-3].valString));
                        strcat(final, ",");
                        strcat(final, (yyvsp[-1].valString));
                        strcat(final, ");");
                        (yyval.valString) = final;
                }else{
                        char * final = malloc(strlen((yyvsp[-3].valString)) * sizeof(char) + sizeof(" = ") + strlen((yyvsp[-1].valString)) * sizeof(char) + sizeof(";") + 1);
                        strcpy(final, (yyvsp[-3].valString));
                        strcat(final, " = ");
                        strcat(final, (yyvsp[-1].valString));
                        strcat(final, ";"); 
                        (yyval.valString) = final;
                }
		}
#line 2060 "scanner.tab.c"
    break;

  case 60: /* exp: term  */
#line 389 "scanner.y"
             {
			(yyval.valString) = (yyvsp[0].valString);	
			}
#line 2068 "scanner.tab.c"
    break;

  case 61: /* term: atom  */
#line 396 "scanner.y"
             {
			(yyval.valString) = (yyvsp[0].valString);
			}
#line 2076 "scanner.tab.c"
    break;

  case 62: /* term: LPAREN exp RPAREN  */
#line 399 "scanner.y"
                            {
			char * final = malloc(strlen((yyvsp[-1].valString)) * sizeof(char) + sizeof("()") + 1);
			strcpy(final, "(");
			strcat(final, (yyvsp[-1].valString));
			strcat(final, ")");
			free((yyvsp[-1].valString));
			(yyval.valString) = final;
		}
#line 2089 "scanner.tab.c"
    break;

  case 63: /* term: HYPHEN atom  */
#line 407 "scanner.y"
                      {
			char * final = malloc(strlen((yyvsp[0].valString)) * sizeof(char) + sizeof("-()") + 1);
                strcpy(final, "-(");
                strcat(final, (yyvsp[0].valString));
                strcat(final, ")");
                free((yyvsp[0].valString));
                (yyval.valString) = final;
		}
#line 2102 "scanner.tab.c"
    break;

  case 64: /* term: EX exp  */
#line 415 "scanner.y"
                 {
			char * final = malloc(strlen((yyvsp[0].valString)) * sizeof(char) + sizeof("!()") + 1);
                strcpy(final, "!(");
                strcat(final, (yyvsp[0].valString));
                strcat(final, ")");
                free((yyvsp[0].valString));
                (yyval.valString) = final;
		}
#line 2115 "scanner.tab.c"
    break;

  case 65: /* operand: PLUS  */
#line 426 "scanner.y"
             {(yyval.valString) = strdup(" + ");}
#line 2121 "scanner.tab.c"
    break;

  case 66: /* operand: PLUS EQ  */
#line 427 "scanner.y"
                         {(yyval.valString) = strdup(" += ");;}
#line 2127 "scanner.tab.c"
    break;

  case 67: /* operand: HYPHEN  */
#line 428 "scanner.y"
                {(yyval.valString) = strdup(" - ");}
#line 2133 "scanner.tab.c"
    break;

  case 68: /* operand: HYPHEN EQ  */
#line 429 "scanner.y"
                           {(yyval.valString) = strdup(" -= ");;}
#line 2139 "scanner.tab.c"
    break;

  case 69: /* operand: PROD  */
#line 430 "scanner.y"
              {(yyval.valString) = strdup(" * ");}
#line 2145 "scanner.tab.c"
    break;

  case 70: /* operand: DIV  */
#line 431 "scanner.y"
             {(yyval.valString) = strdup(" / ");}
#line 2151 "scanner.tab.c"
    break;

  case 71: /* operand: DIVINT  */
#line 432 "scanner.y"
                {(yyval.valString) = strdup(" / ");}
#line 2157 "scanner.tab.c"
    break;

  case 72: /* operand: MOD  */
#line 433 "scanner.y"
             {(yyval.valString) = strdup(" % ");}
#line 2163 "scanner.tab.c"
    break;

  case 73: /* operand: LOWER  */
#line 434 "scanner.y"
               {(yyval.valString) = strdup(" < ");}
#line 2169 "scanner.tab.c"
    break;

  case 74: /* operand: HIGHER  */
#line 435 "scanner.y"
                {(yyval.valString) = strdup(" > ");}
#line 2175 "scanner.tab.c"
    break;

  case 75: /* operand: LOWER EQ  */
#line 436 "scanner.y"
                  {(yyval.valString) = strdup(" <= ");}
#line 2181 "scanner.tab.c"
    break;

  case 76: /* operand: HIGHER EQ  */
#line 437 "scanner.y"
                   {(yyval.valString) = strdup(" >= ");}
#line 2187 "scanner.tab.c"
    break;

  case 77: /* operand: EQ  */
#line 438 "scanner.y"
            {(yyval.valString) = strdup(" == ");}
#line 2193 "scanner.tab.c"
    break;

  case 78: /* operand: AND  */
#line 439 "scanner.y"
             {(yyval.valString) = strdup(" && ");}
#line 2199 "scanner.tab.c"
    break;

  case 79: /* operand: OR  */
#line 440 "scanner.y"
           {(yyval.valString) = strdup(" || ");;}
#line 2205 "scanner.tab.c"
    break;

  case 80: /* atom: STRINGV  */
#line 445 "scanner.y"
                {
			if (!checkName(&typelist, (yyvsp[0].valString))){
                        printf("Error: Variable %s no declarada\n", (yyvsp[0].valString));
                        yyclearin;
                        exit(0);
            }
            (yyval.valString) = (yyvsp[0].valString);
		}
#line 2218 "scanner.tab.c"
    break;

  case 81: /* atom: values  */
#line 453 "scanner.y"
                 {
			(yyval.valString) = (yyvsp[0].valString);
		}
#line 2226 "scanner.tab.c"
    break;


#line 2230 "scanner.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 458 "scanner.y"



/* Funciones auxiliares de borrado de caracteres */
void deleteQuotes(char * stringq) {
        int reader = 0; int writer = 0;

        while(stringq[reader]) {
                if (!((stringq[reader] == '\'') || (stringq[reader] == '\"')) ){
                stringq[writer++] = stringq[reader];
                }
                reader++;
        }

        stringq[writer] = 0;
        return;
}

void deleteCurly(char * stringq) {
        int reader = 0; int writer = 0;

        while(stringq[reader]) {
                if (!((stringq[reader] == '{') || (stringq[reader] == '}')) ){
                stringq[writer++] = stringq[reader];
                }
                reader++;
        }

        stringq[writer] = 0;
        return;
}

void deleteNewLines(char * stringq){
        int reader = 0; int writer = 0;

        while(stringq[reader]) {
                if (!((stringq[reader] == '\n')) ){
                stringq[writer++] = stringq[reader];
                }
                reader++;
        }

        stringq[writer] = 0;
        return;
}

/* Procesa los elementos a incluir en el string de Write */
char * getEndings (NodeList * queue) {
        int size = (*queue).end;
        char * final = malloc(size*100*sizeof(char) + size * sizeof("&") + 1);
        strcpy(final,""); 
        char * variable;
        while(!isEmptyListN(queue)){
                variable = getElementN(queue);
                strcat(final,",");
                strcat(final, variable);
                free(variable);
                DeleteElementN(queue);
        }
        return final;
}

/* Procesa los elementos a incluir en el string de Read */
char * getEndingsR (NodeList * queue) {
        int size = (*queue).end;
        char * final = malloc(size*100*sizeof(char) + size * sizeof("&") + 1);
        strcpy(final,""); 
        char * variable;
        while(!isEmptyListN(queue)){
                variable = getElementN(queue);
                strcat(final,",");
                if (SearchType(&typelist, variable) != 2) {
                        strcat(final, "&");
                }
                strcat(final, variable);
                free(variable);
                DeleteElementN(queue);
        }
        return final;
}

/* Recupera las variables declaradas */
char * getVariables (TypeList * queue) {
        int size = (*queue).end;
        char * final = malloc(size * (109*sizeof(char) + sizeof("=;\n") + 100 *sizeof(char) + sizeof("[100]") + sizeof("const ")) +1);
        char * varlist = malloc(size * (109*sizeof(char) + sizeof("=;\n") + 100 *sizeof(char) + sizeof("[100]")) +1);
        char * constlist = malloc(size * (109*sizeof(char) + sizeof("=;\n") + 100 *sizeof(char) + sizeof("[100]") + sizeof("const ")) +1);
        char * temp = malloc (size * (109*sizeof(char) + sizeof("=;\n") + 100 *sizeof(char) + sizeof("[100]") + sizeof("const ")) +1);
        strcpy(varlist,"");
        strcpy(constlist,"");
        strcpy(final, "");
        char * variable;
        Node * node;
        while(!isEmptyListT(queue)){
                strcpy(temp, "");
                node = getElementT(queue);
                if ((*node).isConstant) {
                        strcat(temp, "const ");
                }
                switch ((*node).type){
                        case 0: strcat(temp, "int ");break;
                        case 1: strcat(temp, "double ");break;
                        case 2: strcat(temp, "char ");break;
                        case 3: strcat(temp, "char ");break;
                        default: break;
                }
                strcat(temp, (*node).name);
                if ((*node).type == 2) {
                        strcat(temp, "[");
                        strcat(temp, sizeS);
                        strcat(temp, "]");
                }
                if ((*node).isValue) {
                        strcat(temp, "=");
                        if( (*node).type == 3) {
                                deleteQuotes((*node).value);
                                strcat(temp, "\'");
                                strcat(temp, (*node).value);
                                strcat(temp, "\'");
                        }
                        else {
                                strcat(temp, (*node).value);
                        }
                }
                strcat(temp,";\n");
                if ((*node).isConstant) {
                        strcat(constlist, temp);
                }else{
                        strcat(varlist, temp);
                }
                free(node);
                DeleteElementT(queue);
        }
        strcat(final, constlist);
        strcat(final, varlist);
        free(varlist);
        free(constlist);
        free(temp);
        return final;
}

/*0=int, 1=double, 2=string, 3=char*/
char * getRef (int type){
        char * ref = malloc (sizeof("%lf") + 1);
        switch (type){
                case 0: strcpy(ref, "%d");break;
                case 1: strcpy(ref, "%lf");break;
                case 2: strcpy(ref, "%s");break;
                case 3: strcpy(ref, "%c");break; 
                default: break;
        }
        return ref;
}

int isNumber(char * stringq) {
        for (int i = 0; stringq[i]!='\0';i++){
                if(isdigit(stringq[i]) == 0){
                        return 0;
                }
        }
        return 1;
}

int main(int argc, char *argv[]){
        FILE *fp = fopen(outputName, "w");
        if(fp!=NULL){
                        
                        fputs("", fp);
                        fclose(fp);
                }

        extern FILE *yyin;
        InitializeListT(&typelist);
        InitializeListN(&queue);
	
	switch (argc) {
		case 1:	printf("Syntax : ./traductorP <archivoPascal> [-s size_string]\n");
			exit(-1);
                        break;
		case 2: yyin = fopen(argv[1], "r");
			if (yyin == NULL) {
				printf("ERROR: No se ha podido abrir el fichero.\n");
			}
			else {
				yyparse();
				fclose(yyin);
			}
                        break;
                case 4 : if((strcmp(argv[2], "-s") != 0) || (isNumber(argv[3])==0)) {
                                printf("Syntax : ./traductorP <archivoPascal> [-s size_string]\n");
			        exit(-1);
                        }
                        else {
                                strcpy(sizeS, argv[3]);
                                yyin = fopen(argv[1], "r");
			        if (yyin == NULL) {
				        printf("ERROR: No se ha podido abrir el fichero.\n");
			        }
			        else {
				        yyparse();
				        fclose(yyin);
			        }
                        }
                        break;
		default: printf("ERROR: Demasiados argumentos.\nSyntax : ./traductorP <archivoPascal> [-s size_string]\n\n");
	}
        //ShowListT(&typelist);
	return 0;
}
