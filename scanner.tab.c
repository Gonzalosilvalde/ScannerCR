/* A Bison parser, made by GNU Bison 3.8.  */

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
#define YYBISON 30800

/* Bison version string.  */
#define YYBISON_VERSION "3.8"

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
TypeList flist;
//queue será la cola a través de la cual recogeremos y volcaremos las variables de los printf 
NodeList queue;
char printV[100]= "";

void yyerror(char const *);
char * getVariables(TypeList *);
char * getEndings(NodeList *);
char * getEndingsR(NodeList *);
char * getRef (int);
void deleteQuotes (char *);
void deleteCurly(char *);
void deleteNewLines(char *);
char* getEndNumber(char* number);


#line 105 "scanner.tab.c"

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
  YYSYMBOL_LISTCONTENT = 36,               /* LISTCONTENT  */
  YYSYMBOL_VALUE = 37,                     /* VALUE  */
  YYSYMBOL_LPAREN = 38,                    /* LPAREN  */
  YYSYMBOL_STRINGQUOTE = 39,               /* STRINGQUOTE  */
  YYSYMBOL_RPAREN = 40,                    /* RPAREN  */
  YYSYMBOL_RSQUAREPAREN = 41,              /* RSQUAREPAREN  */
  YYSYMBOL_LSQUAREPAREN = 42,              /* LSQUAREPAREN  */
  YYSYMBOL_COLON = 43,                     /* COLON  */
  YYSYMBOL_SEMICOLON = 44,                 /* SEMICOLON  */
  YYSYMBOL_INTEGER = 45,                   /* INTEGER  */
  YYSYMBOL_SHORT = 46,                     /* SHORT  */
  YYSYMBOL_LONG = 47,                      /* LONG  */
  YYSYMBOL_UNSIGNED_INT = 48,              /* UNSIGNED_INT  */
  YYSYMBOL_UNSIGNED_SHORT = 49,            /* UNSIGNED_SHORT  */
  YYSYMBOL_UNSIGNED_LONG = 50,             /* UNSIGNED_LONG  */
  YYSYMBOL_FLOAT = 51,                     /* FLOAT  */
  YYSYMBOL_DOUBLE = 52,                    /* DOUBLE  */
  YYSYMBOL_OPENCURLYBRACKET = 53,          /* OPENCURLYBRACKET  */
  YYSYMBOL_CLOSECURLYBRACKET = 54,         /* CLOSECURLYBRACKET  */
  YYSYMBOL_BOOLEAN = 55,                   /* BOOLEAN  */
  YYSYMBOL_CHAR = 56,                      /* CHAR  */
  YYSYMBOL_STRING = 57,                    /* STRING  */
  YYSYMBOL_STRINGV = 58,                   /* STRINGV  */
  YYSYMBOL_QUOTESTRING = 59,               /* QUOTESTRING  */
  YYSYMBOL_TRUEVAL = 60,                   /* TRUEVAL  */
  YYSYMBOL_FALSEVAL = 61,                  /* FALSEVAL  */
  YYSYMBOL_INTNUM = 62,                    /* INTNUM  */
  YYSYMBOL_REALNUM = 63,                   /* REALNUM  */
  YYSYMBOL_RETURN = 64,                    /* RETURN  */
  YYSYMBOL_EX = 65,                        /* EX  */
  YYSYMBOL_YYACCEPT = 66,                  /* $accept  */
  YYSYMBOL_S = 67,                         /* S  */
  YYSYMBOL_comment = 68,                   /* comment  */
  YYSYMBOL_subcabecera = 69,               /* subcabecera  */
  YYSYMBOL_cabecera = 70,                  /* cabecera  */
  YYSYMBOL_constdef = 71,                  /* constdef  */
  YYSYMBOL_fvardef = 72,                   /* fvardef  */
  YYSYMBOL_vardef = 73,                    /* vardef  */
  YYSYMBOL_type = 74,                      /* type  */
  YYSYMBOL_values = 75,                    /* values  */
  YYSYMBOL_preprograma = 76,               /* preprograma  */
  YYSYMBOL_programa = 77,                  /* programa  */
  YYSYMBOL_args = 78,                      /* args  */
  YYSYMBOL_lines_program = 79,             /* lines_program  */
  YYSYMBOL_line_program = 80,              /* line_program  */
  YYSYMBOL_array = 81,                     /* array  */
  YYSYMBOL_precontentWrite = 82,           /* precontentWrite  */
  YYSYMBOL_contentWrite = 83,              /* contentWrite  */
  YYSYMBOL_assignation = 84,               /* assignation  */
  YYSYMBOL_exp = 85,                       /* exp  */
  YYSYMBOL_term = 86,                      /* term  */
  YYSYMBOL_operand = 87,                   /* operand  */
  YYSYMBOL_atom = 88                       /* atom  */
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
#define YYLAST   681

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  66
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  95
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  211

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   320


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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   130,   130,   140,   151,   163,   177,   180,   186,   187,
     190,   191,   195,   206,   221,   248,   275,   302,   336,   363,
     390,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   437,   440,   441,   442,   443,   447,   455,   464,
     525,   616,   625,   632,   673,   711,   723,   734,   739,   743,
     756,   768,   777,   797,   820,   835,   848,   849,   858,   866,
     878,   888,   893,   959,  1022,  1040,  1052,  1070,  1083,  1086,
    1091,  1102,  1152,  1165,  1172,  1174,  1183,  1192,  1204,  1207,
    1208,  1209,  1210,  1211,  1212,  1213,  1214,  1215,  1216,  1217,
    1218,  1219,  1220,  1221,  1226,  1234
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
  "COMMENTLINE", "MULTILINE", "VAR", "CONST", "DEFINE", "LISTCONTENT",
  "VALUE", "LPAREN", "STRINGQUOTE", "RPAREN", "RSQUAREPAREN",
  "LSQUAREPAREN", "COLON", "SEMICOLON", "INTEGER", "SHORT", "LONG",
  "UNSIGNED_INT", "UNSIGNED_SHORT", "UNSIGNED_LONG", "FLOAT", "DOUBLE",
  "OPENCURLYBRACKET", "CLOSECURLYBRACKET", "BOOLEAN", "CHAR", "STRING",
  "STRINGV", "QUOTESTRING", "TRUEVAL", "FALSEVAL", "INTNUM", "REALNUM",
  "RETURN", "EX", "$accept", "S", "comment", "subcabecera", "cabecera",
  "constdef", "fvardef", "vardef", "type", "values", "preprograma",
  "programa", "args", "lines_program", "line_program", "array",
  "precontentWrite", "contentWrite", "assignation", "exp", "term",
  "operand", "atom", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-81)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      12,   -17,    29,   -21,     7,   -81,   -81,   -81,   -81,   -19,
      18,   128,    37,   -81,   -81,   128,   610,    19,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   185,
     185,   185,    24,   185,   -81,   -81,   185,   185,    25,    46,
     185,   -81,   -81,   -12,   -81,   185,    57,   -81,   -81,   -81,
     -81,   -81,    45,   129,   522,   -81,    46,   -81,    52,    53,
      60,    43,    75,    72,   -81,   -81,   549,    92,    68,   -81,
      84,    85,    74,   108,    91,     4,   651,   -11,   -81,   -81,
      88,    87,   -81,   -81,   610,   549,   -11,   610,   549,   127,
     -11,   110,   549,   -81,   -81,   120,   122,     1,   126,   -81,
     -81,   -81,   -81,   -11,   117,   186,   -11,   -81,   -11,   -81,
     596,   -81,   -81,     0,     3,   -81,   -81,   150,   267,   106,
     207,    10,   324,   -11,   112,   -81,   -81,   -81,   -81,   -81,
     609,   -81,   -81,   381,   -81,   -81,   -81,   -11,   215,   107,
     -81,   -81,     3,   115,   140,   168,   -81,   -81,   142,    42,
     119,   438,   -81,   -81,   -81,   -81,   149,   159,   153,   -81,
     549,   147,   175,   -81,   196,    13,   549,   164,   -81,   -81,
     188,   264,   177,   -11,    -3,   -81,   -81,   321,   549,   170,
     -81,   -11,   495,   -81,   -81,   -81,   -81,   378,    46,   624,
     181,   -81,   198,   173,   171,   -81,    46,   184,   651,   203,
     -81,   -81,   210,   213,   217,   549,   549,   435,   492,   -81,
     -81
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,    11,     1,     6,     7,     0,
       0,     0,     0,     8,     9,     0,     0,     0,    21,    22,
      23,    24,    25,    26,    27,    28,    31,    30,    29,     0,
       0,     0,     0,     2,    38,    10,     0,     3,     0,     0,
       4,    42,    41,     0,    37,     5,     0,    36,    32,    33,
      34,    35,     0,     0,     0,    18,     0,    12,     0,     0,
       0,     0,     0,     0,    20,    19,     0,    44,     0,    13,
       0,     0,     0,     0,     0,     0,     0,     0,    56,    59,
       0,     0,    46,    48,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    91,    93,    86,    87,    78,    80,    82,
      83,    84,    85,    90,     0,     0,     0,    94,     0,    95,
       0,    73,    74,     0,     0,    45,    43,     0,     0,     0,
       0,     0,     0,     0,     0,    88,    89,    92,    79,    81,
      71,    57,    76,     0,    77,    90,    58,     0,     0,     0,
      14,    40,     0,     0,     0,     0,    69,    68,     0,    62,
       0,     0,    51,    70,    75,    72,     0,     0,     0,    39,
       0,     0,     0,    47,     0,     0,     0,     0,    16,    15,
       0,     0,     0,     0,     0,    67,    66,     0,     0,     0,
      55,     0,     0,    63,    65,    64,    49,     0,     0,     0,
       0,    50,    61,     0,     0,    54,     0,     0,     0,     0,
      60,    17,     0,     0,     0,     0,     0,     0,     0,    53,
      52
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -81,   -81,    -2,    64,   -81,   -81,   -81,   -81,    30,   -39,
      -8,    48,   167,   -80,   -77,    86,   -81,   -81,    66,   -70,
     143,   -74,   178
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,    78,    11,     3,    30,    79,    31,    80,   109,
      33,    34,    62,    81,    82,   193,   148,   149,    83,   110,
     111,   137,   112
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      52,    10,   104,     4,   115,   117,   183,    37,   120,    29,
       7,     8,   105,    36,    59,   124,   118,    63,    53,    91,
     122,    40,     5,   127,     1,    13,    54,   106,    45,     6,
     138,   128,    55,   130,     7,     8,   133,     9,   134,     9,
     115,    32,   139,   115,   140,    32,    38,   107,    47,    48,
      49,    50,    51,   151,   108,   184,   185,    92,    35,    32,
      32,    32,   164,    32,   165,    12,    32,    32,   146,   147,
      32,   175,   176,    14,    15,    32,     9,    39,    41,    42,
     171,    44,    43,    46,    61,    44,   177,    56,    44,    57,
      70,    71,    72,    44,   115,    73,    64,    65,   187,   157,
     115,    67,    74,   182,    75,    47,    48,    49,    50,    51,
     115,   189,   141,    66,    61,    68,    69,   119,     7,     8,
      84,    85,    86,    87,   202,   207,   208,    88,    89,    90,
     115,   115,    18,    19,    20,    21,    22,    23,    24,    25,
     159,   114,    26,    27,    28,    76,   113,   121,   123,   192,
     125,    77,   126,    70,    71,    72,   129,   192,    73,     7,
       8,   131,    16,    17,   144,    74,   152,    75,   160,   158,
     161,   162,   166,    18,    19,    20,    21,    22,    23,    24,
      25,     7,     8,    26,    27,    28,   163,    58,    47,    48,
      49,    50,    51,   168,   170,    18,    19,    20,    21,    22,
      23,    24,    25,   169,   142,    26,    27,    28,    76,   172,
      70,    71,    72,   173,    77,    73,   174,   178,   179,    16,
      17,   181,    74,   188,    75,   195,   196,   197,   201,   198,
      18,    19,    20,    21,    22,    23,    24,    25,     7,     8,
      26,    27,    28,   203,   107,    47,    48,    49,    50,    51,
     204,   116,    18,    19,    20,    21,    22,    23,    24,    25,
     199,   145,    26,    27,    28,    76,   205,    70,    71,    72,
     206,    77,    73,   156,    47,    48,    49,    50,    51,    74,
     155,    75,   200,   132,     0,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,     7,     8,   135,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   143,     0,    18,
      19,    20,    21,    22,    23,    24,    25,     0,   180,    26,
      27,    28,    76,     0,    70,    71,    72,     0,    77,    73,
       0,     0,     0,     0,     0,     0,    74,     0,    75,     0,
       0,     0,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,     7,     8,   135,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   150,     0,    18,    19,    20,    21,
      22,    23,    24,    25,     0,   186,    26,    27,    28,    76,
       0,    70,    71,    72,     0,    77,    73,     0,     0,     0,
       0,     0,     0,    74,     0,    75,     0,     0,     0,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,     7,
       8,   135,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   154,     0,    18,    19,    20,    21,    22,    23,    24,
      25,     0,   191,    26,    27,    28,    76,     0,    70,    71,
      72,     0,    77,    73,     0,     0,     0,     0,     0,     0,
      74,     0,    75,     0,     0,     0,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,     7,     8,   135,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   167,     0,
      18,    19,    20,    21,    22,    23,    24,    25,     0,   209,
      26,    27,    28,    76,     0,    70,    71,    72,     0,    77,
      73,     0,     0,     0,     0,     0,     0,    74,     0,    75,
       0,     0,     0,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,     7,     8,   135,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   190,     0,    18,    19,    20,
      21,    22,    23,    24,    25,     0,   210,    26,    27,    28,
      76,     0,    70,    71,    72,     0,    77,    73,     0,     0,
       0,     0,    60,     0,    74,     0,    75,    18,    19,    20,
      21,    22,    23,    24,    25,     0,     0,    26,    27,    28,
       7,     8,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    18,    19,    20,    21,    22,    23,
      24,    25,     0,     0,    26,    27,    28,    76,     0,     0,
       0,     0,     0,    77,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,     0,     0,   135,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,     0,     0,   135,
     136,     0,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,     0,   153,   135,    18,    19,    20,    21,    22,
      23,    24,    25,     0,     0,    26,    27,    28,   194,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,     0,
       0,   103
};

static const yytype_int16 yycheck[] =
{
      39,     3,    76,    20,    81,    85,     9,    15,    88,    11,
      31,    32,    23,    15,    53,    92,    86,    56,    30,    15,
      90,    29,    39,    22,    12,    44,    38,    38,    36,     0,
      30,    30,    44,   103,    31,    32,   106,    58,   108,    58,
     117,    11,    42,   120,    44,    15,    16,    58,    59,    60,
      61,    62,    63,   123,    65,    58,    59,    53,    21,    29,
      30,    31,    20,    33,    22,    58,    36,    37,    58,    59,
      40,    58,    59,     9,    10,    45,    58,    58,    30,    31,
     160,    33,    58,    58,    54,    37,   166,    30,    40,    44,
       3,     4,     5,    45,   171,     8,    44,    44,   178,   138,
     177,    58,    15,   173,    17,    59,    60,    61,    62,    63,
     187,   181,   114,    53,    84,    40,    44,    87,    31,    32,
      28,    53,    38,    38,   198,   205,   206,    53,    20,    38,
     207,   208,    45,    46,    47,    48,    49,    50,    51,    52,
     142,    54,    55,    56,    57,    58,    58,    20,    38,   188,
      30,    64,    30,     3,     4,     5,    30,   196,     8,    31,
      32,    44,    34,    35,    58,    15,    54,    17,    53,    62,
      30,     3,    53,    45,    46,    47,    48,    49,    50,    51,
      52,    31,    32,    55,    56,    57,    44,    58,    59,    60,
      61,    62,    63,    44,    41,    45,    46,    47,    48,    49,
      50,    51,    52,    44,    54,    55,    56,    57,    58,    62,
       3,     4,     5,    38,    64,     8,    20,    53,    30,    34,
      35,    44,    15,    53,    17,    44,    28,    54,    44,    58,
      45,    46,    47,    48,    49,    50,    51,    52,    31,    32,
      55,    56,    57,    40,    58,    59,    60,    61,    62,    63,
      40,    84,    45,    46,    47,    48,    49,    50,    51,    52,
     194,    54,    55,    56,    57,    58,    53,     3,     4,     5,
      53,    64,     8,    58,    59,    60,    61,    62,    63,    15,
     137,    17,   196,   105,    -1,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    31,    32,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,    45,
      46,    47,    48,    49,    50,    51,    52,    -1,    54,    55,
      56,    57,    58,    -1,     3,     4,     5,    -1,    64,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,    17,    -1,
      -1,    -1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    31,    32,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    40,    -1,    45,    46,    47,    48,
      49,    50,    51,    52,    -1,    54,    55,    56,    57,    58,
      -1,     3,     4,     5,    -1,    64,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    -1,    17,    -1,    -1,    -1,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    31,
      32,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    -1,    45,    46,    47,    48,    49,    50,    51,
      52,    -1,    54,    55,    56,    57,    58,    -1,     3,     4,
       5,    -1,    64,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    -1,    17,    -1,    -1,    -1,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    31,    32,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,
      45,    46,    47,    48,    49,    50,    51,    52,    -1,    54,
      55,    56,    57,    58,    -1,     3,     4,     5,    -1,    64,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,    17,
      -1,    -1,    -1,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    31,    32,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    40,    -1,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    54,    55,    56,    57,
      58,    -1,     3,     4,     5,    -1,    64,     8,    -1,    -1,
      -1,    -1,    40,    -1,    15,    -1,    17,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    -1,    55,    56,    57,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    47,    48,    49,    50,
      51,    52,    -1,    -1,    55,    56,    57,    58,    -1,    -1,
      -1,    -1,    -1,    64,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    -1,    -1,    30,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    -1,    -1,    30,
      44,    -1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    44,    30,    45,    46,    47,    48,    49,
      50,    51,    52,    -1,    -1,    55,    56,    57,    44,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    -1,
      -1,    30
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    12,    67,    70,    20,    39,     0,    31,    32,    58,
      68,    69,    58,    44,    69,    69,    34,    35,    45,    46,
      47,    48,    49,    50,    51,    52,    55,    56,    57,    68,
      71,    73,    74,    76,    77,    21,    68,    76,    74,    58,
      76,    77,    77,    58,    77,    76,    58,    59,    60,    61,
      62,    63,    75,    30,    38,    44,    30,    44,    58,    75,
      40,    74,    78,    75,    44,    44,    53,    58,    40,    44,
       3,     4,     5,     8,    15,    17,    58,    64,    68,    72,
      74,    79,    80,    84,    28,    53,    38,    38,    53,    20,
      38,    15,    53,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    30,    87,    23,    38,    58,    65,    75,
      85,    86,    88,    58,    54,    80,    78,    79,    85,    74,
      79,    20,    85,    38,    80,    30,    30,    22,    30,    30,
      85,    44,    88,    85,    85,    30,    44,    87,    30,    42,
      44,    68,    54,    40,    58,    54,    58,    59,    82,    83,
      40,    85,    54,    44,    40,    86,    58,    75,    62,    68,
      53,    30,     3,    44,    20,    22,    53,    40,    44,    44,
      41,    79,    62,    38,    20,    58,    59,    79,    53,    30,
      54,    44,    85,     9,    58,    59,    54,    79,    53,    85,
      40,    54,    75,    81,    44,    44,    28,    54,    58,    84,
      81,    44,    87,    40,    40,    53,    53,    79,    79,    54,
      54
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    66,    67,    67,    67,    67,    68,    68,    69,    69,
      70,    70,    71,    71,    72,    72,    72,    72,    73,    73,
      73,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    75,    75,    75,    75,    75,    76,    76,    77,
      77,    77,    77,    78,    78,    79,    79,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      81,    81,    82,    82,    83,    83,    83,    83,    83,    83,
      84,    84,    85,    85,    86,    86,    86,    86,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    88,    88
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     4,     4,     5,     1,     1,     2,     2,
       4,     2,     4,     6,     3,     5,     5,    10,     3,     5,
       5,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     9,
       8,     2,     2,     4,     2,     2,     1,     5,     1,     7,
       8,     4,    15,    14,     9,     7,     1,     3,     3,     1,
       3,     1,     1,     4,     4,     4,     3,     3,     1,     1,
       4,     3,     3,     1,     1,     3,     2,     2,     1,     2,
       1,     2,     1,     1,     1,     1,     1,     1,     2,     2,
       1,     1,     2,     1,     1,     1
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
  case 2: /* S: cabecera subcabecera preprograma  */
#line 130 "scanner.y"
                                         { 
                
                FILE *fp = fopen(outputName, "w");
                
                if (fp!=NULL) {
                fputs((yyvsp[0].valString), fp);
                    fclose(fp);  
                }
                
        }
#line 1695 "scanner.tab.c"
    break;

  case 3: /* S: cabecera comment subcabecera preprograma  */
#line 140 "scanner.y"
                                                  { 
                
                //printf("%s\n", $4);
                FILE *fp = fopen(outputName, "w");
				//char * variables = getVariables(&typelist);
                
                if (fp!=NULL) {
                    fputs((yyvsp[0].valString), fp);
                    fclose(fp);  
                }
        }
#line 1711 "scanner.tab.c"
    break;

  case 4: /* S: cabecera subcabecera comment preprograma  */
#line 151 "scanner.y"
                                                  { 
                
                //printf("%s\n", $4);//por alguna razon devuelve de la segunda linea, el tercer valor, pasa lo mismo con subcabecera, en cambio en cabecera no pasa eso
                
                FILE *fp = fopen(outputName, "w");
		//char * variables = getVariables(&typelist);
                
                if (fp!=NULL) {
                    fputs((yyvsp[0].valString), fp);
                    fclose(fp);  
                }
        }
#line 1728 "scanner.tab.c"
    break;

  case 5: /* S: cabecera comment subcabecera comment preprograma  */
#line 163 "scanner.y"
                                                          { 
                
               FILE *fp = fopen(outputName, "w");
		//char * variables = getVariables(&typelist);
                
                if (fp!=NULL) {
                    fputs((yyvsp[-1].valString), fp);
                    fclose(fp);  
                }
        }
#line 1743 "scanner.tab.c"
    break;

  case 6: /* comment: COMMENTLINE  */
#line 177 "scanner.y"
                     {
                (yyval.valString) = (yyvsp[0].valString);
                }
#line 1751 "scanner.tab.c"
    break;

  case 7: /* comment: MULTILINE  */
#line 180 "scanner.y"
                    {;}
#line 1757 "scanner.tab.c"
    break;

  case 8: /* subcabecera: STRINGV SEMICOLON  */
#line 186 "scanner.y"
                          {(yyval.valString) = "";}
#line 1763 "scanner.tab.c"
    break;

  case 9: /* subcabecera: STRINGV subcabecera  */
#line 187 "scanner.y"
                             {;}
#line 1769 "scanner.tab.c"
    break;

  case 10: /* cabecera: PROGRAM LOWER STRINGV HIGHER  */
#line 190 "scanner.y"
                                        {(yyval.valString) = "";}
#line 1775 "scanner.tab.c"
    break;

  case 11: /* cabecera: PROGRAM STRINGQUOTE  */
#line 191 "scanner.y"
                                       {;}
#line 1781 "scanner.tab.c"
    break;

  case 12: /* constdef: DEFINE STRINGV values SEMICOLON  */
#line 195 "scanner.y"
                                        {
                /*Node node;
                strcpy(node.name, $2);
                node.isConstant = 1;
                node.isValue = 1;
                node.type = 0;
                strcpy(node.value, $3);
                InsertElementT(&typelist, &node);
                free($2);
                free($3);
                */}
#line 1797 "scanner.tab.c"
    break;

  case 13: /* constdef: CONST type STRINGV EQ values SEMICOLON  */
#line 206 "scanner.y"
                                                {
                /*Node node;
                strcpy(node.name, $3);
                node.isConstant = 1;
                node.isValue = 1;
                node.type = $2;
                strcpy(node.value, $5);
                InsertElementT(&typelist, &node);
                free($3);
                free($5);
               */ }
#line 1813 "scanner.tab.c"
    break;

  case 14: /* fvardef: type STRINGV SEMICOLON  */
#line 221 "scanner.y"
                               {
                char * tipo;
                switch ((yyvsp[-2].valInt)){
                        case 0: tipo  = "i32 ";break;
                        case 1: tipo = "i16 ";break;
                        case 2: tipo = "i64 ";break;
                        case 3: tipo = "u32 ";break;
                        case 4: tipo = "u16 ";break;
                        case 5: tipo = "u64 ";break;
                        case 6: tipo = "f32 ";break;
                        case 7: tipo = "f64 ";break;
                        case 8: tipo = "String ";break;
                        case 9: tipo = "char ";break;
                        case 10: tipo = "bool ";break;
                        default: break;
                }
                char * final = malloc(strlen(tipo)*sizeof(char) + strlen((yyvsp[-1].valString))*sizeof(char) + strlen("let \n : ;"));
                memset(final,0,sizeof(final));
                strcat(final,"let ");
                strcat(final,(yyvsp[-1].valString));
                strcat(final,":");
                strcat(final,tipo);
                strcat(final,";\n");

                (yyval.valString) = final;

        }
#line 1845 "scanner.tab.c"
    break;

  case 15: /* fvardef: type STRINGV EQ values SEMICOLON  */
#line 248 "scanner.y"
                                           {
                char * tipo;
                switch ((yyvsp[-4].valInt)){
                        case 0: tipo  = "i32 ";break;
                        case 1: tipo = "i16 ";break;
                        case 2: tipo = "i64 ";break;
                        case 3: tipo = "u32 ";break;
                        case 4: tipo = "u16 ";break;
                        case 5: tipo = "u64 ";break;
                        case 6: tipo = "f32 ";break;
                        case 7: tipo = "f64 ";break;
                        case 8: tipo = "String ";break;
                        case 9: tipo = "char ";break;
                        case 10: tipo = "bool ";break;
                        default: break;
                }
                char * final = malloc(strlen(tipo)*sizeof(char) + strlen((yyvsp[-1].valString))*sizeof(char) + strlen((yyvsp[-3].valString))*sizeof(char) + strlen("= let \n : ;"));
                memset(final,0,sizeof(final));
                strcat(final,"let ");
                strcat(final,(yyvsp[-3].valString));
                strcat(final,":");
                strcat(final,tipo);
                strcat(final,"=");
                strcat(final,(yyvsp[-1].valString));
                strcat(final,";\n");
                (yyval.valString) = final;
        }
#line 1877 "scanner.tab.c"
    break;

  case 16: /* fvardef: type STRINGV EQ STRINGV SEMICOLON  */
#line 275 "scanner.y"
                                            {
                char * tipo;
                switch ((yyvsp[-4].valInt)){
                        case 0: tipo  = "i32 ";break;
                        case 1: tipo = "i16 ";break;
                        case 2: tipo = "i64 ";break;
                        case 3: tipo = "u32 ";break;
                        case 4: tipo = "u16 ";break;
                        case 5: tipo = "u64 ";break;
                        case 6: tipo = "f32 ";break;
                        case 7: tipo = "f64 ";break;
                        case 8: tipo = "String ";break;
                        case 9: tipo = "char ";break;
                        case 10: tipo = "bool ";break;
                        default: break;
                }
                char * final = malloc(strlen(tipo)*sizeof(char) + strlen((yyvsp[-1].valString))*sizeof(char) + strlen((yyvsp[-3].valString))*sizeof(char) + strlen("= let \n : ;"));
                memset(final,0,sizeof(final));
                strcat(final,"let ");
                strcat(final,(yyvsp[-3].valString));
                strcat(final,":");
                strcat(final,tipo);
                strcat(final,"=");
                strcat(final,(yyvsp[-1].valString));
                strcat(final,";\n");
                (yyval.valString) = final;
        }
#line 1909 "scanner.tab.c"
    break;

  case 17: /* fvardef: type STRINGV LSQUAREPAREN INTNUM RSQUAREPAREN EQ OPENCURLYBRACKET array CLOSECURLYBRACKET SEMICOLON  */
#line 302 "scanner.y"
                                                                                                             {
                char * tipo;
                switch ((yyvsp[-9].valInt)){
                        case 0: tipo  = "i32 ";break;
                        case 1: tipo = "i16 ";break;
                        case 2: tipo = "i64 ";break;
                        case 3: tipo = "u32 ";break;
                        case 4: tipo = "u16 ";break;
                        case 5: tipo = "u64 ";break;
                        case 6: tipo = "f32 ";break;
                        case 7: tipo = "f64 ";break;
                        case 8: tipo = "String ";break;
                        case 9: tipo = "char ";break;
                        case 10: tipo = "bool ";break;
                        default: break;
                }
                char * final = malloc(strlen((yyvsp[-8].valString))*sizeof(char) + strlen(tipo)*sizeof(char)+ strlen((yyvsp[-6].valString))*sizeof(char) + strlen((yyvsp[-2].valString))*sizeof(char) + sizeof("[] [] ; \n"));
                memset(final,0,sizeof(final));
                strcat(final,"let ");
                strcat(final,(yyvsp[-8].valString));
                strcat(final,": [");
                strcat(final,tipo);
                strcat(final,":");
                strcat(final,(yyvsp[-6].valString));
                strcat(final,"] =");
                strcat(final,"[");
                strcat(final,(yyvsp[-2].valString));
                strcat(final,"];\n");
                (yyval.valString) = final;
        }
#line 1944 "scanner.tab.c"
    break;

  case 18: /* vardef: type STRINGV SEMICOLON  */
#line 336 "scanner.y"
                               {
                char * tipo;
                switch ((yyvsp[-2].valInt)){
                        case 0: tipo  = "i32 ";break;
                        case 1: tipo = "i16 ";break;
                        case 2: tipo = "i64 ";break;
                        case 3: tipo = "u32 ";break;
                        case 4: tipo = "u16 ";break;
                        case 5: tipo = "u64 ";break;
                        case 6: tipo = "f32 ";break;
                        case 7: tipo = "f64 ";break;
                        case 8: tipo = "String ";break;
                        case 9: tipo = "char ";break;
                        case 10: tipo = "bool ";break;
                        default: break;
                }
                char * final = malloc(strlen(tipo)*sizeof(char) + strlen((yyvsp[-1].valString))*sizeof(char) + strlen("let \n : ;"));
                memset(final,0,sizeof(final));
                strcat(final,"let ");
                strcat(final,(yyvsp[-1].valString));
                strcat(final,":");
                strcat(final,tipo);
                strcat(final,";\n");

                (yyval.valString) = final;

        }
#line 1976 "scanner.tab.c"
    break;

  case 19: /* vardef: type STRINGV EQ values SEMICOLON  */
#line 363 "scanner.y"
                                           {
                char * tipo;
                switch ((yyvsp[-4].valInt)){
                        case 0: tipo  = "i32 ";break;
                        case 1: tipo = "i16 ";break;
                        case 2: tipo = "i64 ";break;
                        case 3: tipo = "u32 ";break;
                        case 4: tipo = "u16 ";break;
                        case 5: tipo = "u64 ";break;
                        case 6: tipo = "f32 ";break;
                        case 7: tipo = "f64 ";break;
                        case 8: tipo = "String ";break;
                        case 9: tipo = "char ";break;
                        case 10: tipo = "bool ";break;
                        default: break;
                }
                char * final = malloc(strlen(tipo)*sizeof(char) + strlen((yyvsp[-1].valString))*sizeof(char) + strlen((yyvsp[-3].valString))*sizeof(char) + strlen("= let \n : ;"));
                memset(final,0,sizeof(final));
                strcat(final,"let ");
                strcat(final,(yyvsp[-3].valString));
                strcat(final,":");
                strcat(final,tipo);
                strcat(final,"=");
                strcat(final,(yyvsp[-1].valString));
                strcat(final,";\n");
                (yyval.valString) = final;
        }
#line 2008 "scanner.tab.c"
    break;

  case 20: /* vardef: type STRINGV EQ STRINGV SEMICOLON  */
#line 390 "scanner.y"
                                            {
                char * tipo;
                switch ((yyvsp[-4].valInt)){
                        case 0: tipo  = "i32 ";break;
                        case 1: tipo = "i16 ";break;
                        case 2: tipo = "i64 ";break;
                        case 3: tipo = "u32 ";break;
                        case 4: tipo = "u16 ";break;
                        case 5: tipo = "u64 ";break;
                        case 6: tipo = "f32 ";break;
                        case 7: tipo = "f64 ";break;
                        case 8: tipo = "String ";break;
                        case 9: tipo = "char ";break;
                        case 10: tipo = "bool ";break;
                        default: break;
                }
                char * final = malloc(strlen(tipo)*sizeof(char) + strlen((yyvsp[-1].valString))*sizeof(char) + strlen((yyvsp[-3].valString))*sizeof(char) + strlen("= let \n : ;"));
                memset(final,0,sizeof(final));
                strcat(final,"let ");
                strcat(final,(yyvsp[-3].valString));
                strcat(final,":");
                strcat(final,tipo);
                strcat(final,"=");
                strcat(final,(yyvsp[-1].valString));
                strcat(final,";\n");
                (yyval.valString) = final;
        }
#line 2040 "scanner.tab.c"
    break;

  case 21: /* type: INTEGER  */
#line 421 "scanner.y"
                {(yyval.valInt) = 0;}
#line 2046 "scanner.tab.c"
    break;

  case 22: /* type: SHORT  */
#line 422 "scanner.y"
                {(yyval.valInt) = 1;}
#line 2052 "scanner.tab.c"
    break;

  case 23: /* type: LONG  */
#line 423 "scanner.y"
               {(yyval.valInt) = 2;}
#line 2058 "scanner.tab.c"
    break;

  case 24: /* type: UNSIGNED_INT  */
#line 424 "scanner.y"
                       {(yyval.valInt) = 3;}
#line 2064 "scanner.tab.c"
    break;

  case 25: /* type: UNSIGNED_SHORT  */
#line 425 "scanner.y"
                         {(yyval.valInt) = 4;}
#line 2070 "scanner.tab.c"
    break;

  case 26: /* type: UNSIGNED_LONG  */
#line 426 "scanner.y"
                        {(yyval.valInt) = 5;}
#line 2076 "scanner.tab.c"
    break;

  case 27: /* type: FLOAT  */
#line 427 "scanner.y"
                {(yyval.valInt) = 6;}
#line 2082 "scanner.tab.c"
    break;

  case 28: /* type: DOUBLE  */
#line 428 "scanner.y"
                 {(yyval.valInt) = 7;}
#line 2088 "scanner.tab.c"
    break;

  case 29: /* type: STRING  */
#line 429 "scanner.y"
                 {(yyval.valInt) = 8;}
#line 2094 "scanner.tab.c"
    break;

  case 30: /* type: CHAR  */
#line 430 "scanner.y"
               {(yyval.valInt) = 9;}
#line 2100 "scanner.tab.c"
    break;

  case 31: /* type: BOOLEAN  */
#line 431 "scanner.y"
                  {(yyval.valInt) = 10;}
#line 2106 "scanner.tab.c"
    break;

  case 32: /* values: TRUEVAL  */
#line 437 "scanner.y"
                {
                (yyval.valString) = strdup("true");
        }
#line 2114 "scanner.tab.c"
    break;

  case 33: /* values: FALSEVAL  */
#line 440 "scanner.y"
                   {(yyval.valString) = (yyvsp[0].valString);}
#line 2120 "scanner.tab.c"
    break;

  case 34: /* values: INTNUM  */
#line 441 "scanner.y"
                 {(yyval.valString) = (yyvsp[0].valString);}
#line 2126 "scanner.tab.c"
    break;

  case 35: /* values: REALNUM  */
#line 442 "scanner.y"
                  {(yyval.valString) = (yyvsp[0].valString);}
#line 2132 "scanner.tab.c"
    break;

  case 36: /* values: QUOTESTRING  */
#line 443 "scanner.y"
                      {(yyval.valString) = (yyvsp[0].valString);}
#line 2138 "scanner.tab.c"
    break;

  case 37: /* preprograma: preprograma programa  */
#line 447 "scanner.y"
                            {
                char * final = malloc(strlen((yyvsp[-1].valString))*sizeof(char) + strlen((yyvsp[0].valString))*sizeof(char));
                memset(final,0,sizeof(final));
                strcat(final, (yyvsp[-1].valString));
                strcat(final, (yyvsp[0].valString));

                (yyval.valString) = final;
        }
#line 2151 "scanner.tab.c"
    break;

  case 38: /* preprograma: programa  */
#line 455 "scanner.y"
                 {
                char * final = malloc(strlen((yyvsp[0].valString))*sizeof(char));
                memset(final,0,sizeof(final));

                strcat(final, (yyvsp[0].valString));

                (yyval.valString) = final;
        }
#line 2164 "scanner.tab.c"
    break;

  case 39: /* programa: type STRINGV LPAREN args RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET comment  */
#line 464 "scanner.y"
                                                                                                {                        
                        
                        
                        char * final = malloc( strlen((yyvsp[-5].valString)) * sizeof(char) + strlen((yyvsp[-2].valString)) * sizeof(char)   + 20*sizeof(char) + sizeof("fn ->String {}"));
                        memset(final, 0, sizeof(final));
                        strcat(final, "fn ");
                        strcat(final, (yyvsp[-7].valString));
                        strcat(final, " (");
                        strcat(final,(yyvsp[-5].valString));
                        strcat(final,") ");
                        if((yyvsp[-8].valInt) == 0){
                                strcat(final, "-> i32 {");
                        } else if ((yyvsp[-8].valInt) == 1){
                                strcat(final, "-> i16 {");
                        }else if ((yyvsp[-8].valInt) == 2){
                                strcat(final, "-> i64 {");
                        }else if ((yyvsp[-8].valInt) == 3){
                                strcat(final, "-> u32 {");
                        }else if ((yyvsp[-8].valInt) == 4){
                                strcat(final, "-> u16 {");
                        }else if ((yyvsp[-8].valInt) == 5){
                                strcat(final, "-> u64 {");
                        }else if ((yyvsp[-8].valInt) == 6){
                                strcat(final, "-> f32 {");
                        }else if ((yyvsp[-8].valInt) == 7){
                                strcat(final, "-> f64 {");
                        }else if ((yyvsp[-8].valInt) == 8){
                                strcat(final, "-> String {");
                        }else if ((yyvsp[-8].valInt) == 9){
                                strcat(final, "-> char {");
                        }else if ((yyvsp[-8].valInt) == 10){
                                strcat(final, "-> bool {");
                        }else{
                                printf("otra cosa\n");
                        }
                        strcat(final, "\n");
                        strcat(final, (yyvsp[-2].valString));
                        strcat(final, "\n");
                        strcat(final, "}\n\n");
                        free((yyvsp[-2].valString));
                        free((yyvsp[-5].valString));
                        DeleteListT (&flist);
                        
                        (yyval.valString) = final;
                /*               
                }else{
                        char * variables = getVariables(&flist);
                        char * final = malloc( strlen($7) * sizeof(char)  + strlen(variables) * sizeof(char) + 20*sizeof(char));
                        memset(final, 0, sizeof(final));

                        strcat(final, variables);
                        strcat(final, "\n");
                        strcat(final, $7);
                        free($7);
                        free(variables);
                        DeleteListT(&flist);

                        $$ = final;
                }*/
        }
#line 2229 "scanner.tab.c"
    break;

  case 40: /* programa: type STRINGV LPAREN RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET comment  */
#line 525 "scanner.y"
                                                                                             {
                
                        
                char * final = malloc( strlen((yyvsp[-2].valString)) * sizeof(char)   + 20*sizeof(char) + sizeof(" -> i16")+ sizeof("fn "));
                memset(final, 0, sizeof(final));

                strcat(final, "fn () ");
                strcat(final, (yyvsp[-6].valString));
                if((yyvsp[-7].valInt) == 0){
                        strcat(final, "-> i32 {");
                } else if ((yyvsp[-7].valInt) == 1){
                        strcat(final, "-> i16 {");
                }else if ((yyvsp[-7].valInt) == 2){
                        strcat(final, "-> i64 {");
                }else if ((yyvsp[-7].valInt) == 3){
                        strcat(final, "-> u32 {");
                }else if ((yyvsp[-7].valInt) == 4){
                        strcat(final, "-> u16 {");
                }else if ((yyvsp[-7].valInt) == 5){
                        strcat(final, "-> u64 {");
                }else if ((yyvsp[-7].valInt) == 6){
                        strcat(final, "-> f32 {");
                }else if ((yyvsp[-7].valInt) == 7){
                        strcat(final, "-> f64 {");
                }else if ((yyvsp[-7].valInt) == 8){
                        strcat(final, "-> String {");
                }else if ((yyvsp[-7].valInt) == 9){
                        strcat(final, "-> char {");
                }else if ((yyvsp[-7].valInt) == 10){
                        strcat(final, "-> bool {");
                }else{
                        printf("otra cosa\n");
                }
                strcat(final, "\n");
                strcat(final, (yyvsp[-2].valString));
                strcat(final, "\n}\n\n");
                
                free((yyvsp[-2].valString));
                DeleteListT (&flist);

                (yyval.valString) = final;
                                
                
        }
#line 2278 "scanner.tab.c"
    break;

  case 41: /* programa: vardef programa  */
#line 616 "scanner.y"
                          {
                char * final = malloc(strlen((yyvsp[-1].valString))*sizeof(char) + strlen((yyvsp[0].valString))*sizeof(char) + sizeof("\n\n"));
                strcat(final,(yyvsp[-1].valString));
                strcat(final,"\n");
                strcat(final, (yyvsp[0].valString));
                strcat(final,"\n");
                
                (yyval.valString) = final;
        }
#line 2292 "scanner.tab.c"
    break;

  case 42: /* programa: constdef programa  */
#line 625 "scanner.y"
                            {
                
                (yyval.valString) = (yyvsp[0].valString);}
#line 2300 "scanner.tab.c"
    break;

  case 43: /* args: type STRINGV COMMA args  */
#line 632 "scanner.y"
                                {
                char * final;
                
                char * tipo;
                if((yyvsp[-3].valInt) == 0){
                        tipo = "i32";
                } else if ((yyvsp[-3].valInt) == 1){
                        tipo = "i16";
                }else if ((yyvsp[-3].valInt) == 2){
                        tipo = "i64";
                }else if ((yyvsp[-3].valInt) == 3){
                        tipo = "u32";
                }else if ((yyvsp[-3].valInt) == 4){
                        tipo = "u16";
                }else if ((yyvsp[-3].valInt) == 5){
                        tipo = "i64";
                }else if ((yyvsp[-3].valInt) == 6){
                        tipo = "f32";
                }else if ((yyvsp[-3].valInt) == 7){
                        tipo = "f64";
                }else if ((yyvsp[-3].valInt) == 8){
                        tipo = "String";
                }else if ((yyvsp[-3].valInt) == 9){
                        tipo = "char";
                }else if ((yyvsp[-3].valInt) == 10){
                        tipo = "bool";
                }else {
                        printf("pasa por aqui \n");
                }
                final = malloc(strlen(tipo)  + strlen((yyvsp[-2].valString)) * sizeof(char) + strlen((yyvsp[0].valString)) * sizeof(char) + sizeof(",  ") + 3*sizeof(char));
                memset(final, 0, sizeof(final));
                strcat(final, (yyvsp[0].valString));
                strcat(final, ",");
                strcat(final, " ");
                strcat(final, tipo);
                strcat(final, " ");
                strcat(final, (yyvsp[-2].valString));
                free((yyvsp[0].valString));
                (yyval.valString) = final;
                
                }
#line 2346 "scanner.tab.c"
    break;

  case 44: /* args: type STRINGV  */
#line 673 "scanner.y"
                      {
                char * final;
                char * tipo;
                if((yyvsp[-1].valInt) == 0){
                        tipo = "i32";
                } else if ((yyvsp[-1].valInt) == 1){
                        tipo = "i16";
                }else if ((yyvsp[-1].valInt) == 2){
                        tipo = "i64";
                }else if ((yyvsp[-1].valInt) == 3){
                        tipo = "u32";
                }else if ((yyvsp[-1].valInt) == 4){
                        tipo = "u16";
                }else if ((yyvsp[-1].valInt) == 5){
                        tipo = "i64";
                }else if ((yyvsp[-1].valInt) == 6){
                        tipo = "f32";
                }else if ((yyvsp[-1].valInt) == 7){
                        tipo = "f64";
                }else if ((yyvsp[-1].valInt) == 8){
                        tipo = "String";
                }else if ((yyvsp[-1].valInt) == 9){
                        tipo = "char";
                }else if ((yyvsp[-1].valInt) == 10){
                        tipo = "bool";
                }else {
                        printf("pasa por aqui \n");
                }
                final = malloc(strlen(tipo) * sizeof(char) + strlen((yyvsp[0].valString)) * sizeof(char) );
                memset(final, 0, sizeof(final));
                strcat(final, tipo);
                strcat(final, " ");
                strcat(final, (yyvsp[0].valString));
                (yyval.valString) = final;
        }
#line 2386 "scanner.tab.c"
    break;

  case 45: /* lines_program: lines_program line_program  */
#line 711 "scanner.y"
                                   {
                
                char * final = malloc(strlen((yyvsp[-1].valString)) * sizeof(char) + strlen((yyvsp[0].valString)) * sizeof(char) + sizeof("\n") + 3*sizeof(char));
                memset(final, 0, sizeof(final));

                strcpy(final, (yyvsp[-1].valString));
                strcat(final, "\n");
                strcat(final, (yyvsp[0].valString));
                free((yyvsp[-1].valString));
                free((yyvsp[0].valString));
                (yyval.valString) = final;
        }
#line 2403 "scanner.tab.c"
    break;

  case 46: /* lines_program: line_program  */
#line 723 "scanner.y"
                       {
                (yyval.valString) = (yyvsp[0].valString);
                
                }
#line 2412 "scanner.tab.c"
    break;

  case 47: /* line_program: WRITE LOWER LOWER precontentWrite SEMICOLON  */
#line 734 "scanner.y"
                                                    {
                
                (yyval.valString) = (yyvsp[-1].valString);
                
        }
#line 2422 "scanner.tab.c"
    break;

  case 48: /* line_program: assignation  */
#line 739 "scanner.y"
                      {
                (yyval.valString) = (yyvsp[0].valString);
        }
#line 2430 "scanner.tab.c"
    break;

  case 49: /* line_program: IF LPAREN exp RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET  */
#line 743 "scanner.y"
                                                                                 {
                char * final = malloc(strlen((yyvsp[-4].valString))* sizeof(char) + strlen((yyvsp[-1].valString))*sizeof(char) + sizeof("if ( ) { } \t \n \n"));
                memset(final, 0, sizeof(final));
                strcat(final, "if (");
                strcat(final, (yyvsp[-4].valString));
                strcat(final, "){\n\t");
                strcat(final, (yyvsp[-1].valString));
                strcat(final, "\n}");
                free((yyvsp[-4].valString));
                free((yyvsp[-1].valString));
                (yyval.valString) = final;

        }
#line 2448 "scanner.tab.c"
    break;

  case 50: /* line_program: ELSE IF LPAREN exp RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET  */
#line 756 "scanner.y"
                                                                                     {
                char * final = malloc(strlen((yyvsp[-4].valString))* sizeof(char) + strlen((yyvsp[-1].valString))*sizeof(char) + sizeof("else if ( ) { } \t \n \n"));
                memset(final, 0, sizeof(final));
                strcat(final, "else if (");
                strcat(final, (yyvsp[-4].valString));
                strcat(final, "){\n\t");
                strcat(final, (yyvsp[-1].valString));
                strcat(final, "\n}");
                free((yyvsp[-4].valString));
                free((yyvsp[-1].valString));
                (yyval.valString) = final;
        }
#line 2465 "scanner.tab.c"
    break;

  case 51: /* line_program: ELSE OPENCURLYBRACKET line_program CLOSECURLYBRACKET  */
#line 768 "scanner.y"
                                                               {
                char* final = malloc(strlen((yyvsp[-1].valString))*sizeof(char)+ sizeof("else {} \n \n \t"));
                memset(final, 0, sizeof(final));
                strcat(final, "else{\n\t");
                strcat(final, (yyvsp[-1].valString));
                strcat(final, "}\n");
                (yyval.valString) = final;
        
        }
#line 2479 "scanner.tab.c"
    break;

  case 52: /* line_program: FOR LPAREN type STRINGV EQ INTNUM SEMICOLON exp SEMICOLON STRINGV operand RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET  */
#line 777 "scanner.y"
                                                                                                                                            {
                char * final = malloc((yyvsp[-12].valInt)*sizeof(int) + strlen((yyvsp[-7].valString))*sizeof(char) +
                                sizeof("for ; ; {}")+strlen((yyvsp[-11].valString))*sizeof(char)+ strlen((yyvsp[-9].valString))*sizeof(char) + strlen((yyvsp[-5].valString))*sizeof(char) + 
                                strlen((yyvsp[-4].valString))*sizeof(char) + strlen((yyvsp[-1].valString))*sizeof(char));
                memset(final,0, strlen(final));

                char * numero = getEndNumber((yyvsp[-7].valString));

                strcat(final, "for ");
                strcat(final, (yyvsp[-11].valString));
                strcat(final, " in ");
                strcat(final, (yyvsp[-9].valString));
                strcat(final, "..");
                strcat(final, numero);
                strcat(final, "{\n\t");
                strcat(final, (yyvsp[-1].valString));
                strcat(final, "\n}");
                (yyval.valString)=final;
                ;}
#line 2503 "scanner.tab.c"
    break;

  case 53: /* line_program: FOR LPAREN type STRINGV EQ INTNUM SEMICOLON exp SEMICOLON assignation RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET  */
#line 797 "scanner.y"
                                                                                                                                         {
                char * final = malloc ((yyvsp[-11].valInt)*sizeof(int) + strlen((yyvsp[-10].valString))*sizeof(char) + strlen((yyvsp[-8].valString))*sizeof(char) + strlen((yyvsp[-6].valString))*sizeof(char)  +
                                        strlen((yyvsp[-4].valString))*sizeof(char) + strlen((yyvsp[-1].valString))*sizeof(char)+ sizeof("for ; ; {} .step_by( )"));
                memset(final,0, strlen(final));
                char * numero = getEndNumber((yyvsp[-6].valString));
                char * numero2 = getEndNumber((yyvsp[-4].valString));
                
                strcat(final, "for ");
                strcat(final, (yyvsp[-10].valString));
                strcat(final, " in ");
                strcat(final, (yyvsp[-8].valString));
                strcat(final, "..");
                strcat(final, numero);
                strcat(final, ".step_by(");
                strcat(final, numero2);
                strcat(final, ")");
                strcat(final, "{\n\t");
                strcat(final, (yyvsp[-1].valString));
                strcat(final, "\n}");
                (yyval.valString)=final;
        
        
        }
#line 2531 "scanner.tab.c"
    break;

  case 54: /* line_program: DO OPENCURLYBRACKET lines_program CLOSECURLYBRACKET WHILE LPAREN exp RPAREN SEMICOLON  */
#line 820 "scanner.y"
                                                                                               {
                char * final = malloc( strlen((yyvsp[-6].valString))*sizeof(char) + strlen((yyvsp[-2].valString))*sizeof(char) + sizeof("loop {} if() == {} break; \n") );
                memset(final, 0 , sizeof(final));

                strcat(final, "loop{\n");
                strcat(final, (yyvsp[-6].valString));
                strcat(final, "if(");
                strcat(final, (yyvsp[-2].valString));
                strcat(final, "){\n");
                strcat(final, "break;\n");
                strcat(final, "}\n}");

                (yyval.valString) = final;
        
        }
#line 2551 "scanner.tab.c"
    break;

  case 55: /* line_program: WHILE LPAREN exp RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET  */
#line 835 "scanner.y"
                                                                                  {
                char * final = malloc(strlen((yyvsp[-4].valString))*sizeof(char) + strlen((yyvsp[-1].valString))*sizeof(char) + sizeof("while () {} \n\n"));
                memset(final, 0, sizeof(final));

                strcat(final, "while(");
                strcat(final, (yyvsp[-4].valString));
                strcat(final, "){\n");
                strcat(final, (yyvsp[-1].valString));
                strcat(final, "\n}");
                (yyval.valString) = final;
                
        }
#line 2568 "scanner.tab.c"
    break;

  case 56: /* line_program: comment  */
#line 848 "scanner.y"
                 {;}
#line 2574 "scanner.tab.c"
    break;

  case 57: /* line_program: STRINGV operand SEMICOLON  */
#line 849 "scanner.y"
                                   {
                char * final = malloc (strlen((yyvsp[-1].valString))*sizeof(char) + strlen((yyvsp[-2].valString))*sizeof(char));
                memset(final, 0, sizeof(final));
                strcat(final, (yyvsp[-2].valString));
                strcat(final, (yyvsp[-1].valString));
                strcat(final, ";");

                (yyval.valString) = final;
        }
#line 2588 "scanner.tab.c"
    break;

  case 58: /* line_program: RETURN exp SEMICOLON  */
#line 858 "scanner.y"
                               {
                char * final = malloc(strlen((yyvsp[-1].valString))*sizeof(char) );
                memset(final, 0 , sizeof(final));
                
                strcat(final, (yyvsp[-1].valString));
                (yyval.valString)=final;
                
        }
#line 2601 "scanner.tab.c"
    break;

  case 59: /* line_program: fvardef  */
#line 866 "scanner.y"
                 {
                char * final = malloc(strlen((yyvsp[0].valString))*sizeof(char)  + sizeof("\n"));
                strcat(final,(yyvsp[0].valString));
                strcat(final,"\n");

                
                (yyval.valString) = final;
        }
#line 2614 "scanner.tab.c"
    break;

  case 60: /* array: values COMMA array  */
#line 878 "scanner.y"
                          {
                char * final = malloc(strlen((yyvsp[-2].valString))*sizeof(char) + strlen((yyvsp[0].valString))*sizeof(char)) ;
                memset(final,0,sizeof(final));

                strcat(final,(yyvsp[-2].valString));
                strcat(final,",");
                strcat(final,(yyvsp[0].valString));
                (yyval.valString) = final;

        }
#line 2629 "scanner.tab.c"
    break;

  case 61: /* array: values  */
#line 888 "scanner.y"
               {
                (yyval.valString) = (yyvsp[0].valString);
        }
#line 2637 "scanner.tab.c"
    break;

  case 62: /* precontentWrite: contentWrite  */
#line 893 "scanner.y"
                    {
                if(strlen(printV) ==0){
                        char * final = malloc(strlen((yyvsp[0].valString))*sizeof(char) + strlen(printV)*sizeof(char)+strlen("print!();") * sizeof(char) );
                        memset(final, 0, sizeof(final));
                        strcat(final, "print!(");
                        strcat(final,(yyvsp[0].valString));
                        strcat(final, ");");
                        (yyval.valString) = final;
                }else{
                        int longitud = strlen(printV);
                        char * final = malloc(strlen((yyvsp[0].valString))*sizeof(char) + strlen("{},,,")*sizeof(char) + longitud*sizeof(char)+strlen("print!(\"") * sizeof(char)+ strlen("\");")*sizeof(char));
                        memset(final, 0, sizeof(final));
                        
                        int contador = 0;
                         // Obtenemos la longitud de la cadena original
                        char* nueva_cadena =malloc(sizeof(char) * (longitud)); // Reservamos memoria para la nueva cadena
                        memset(nueva_cadena, 0, sizeof(nueva_cadena));


                        for (int i = longitud - 1; i >= 0; i--) {
                                if (printV[i] == ',') {
                                        // Reemplazar la última coma por el carácter nulo
                                        printV[i] = '\0';
                                        break;
                                }
                        }
                        strcpy(nueva_cadena, printV);
                        nueva_cadena[longitud*2-1] = '\0'; // Agregamos el terminador nulo al final de la nueva cadena

                        
                        for (int i = 0; (yyvsp[0].valString)[i] != '\0'; i++) {
                                if ((yyvsp[0].valString)[i] == '}') {
                                        contador++;
                                }
                        }
                        strcat(final, "print!(");
                        if(strlen(printV) == contador){
                                strcat(final, "\"");
                                strcat(final, (yyvsp[0].valString));
                                strcat(final, "\"");
                                strcat(final, ",");
                                strcat(final, nueva_cadena);
                                printf("%s\n", nueva_cadena);

                                
                        } else if (strlen(printV) > contador){
                                strcat(final, "\"");
                                strcat(final, (yyvsp[0].valString));
                                strcat(final, "{}");
                                strcat(final, "\"");
                                strcat(final, ",");
                                strcat(final, nueva_cadena);
                                
                        } else {
                                printf("tiene que haber algun error");
                        }
                        strcat(final, ");");
                        memset(printV, 0, sizeof(printV));
                        free((yyvsp[0].valString));
                        free(nueva_cadena);
                        (yyval.valString) = final;
                }



        }
#line 2708 "scanner.tab.c"
    break;

  case 63: /* precontentWrite: contentWrite LOWER LOWER ENDL  */
#line 959 "scanner.y"
                                      {
                if(strlen(printV) ==0){
                        char * final = malloc(strlen((yyvsp[-3].valString))*sizeof(char) + strlen(printV)*sizeof(char)+strlen("println!();") * sizeof(char) );
                        memset(final, 0, sizeof(final));
                        strcat(final, "println!(");
                        strcat(final,(yyvsp[-3].valString));
                        strcat(final, ");");
                        (yyval.valString) = final;
                }else{
                        char * final = malloc(strlen((yyvsp[-3].valString))*sizeof(char) + strlen("{},,,")*sizeof(char) + strlen(printV)*sizeof(char)+strlen("println!(\"") * sizeof(char)+ strlen("\");")*sizeof(char));
                        memset(final, 0, sizeof(final));
                        
                        int contador = 0;
                        int longitud = strlen(printV); // Obtenemos la longitud de la cadena original
                        char* nueva_cadena = (char*) malloc(sizeof(char) * (longitud * 2)); // Reservamos memoria para la nueva cadena
                        for (int i = longitud - 1; i >= 0; i--) {
                                if (printV[i] == ',') {
                                        // Reemplazar la última coma por el carácter nulo
                                        printV[i] = '\0';
                                        break;
                                }
                        }
                        strcpy(nueva_cadena, printV);

                        nueva_cadena[longitud*2-1] = '\0'; // Agregamos el terminador nulo al final de la nueva cadena

                        
                        for (int i = 0; (yyvsp[-3].valString)[i] != '\0'; i++) {
                                if ((yyvsp[-3].valString)[i] == '}') {
                                        contador++;
                                }
                        }
                        strcat(final, "print!(");
                        if(strlen(printV) == contador){
                                strcat(final, "\"");
                                strcat(final, (yyvsp[-3].valString));
                                strcat(final, "\"");
                                strcat(final, ",");
                                strcat(final, nueva_cadena);
                                
                        } else if (strlen(printV) > contador){
                                strcat(final, "\"");
                                strcat(final, (yyvsp[-3].valString));
                                strcat(final, "{}");
                                strcat(final, "\"");
                                strcat(final, ",");
                                strcat(final, nueva_cadena);
                                
                        } else {
                                printf("tiene que haber algun error");
                        }
                        strcat(final, ");");
                        memset(printV, 0, sizeof(printV));
                        free((yyvsp[-3].valString));
                        free(nueva_cadena);

                        (yyval.valString) = final;
                }
        }
#line 2772 "scanner.tab.c"
    break;

  case 64: /* contentWrite: contentWrite LOWER LOWER QUOTESTRING  */
#line 1022 "scanner.y"
                                            {
                char * final = malloc(strlen((yyvsp[-3].valString)) * sizeof(char) + strlen((yyvsp[0].valString)) * sizeof(char) + strlen("{}") * sizeof(char)+strlen("println!(\"")); 
                memset(final, 0, sizeof(final));
                char temp[strlen((yyvsp[0].valString))];
                memset(temp,0,strlen((yyvsp[0].valString)));

                strcat(temp, (yyvsp[0].valString));
                
                strcat(final, (yyvsp[-3].valString));
                strcat(final,"{}");
                deleteQuotes(final);
                deleteQuotes(temp);

                strcat(final, temp);
                free((yyvsp[-3].valString));

                (yyval.valString) = final;
        }
#line 2795 "scanner.tab.c"
    break;

  case 65: /* contentWrite: contentWrite LOWER LOWER STRINGV  */
#line 1040 "scanner.y"
                                         {
                char * final = malloc(strlen((yyvsp[-3].valString)) * sizeof(char) + strlen((yyvsp[0].valString)) * sizeof(char) + strlen("{}") * sizeof(char)); 
                memset(final, 0, sizeof(final));

                strcat(printV,(yyvsp[0].valString));
                strcat(printV,",");

                
                strcat(final, (yyvsp[-3].valString));
                deleteQuotes(final);
                (yyval.valString) = final;
        }
#line 2812 "scanner.tab.c"
    break;

  case 66: /* contentWrite: contentWrite PLUS QUOTESTRING  */
#line 1052 "scanner.y"
                                      {
                char * final = malloc(strlen((yyvsp[-2].valString)) * sizeof(char) + strlen((yyvsp[0].valString)) * sizeof(char) + strlen("{}") * sizeof(char)); 
                memset(final, 0, sizeof(final));

                char temp[strlen((yyvsp[0].valString))];
                memset(temp,0,strlen((yyvsp[0].valString)));

                strcat(temp, (yyvsp[0].valString));
                
                strcat(final, (yyvsp[-2].valString));
                strcat(final,"{}");
                deleteQuotes(final);
                deleteQuotes(temp);

                strcat(final, temp);
                free((yyvsp[-2].valString));
                (yyval.valString) = final;
        }
#line 2835 "scanner.tab.c"
    break;

  case 67: /* contentWrite: contentWrite PLUS STRINGV  */
#line 1070 "scanner.y"
                                  {
                char * final = malloc(strlen((yyvsp[-2].valString)) * sizeof(char) + strlen((yyvsp[0].valString)) * sizeof(char) + strlen("{}") * sizeof(char)); 
                memset(final, 0, sizeof(final));

                strcat(printV,(yyvsp[0].valString));
                strcat(printV,",");

                
                strcat(final, (yyvsp[-2].valString));
                deleteQuotes(final);
                (yyval.valString) = (yyvsp[-2].valString);
        }
#line 2852 "scanner.tab.c"
    break;

  case 68: /* contentWrite: QUOTESTRING  */
#line 1083 "scanner.y"
                      {

                (yyval.valString) = (yyvsp[0].valString);}
#line 2860 "scanner.tab.c"
    break;

  case 69: /* contentWrite: STRINGV  */
#line 1086 "scanner.y"
                  {
                (yyval.valString) = (yyvsp[0].valString);}
#line 2867 "scanner.tab.c"
    break;

  case 70: /* assignation: STRINGV EQ exp SEMICOLON  */
#line 1091 "scanner.y"
                                 {
                char * final = malloc(strlen((yyvsp[-3].valString)) * sizeof(char) + sizeof(" = ") + strlen((yyvsp[-1].valString)) * sizeof(char) + sizeof(";") + 1);
                memset(final, 0, sizeof(final));
                strcpy(final, (yyvsp[-3].valString));
                strcat(final, " = ");
                strcat(final, (yyvsp[-1].valString));
                strcat(final, ";"); 
                free((yyvsp[-1].valString));
                free((yyvsp[-3].valString));
                (yyval.valString) = final;
        }
#line 2883 "scanner.tab.c"
    break;

  case 71: /* assignation: STRINGV EQ exp  */
#line 1102 "scanner.y"
                       {
                char * final = malloc(strlen((yyvsp[-2].valString)) * sizeof(char) + sizeof(" = ") + strlen((yyvsp[0].valString)) * sizeof(char)  + 1);
                memset(final, 0, sizeof(final));
                strcpy(final, (yyvsp[-2].valString));
                strcat(final, " = ");
                strcat(final, (yyvsp[0].valString));
                free((yyvsp[0].valString));
                free((yyvsp[-2].valString));
                (yyval.valString) = final;
        }
#line 2898 "scanner.tab.c"
    break;

  case 72: /* exp: exp operand term  */
#line 1152 "scanner.y"
                         {
                
                char * final = malloc(strlen((yyvsp[-2].valString)) * sizeof(char) +strlen((yyvsp[-1].valString)) * sizeof(char) + strlen((yyvsp[0].valString)) * sizeof(char) + 1);
                memset(final, 0, sizeof(final));
                strcpy(final, (yyvsp[-2].valString));
                strcat(final, (yyvsp[-1].valString));
                strcat(final, (yyvsp[0].valString));
                free((yyvsp[-2].valString));
                free((yyvsp[-1].valString));
                free((yyvsp[0].valString));
                (yyval.valString) = final;
                
        }
#line 2916 "scanner.tab.c"
    break;

  case 73: /* exp: term  */
#line 1165 "scanner.y"
              {
        	(yyval.valString) = (yyvsp[0].valString);
			}
#line 2924 "scanner.tab.c"
    break;

  case 74: /* term: atom  */
#line 1172 "scanner.y"
             {
                (yyval.valString) = (yyvsp[0].valString);}
#line 2931 "scanner.tab.c"
    break;

  case 75: /* term: LPAREN exp RPAREN  */
#line 1174 "scanner.y"
                            {
                char * final = malloc(strlen((yyvsp[-1].valString)) * sizeof(char) + sizeof("()") + 1);
                memset(final, 0, sizeof(final));
                strcpy(final, "(");
                strcat(final, (yyvsp[-1].valString));
                strcat(final, ")");
                free((yyvsp[-1].valString));
                (yyval.valString) = final;
                }
#line 2945 "scanner.tab.c"
    break;

  case 76: /* term: HYPHEN atom  */
#line 1183 "scanner.y"
                      {
                char * final = malloc(strlen((yyvsp[0].valString)) * sizeof(char) + sizeof("-()") + 1);
                memset(final, 0, sizeof(final));
                strcpy(final, "-(");
                strcat(final, (yyvsp[0].valString));
                strcat(final, ")");
                free((yyvsp[0].valString));
                (yyval.valString) = final;
                }
#line 2959 "scanner.tab.c"
    break;

  case 77: /* term: EX exp  */
#line 1192 "scanner.y"
                 {
                char * final = malloc(strlen((yyvsp[0].valString)) * sizeof(char) + sizeof("!()") + 1);
                memset(final, 0, sizeof(final));
                strcpy(final, "!(");
                strcat(final, (yyvsp[0].valString));
                strcat(final, ")");
                free((yyvsp[0].valString));
                (yyval.valString) = final;
                }
#line 2973 "scanner.tab.c"
    break;

  case 78: /* operand: PLUS  */
#line 1204 "scanner.y"
             {
                (yyval.valString) = strdup(" + ");
        }
#line 2981 "scanner.tab.c"
    break;

  case 79: /* operand: PLUS EQ  */
#line 1207 "scanner.y"
                 {(yyval.valString) = strdup(" += ");}
#line 2987 "scanner.tab.c"
    break;

  case 80: /* operand: HYPHEN  */
#line 1208 "scanner.y"
                {(yyval.valString) = strdup(" - ");}
#line 2993 "scanner.tab.c"
    break;

  case 81: /* operand: HYPHEN EQ  */
#line 1209 "scanner.y"
                   {(yyval.valString) = strdup(" -= ");}
#line 2999 "scanner.tab.c"
    break;

  case 82: /* operand: PROD  */
#line 1210 "scanner.y"
              {(yyval.valString) = strdup(" * ");}
#line 3005 "scanner.tab.c"
    break;

  case 83: /* operand: DIV  */
#line 1211 "scanner.y"
             {(yyval.valString) = strdup(" / ");}
#line 3011 "scanner.tab.c"
    break;

  case 84: /* operand: DIVINT  */
#line 1212 "scanner.y"
                {(yyval.valString) = strdup(" / ");}
#line 3017 "scanner.tab.c"
    break;

  case 85: /* operand: MOD  */
#line 1213 "scanner.y"
             {(yyval.valString) = strdup(" % ");}
#line 3023 "scanner.tab.c"
    break;

  case 86: /* operand: LOWER  */
#line 1214 "scanner.y"
               {(yyval.valString) = strdup(" < ");}
#line 3029 "scanner.tab.c"
    break;

  case 87: /* operand: HIGHER  */
#line 1215 "scanner.y"
                {(yyval.valString) = strdup(" > ");}
#line 3035 "scanner.tab.c"
    break;

  case 88: /* operand: LOWER EQ  */
#line 1216 "scanner.y"
                  {(yyval.valString) = strdup(" <= ");}
#line 3041 "scanner.tab.c"
    break;

  case 89: /* operand: HIGHER EQ  */
#line 1217 "scanner.y"
                   {(yyval.valString) = strdup(" >= ");}
#line 3047 "scanner.tab.c"
    break;

  case 90: /* operand: EQ  */
#line 1218 "scanner.y"
            {(yyval.valString) = strdup(" == ");}
#line 3053 "scanner.tab.c"
    break;

  case 91: /* operand: AND  */
#line 1219 "scanner.y"
             {(yyval.valString) = strdup(" && ");}
#line 3059 "scanner.tab.c"
    break;

  case 92: /* operand: PLUS PLUS  */
#line 1220 "scanner.y"
                   {(yyval.valString) = strdup(" ++ ");}
#line 3065 "scanner.tab.c"
    break;

  case 93: /* operand: OR  */
#line 1221 "scanner.y"
           {(yyval.valString) = strdup(" || ");}
#line 3071 "scanner.tab.c"
    break;

  case 94: /* atom: STRINGV  */
#line 1226 "scanner.y"
                {
			/*if (!checkName(&typelist, $1)){
                        printf("Error: Variable %s no declarada\n", $1);
                        yyclearin;
                        exit(0);
            }
            $$ = $1;*/
		}
#line 3084 "scanner.tab.c"
    break;

  case 95: /* atom: values  */
#line 1234 "scanner.y"
                 {
                        
			(yyval.valString) = (yyvsp[0].valString);
		}
#line 3093 "scanner.tab.c"
    break;


#line 3097 "scanner.tab.c"

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

#line 1240 "scanner.y"



char* getEndNumber(char* number){
                int len = strlen(number);
                char* numero = (char*) malloc(len + 1); // Reservar espacio para el nuevo número (+1 por el '\0')
                char* newNumero = (char*) malloc(2); // Reservar espacio para el dígito y el '\0'
                numero[0] = '\0'; // Inicializar la cadena vacía
                for (int i = len - 1; i >= 0; i--) {
                        if (!isdigit(number[i])) {
                                break;
                                
                        } else {
                                newNumero[0] = number[i];
                                newNumero[1] = '\0'; // Agregar el '\0' para que sea una cadena válida
                                char* temp = strdup(numero); // Crear una copia temporal de la cadena
                                strcpy(numero, newNumero); // Copiar el dígito al principio de la cadena
                                strcat(numero, temp); // Concatenar el resto de la cadena al final
                                free(temp); // Liberar la memoria de la cadena temporal
                        }
                }
                free(newNumero); // Liberar la memoria del dígito
                return numero;
}


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
                        case 0: strcat(temp, "i32 ");break;
                        case 1: strcat(temp, "i16 ");break;
                        case 2: strcat(temp, "i64 ");break;
                        case 3: strcat(temp, "u32 ");break;
                        case 4: strcat(temp, "u16 ");break;
                        case 5: strcat(temp, "u64 ");break;
                        case 6: strcat(temp, "f32 ");break;
                        case 7: strcat(temp, "f64 ");break;
                        case 8: strcat(temp, "String ");break;
                        case 9: strcat(temp, "char ");break;
                        case 10: strcat(temp, "bool ");break;
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
