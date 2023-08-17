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
TypeList flist;
//queue será la cola a través de la cual recogeremos y volcaremos las variables de los printf 
NodeList queue;
char printV[100]= "";

void yyerror(char const *);
char * getVariables(TypeList *);
char * getEndings(NodeList *);
char * getEndingsR(NodeList *);
char * obtenerTipo(int valor);
char * getRef (int);
void deleteQuotes (char *);
void deleteCurly(char *);
void deleteNewLines(char *);
char* getEndNumber(char* number);


#line 106 "scanner.tab.c"

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
  YYSYMBOL_PRINTF = 57,                    /* PRINTF  */
  YYSYMBOL_STRING = 58,                    /* STRING  */
  YYSYMBOL_STRINGV = 59,                   /* STRINGV  */
  YYSYMBOL_QUOTESTRING = 60,               /* QUOTESTRING  */
  YYSYMBOL_TRUEVAL = 61,                   /* TRUEVAL  */
  YYSYMBOL_FALSEVAL = 62,                  /* FALSEVAL  */
  YYSYMBOL_INTNUM = 63,                    /* INTNUM  */
  YYSYMBOL_REALNUM = 64,                   /* REALNUM  */
  YYSYMBOL_RETURN = 65,                    /* RETURN  */
  YYSYMBOL_EX = 66,                        /* EX  */
  YYSYMBOL_YYACCEPT = 67,                  /* $accept  */
  YYSYMBOL_S = 68,                         /* S  */
  YYSYMBOL_comment = 69,                   /* comment  */
  YYSYMBOL_subcabecera = 70,               /* subcabecera  */
  YYSYMBOL_cabecera = 71,                  /* cabecera  */
  YYSYMBOL_constdef = 72,                  /* constdef  */
  YYSYMBOL_fvardef = 73,                   /* fvardef  */
  YYSYMBOL_vardef = 74,                    /* vardef  */
  YYSYMBOL_type = 75,                      /* type  */
  YYSYMBOL_values = 76,                    /* values  */
  YYSYMBOL_preprograma = 77,               /* preprograma  */
  YYSYMBOL_programa = 78,                  /* programa  */
  YYSYMBOL_args = 79,                      /* args  */
  YYSYMBOL_lines_program = 80,             /* lines_program  */
  YYSYMBOL_line_program = 81,              /* line_program  */
  YYSYMBOL_array = 82,                     /* array  */
  YYSYMBOL_precontentWrite = 83,           /* precontentWrite  */
  YYSYMBOL_contentWrite = 84,              /* contentWrite  */
  YYSYMBOL_assignation = 85,               /* assignation  */
  YYSYMBOL_exp = 86,                       /* exp  */
  YYSYMBOL_term = 87,                      /* term  */
  YYSYMBOL_operand = 88,                   /* operand  */
  YYSYMBOL_atom = 89                       /* atom  */
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
#define YYLAST   711

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  67
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  216

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   321


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
      65,    66
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   132,   132,   142,   153,   165,   179,   182,   188,   189,
     192,   193,   197,   208,   223,   235,   249,   263,   285,   297,
     310,   328,   329,   330,   331,   332,   333,   334,   335,   336,
     337,   338,   344,   347,   348,   349,   350,   354,   362,   371,
     432,   523,   532,   539,   555,   568,   580,   591,   596,   599,
     603,   616,   628,   637,   657,   680,   695,   708,   709,   718,
     726,   740,   750,   755,   821,   884,   902,   914,   932,   945,
     948,   953,   964,  1014,  1027,  1034,  1036,  1045,  1054,  1066,
    1069,  1070,  1071,  1072,  1073,  1074,  1075,  1076,  1077,  1078,
    1079,  1080,  1081,  1082,  1083,  1088,  1096
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
  "OPENCURLYBRACKET", "CLOSECURLYBRACKET", "BOOLEAN", "CHAR", "PRINTF",
  "STRING", "STRINGV", "QUOTESTRING", "TRUEVAL", "FALSEVAL", "INTNUM",
  "REALNUM", "RETURN", "EX", "$accept", "S", "comment", "subcabecera",
  "cabecera", "constdef", "fvardef", "vardef", "type", "values",
  "preprograma", "programa", "args", "lines_program", "line_program",
  "array", "precontentWrite", "contentWrite", "assignation", "exp", "term",
  "operand", "atom", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-85)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       9,    -1,    12,    18,   -36,   -85,   -85,   -85,   -85,   -16,
     -33,   163,    11,   -85,   -85,   163,   569,   -24,   -85,   -85,
     -85,   -85,   -85,   -85,   -85,   -85,   -85,   -85,   -85,    45,
      45,    45,   -13,    45,   -85,   -85,    45,    45,    -7,    49,
      45,   -85,   -85,    28,   -85,    45,    40,   -85,   -85,   -85,
     -85,   -85,    32,    88,   511,   -85,    49,   -85,    37,    43,
      31,    30,    62,    77,   -85,   -85,   591,    97,    75,   -85,
      95,    96,    83,   119,   102,    -5,   103,   680,     1,   -85,
     -85,    86,   127,   -85,   -85,   569,   591,     1,   569,   591,
     123,     1,   115,   591,    14,   -85,   -85,   125,   126,    29,
     130,   -85,   -85,   -85,   -85,     1,   113,   104,     1,   -85,
       1,   -85,   639,   -85,   -85,    78,    84,   -85,   -85,   185,
     246,   110,   243,    14,   304,     1,   107,   -85,   -85,   131,
      33,   -85,   -85,   -85,   -85,   -85,   652,   -85,   -85,   362,
     -85,   -85,   -85,     1,   164,   117,   -85,   -85,    84,   134,
     140,   188,   152,   146,   420,   -85,   157,   183,    59,   -85,
     -85,   -85,   160,   161,   165,   -85,   591,   144,   182,   -85,
     591,   169,   -85,    -3,   -85,   -85,   -85,   -85,   199,   301,
     194,     1,   359,   591,   -85,   -85,   -85,   192,   -85,     1,
     478,   -85,   417,    49,   667,   205,   -85,   224,   200,   196,
     -85,    49,   209,   680,   216,   -85,   -85,   217,   206,   208,
     591,   591,   475,   533,   -85,   -85
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,    57,
      60,     0,     0,    46,    49,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    92,    94,    87,    88,    79,
      81,    83,    84,    85,    86,    91,     0,     0,     0,    95,
       0,    96,     0,    74,    75,     0,     0,    45,    43,     0,
       0,     0,     0,     0,     0,     0,     0,    70,    69,     0,
      63,    89,    90,    93,    80,    82,    72,    58,    77,     0,
      78,    91,    59,     0,     0,     0,    14,    40,     0,     0,
       0,     0,     0,     0,     0,    52,     0,     0,     0,    71,
      76,    73,     0,     0,     0,    39,     0,     0,     0,    47,
       0,     0,    48,     0,    68,    67,    16,    15,     0,     0,
       0,     0,     0,     0,    64,    66,    65,     0,    56,     0,
       0,    50,     0,     0,     0,     0,    51,    62,     0,     0,
      55,     0,     0,     0,     0,    61,    17,     0,     0,     0,
       0,     0,     0,     0,    54,    53
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -85,   -85,    -2,   114,   -85,   -85,   -85,   -85,     0,   -39,
       5,    38,   177,   -84,   -75,    76,   155,   -85,    64,   -83,
     136,   -74,   173
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,    79,    11,     3,    30,    80,    31,    81,   111,
      33,    34,    62,    82,    83,   198,   129,   130,    84,   112,
     113,   143,   114
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      52,    10,   119,   106,   120,   122,   184,   117,   124,    29,
      92,    32,     6,    36,    59,    32,    38,    63,   126,     4,
      37,     1,   136,    12,   107,   139,     9,   140,    13,    32,
      32,    32,    35,    32,    40,    39,    32,    32,     5,   108,
      32,    45,   154,     9,   117,    32,    43,   117,    93,     7,
       8,   133,    46,   157,    61,   158,   185,   186,    53,   134,
     109,    47,    48,    49,    50,    51,    54,   110,    41,    42,
      56,    44,    55,   127,   128,    44,    57,     9,    44,    16,
      17,    64,   179,    44,    66,    61,   182,    65,   121,    67,
      18,    19,    20,    21,    22,    23,    24,    25,   190,   192,
      26,    27,    68,    28,   117,   163,   194,   117,   144,    47,
      48,    49,    50,    51,   147,     7,     8,   117,   174,   175,
     145,    69,   146,    14,    15,    85,   212,   213,    86,   207,
      70,    71,    72,    87,    88,    73,    89,   117,   117,    90,
      91,    94,    74,   123,    75,   115,   165,    58,    47,    48,
      49,    50,    51,   125,   197,   131,   132,   137,     7,     8,
     135,   155,   197,   109,    47,    48,    49,    50,    51,   150,
     167,   156,    18,    19,    20,    21,    22,    23,    24,    25,
     164,   116,    26,    27,    76,    28,    77,   166,    70,    71,
      72,   168,    78,    73,     7,     8,   169,    16,    17,   170,
      74,   172,    75,   173,   176,   177,   178,   180,    18,    19,
      20,    21,    22,    23,    24,    25,     7,     8,    26,    27,
     181,    28,   183,   162,    47,    48,    49,    50,    51,   187,
      18,    19,    20,    21,    22,    23,    24,    25,   189,   148,
      26,    27,    76,    28,    77,   193,    70,    71,    72,   200,
      78,    73,   201,   206,   202,   203,   208,   209,    74,   210,
      75,   211,   118,   204,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,     7,     8,   141,   205,   152,   161,
     138,     0,     0,     0,     0,     0,   149,     0,    18,    19,
      20,    21,    22,    23,    24,    25,     0,   151,    26,    27,
      76,    28,    77,     0,    70,    71,    72,     0,    78,    73,
       0,     0,     0,     0,     0,     0,    74,     0,    75,     0,
       0,     0,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,     7,     8,   141,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   153,     0,    18,    19,    20,    21,
      22,    23,    24,    25,     0,   188,    26,    27,    76,    28,
      77,     0,    70,    71,    72,     0,    78,    73,     0,     0,
       0,     0,     0,     0,    74,     0,    75,     0,     0,     0,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
       7,     8,   141,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   160,     0,    18,    19,    20,    21,    22,    23,
      24,    25,     0,   191,    26,    27,    76,    28,    77,     0,
      70,    71,    72,     0,    78,    73,     0,     0,     0,     0,
       0,     0,    74,     0,    75,     0,     0,     0,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,     7,     8,
     141,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     171,     0,    18,    19,    20,    21,    22,    23,    24,    25,
       0,   196,    26,    27,    76,    28,    77,     0,    70,    71,
      72,     0,    78,    73,     0,     0,     0,     0,     0,     0,
      74,     0,    75,     0,     0,     0,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,     7,     8,   141,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   195,     0,
      18,    19,    20,    21,    22,    23,    24,    25,     0,   214,
      26,    27,    76,    28,    77,     0,    70,    71,    72,     0,
      78,    73,     0,     0,     0,     0,     0,     0,    74,     0,
      75,    60,     0,     0,     0,     0,    18,    19,    20,    21,
      22,    23,    24,    25,     7,     8,    26,    27,     0,    28,
       0,     0,     0,     0,     0,     0,     0,     0,    18,    19,
      20,    21,    22,    23,    24,    25,     0,   215,    26,    27,
      76,    28,    77,     0,    70,    71,    72,     0,    78,    73,
       0,     0,     0,     0,     0,     0,    74,     0,    75,     0,
       0,     0,     0,     0,    18,    19,    20,    21,    22,    23,
      24,    25,     7,     8,    26,    27,     0,    28,     0,     0,
       0,     0,     0,     0,     0,     0,    18,    19,    20,    21,
      22,    23,    24,    25,     0,     0,    26,    27,    76,    28,
      77,     0,     0,     0,     0,     0,    78,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,     0,     0,   141,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
       0,     0,   141,   142,     0,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,     0,   159,   141,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,     0,     0,
     105,   199
};

static const yytype_int16 yycheck[] =
{
      39,     3,    86,    77,    87,    89,     9,    82,    91,    11,
      15,    11,     0,    15,    53,    15,    16,    56,    93,    20,
      15,    12,   105,    59,    23,   108,    59,   110,    44,    29,
      30,    31,    21,    33,    29,    59,    36,    37,    39,    38,
      40,    36,   125,    59,   119,    45,    59,   122,    53,    31,
      32,    22,    59,    20,    54,    22,    59,    60,    30,    30,
      59,    60,    61,    62,    63,    64,    38,    66,    30,    31,
      30,    33,    44,    59,    60,    37,    44,    59,    40,    34,
      35,    44,   166,    45,    53,    85,   170,    44,    88,    59,
      45,    46,    47,    48,    49,    50,    51,    52,   181,   183,
      55,    56,    40,    58,   179,   144,   189,   182,    30,    60,
      61,    62,    63,    64,   116,    31,    32,   192,    59,    60,
      42,    44,    44,     9,    10,    28,   210,   211,    53,   203,
       3,     4,     5,    38,    38,     8,    53,   212,   213,    20,
      38,    38,    15,    20,    17,    59,   148,    59,    60,    61,
      62,    63,    64,    38,   193,    30,    30,    44,    31,    32,
      30,    54,   201,    59,    60,    61,    62,    63,    64,    59,
      30,    40,    45,    46,    47,    48,    49,    50,    51,    52,
      63,    54,    55,    56,    57,    58,    59,    53,     3,     4,
       5,     3,    65,     8,    31,    32,    44,    34,    35,    53,
      15,    44,    17,    20,    44,    44,    41,    63,    45,    46,
      47,    48,    49,    50,    51,    52,    31,    32,    55,    56,
      38,    58,    53,    59,    60,    61,    62,    63,    64,    30,
      45,    46,    47,    48,    49,    50,    51,    52,    44,    54,
      55,    56,    57,    58,    59,    53,     3,     4,     5,    44,
      65,     8,    28,    44,    54,    59,    40,    40,    15,    53,
      17,    53,    85,   199,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    31,    32,    30,   201,   123,   143,
     107,    -1,    -1,    -1,    -1,    -1,    40,    -1,    45,    46,
      47,    48,    49,    50,    51,    52,    -1,    54,    55,    56,
      57,    58,    59,    -1,     3,     4,     5,    -1,    65,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,    17,    -1,
      -1,    -1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    31,    32,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    40,    -1,    45,    46,    47,    48,
      49,    50,    51,    52,    -1,    54,    55,    56,    57,    58,
      59,    -1,     3,     4,     5,    -1,    65,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    -1,    17,    -1,    -1,    -1,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      31,    32,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    40,    -1,    45,    46,    47,    48,    49,    50,
      51,    52,    -1,    54,    55,    56,    57,    58,    59,    -1,
       3,     4,     5,    -1,    65,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    -1,    17,    -1,    -1,    -1,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    31,    32,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      40,    -1,    45,    46,    47,    48,    49,    50,    51,    52,
      -1,    54,    55,    56,    57,    58,    59,    -1,     3,     4,
       5,    -1,    65,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    -1,    17,    -1,    -1,    -1,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    31,    32,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,
      45,    46,    47,    48,    49,    50,    51,    52,    -1,    54,
      55,    56,    57,    58,    59,    -1,     3,     4,     5,    -1,
      65,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,
      17,    40,    -1,    -1,    -1,    -1,    45,    46,    47,    48,
      49,    50,    51,    52,    31,    32,    55,    56,    -1,    58,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,
      47,    48,    49,    50,    51,    52,    -1,    54,    55,    56,
      57,    58,    59,    -1,     3,     4,     5,    -1,    65,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,    17,    -1,
      -1,    -1,    -1,    -1,    45,    46,    47,    48,    49,    50,
      51,    52,    31,    32,    55,    56,    -1,    58,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    48,
      49,    50,    51,    52,    -1,    -1,    55,    56,    57,    58,
      59,    -1,    -1,    -1,    -1,    -1,    65,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    -1,    -1,    30,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      -1,    -1,    30,    44,    -1,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    -1,    44,    30,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    -1,    -1,
      30,    44
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    12,    68,    71,    20,    39,     0,    31,    32,    59,
      69,    70,    59,    44,    70,    70,    34,    35,    45,    46,
      47,    48,    49,    50,    51,    52,    55,    56,    58,    69,
      72,    74,    75,    77,    78,    21,    69,    77,    75,    59,
      77,    78,    78,    59,    78,    77,    59,    60,    61,    62,
      63,    64,    76,    30,    38,    44,    30,    44,    59,    76,
      40,    75,    79,    76,    44,    44,    53,    59,    40,    44,
       3,     4,     5,     8,    15,    17,    57,    59,    65,    69,
      73,    75,    80,    81,    85,    28,    53,    38,    38,    53,
      20,    38,    15,    53,    38,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    30,    88,    23,    38,    59,
      66,    76,    86,    87,    89,    59,    54,    81,    79,    80,
      86,    75,    80,    20,    86,    38,    81,    59,    60,    83,
      84,    30,    30,    22,    30,    30,    86,    44,    89,    86,
      86,    30,    44,    88,    30,    42,    44,    69,    54,    40,
      59,    54,    83,    40,    86,    54,    40,    20,    22,    44,
      40,    87,    59,    76,    63,    69,    53,    30,     3,    44,
      53,    40,    44,    20,    59,    60,    44,    44,    41,    80,
      63,    38,    80,    53,     9,    59,    60,    30,    54,    44,
      86,    54,    80,    53,    86,    40,    54,    76,    82,    44,
      44,    28,    54,    59,    85,    82,    44,    88,    40,    40,
      53,    53,    80,    80,    54,    54
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    67,    68,    68,    68,    68,    69,    69,    70,    70,
      71,    71,    72,    72,    73,    73,    73,    73,    74,    74,
      74,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    76,    76,    76,    76,    76,    77,    77,    78,
      78,    78,    78,    79,    79,    80,    80,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    82,    82,    83,    83,    84,    84,    84,    84,    84,
      84,    85,    85,    86,    86,    87,    87,    87,    87,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    89,    89
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     4,     4,     5,     1,     1,     2,     2,
       4,     2,     4,     6,     3,     5,     5,    10,     3,     5,
       5,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     9,
       8,     2,     2,     4,     2,     2,     1,     5,     5,     1,
       7,     8,     4,    15,    14,     9,     7,     1,     3,     3,
       1,     3,     1,     1,     4,     4,     4,     3,     3,     1,
       1,     4,     3,     3,     1,     1,     3,     2,     2,     1,
       2,     1,     2,     1,     1,     1,     1,     1,     1,     2,
       2,     1,     1,     2,     1,     1,     1
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
#line 132 "scanner.y"
                                         { 
                
                FILE *fp = fopen(outputName, "w");
                
                if (fp!=NULL) {
                fputs((yyvsp[0].valString), fp);
                    fclose(fp);  
                }
                
        }
#line 1703 "scanner.tab.c"
    break;

  case 3: /* S: cabecera comment subcabecera preprograma  */
#line 142 "scanner.y"
                                                  { 
                
                //printf("%s\n", $4);
                FILE *fp = fopen(outputName, "w");
				//char * variables = getVariables(&typelist);
                
                if (fp!=NULL) {
                    fputs((yyvsp[0].valString), fp);
                    fclose(fp);  
                }
        }
#line 1719 "scanner.tab.c"
    break;

  case 4: /* S: cabecera subcabecera comment preprograma  */
#line 153 "scanner.y"
                                                  { 
                
                //printf("%s\n", $4);//por alguna razon devuelve de la segunda linea, el tercer valor, pasa lo mismo con subcabecera, en cambio en cabecera no pasa eso
                
                FILE *fp = fopen(outputName, "w");
		//char * variables = getVariables(&typelist);
                
                if (fp!=NULL) {
                    fputs((yyvsp[0].valString), fp);
                    fclose(fp);  
                }
        }
#line 1736 "scanner.tab.c"
    break;

  case 5: /* S: cabecera comment subcabecera comment preprograma  */
#line 165 "scanner.y"
                                                          { 
                
               FILE *fp = fopen(outputName, "w");
		//char * variables = getVariables(&typelist);
                
                if (fp!=NULL) {
                    fputs((yyvsp[-1].valString), fp);
                    fclose(fp);  
                }
        }
#line 1751 "scanner.tab.c"
    break;

  case 6: /* comment: COMMENTLINE  */
#line 179 "scanner.y"
                     {
                (yyval.valString) = (yyvsp[0].valString);
                }
#line 1759 "scanner.tab.c"
    break;

  case 7: /* comment: MULTILINE  */
#line 182 "scanner.y"
                    {;}
#line 1765 "scanner.tab.c"
    break;

  case 8: /* subcabecera: STRINGV SEMICOLON  */
#line 188 "scanner.y"
                          {(yyval.valString) = "";}
#line 1771 "scanner.tab.c"
    break;

  case 9: /* subcabecera: STRINGV subcabecera  */
#line 189 "scanner.y"
                             {;}
#line 1777 "scanner.tab.c"
    break;

  case 10: /* cabecera: PROGRAM LOWER STRINGV HIGHER  */
#line 192 "scanner.y"
                                        {(yyval.valString) = "";}
#line 1783 "scanner.tab.c"
    break;

  case 11: /* cabecera: PROGRAM STRINGQUOTE  */
#line 193 "scanner.y"
                                       {;}
#line 1789 "scanner.tab.c"
    break;

  case 12: /* constdef: DEFINE STRINGV values SEMICOLON  */
#line 197 "scanner.y"
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
#line 1805 "scanner.tab.c"
    break;

  case 13: /* constdef: CONST type STRINGV EQ values SEMICOLON  */
#line 208 "scanner.y"
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
#line 1821 "scanner.tab.c"
    break;

  case 14: /* fvardef: type STRINGV SEMICOLON  */
#line 223 "scanner.y"
                               {
                char * tipo = obtenerTipo((yyvsp[-2].valInt));
                char * final = malloc(strlen(tipo)*sizeof(char) + strlen((yyvsp[-1].valString))*sizeof(char) + strlen("let\n: ;"));
                memset(final,0,sizeof(final));
                strcat(final,"let ");
                strcat(final,(yyvsp[-1].valString));
                strcat(final,":");
                strcat(final,tipo);
                strcat(final,";\n");
                (yyval.valString) = final;

        }
#line 1838 "scanner.tab.c"
    break;

  case 15: /* fvardef: type STRINGV EQ values SEMICOLON  */
#line 235 "scanner.y"
                                           {
                char * tipo = obtenerTipo((yyvsp[-4].valInt));
                char * final = malloc(strlen(tipo)*sizeof(char) + strlen((yyvsp[-1].valString))*sizeof(char) + strlen((yyvsp[-3].valString))*sizeof(char) + strlen("=let\n: ;"));
                memset(final,0,sizeof(final));
                strcat(final,"let ");
                strcat(final,(yyvsp[-3].valString));
                strcat(final,":");
                strcat(final,tipo);
                strcat(final,"=");
                strcat(final,(yyvsp[-1].valString));
                strcat(final,";\n");
                printf("%s",final);
                (yyval.valString) = final;
        }
#line 1857 "scanner.tab.c"
    break;

  case 16: /* fvardef: type STRINGV EQ STRINGV SEMICOLON  */
#line 249 "scanner.y"
                                            {
                char * tipo = obtenerTipo((yyvsp[-4].valInt));
                char * final = malloc(strlen(tipo)*sizeof(char) + strlen((yyvsp[-1].valString))*sizeof(char) + strlen((yyvsp[-3].valString))*sizeof(char) + strlen("=let\n: ;"));
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
#line 1876 "scanner.tab.c"
    break;

  case 17: /* fvardef: type STRINGV LSQUAREPAREN INTNUM RSQUAREPAREN EQ OPENCURLYBRACKET array CLOSECURLYBRACKET SEMICOLON  */
#line 263 "scanner.y"
                                                                                                             {
                char * tipo = obtenerTipo((yyvsp[-9].valInt));
                char * final = malloc(strlen((yyvsp[-8].valString))*sizeof(char) + strlen(tipo)*sizeof(char)+ strlen((yyvsp[-6].valString))*sizeof(char) + strlen((yyvsp[-2].valString))*sizeof(char) + sizeof("let ::[] [] ; \n"));
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
                printf("%s",final);
                (yyval.valString) = final;
        }
#line 1899 "scanner.tab.c"
    break;

  case 18: /* vardef: type STRINGV SEMICOLON  */
#line 285 "scanner.y"
                               {
                char * tipo = obtenerTipo((yyvsp[-2].valInt));
                char * final = malloc(strlen(tipo)*sizeof(char) + strlen((yyvsp[-1].valString))*sizeof(char) + strlen("let\n: ;"));
                memset(final,0,sizeof(final));
                strcat(final,"let ");
                strcat(final,(yyvsp[-1].valString));
                strcat(final,":");
                strcat(final,tipo);
                strcat(final,";\n");
                (yyval.valString) = final;

        }
#line 1916 "scanner.tab.c"
    break;

  case 19: /* vardef: type STRINGV EQ values SEMICOLON  */
#line 297 "scanner.y"
                                           {
                char * tipo = obtenerTipo((yyvsp[-4].valInt));
                char * final = malloc(strlen(tipo)*sizeof(char) + strlen((yyvsp[-1].valString))*sizeof(char) + strlen((yyvsp[-3].valString))*sizeof(char) + strlen("=let\n: ;"));
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
#line 1934 "scanner.tab.c"
    break;

  case 20: /* vardef: type STRINGV EQ STRINGV SEMICOLON  */
#line 310 "scanner.y"
                                            {
                char * tipo = obtenerTipo((yyvsp[-4].valInt));
                char * final = malloc(strlen(tipo)*sizeof(char) + strlen((yyvsp[-1].valString))*sizeof(char) + strlen((yyvsp[-3].valString))*sizeof(char) + strlen("=let\n : ;"));
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
#line 1953 "scanner.tab.c"
    break;

  case 21: /* type: INTEGER  */
#line 328 "scanner.y"
                {(yyval.valInt) = 0;}
#line 1959 "scanner.tab.c"
    break;

  case 22: /* type: SHORT  */
#line 329 "scanner.y"
                {(yyval.valInt) = 1;}
#line 1965 "scanner.tab.c"
    break;

  case 23: /* type: LONG  */
#line 330 "scanner.y"
               {(yyval.valInt) = 2;}
#line 1971 "scanner.tab.c"
    break;

  case 24: /* type: UNSIGNED_INT  */
#line 331 "scanner.y"
                       {(yyval.valInt) = 3;}
#line 1977 "scanner.tab.c"
    break;

  case 25: /* type: UNSIGNED_SHORT  */
#line 332 "scanner.y"
                         {(yyval.valInt) = 4;}
#line 1983 "scanner.tab.c"
    break;

  case 26: /* type: UNSIGNED_LONG  */
#line 333 "scanner.y"
                        {(yyval.valInt) = 5;}
#line 1989 "scanner.tab.c"
    break;

  case 27: /* type: FLOAT  */
#line 334 "scanner.y"
                {(yyval.valInt) = 6;}
#line 1995 "scanner.tab.c"
    break;

  case 28: /* type: DOUBLE  */
#line 335 "scanner.y"
                 {(yyval.valInt) = 7;}
#line 2001 "scanner.tab.c"
    break;

  case 29: /* type: STRING  */
#line 336 "scanner.y"
                 {(yyval.valInt) = 8;}
#line 2007 "scanner.tab.c"
    break;

  case 30: /* type: CHAR  */
#line 337 "scanner.y"
               {(yyval.valInt) = 9;}
#line 2013 "scanner.tab.c"
    break;

  case 31: /* type: BOOLEAN  */
#line 338 "scanner.y"
                  {(yyval.valInt) = 10;}
#line 2019 "scanner.tab.c"
    break;

  case 32: /* values: TRUEVAL  */
#line 344 "scanner.y"
                {
                (yyval.valString) = strdup("true");
        }
#line 2027 "scanner.tab.c"
    break;

  case 33: /* values: FALSEVAL  */
#line 347 "scanner.y"
                   {(yyval.valString) = (yyvsp[0].valString);}
#line 2033 "scanner.tab.c"
    break;

  case 34: /* values: INTNUM  */
#line 348 "scanner.y"
                 {(yyval.valString) = (yyvsp[0].valString);}
#line 2039 "scanner.tab.c"
    break;

  case 35: /* values: REALNUM  */
#line 349 "scanner.y"
                  {(yyval.valString) = (yyvsp[0].valString);}
#line 2045 "scanner.tab.c"
    break;

  case 36: /* values: QUOTESTRING  */
#line 350 "scanner.y"
                      {(yyval.valString) = (yyvsp[0].valString);}
#line 2051 "scanner.tab.c"
    break;

  case 37: /* preprograma: preprograma programa  */
#line 354 "scanner.y"
                            {
                char * final = malloc(strlen((yyvsp[-1].valString))*sizeof(char) + strlen((yyvsp[0].valString))*sizeof(char));
                memset(final,0,sizeof(final));
                strcat(final, (yyvsp[-1].valString));
                strcat(final, (yyvsp[0].valString));

                (yyval.valString) = final;
        }
#line 2064 "scanner.tab.c"
    break;

  case 38: /* preprograma: programa  */
#line 362 "scanner.y"
                 {
                char * final = malloc(strlen((yyvsp[0].valString))*sizeof(char));
                memset(final,0,sizeof(final));

                strcat(final, (yyvsp[0].valString));

                (yyval.valString) = final;
        }
#line 2077 "scanner.tab.c"
    break;

  case 39: /* programa: type STRINGV LPAREN args RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET comment  */
#line 371 "scanner.y"
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
#line 2142 "scanner.tab.c"
    break;

  case 40: /* programa: type STRINGV LPAREN RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET comment  */
#line 432 "scanner.y"
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
#line 2191 "scanner.tab.c"
    break;

  case 41: /* programa: vardef programa  */
#line 523 "scanner.y"
                          {
                char * final = malloc(strlen((yyvsp[-1].valString))*sizeof(char) + strlen((yyvsp[0].valString))*sizeof(char) + sizeof("\n\n"));
                strcat(final,(yyvsp[-1].valString));
                strcat(final,"\n");
                strcat(final, (yyvsp[0].valString));
                strcat(final,"\n");
                
                (yyval.valString) = final;
        }
#line 2205 "scanner.tab.c"
    break;

  case 42: /* programa: constdef programa  */
#line 532 "scanner.y"
                            {
                
                (yyval.valString) = (yyvsp[0].valString);}
#line 2213 "scanner.tab.c"
    break;

  case 43: /* args: type STRINGV COMMA args  */
#line 539 "scanner.y"
                                {
                char * final;
                
                char * tipo = obtenerTipo((yyvsp[-3].valInt));
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
#line 2234 "scanner.tab.c"
    break;

  case 44: /* args: type STRINGV  */
#line 555 "scanner.y"
                      {
                char * final;
                char * tipo = obtenerTipo((yyvsp[-1].valInt));
                final = malloc(strlen(tipo) * sizeof(char) + strlen((yyvsp[0].valString)) * sizeof(char) );
                memset(final, 0, sizeof(final));
                strcat(final, tipo);
                strcat(final, " ");
                strcat(final, (yyvsp[0].valString));
                (yyval.valString) = final;
        }
#line 2249 "scanner.tab.c"
    break;

  case 45: /* lines_program: lines_program line_program  */
#line 568 "scanner.y"
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
#line 2266 "scanner.tab.c"
    break;

  case 46: /* lines_program: line_program  */
#line 580 "scanner.y"
                       {
                (yyval.valString) = (yyvsp[0].valString);
                
                }
#line 2275 "scanner.tab.c"
    break;

  case 47: /* line_program: WRITE LOWER LOWER precontentWrite SEMICOLON  */
#line 591 "scanner.y"
                                                    {
                
                (yyval.valString) = (yyvsp[-1].valString);
                
        }
#line 2285 "scanner.tab.c"
    break;

  case 48: /* line_program: PRINTF LPAREN precontentWrite RPAREN SEMICOLON  */
#line 596 "scanner.y"
                                                         {
                (yyval.valString) = (yyvsp[-2].valString);
        }
#line 2293 "scanner.tab.c"
    break;

  case 49: /* line_program: assignation  */
#line 599 "scanner.y"
                      {
                (yyval.valString) = (yyvsp[0].valString);
        }
#line 2301 "scanner.tab.c"
    break;

  case 50: /* line_program: IF LPAREN exp RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET  */
#line 603 "scanner.y"
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
#line 2319 "scanner.tab.c"
    break;

  case 51: /* line_program: ELSE IF LPAREN exp RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET  */
#line 616 "scanner.y"
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
#line 2336 "scanner.tab.c"
    break;

  case 52: /* line_program: ELSE OPENCURLYBRACKET line_program CLOSECURLYBRACKET  */
#line 628 "scanner.y"
                                                               {
                char* final = malloc(strlen((yyvsp[-1].valString))*sizeof(char)+ sizeof("else {} \n \n \t"));
                memset(final, 0, sizeof(final));
                strcat(final, "else{\n\t");
                strcat(final, (yyvsp[-1].valString));
                strcat(final, "}\n");
                (yyval.valString) = final;
        
        }
#line 2350 "scanner.tab.c"
    break;

  case 53: /* line_program: FOR LPAREN type STRINGV EQ INTNUM SEMICOLON exp SEMICOLON STRINGV operand RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET  */
#line 637 "scanner.y"
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
#line 2374 "scanner.tab.c"
    break;

  case 54: /* line_program: FOR LPAREN type STRINGV EQ INTNUM SEMICOLON exp SEMICOLON assignation RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET  */
#line 657 "scanner.y"
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
#line 2402 "scanner.tab.c"
    break;

  case 55: /* line_program: DO OPENCURLYBRACKET lines_program CLOSECURLYBRACKET WHILE LPAREN exp RPAREN SEMICOLON  */
#line 680 "scanner.y"
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
#line 2422 "scanner.tab.c"
    break;

  case 56: /* line_program: WHILE LPAREN exp RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET  */
#line 695 "scanner.y"
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
#line 2439 "scanner.tab.c"
    break;

  case 57: /* line_program: comment  */
#line 708 "scanner.y"
                 {;}
#line 2445 "scanner.tab.c"
    break;

  case 58: /* line_program: STRINGV operand SEMICOLON  */
#line 709 "scanner.y"
                                   {
                char * final = malloc (strlen((yyvsp[-1].valString))*sizeof(char) + strlen((yyvsp[-2].valString))*sizeof(char));
                memset(final, 0, sizeof(final));
                strcat(final, (yyvsp[-2].valString));
                strcat(final, (yyvsp[-1].valString));
                strcat(final, ";");

                (yyval.valString) = final;
        }
#line 2459 "scanner.tab.c"
    break;

  case 59: /* line_program: RETURN exp SEMICOLON  */
#line 718 "scanner.y"
                               {
                char * final = malloc(strlen((yyvsp[-1].valString))*sizeof(char) );
                memset(final, 0 , sizeof(final));
                
                strcat(final, (yyvsp[-1].valString));
                (yyval.valString)=final;
                
        }
#line 2472 "scanner.tab.c"
    break;

  case 60: /* line_program: fvardef  */
#line 726 "scanner.y"
                 {
                char * final = malloc(strlen((yyvsp[0].valString))*sizeof(char)  + sizeof("\n"));
                memset(final,0,sizeof(final));
                strcat(final,(yyvsp[0].valString));
                strcat(final,"\n");

                
                (yyval.valString) = final;
                
        }
#line 2487 "scanner.tab.c"
    break;

  case 61: /* array: values COMMA array  */
#line 740 "scanner.y"
                          {
                char * final = malloc(strlen((yyvsp[-2].valString))*sizeof(char) + strlen((yyvsp[0].valString))*sizeof(char)) ;
                memset(final,0,sizeof(final));

                strcat(final,(yyvsp[-2].valString));
                strcat(final,",");
                strcat(final,(yyvsp[0].valString));
                (yyval.valString) = final;

        }
#line 2502 "scanner.tab.c"
    break;

  case 62: /* array: values  */
#line 750 "scanner.y"
               {
                (yyval.valString) = (yyvsp[0].valString);
        }
#line 2510 "scanner.tab.c"
    break;

  case 63: /* precontentWrite: contentWrite  */
#line 755 "scanner.y"
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
#line 2581 "scanner.tab.c"
    break;

  case 64: /* precontentWrite: contentWrite LOWER LOWER ENDL  */
#line 821 "scanner.y"
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
#line 2645 "scanner.tab.c"
    break;

  case 65: /* contentWrite: contentWrite LOWER LOWER QUOTESTRING  */
#line 884 "scanner.y"
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
#line 2668 "scanner.tab.c"
    break;

  case 66: /* contentWrite: contentWrite LOWER LOWER STRINGV  */
#line 902 "scanner.y"
                                         {
                char * final = malloc(strlen((yyvsp[-3].valString)) * sizeof(char) + strlen((yyvsp[0].valString)) * sizeof(char) + strlen("{}") * sizeof(char)); 
                memset(final, 0, sizeof(final));

                strcat(printV,(yyvsp[0].valString));
                strcat(printV,",");

                
                strcat(final, (yyvsp[-3].valString));
                deleteQuotes(final);
                (yyval.valString) = final;
        }
#line 2685 "scanner.tab.c"
    break;

  case 67: /* contentWrite: contentWrite PLUS QUOTESTRING  */
#line 914 "scanner.y"
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
#line 2708 "scanner.tab.c"
    break;

  case 68: /* contentWrite: contentWrite PLUS STRINGV  */
#line 932 "scanner.y"
                                  {
                char * final = malloc(strlen((yyvsp[-2].valString)) * sizeof(char) + strlen((yyvsp[0].valString)) * sizeof(char) + strlen("{}") * sizeof(char)); 
                memset(final, 0, sizeof(final));

                strcat(printV,(yyvsp[0].valString));
                strcat(printV,",");

                
                strcat(final, (yyvsp[-2].valString));
                deleteQuotes(final);
                (yyval.valString) = (yyvsp[-2].valString);
        }
#line 2725 "scanner.tab.c"
    break;

  case 69: /* contentWrite: QUOTESTRING  */
#line 945 "scanner.y"
                      {

                (yyval.valString) = (yyvsp[0].valString);}
#line 2733 "scanner.tab.c"
    break;

  case 70: /* contentWrite: STRINGV  */
#line 948 "scanner.y"
                  {
                (yyval.valString) = (yyvsp[0].valString);}
#line 2740 "scanner.tab.c"
    break;

  case 71: /* assignation: STRINGV EQ exp SEMICOLON  */
#line 953 "scanner.y"
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
#line 2756 "scanner.tab.c"
    break;

  case 72: /* assignation: STRINGV EQ exp  */
#line 964 "scanner.y"
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
#line 2771 "scanner.tab.c"
    break;

  case 73: /* exp: exp operand term  */
#line 1014 "scanner.y"
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
#line 2789 "scanner.tab.c"
    break;

  case 74: /* exp: term  */
#line 1027 "scanner.y"
              {
        	(yyval.valString) = (yyvsp[0].valString);
			}
#line 2797 "scanner.tab.c"
    break;

  case 75: /* term: atom  */
#line 1034 "scanner.y"
             {
                (yyval.valString) = (yyvsp[0].valString);}
#line 2804 "scanner.tab.c"
    break;

  case 76: /* term: LPAREN exp RPAREN  */
#line 1036 "scanner.y"
                            {
                char * final = malloc(strlen((yyvsp[-1].valString)) * sizeof(char) + sizeof("()") + 1);
                memset(final, 0, sizeof(final));
                strcpy(final, "(");
                strcat(final, (yyvsp[-1].valString));
                strcat(final, ")");
                free((yyvsp[-1].valString));
                (yyval.valString) = final;
                }
#line 2818 "scanner.tab.c"
    break;

  case 77: /* term: HYPHEN atom  */
#line 1045 "scanner.y"
                      {
                char * final = malloc(strlen((yyvsp[0].valString)) * sizeof(char) + sizeof("-()") + 1);
                memset(final, 0, sizeof(final));
                strcpy(final, "-(");
                strcat(final, (yyvsp[0].valString));
                strcat(final, ")");
                free((yyvsp[0].valString));
                (yyval.valString) = final;
                }
#line 2832 "scanner.tab.c"
    break;

  case 78: /* term: EX exp  */
#line 1054 "scanner.y"
                 {
                char * final = malloc(strlen((yyvsp[0].valString)) * sizeof(char) + sizeof("!()") + 1);
                memset(final, 0, sizeof(final));
                strcpy(final, "!(");
                strcat(final, (yyvsp[0].valString));
                strcat(final, ")");
                free((yyvsp[0].valString));
                (yyval.valString) = final;
                }
#line 2846 "scanner.tab.c"
    break;

  case 79: /* operand: PLUS  */
#line 1066 "scanner.y"
             {
                (yyval.valString) = strdup(" + ");
        }
#line 2854 "scanner.tab.c"
    break;

  case 80: /* operand: PLUS EQ  */
#line 1069 "scanner.y"
                 {(yyval.valString) = strdup(" += ");}
#line 2860 "scanner.tab.c"
    break;

  case 81: /* operand: HYPHEN  */
#line 1070 "scanner.y"
                {(yyval.valString) = strdup(" - ");}
#line 2866 "scanner.tab.c"
    break;

  case 82: /* operand: HYPHEN EQ  */
#line 1071 "scanner.y"
                   {(yyval.valString) = strdup(" -= ");}
#line 2872 "scanner.tab.c"
    break;

  case 83: /* operand: PROD  */
#line 1072 "scanner.y"
              {(yyval.valString) = strdup(" * ");}
#line 2878 "scanner.tab.c"
    break;

  case 84: /* operand: DIV  */
#line 1073 "scanner.y"
             {(yyval.valString) = strdup(" / ");}
#line 2884 "scanner.tab.c"
    break;

  case 85: /* operand: DIVINT  */
#line 1074 "scanner.y"
                {(yyval.valString) = strdup(" / ");}
#line 2890 "scanner.tab.c"
    break;

  case 86: /* operand: MOD  */
#line 1075 "scanner.y"
             {(yyval.valString) = strdup(" % ");}
#line 2896 "scanner.tab.c"
    break;

  case 87: /* operand: LOWER  */
#line 1076 "scanner.y"
               {(yyval.valString) = strdup(" < ");}
#line 2902 "scanner.tab.c"
    break;

  case 88: /* operand: HIGHER  */
#line 1077 "scanner.y"
                {(yyval.valString) = strdup(" > ");}
#line 2908 "scanner.tab.c"
    break;

  case 89: /* operand: LOWER EQ  */
#line 1078 "scanner.y"
                  {(yyval.valString) = strdup(" <= ");}
#line 2914 "scanner.tab.c"
    break;

  case 90: /* operand: HIGHER EQ  */
#line 1079 "scanner.y"
                   {(yyval.valString) = strdup(" >= ");}
#line 2920 "scanner.tab.c"
    break;

  case 91: /* operand: EQ  */
#line 1080 "scanner.y"
            {(yyval.valString) = strdup(" == ");}
#line 2926 "scanner.tab.c"
    break;

  case 92: /* operand: AND  */
#line 1081 "scanner.y"
             {(yyval.valString) = strdup(" && ");}
#line 2932 "scanner.tab.c"
    break;

  case 93: /* operand: PLUS PLUS  */
#line 1082 "scanner.y"
                   {(yyval.valString) = strdup(" ++ ");}
#line 2938 "scanner.tab.c"
    break;

  case 94: /* operand: OR  */
#line 1083 "scanner.y"
           {(yyval.valString) = strdup(" || ");}
#line 2944 "scanner.tab.c"
    break;

  case 95: /* atom: STRINGV  */
#line 1088 "scanner.y"
                {
			/*if (!checkName(&typelist, $1)){
                        printf("Error: Variable %s no declarada\n", $1);
                        yyclearin;
                        exit(0);
            }
            $$ = $1;*/
		}
#line 2957 "scanner.tab.c"
    break;

  case 96: /* atom: values  */
#line 1096 "scanner.y"
                 {
                        
			(yyval.valString) = (yyvsp[0].valString);
		}
#line 2966 "scanner.tab.c"
    break;


#line 2970 "scanner.tab.c"

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

#line 1102 "scanner.y"


char * obtenerTipo(int valor) {
    char * tipo;
    switch (valor) {
        case 0: tipo = "i32 "; break;
        case 1: tipo = "i16 "; break;
        case 2: tipo = "i64 "; break;
        case 3: tipo = "u32 "; break;
        case 4: tipo = "u16 "; break;
        case 5: tipo = "u64 "; break;
        case 6: tipo = "f32 "; break;
        case 7: tipo = "f64 "; break;
        case 8: tipo = "String "; break;
        case 9: tipo = "char "; break;
        case 10: tipo = "bool "; break;
        default: tipo = ""; break;
    }
    return tipo;
}

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
void yyerror(const char* msg) {
    fprintf(stderr, "Error: %s\n", msg);
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
