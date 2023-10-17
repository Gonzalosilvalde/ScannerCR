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
#include <pthread.h>
#include <unistd.h>
#include <omp.h>
#include "list.h"
#include "scanner.tab.h"

typedef struct yy_buffer_state * YY_BUFFER_STATE;
extern int yylex(void); 
extern int yylineno;
extern char *yytext;
extern void yyrestart( FILE *new_file );
extern void yy_flush_buffer( YY_BUFFER_STATE buffer );
extern void yy_switch_to_buffer( YY_BUFFER_STATE new_buffer );
extern YY_BUFFER_STATE yy_create_buffer( FILE *file, int size );
extern YY_BUFFER_STATE yy_current_buffer();
extern void yypush_buffer_state ( YY_BUFFER_STATE new_buffer  );
extern void yypop_buffer_state ( void );
pthread_mutex_t mutex;
pthread_mutex_t file_mutex;
extern FILE *yyin;
char filePath[100] ;
char filePathOld[100];

int global_argc; // Variable global para almacenar argc
char **global_argv; // Variable global para almacenar argv

char **arrayCabeceras = NULL;
int arraySize = 0;

char sizeS[8] = "200";

const char *nombreArchivo = "cabeceras.txt";

//typeList será la tabla de tipos y constantes.
TypeList typelist;
TypeList flist;
char gType[10] = "";
//queue será la cola a través de la cual recogeremos y volcaremos las variables de los printf 
NodeList queue;
char printV[100]= "";
//int comienzo ( int argc, char * argv[]);
void yyerror(char const *);
char * getVariables(TypeList *);
void saveGType(char *tipo);
char *getGType();
char *insertTabsBetweenBraces(char *code);
char * getEndings(NodeList *);
void custom_function();
char * getEndingsR(NodeList *);
char * obtenerTipo(int valor);
void replaceSemicolon(char *string);
char * getRef (int);
void deleteQuotes (char *);
char *reemplazar(const char *cadena, const char *busqueda, const char *reemplazo);
void deleteCurly(char *);
void deleteNewLines(char *);
char* getEndNumber(char* number);
int searchString(char **arr, char *toFind, int size);

#line 137 "scanner.tab.c"

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
  YYSYMBOL_VOID = 53,                      /* VOID  */
  YYSYMBOL_OPENCURLYBRACKET = 54,          /* OPENCURLYBRACKET  */
  YYSYMBOL_CLOSECURLYBRACKET = 55,         /* CLOSECURLYBRACKET  */
  YYSYMBOL_BOOLEAN = 56,                   /* BOOLEAN  */
  YYSYMBOL_CHAR = 57,                      /* CHAR  */
  YYSYMBOL_PRINTF = 58,                    /* PRINTF  */
  YYSYMBOL_SCANF = 59,                     /* SCANF  */
  YYSYMBOL_STRING = 60,                    /* STRING  */
  YYSYMBOL_STRINGV = 61,                   /* STRINGV  */
  YYSYMBOL_QUOTESTRING = 62,               /* QUOTESTRING  */
  YYSYMBOL_TRUEVAL = 63,                   /* TRUEVAL  */
  YYSYMBOL_FALSEVAL = 64,                  /* FALSEVAL  */
  YYSYMBOL_INTNUM = 65,                    /* INTNUM  */
  YYSYMBOL_REALNUM = 66,                   /* REALNUM  */
  YYSYMBOL_RETURN = 67,                    /* RETURN  */
  YYSYMBOL_STRUCT = 68,                    /* STRUCT  */
  YYSYMBOL_EX = 69,                        /* EX  */
  YYSYMBOL_YYACCEPT = 70,                  /* $accept  */
  YYSYMBOL_S = 71,                         /* S  */
  YYSYMBOL_comment = 72,                   /* comment  */
  YYSYMBOL_cabecera = 73,                  /* cabecera  */
  YYSYMBOL_constdef = 74,                  /* constdef  */
  YYSYMBOL_vardef = 75,                    /* vardef  */
  YYSYMBOL_type = 76,                      /* type  */
  YYSYMBOL_values = 77,                    /* values  */
  YYSYMBOL_preprograma = 78,               /* preprograma  */
  YYSYMBOL_programa = 79,                  /* programa  */
  YYSYMBOL_args = 80,                      /* args  */
  YYSYMBOL_lines_program = 81,             /* lines_program  */
  YYSYMBOL_line_program = 82,              /* line_program  */
  YYSYMBOL_array = 83,                     /* array  */
  YYSYMBOL_precontentWrite = 84,           /* precontentWrite  */
  YYSYMBOL_contentWrite = 85,              /* contentWrite  */
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
#define YYLAST   1346

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  108
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  254

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   324


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
      65,    66,    67,    68,    69
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   170,   170,   221,   224,   229,   230,   231,   263,   264,
     265,   299,   301,   309,   321,   332,   346,   363,   375,   390,
     405,   449,   492,   503,   512,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   558,   561,
     562,   563,   564,   568,   576,   585,   632,   678,   681,   691,
     702,   705,   710,   726,   736,   751,   765,   777,   788,   793,
     797,   811,   821,   834,   846,   855,   875,   898,   913,   926,
     927,   936,   944,   951,   961,   971,   989,   998,  1004,  1069,
    1132,  1150,  1163,  1166,  1192,  1194,  1203,  1212,  1221,  1232,
    1235,  1236,  1237,  1238,  1239,  1240,  1241,  1242,  1243,  1244,
    1245,  1246,  1247,  1248,  1249,  1250,  1255,  1259,  1263
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
  "VOID", "OPENCURLYBRACKET", "CLOSECURLYBRACKET", "BOOLEAN", "CHAR",
  "PRINTF", "SCANF", "STRING", "STRINGV", "QUOTESTRING", "TRUEVAL",
  "FALSEVAL", "INTNUM", "REALNUM", "RETURN", "STRUCT", "EX", "$accept",
  "S", "comment", "cabecera", "constdef", "vardef", "type", "values",
  "preprograma", "programa", "args", "lines_program", "line_program",
  "array", "precontentWrite", "contentWrite", "term", "operand", "atom", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-161)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       4,   -17,    47,   956,    16,     4,  -161,  -161,  -161,  1124,
      19,  -161,  -161,  -161,  -161,  -161,  -161,  -161,  -161,  -161,
    -161,  -161,  -161,  1058,    21,  -161,   956,   956,    29,   956,
    -161,    -4,  -161,    32,    35,    51,  -161,  -161,    31,    43,
      -9,   -12,  -161,  -161,  -161,  -161,  1100,    68,  -161,   870,
      56,  -161,  -161,    61,  -161,     4,    59,  -161,    74,  -161,
    -161,  -161,  -161,  -161,  -161,  -161,  -161,  -161,  -161,  -161,
    -161,  -161,    62,  -161,   114,   870,    69,   870,  -161,  1290,
    -161,   854,  1100,   902,   980,     3,  -161,  -161,   103,    51,
      30,  -161,  1175,   114,  -161,  1100,   870,    88,    92,    77,
     112,    97,    -8,    98,    99,  1031,    89,    79,  -161,  -161,
     184,  -161,  1316,  -161,    12,  1071,     5,   -13,   102,   116,
     106,     4,   100,  -161,   115,  -161,  1086,   870,  1124,   854,
     139,   870,   122,   854,   -10,   -10,   121,   886,  -161,  1099,
     108,   120,  -161,   105,  1100,  -161,  -161,   854,   104,   144,
     119,   870,   -15,  -161,  -161,  -161,  -161,  1198,   123,   251,
     -10,  1221,   870,   127,  -161,  -161,   145,    50,   146,   147,
    -161,  -161,   854,  -161,   149,   154,  1303,  -161,   318,   167,
    1124,   854,  1114,   142,  -161,   143,   168,   197,   158,   150,
    1244,  -161,   161,   186,    25,   164,  -161,   385,  -161,   165,
     870,  -161,  1124,  -161,   452,  -161,   870,   854,   148,   172,
    -161,   854,   157,  -161,   203,  -161,  -161,  -161,   170,  -161,
    -161,  -161,  -161,   162,   519,   174,   870,   586,   854,  -161,
    -161,   175,  -161,   870,  1267,  -161,   653,  -161,   954,   177,
    -161,  1100,  1316,  -161,   183,   185,   173,   204,   854,   854,
     720,   787,  -161,  -161
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     7,     1,     3,     4,     0,
       0,    25,    26,    27,    28,    29,    30,    31,    32,    36,
      35,    34,    33,     0,     0,    51,     0,     0,     0,     2,
      44,     0,    10,     0,     0,     0,   103,   105,    98,    99,
      89,    91,    94,    95,    96,    97,     0,     0,    24,     0,
      37,    50,    48,     0,    43,     5,     0,    37,     0,    42,
      38,    39,    40,    41,    11,   100,   101,   104,    90,    93,
      92,    23,     0,   102,     0,     0,   106,     0,   107,     0,
      84,     0,     0,     0,     0,     0,    13,     8,     0,     0,
       0,    86,     0,     0,    87,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   106,     0,     0,    69,    73,
       0,    57,    74,    20,   106,     0,     0,     0,     0,     0,
       0,     6,     0,    85,     0,    22,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    72,     0,
      37,     0,    56,     0,     0,    15,    47,     0,     0,    53,
       0,     0,     0,     9,    12,   108,    88,     0,     0,     0,
       0,     0,     0,     0,    83,    82,     0,    78,     0,     0,
      70,    71,     0,    49,     0,     0,    77,    21,     0,    55,
       0,     0,     0,     0,    14,     0,     0,     0,     0,     0,
       0,    64,     0,     0,     0,     0,    61,     0,    19,     0,
       0,    46,     0,    52,     0,    17,     0,     0,     0,     0,
      58,     0,     0,    59,     0,    81,    80,    60,     0,    18,
      76,    54,    45,     0,     0,     0,     0,     0,     0,    79,
      75,     0,    68,     0,     0,    62,     0,    16,     0,     0,
      63,     0,     0,    67,     0,     0,     0,     0,     0,     0,
       0,     0,    66,    65
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -161,  -161,     9,     0,  -161,    -3,     1,   -33,  -161,    80,
    -160,  -110,  -102,  -125,  -121,  -161,   -43,   -22,   -52
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,   108,     3,    26,   109,    72,    78,    29,    30,
     118,   110,   111,   175,   166,   167,   112,    96,    80
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      27,    49,    64,     4,    28,    32,    79,   132,   142,    69,
      34,   148,    25,    67,   168,   183,     1,    55,    70,   159,
     203,    68,    91,    27,    27,    56,    27,    28,    28,   184,
      28,   163,    92,   120,    94,    25,    25,   178,    25,   188,
     115,   124,   221,    71,   119,     5,   133,     6,   149,   146,
     143,   164,   165,   126,    93,    87,   122,   142,    82,   147,
      83,    65,   197,   139,    76,    59,    60,    61,    62,    63,
     193,   204,    85,    66,    86,   220,   142,    31,   194,   113,
      35,   223,    50,   137,   157,   117,   215,   216,   161,    82,
      53,    83,   125,    57,    79,   142,    58,   224,    73,    84,
     176,   227,   142,    85,    89,    86,    51,    52,   182,    54,
      81,    93,    74,    59,    60,    61,    62,    63,   236,   190,
      88,   153,   142,    90,   121,   142,   127,    75,    74,   158,
     128,   129,   130,   138,   142,   131,   134,   135,   250,   251,
     140,   177,   150,    75,   154,   174,   151,   152,   142,   142,
      76,    59,    60,    61,    62,    63,   155,   176,    77,   160,
     162,   169,   172,   176,   173,   179,    76,    59,    60,    61,
      62,    63,   180,   181,    77,    76,    59,    60,    61,    62,
      63,   117,   191,   234,   186,   192,   195,    97,    98,    99,
     238,   196,   100,   198,   199,   202,   206,   207,   208,   101,
     209,   102,   210,   117,   211,   213,   214,    74,   217,   219,
     226,   228,   229,   225,   230,     7,     8,   231,   233,   237,
     245,   243,    75,   246,     0,   247,     0,   248,     0,    11,
      12,    13,    14,    15,    16,    17,    18,    19,   244,   141,
      20,    21,   103,   104,    22,   105,    59,    60,    61,    62,
      63,   106,   107,    77,    97,    98,    99,     0,   249,   100,
       0,     0,     0,     0,     0,     0,   101,     0,   102,     0,
       0,     0,     0,     0,    74,     0,     0,     0,     0,     0,
       0,     0,     7,     8,     0,     0,     0,     0,     0,    75,
       0,     0,     0,     0,     0,     0,    11,    12,    13,    14,
      15,    16,    17,    18,    19,     0,   187,    20,    21,   103,
     104,    22,   105,    59,    60,    61,    62,    63,   106,   107,
      77,    97,    98,    99,     0,     0,   100,     0,     0,     0,
       0,     0,     0,   101,     0,   102,     0,     0,     0,     0,
       0,    74,     0,     0,     0,     0,     0,     0,     0,     7,
       8,     0,     0,     0,     0,     0,    75,     0,     0,     0,
       0,     0,     0,    11,    12,    13,    14,    15,    16,    17,
      18,    19,     0,   201,    20,    21,   103,   104,    22,   105,
      59,    60,    61,    62,    63,   106,   107,    77,    97,    98,
      99,     0,     0,   100,     0,     0,     0,     0,     0,     0,
     101,     0,   102,     0,     0,     0,     0,     0,    74,     0,
       0,     0,     0,     0,     0,     0,     7,     8,     0,     0,
       0,     0,     0,    75,     0,     0,     0,     0,     0,     0,
      11,    12,    13,    14,    15,    16,    17,    18,    19,     0,
     218,    20,    21,   103,   104,    22,   105,    59,    60,    61,
      62,    63,   106,   107,    77,    97,    98,    99,     0,     0,
     100,     0,     0,     0,     0,     0,     0,   101,     0,   102,
       0,     0,     0,     0,     0,    74,     0,     0,     0,     0,
       0,     0,     0,     7,     8,     0,     0,     0,     0,     0,
      75,     0,     0,     0,     0,     0,     0,    11,    12,    13,
      14,    15,    16,    17,    18,    19,     0,   222,    20,    21,
     103,   104,    22,   105,    59,    60,    61,    62,    63,   106,
     107,    77,    97,    98,    99,     0,     0,   100,     0,     0,
       0,     0,     0,     0,   101,     0,   102,     0,     0,     0,
       0,     0,    74,     0,     0,     0,     0,     0,     0,     0,
       7,     8,     0,     0,     0,     0,     0,    75,     0,     0,
       0,     0,     0,     0,    11,    12,    13,    14,    15,    16,
      17,    18,    19,     0,   232,    20,    21,   103,   104,    22,
     105,    59,    60,    61,    62,    63,   106,   107,    77,    97,
      98,    99,     0,     0,   100,     0,     0,     0,     0,     0,
       0,   101,     0,   102,     0,     0,     0,     0,     0,    74,
       0,     0,     0,     0,     0,     0,     0,     7,     8,     0,
       0,     0,     0,     0,    75,     0,     0,     0,     0,     0,
       0,    11,    12,    13,    14,    15,    16,    17,    18,    19,
       0,   235,    20,    21,   103,   104,    22,   105,    59,    60,
      61,    62,    63,   106,   107,    77,    97,    98,    99,     0,
       0,   100,     0,     0,     0,     0,     0,     0,   101,     0,
     102,     0,     0,     0,     0,     0,    74,     0,     0,     0,
       0,     0,     0,     0,     7,     8,     0,     0,     0,     0,
       0,    75,     0,     0,     0,     0,     0,     0,    11,    12,
      13,    14,    15,    16,    17,    18,    19,     0,   240,    20,
      21,   103,   104,    22,   105,    59,    60,    61,    62,    63,
     106,   107,    77,    97,    98,    99,     0,     0,   100,     0,
       0,     0,     0,     0,     0,   101,     0,   102,     0,     0,
       0,     0,     0,    74,     0,     0,     0,     0,     0,     0,
       0,     7,     8,     0,     0,     0,     0,     0,    75,     0,
       0,     0,     0,     0,     0,    11,    12,    13,    14,    15,
      16,    17,    18,    19,     0,   252,    20,    21,   103,   104,
      22,   105,    59,    60,    61,    62,    63,   106,   107,    77,
      97,    98,    99,     0,     0,   100,     0,     0,     0,     0,
       0,     0,   101,     0,   102,     0,     0,     0,     0,     0,
      74,     0,     0,     0,     0,     0,     0,     0,     7,     8,
       0,     0,     0,     0,     0,    75,     0,     0,     0,     0,
       0,     0,    11,    12,    13,    14,    15,    16,    17,    18,
      19,     0,   253,    20,    21,   103,   104,    22,   105,    59,
      60,    61,    62,    63,   106,   107,    77,    97,    98,    99,
       0,     0,   100,     0,     0,     0,     0,     0,     0,   101,
       0,   102,     0,     0,     0,     0,     0,    74,     0,     0,
       0,     0,     0,     0,     0,     7,     8,     0,     0,     0,
       0,     0,    75,    74,     0,     0,     0,     0,     0,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    75,    74,
      20,    21,   103,   104,    22,   105,    59,    60,    61,    62,
      63,   106,   107,    77,    75,    74,     0,     0,     0,     0,
     170,    76,    59,    60,    61,    62,    63,     0,     0,    77,
      75,     0,     0,     0,     0,     0,     0,    76,    59,    60,
      61,    62,    63,     0,     0,    77,     0,     0,     0,     0,
       0,     0,     0,   114,    59,    60,    61,    62,    63,     0,
       0,    77,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,     0,     0,    47,     0,     0,     7,     8,     0,
       9,    10,     0,     0,     0,     0,     0,     0,   241,     0,
       0,    11,    12,    13,    14,    15,    16,    17,    18,    19,
       0,     0,    20,    21,     0,   242,    22,    23,     0,     0,
     116,     0,     0,     0,    24,    11,    12,    13,    14,    15,
      16,    17,    18,    19,     0,     0,    20,    21,     0,     0,
      22,     0,     0,     0,     0,     0,     0,     0,    33,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
       0,    47,     0,     0,     0,     0,     0,     0,     0,   136,
       0,     0,     0,    93,     0,    48,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,     0,    47,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,   144,
       0,    47,    48,     0,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,     0,   145,    47,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,     0,     0,    47,
     156,     0,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,     0,   171,    47,    11,    12,    13,    14,    15,
      16,    17,    18,    19,     0,     0,    20,    21,   205,     0,
      22,    23,     0,     0,     0,     0,     0,     0,    33,    11,
      12,    13,    14,    15,    16,    17,    18,    19,     0,     0,
      20,    21,     0,     0,    22,     0,     0,     0,     0,     0,
       0,     0,    33,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,     0,     0,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   123,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,     0,     0,    47,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   185,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,     0,
       0,    47,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   189,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,     0,     0,    47,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   212,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,     0,     0,    47,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   239,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    95,     0,
      47,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,   200,     0,    47,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,     0,     0,    47
};

static const yytype_int16 yycheck[] =
{
       3,    23,    35,    20,     3,     5,    49,    15,   110,    21,
       9,    24,     3,    22,   135,    30,    12,    21,    30,   129,
     180,    30,    74,    26,    27,    29,    29,    26,    27,    44,
      29,   133,    75,    85,    77,    26,    27,   147,    29,   160,
      83,    93,   202,    46,    41,    62,    54,     0,    61,    44,
      38,    61,    62,    96,    42,    55,    89,   159,    28,    54,
      30,    30,   172,   106,    61,    62,    63,    64,    65,    66,
      20,   181,    42,    30,    44,   200,   178,    61,    28,    82,
      61,   206,    61,   105,   127,    84,    61,    62,   131,    28,
      61,    30,    95,    61,   137,   197,    61,   207,    30,    38,
     143,   211,   204,    42,    30,    44,    26,    27,   151,    29,
      54,    42,    23,    62,    63,    64,    65,    66,   228,   162,
      61,   121,   224,    61,    21,   227,    38,    38,    23,   128,
      38,    54,    20,    44,   236,    38,    38,    38,   248,   249,
      61,   144,    40,    38,    44,    40,    30,    41,   250,   251,
      61,    62,    63,    64,    65,    66,    41,   200,    69,    20,
      38,    40,    54,   206,    44,    61,    61,    62,    63,    64,
      65,    66,    28,    54,    69,    61,    62,    63,    64,    65,
      66,   180,    55,   226,    61,    40,    40,     3,     4,     5,
     233,    44,     8,    44,    40,    28,    54,    54,    30,    15,
       3,    17,    44,   202,    54,    44,    20,    23,    44,    44,
      38,    54,     9,    65,    44,    31,    32,    55,    44,    44,
     242,    44,    38,    40,    -1,    40,    -1,    54,    -1,    45,
      46,    47,    48,    49,    50,    51,    52,    53,   241,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,     3,     4,     5,    -1,    54,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,    17,    -1,
      -1,    -1,    -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    32,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,     3,     4,     5,    -1,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    -1,    17,    -1,    -1,    -1,    -1,
      -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      32,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,     3,     4,
       5,    -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    -1,    17,    -1,    -1,    -1,    -1,    -1,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    -1,
      -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,     3,     4,     5,    -1,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,    17,
      -1,    -1,    -1,    -1,    -1,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    32,    -1,    -1,    -1,    -1,    -1,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,     3,     4,     5,    -1,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    -1,    17,    -1,    -1,    -1,
      -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    32,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,     3,
       4,     5,    -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    -1,    17,    -1,    -1,    -1,    -1,    -1,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    -1,
      -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,     3,     4,     5,    -1,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,
      17,    -1,    -1,    -1,    -1,    -1,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    32,    -1,    -1,    -1,    -1,
      -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,     3,     4,     5,    -1,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    -1,    17,    -1,    -1,
      -1,    -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,    -1,    -1,    -1,    -1,    -1,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
       3,     4,     5,    -1,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    -1,    17,    -1,    -1,    -1,    -1,    -1,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,
      -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,     3,     4,     5,
      -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      -1,    17,    -1,    -1,    -1,    -1,    -1,    23,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    -1,    -1,
      -1,    -1,    38,    23,    -1,    -1,    -1,    -1,    -1,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    38,    23,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    38,    23,    -1,    -1,    -1,    -1,
      44,    61,    62,    63,    64,    65,    66,    -1,    -1,    69,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,    63,
      64,    65,    66,    -1,    -1,    69,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    61,    62,    63,    64,    65,    66,    -1,
      -1,    69,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    -1,    30,    -1,    -1,    31,    32,    -1,
      34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    44,    -1,
      -1,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    -1,    56,    57,    -1,    61,    60,    61,    -1,    -1,
      40,    -1,    -1,    -1,    68,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    -1,    56,    57,    -1,    -1,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    -1,    -1,    42,    -1,    44,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    -1,    30,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      -1,    30,    44,    -1,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    -1,    44,    30,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    -1,    -1,    30,
      44,    -1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    44,    30,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    -1,    56,    57,    44,    -1,
      60,    61,    -1,    -1,    -1,    -1,    -1,    -1,    68,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    -1,
      56,    57,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    68,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    -1,    -1,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    40,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,    -1,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    -1,
      -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    40,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    -1,    -1,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    -1,
      30,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    -1,    30,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    -1,    -1,    30
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    12,    71,    73,    20,    62,     0,    31,    32,    34,
      35,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      56,    57,    60,    61,    68,    72,    74,    75,    76,    78,
      79,    61,    73,    68,    76,    61,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    30,    44,    87,
      61,    79,    79,    61,    79,    21,    29,    61,    61,    62,
      63,    64,    65,    66,    77,    30,    30,    22,    30,    21,
      30,    75,    76,    30,    23,    38,    61,    69,    77,    86,
      88,    54,    28,    30,    38,    42,    44,    73,    61,    30,
      61,    88,    86,    42,    86,    28,    87,     3,     4,     5,
       8,    15,    17,    58,    59,    61,    67,    68,    72,    75,
      81,    82,    86,    75,    61,    86,    40,    76,    80,    41,
      88,    21,    77,    40,    88,    75,    86,    38,    38,    54,
      20,    38,    15,    54,    38,    38,    38,    87,    44,    86,
      61,    55,    82,    38,    28,    44,    44,    54,    24,    61,
      40,    30,    41,    73,    44,    41,    44,    86,    76,    81,
      20,    86,    38,    82,    61,    62,    84,    85,    84,    40,
      44,    44,    54,    44,    40,    83,    86,    75,    81,    61,
      28,    54,    86,    30,    44,    40,    61,    55,    84,    40,
      86,    55,    40,    20,    28,    40,    44,    81,    44,    40,
      28,    55,    28,    80,    81,    44,    54,    54,    30,     3,
      44,    54,    40,    44,    20,    61,    62,    44,    55,    44,
      83,    80,    55,    83,    81,    65,    38,    81,    54,     9,
      44,    55,    55,    44,    86,    55,    81,    44,    86,    40,
      55,    44,    61,    44,    75,    87,    40,    40,    54,    54,
      81,    81,    55,    55
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    70,    71,    72,    72,    73,    73,    73,    73,    73,
      73,    74,    74,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    77,    77,
      77,    77,    77,    78,    78,    79,    79,    79,    79,    79,
      79,    79,    80,    80,    80,    80,    81,    81,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    83,    83,    84,    84,
      85,    85,    85,    85,    86,    86,    86,    86,    86,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    88,    88,    88
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     4,     6,     2,     5,     7,
       3,     3,     6,     3,     6,     5,    10,     7,     8,     7,
       4,     6,     5,     3,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     2,     1,     8,     7,     5,     2,     6,
       2,     1,     4,     2,     5,     3,     2,     1,     5,     5,
       5,     4,     7,     8,     4,    14,    14,     9,     7,     1,
       3,     3,     2,     1,     1,     6,     3,     1,     1,     4,
       3,     3,     1,     1,     1,     3,     2,     2,     4,     1,
       2,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     1,     2,     1,     1,     1,     4
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
  case 2: /* S: cabecera preprograma  */
#line 170 "scanner.y"
                             { 
                char* entrada = (char*)malloc(strlen(filePath) + 1); // Asignar memoria para la cadena
                memset(entrada, 0 , sizeof(entrada));
                printf("filepath: %s\n", filePath );
                
                strcpy(entrada, filePath);
                printf("entrada: %s\n", entrada );
                char salida[100]; // Puedes ajustar el tamaño del buffer según tus necesidades

                // Encontrar la posición del primer '/' desde el final de la cadena
                char* lastSlash = strrchr(entrada, '/');
                printf("lastSlash: %s\n", lastSlash );


                // Si lastSlash no es NULL, significa que se ha encontrado el caracter '/'
                if (lastSlash) {
                        // Calcular la longitud de la subcadena a partir del último '/'
                        size_t length = strlen(lastSlash + 1);
                        
                        // Copiar la subcadena a 'salida' y sustituir la extensión
                        strcpy(salida, "salida"); // Copiar "salida/" a la cadena 'salida'
                        strncat(salida, lastSlash, length - 1); // Agregar la subcadena 'hola' sin la extensión
                        strcat(salida, ".rs"); // Agregar la extensión ".rs" al final

                        printf("sal   %s\n", salida); // Imprimir el resultado
                } else {
                        printf("No se ha encontrado '/' en la cadena de entrada.\n");
                }

                free(entrada);
                printf("%s", salida);
                FILE *fp = fopen(salida, "w");

                if (fp != NULL) {
                        char *resultado = insertTabsBetweenBraces((yyvsp[0].valString));
                        if (resultado != NULL) {

                                fputs(resultado, fp);
                                fclose(fp);
                                
                        }
                }
                
                
        }
#line 1906 "scanner.tab.c"
    break;

  case 3: /* comment: COMMENTLINE  */
#line 221 "scanner.y"
                     {
                (yyval.valString) = (yyvsp[0].valString);
                }
#line 1914 "scanner.tab.c"
    break;

  case 4: /* comment: MULTILINE  */
#line 224 "scanner.y"
                    {;}
#line 1920 "scanner.tab.c"
    break;

  case 5: /* cabecera: PROGRAM LOWER STRINGV HIGHER  */
#line 229 "scanner.y"
                                        {(yyval.valString) = "";}
#line 1926 "scanner.tab.c"
    break;

  case 6: /* cabecera: PROGRAM LOWER STRINGV DOT STRINGV HIGHER  */
#line 230 "scanner.y"
                                                          {(yyval.valString) = "";}
#line 1932 "scanner.tab.c"
    break;

  case 7: /* cabecera: PROGRAM QUOTESTRING  */
#line 231 "scanner.y"
                                     {
                        #pragma omp critical
                        {       
                                char final[100] = "";
                                char fichero[50] = "";
                                strcat(fichero, (yyvsp[0].valString));
                                deleteQuotes(fichero);
                                fichero[strlen(fichero) - 2] = '\0';
                        
                                char ruta[100] = "entrada/";

                                strcat(final, fichero);
                                strcat(final, ".c");
                                printf("-----------------%s------------------ \n", final);
                                strcat(ruta, final);
                                if(searchString(arrayCabeceras, ruta, arraySize ) == 0){
                                        arraySize++;
                                        arrayCabeceras = (char**)realloc(arrayCabeceras, arraySize * sizeof(char*));
                                        arrayCabeceras[arraySize - 1] = (char*)malloc(strlen(ruta) * sizeof(char)); 

                                        strcpy(arrayCabeceras[arraySize - 1], ruta);
                                        printf("array size %i\n\n", arraySize);
                                        printf("array cabeceras %s\n\n", arrayCabeceras[arraySize - 1]);
                                        printf("ruta  %s\n\n", ruta);
                                }
                                

                        }
                        
                        
                        
                }
#line 1969 "scanner.tab.c"
    break;

  case 8: /* cabecera: PROGRAM LOWER STRINGV HIGHER cabecera  */
#line 263 "scanner.y"
                                                       {(yyval.valString) = "";}
#line 1975 "scanner.tab.c"
    break;

  case 9: /* cabecera: PROGRAM LOWER STRINGV DOT STRINGV HIGHER cabecera  */
#line 264 "scanner.y"
                                                                  {(yyval.valString) = "";}
#line 1981 "scanner.tab.c"
    break;

  case 10: /* cabecera: PROGRAM QUOTESTRING cabecera  */
#line 265 "scanner.y"
                                             {
                                                
                        #pragma omp critical
                        {       
                                char final[100] = "";
                                char fichero[50] = "";
                                strcat(fichero, (yyvsp[-1].valString));
                                deleteQuotes(fichero);
                                fichero[strlen(fichero) - 2] = '\0';
                        
                                char ruta[100] = "entrada/";

                                strcat(final, fichero);
                                strcat(final, ".c");
                                printf("-----------------%s------------------ \n", final);
                                strcat(ruta, final);
                                
                                if(searchString(arrayCabeceras, ruta, arraySize ) == 0){

                                        arraySize++;
                                        arrayCabeceras = (char**)realloc(arrayCabeceras, arraySize * sizeof(char*));
                                        arrayCabeceras[arraySize - 1] = (char*)malloc(strlen(ruta) * sizeof(char)); 

                                        strcpy(arrayCabeceras[arraySize - 1], ruta);
                                        printf("array size %i\n\n", arraySize);
                                        printf("array cabeceras %s\n\n", arrayCabeceras[arraySize - 1]);
                                        printf("ruta  %s\n\n", ruta);
                                }

                        }
                }
#line 2017 "scanner.tab.c"
    break;

  case 11: /* constdef: DEFINE STRINGV values  */
#line 299 "scanner.y"
                              {
                ;}
#line 2024 "scanner.tab.c"
    break;

  case 12: /* constdef: CONST type STRINGV EQ values SEMICOLON  */
#line 301 "scanner.y"
                                                {
                ; }
#line 2031 "scanner.tab.c"
    break;

  case 13: /* vardef: type STRINGV SEMICOLON  */
#line 309 "scanner.y"
                               {//1
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
#line 2048 "scanner.tab.c"
    break;

  case 14: /* vardef: type STRINGV LSQUAREPAREN atom RSQUAREPAREN SEMICOLON  */
#line 321 "scanner.y"
                                                               {
                char * tipo = obtenerTipo((yyvsp[-5].valInt));
                char * final = malloc(strlen(tipo)*sizeof(char) + strlen((yyvsp[-4].valString))*sizeof(char) + strlen("let\n: ;"));
                memset(final,0,sizeof(final));
                strcat(final,"let ");
                strcat(final,(yyvsp[-4].valString));
                strcat(final,":");
                strcat(final,tipo);
                strcat(final,";\n");
                (yyval.valString) = final;
        }
#line 2064 "scanner.tab.c"
    break;

  case 15: /* vardef: type STRINGV EQ term SEMICOLON  */
#line 332 "scanner.y"
                                         {//2
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
#line 2082 "scanner.tab.c"
    break;

  case 16: /* vardef: type STRINGV LSQUAREPAREN atom RSQUAREPAREN EQ OPENCURLYBRACKET array CLOSECURLYBRACKET SEMICOLON  */
#line 346 "scanner.y"
                                                                                                           {//4
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
                (yyval.valString) = final;
        }
#line 2104 "scanner.tab.c"
    break;

  case 17: /* vardef: type STRINGV LSQUAREPAREN RSQUAREPAREN EQ term SEMICOLON  */
#line 363 "scanner.y"
                                                                  {//4
                char * tipo = obtenerTipo((yyvsp[-6].valInt));
                char * final = malloc(strlen((yyvsp[-5].valString))*sizeof(char) + strlen(tipo)*sizeof(char) + strlen((yyvsp[-1].valString))*sizeof(char) + sizeof("let ::[] [] ; \n"));
                memset(final,0,sizeof(final));
                
                strcat(final,"let ");
                strcat(final,(yyvsp[-5].valString));
                strcat(final,"=");
                strcat(final,(yyvsp[-1].valString));
                strcat(final,";");
                (yyval.valString) = final;
        }
#line 2121 "scanner.tab.c"
    break;

  case 18: /* vardef: type STRINGV EQ STRINGV LPAREN array RPAREN SEMICOLON  */
#line 375 "scanner.y"
                                                               {//5
                char * tipo = obtenerTipo((yyvsp[-7].valInt));
                char * final = malloc(strlen((yyvsp[-6].valString))*sizeof(char) +strlen((yyvsp[-4].valString))*sizeof(char) + strlen(tipo)*sizeof(char) + strlen((yyvsp[-2].valString))*sizeof(char) + sizeof("let = ();"));
                memset(final,0, sizeof(final));

                strcat(final, "let ");
                strcat(final, (yyvsp[-6].valString));
                strcat(final, "=");
                strcat(final, (yyvsp[-4].valString));
                strcat(final,"(");
                strcat(final, (yyvsp[-2].valString));
                strcat(final, ");");
                (yyval.valString) = final;

        }
#line 2141 "scanner.tab.c"
    break;

  case 19: /* vardef: type STRINGV EQ STRINGV LPAREN RPAREN SEMICOLON  */
#line 390 "scanner.y"
                                                         {//6
                char * tipo = obtenerTipo((yyvsp[-6].valInt));
                char * final = malloc(strlen((yyvsp[-5].valString))*sizeof(char) +strlen((yyvsp[-3].valString))*sizeof(char) + strlen(tipo)*sizeof(char)  + sizeof("let = ();"));
                memset(final,0, sizeof(final));

                strcat(final, "let ");
                strcat(final, (yyvsp[-5].valString));
                strcat(final, "=");
                strcat(final, (yyvsp[-3].valString));
                strcat(final,"();");
        

                (yyval.valString) = final;

        }
#line 2161 "scanner.tab.c"
    break;

  case 20: /* vardef: type STRINGV COMMA vardef  */
#line 405 "scanner.y"
                                   {//7
                char * tipo = obtenerTipo((yyvsp[-3].valInt));
                strcpy(gType, tipo);
                char * final = malloc(strlen((yyvsp[-2].valString))*sizeof(char) + strlen((yyvsp[0].valString))*sizeof(char)+ strlen(tipo)*sizeof(char) + sizeof(", "));
                memset(final, 0 , sizeof(final));

                strcat(final, "let ");
                strcat(final, (yyvsp[-2].valString));
                strcat(final, ":;\n");;
                strcat(final, (yyvsp[0].valString));

                char modTipo1[4 + strlen(tipo) + 2]; // 4 por ":;\n", 2 por ": y ";\n", +1 por el nulo
                char modTipo2[4 + strlen(tipo) + 2]; // 4 por ":=\n", 2 por ": y "=", +1 por el nulo

                if (strstr(final, ":;") != NULL) {
                        memset(modTipo1, 0, sizeof(modTipo1));
                        strcat(modTipo1, ":");
                        strcat(modTipo1, tipo);
                        strcat(modTipo1, ";\n");
                }

                if (strstr(final, ":=") != NULL) {
                        memset(modTipo2, 0, sizeof(modTipo2));
                        strcat(modTipo2, ":");
                        strcat(modTipo2, tipo);
                        strcat(modTipo2, "=");
                }

                char *finalMod = reemplazar(final, ":;", modTipo1);  // Primera llamada a reemplazar

                if (finalMod != NULL) {
                        finalMod = reemplazar(finalMod, ":=", modTipo2);  // Segunda llamada a reemplazar

                        if (finalMod != NULL) {
                                (yyval.valString) = finalMod;
                        } else {
                                // Manejar el error si la segunda llamada a reemplazar falla
                        }
                } else {
                        // Manejar el error si la primera llamada a reemplazar falla
                }

                
        }
#line 2210 "scanner.tab.c"
    break;

  case 21: /* vardef: type STRINGV EQ term COMMA vardef  */
#line 449 "scanner.y"
                                           {//8
                char * tipo = obtenerTipo((yyvsp[-5].valInt));
                char * final = malloc(strlen((yyvsp[-4].valString))*sizeof(char) + strlen((yyvsp[-2].valString))*sizeof(char)+ strlen((yyvsp[0].valString))*sizeof(char)+ strlen(tipo)*sizeof(char) + sizeof(", "));
                memset(final, 0 , sizeof(final));

                strcat(final, "let ");
                strcat(final, (yyvsp[-4].valString));
                strcat(final, ":=");
                strcat(final, (yyvsp[-2].valString));
                strcat(final,";\n");
                strcat(final, (yyvsp[0].valString));

                char modTipo1[4 + strlen(tipo) + 2]; // 4 por ":;\n", 2 por ": y ";\n", +1 por el nulo
                char modTipo2[4 + strlen(tipo) + 2]; // 4 por ":=\n", 2 por ": y "=", +1 por el nulo

                if (strstr(final, ":;") != NULL) {
                        memset(modTipo1, 0, sizeof(modTipo1));
                        strcat(modTipo1, ":");
                        strcat(modTipo1, tipo);
                        strcat(modTipo1, ";\n");
                }

                if (strstr(final, ":=") != NULL) {
                        memset(modTipo2, 0, sizeof(modTipo2));
                        strcat(modTipo2, ":");
                        strcat(modTipo2, tipo);
                        strcat(modTipo2, "=");
                }

                char *finalMod = reemplazar(final, ":;", modTipo1);  // Primera llamada a reemplazar

                if (finalMod != NULL) {
                        finalMod = reemplazar(finalMod, ":=", modTipo2);  // Segunda llamada a reemplazar

                        if (finalMod != NULL) {
                                (yyval.valString) = finalMod;
                        } else {
                                // Manejar el error si la segunda llamada a reemplazar falla
                        }
                } else {
                        // Manejar el error si la primera llamada a reemplazar falla
                }
        }
#line 2258 "scanner.tab.c"
    break;

  case 22: /* vardef: STRINGV operand term COMMA vardef  */
#line 492 "scanner.y"
                                          {//9
                char * final = malloc(strlen((yyvsp[-4].valString))*sizeof(char) + sizeof("; : let \n") + strlen((yyvsp[-2].valString))*sizeof(char)+ strlen((yyvsp[0].valString))*sizeof(char) );
                memset(final, 0, sizeof(final));
                strcat(final, "let ");
                strcat(final, (yyvsp[-4].valString));
                strcat(final, ":=");
                strcat(final, (yyvsp[-2].valString));
                strcat(final,";\n");
                strcat(final, (yyvsp[0].valString));
                (yyval.valString) = final;
        }
#line 2274 "scanner.tab.c"
    break;

  case 23: /* vardef: STRINGV COMMA vardef  */
#line 503 "scanner.y"
                             {//10
                char * final = malloc(strlen((yyvsp[-2].valString))*sizeof(char) + sizeof("; : let \n") + strlen((yyvsp[0].valString))* sizeof(char));
                memset(final, 0, sizeof(final));
                strcat(final, "let ");
                strcat(final, (yyvsp[-2].valString));
                strcat(final, ":;\n");;
                strcat(final, (yyvsp[0].valString));
                (yyval.valString) = final;
        }
#line 2288 "scanner.tab.c"
    break;

  case 24: /* vardef: STRINGV SEMICOLON  */
#line 512 "scanner.y"
                          {//11

                char * final = malloc(strlen((yyvsp[-1].valString))*sizeof(char) + sizeof("; : let \n") );
                memset(final, 0, sizeof(final));
                strcat(final, "let ");
                strcat(final, (yyvsp[-1].valString));
                strcat(final, ":;\n");;
                (yyval.valString) = final;
        }
#line 2302 "scanner.tab.c"
    break;

  case 25: /* type: INTEGER  */
#line 540 "scanner.y"
                {(yyval.valInt) = 0;}
#line 2308 "scanner.tab.c"
    break;

  case 26: /* type: SHORT  */
#line 541 "scanner.y"
                {(yyval.valInt) = 1;}
#line 2314 "scanner.tab.c"
    break;

  case 27: /* type: LONG  */
#line 542 "scanner.y"
               {(yyval.valInt) = 2;}
#line 2320 "scanner.tab.c"
    break;

  case 28: /* type: UNSIGNED_INT  */
#line 543 "scanner.y"
                       {(yyval.valInt) = 3;}
#line 2326 "scanner.tab.c"
    break;

  case 29: /* type: UNSIGNED_SHORT  */
#line 544 "scanner.y"
                         {(yyval.valInt) = 4;}
#line 2332 "scanner.tab.c"
    break;

  case 30: /* type: UNSIGNED_LONG  */
#line 545 "scanner.y"
                        {(yyval.valInt) = 5;}
#line 2338 "scanner.tab.c"
    break;

  case 31: /* type: FLOAT  */
#line 546 "scanner.y"
                {(yyval.valInt) = 6;}
#line 2344 "scanner.tab.c"
    break;

  case 32: /* type: DOUBLE  */
#line 547 "scanner.y"
                 {(yyval.valInt) = 7;}
#line 2350 "scanner.tab.c"
    break;

  case 33: /* type: STRING  */
#line 548 "scanner.y"
                 {(yyval.valInt) = 8;}
#line 2356 "scanner.tab.c"
    break;

  case 34: /* type: CHAR  */
#line 549 "scanner.y"
               {(yyval.valInt) = 9;}
#line 2362 "scanner.tab.c"
    break;

  case 35: /* type: BOOLEAN  */
#line 550 "scanner.y"
                  {(yyval.valInt) = 10;}
#line 2368 "scanner.tab.c"
    break;

  case 36: /* type: VOID  */
#line 551 "scanner.y"
               {;}
#line 2374 "scanner.tab.c"
    break;

  case 37: /* type: STRUCT STRINGV  */
#line 552 "scanner.y"
                         {;}
#line 2380 "scanner.tab.c"
    break;

  case 38: /* values: TRUEVAL  */
#line 558 "scanner.y"
                {
                (yyval.valString) = strdup("true");
        }
#line 2388 "scanner.tab.c"
    break;

  case 39: /* values: FALSEVAL  */
#line 561 "scanner.y"
                   {(yyval.valString) = (yyvsp[0].valString);}
#line 2394 "scanner.tab.c"
    break;

  case 40: /* values: INTNUM  */
#line 562 "scanner.y"
                 {(yyval.valString) = (yyvsp[0].valString);}
#line 2400 "scanner.tab.c"
    break;

  case 41: /* values: REALNUM  */
#line 563 "scanner.y"
                  {(yyval.valString) = (yyvsp[0].valString);}
#line 2406 "scanner.tab.c"
    break;

  case 42: /* values: QUOTESTRING  */
#line 564 "scanner.y"
                      {(yyval.valString) = (yyvsp[0].valString);}
#line 2412 "scanner.tab.c"
    break;

  case 43: /* preprograma: preprograma programa  */
#line 568 "scanner.y"
                            {
                char * final = malloc(strlen((yyvsp[-1].valString))*sizeof(char) + strlen((yyvsp[0].valString))*sizeof(char));
                memset(final,0,sizeof(final));
                strcat(final, (yyvsp[-1].valString));
                strcat(final, (yyvsp[0].valString));

                (yyval.valString) = final;
        }
#line 2425 "scanner.tab.c"
    break;

  case 44: /* preprograma: programa  */
#line 576 "scanner.y"
                 {
                char * final = malloc(strlen((yyvsp[0].valString))*sizeof(char));
                memset(final,0,sizeof(final));

                strcat(final, (yyvsp[0].valString));

                (yyval.valString) = final;
        }
#line 2438 "scanner.tab.c"
    break;

  case 45: /* programa: type STRINGV LPAREN args RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET  */
#line 585 "scanner.y"
                                                                                        {                        
                        
                        
                        char * final = malloc( strlen((yyvsp[-4].valString)) * sizeof(char) + strlen((yyvsp[-1].valString)) * sizeof(char)   + 20*sizeof(char) + sizeof("fn ->String {}"));
                        memset(final, 0, sizeof(final));
                        strcat(final, "fn ");
                        strcat(final, (yyvsp[-6].valString));
                        strcat(final, " (");
                        strcat(final,(yyvsp[-4].valString));
                        strcat(final,") ");
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
                                strcat(final, "{");
                        }
                        strcat(final, "{\n");
                        strcat(final, (yyvsp[-1].valString));
                        strcat(final, "\n");
                        strcat(final, "}\n\n");
                        free((yyvsp[-1].valString));
                        free((yyvsp[-4].valString));
                        DeleteListT (&flist);
                        
                        (yyval.valString) = final;
                
        }
#line 2489 "scanner.tab.c"
    break;

  case 46: /* programa: type STRINGV LPAREN RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET  */
#line 632 "scanner.y"
                                                                                      {
                
                        
                char * final = malloc( strlen((yyvsp[-1].valString)) * sizeof(char)   + 20*sizeof(char) + sizeof(" -> i16")+ sizeof("fn "));
                memset(final, 0, sizeof(final));

                strcat(final, "fn () ");
                strcat(final, (yyvsp[-5].valString));
                switch ((yyvsp[-6].valInt)) {
                case 0:strcat(final, "-> i32 {");
                        break;
                case 1:strcat(final, "-> i16 {");
                        break;
                case 2:strcat(final, "-> i64 {");
                        break;
                case 3:strcat(final, "-> u32 {");
                        break;
                case 4:strcat(final, "-> u16 {");
                        break;
                case 5:strcat(final, "-> u64 {");
                        break;
                case 6:strcat(final, "-> f32 {");
                        break;
                case 7:strcat(final, "-> f64 {");
                        break;
                case 8:strcat(final, "-> String {");
                        break;
                case 9:strcat(final, "-> char {");
                        break;
                case 10:strcat(final, "-> bool {");
                        break;
                default:break;
                }

                strcat(final, "\n");
                strcat(final, (yyvsp[-1].valString));
                strcat(final, "\n}\n\n");
                
                free((yyvsp[-1].valString));
                DeleteListT (&flist);

                (yyval.valString) = final;
                                
                
        }
#line 2539 "scanner.tab.c"
    break;

  case 47: /* programa: type STRINGV LPAREN RPAREN SEMICOLON  */
#line 678 "scanner.y"
                                             {
                (yyval.valString) = "";
        }
#line 2547 "scanner.tab.c"
    break;

  case 48: /* programa: vardef programa  */
#line 681 "scanner.y"
                          {
                char * final = malloc(strlen((yyvsp[-1].valString))*sizeof(char) + strlen((yyvsp[0].valString))*sizeof(char) + sizeof("\n\n"));
                strcat(final,(yyvsp[-1].valString));
                strcat(final,"\n");
                strcat(final, (yyvsp[0].valString));
                strcat(final,"\n");
                
                (yyval.valString) = final;
        }
#line 2561 "scanner.tab.c"
    break;

  case 49: /* programa: STRUCT STRINGV OPENCURLYBRACKET lines_program CLOSECURLYBRACKET SEMICOLON  */
#line 691 "scanner.y"
                                                                                  {
                char * final = malloc(strlen((yyvsp[-4].valString))*sizeof(char) + strlen((yyvsp[-2].valString))*sizeof(char) + strlen("struct { } \n\n"));
                memset(final, 0 , sizeof(final));
                strcat(final, "struct ");
                strcat(final, (yyvsp[-4].valString));
                strcat(final, " {\n");
                strcat(final, (yyvsp[-2].valString));
                strcat(final, "}\n");
                replaceSemicolon(final);
                (yyval.valString) = final; 
        }
#line 2577 "scanner.tab.c"
    break;

  case 50: /* programa: constdef programa  */
#line 702 "scanner.y"
                            {
                
                (yyval.valString) = (yyvsp[0].valString);}
#line 2585 "scanner.tab.c"
    break;

  case 51: /* programa: comment  */
#line 705 "scanner.y"
                {;}
#line 2591 "scanner.tab.c"
    break;

  case 52: /* args: type STRINGV COMMA args  */
#line 710 "scanner.y"
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
#line 2612 "scanner.tab.c"
    break;

  case 53: /* args: type STRINGV  */
#line 726 "scanner.y"
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
#line 2627 "scanner.tab.c"
    break;

  case 54: /* args: type PROD STRINGV COMMA args  */
#line 736 "scanner.y"
                                      {
                char * final;
                
                char * tipo = obtenerTipo((yyvsp[-4].valInt));
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
#line 2647 "scanner.tab.c"
    break;

  case 55: /* args: type PROD STRINGV  */
#line 751 "scanner.y"
                           {
                
                char * final;
                char * tipo = obtenerTipo((yyvsp[-2].valInt));
                final = malloc(strlen(tipo) * sizeof(char) + strlen((yyvsp[0].valString)) * sizeof(char) );
                memset(final, 0, sizeof(final));
                strcat(final, tipo);
                strcat(final, " ");
                strcat(final, (yyvsp[0].valString));
                (yyval.valString) = final;
        }
#line 2663 "scanner.tab.c"
    break;

  case 56: /* lines_program: lines_program line_program  */
#line 765 "scanner.y"
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
#line 2680 "scanner.tab.c"
    break;

  case 57: /* lines_program: line_program  */
#line 777 "scanner.y"
                       {
                (yyval.valString) = (yyvsp[0].valString);
                
                }
#line 2689 "scanner.tab.c"
    break;

  case 58: /* line_program: WRITE LOWER LOWER precontentWrite SEMICOLON  */
#line 788 "scanner.y"
                                                    {
                
                (yyval.valString) = (yyvsp[-1].valString);
                
        }
#line 2699 "scanner.tab.c"
    break;

  case 59: /* line_program: PRINTF LPAREN precontentWrite RPAREN SEMICOLON  */
#line 793 "scanner.y"
                                                         {

                (yyval.valString) = (yyvsp[-2].valString);
        }
#line 2708 "scanner.tab.c"
    break;

  case 60: /* line_program: SCANF LPAREN precontentWrite RPAREN SEMICOLON  */
#line 797 "scanner.y"
                                                       {
                (yyval.valString) = (yyvsp[-2].valString);
        }
#line 2716 "scanner.tab.c"
    break;

  case 61: /* line_program: STRINGV LPAREN RPAREN SEMICOLON  */
#line 811 "scanner.y"
                                        {
                char * final = malloc(strlen((yyvsp[-3].valString))* sizeof(char) +  sizeof("();") + 1);
                memset(final,0, sizeof(final));
                strcat(final, (yyvsp[-3].valString));
                strcat(final, "(");
                strcat(final,");");
                (yyval.valString) = final;

        }
#line 2730 "scanner.tab.c"
    break;

  case 62: /* line_program: IF LPAREN term RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET  */
#line 821 "scanner.y"
                                                                                  {
                char * final = malloc(strlen((yyvsp[-4].valString))* sizeof(char) + strlen((yyvsp[-1].valString))*sizeof(char) + sizeof("if ( ) { } \t \n \n"));
                memset(final, 0, sizeof(final));
                strcat(final, "if (");
                strcat(final, (yyvsp[-4].valString));
                strcat(final, "){\n");
                strcat(final, (yyvsp[-1].valString));
                strcat(final, "\n}");
                free((yyvsp[-4].valString));
                free((yyvsp[-1].valString));
                (yyval.valString) = final;

        }
#line 2748 "scanner.tab.c"
    break;

  case 63: /* line_program: ELSE IF LPAREN term RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET  */
#line 834 "scanner.y"
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
#line 2765 "scanner.tab.c"
    break;

  case 64: /* line_program: ELSE OPENCURLYBRACKET line_program CLOSECURLYBRACKET  */
#line 846 "scanner.y"
                                                               {
                char* final = malloc(strlen((yyvsp[-1].valString))*sizeof(char)+ sizeof("else {} \n \n \t"));
                memset(final, 0, sizeof(final));
                strcat(final, "else{\n\t");
                strcat(final, (yyvsp[-1].valString));
                strcat(final, "}\n");
                (yyval.valString) = final;
        
        }
#line 2779 "scanner.tab.c"
    break;

  case 65: /* line_program: FOR LPAREN type STRINGV EQ INTNUM SEMICOLON term STRINGV operand RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET  */
#line 855 "scanner.y"
                                                                                                                                   {
                char * final = malloc((yyvsp[-11].valInt)*sizeof(int) + strlen((yyvsp[-6].valString))*sizeof(char) +
                                sizeof("for ; ; {}")+strlen((yyvsp[-10].valString))*sizeof(char)+ strlen((yyvsp[-8].valString))*sizeof(char) + strlen((yyvsp[-5].valString))*sizeof(char) + 
                                strlen((yyvsp[-4].valString))*sizeof(char) + strlen((yyvsp[-1].valString))*sizeof(char));
                memset(final,0, strlen(final));

                char * numero = getEndNumber((yyvsp[-6].valString));

                strcat(final, "for ");
                strcat(final, (yyvsp[-10].valString));
                strcat(final, " in ");
                strcat(final, (yyvsp[-8].valString));
                strcat(final, "..");
                strcat(final, numero);
                strcat(final, "{\n\t");
                strcat(final, (yyvsp[-1].valString));
                strcat(final, "\n}");
                (yyval.valString)=final;
                ;}
#line 2803 "scanner.tab.c"
    break;

  case 66: /* line_program: FOR LPAREN type STRINGV EQ INTNUM SEMICOLON term SEMICOLON vardef RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET  */
#line 875 "scanner.y"
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
#line 2831 "scanner.tab.c"
    break;

  case 67: /* line_program: DO OPENCURLYBRACKET lines_program CLOSECURLYBRACKET WHILE LPAREN term RPAREN SEMICOLON  */
#line 898 "scanner.y"
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
#line 2851 "scanner.tab.c"
    break;

  case 68: /* line_program: WHILE LPAREN term RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET  */
#line 913 "scanner.y"
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
#line 2868 "scanner.tab.c"
    break;

  case 69: /* line_program: comment  */
#line 926 "scanner.y"
                 {;}
#line 2874 "scanner.tab.c"
    break;

  case 70: /* line_program: STRINGV operand SEMICOLON  */
#line 927 "scanner.y"
                                   {
                char * final = malloc (strlen((yyvsp[-1].valString))*sizeof(char) + strlen((yyvsp[-2].valString))*sizeof(char));
                memset(final, 0, sizeof(final));
                strcat(final, (yyvsp[-2].valString));
                strcat(final, (yyvsp[-1].valString));
                strcat(final, ";");

                (yyval.valString) = final;
        }
#line 2888 "scanner.tab.c"
    break;

  case 71: /* line_program: RETURN term SEMICOLON  */
#line 936 "scanner.y"
                                {
                char * final = malloc(strlen((yyvsp[-1].valString))*sizeof(char) );
                memset(final, 0 , sizeof(final));
                
                strcat(final, (yyvsp[-1].valString));
                (yyval.valString)=final;
                
        }
#line 2901 "scanner.tab.c"
    break;

  case 72: /* line_program: RETURN SEMICOLON  */
#line 944 "scanner.y"
                           {
                char * final = malloc(sizeof("return;"));
                memset(final, 0 , sizeof(final));
                strcat(final, "return;");
                (yyval.valString) = final;
                
        }
#line 2913 "scanner.tab.c"
    break;

  case 73: /* line_program: vardef  */
#line 951 "scanner.y"
                {
                char * final = malloc(strlen((yyvsp[0].valString))*sizeof(char)  + sizeof("\n"));
                memset(final,0,sizeof(final));
                strcat(final,(yyvsp[0].valString));
                strcat(final,"\n");

                
                (yyval.valString) = final;
                
        }
#line 2928 "scanner.tab.c"
    break;

  case 74: /* line_program: term  */
#line 961 "scanner.y"
                {
                printf("\n\nAQUI\n\n");
                char * final = malloc(strlen((yyvsp[0].valString))*sizeof(char)  + sizeof("\n;"));
                memset(final,0,sizeof(final));
                strcat(final,(yyvsp[0].valString));
                strcat(final,";\n");

                
                (yyval.valString) = final;
        }
#line 2943 "scanner.tab.c"
    break;

  case 75: /* line_program: STRUCT STRINGV OPENCURLYBRACKET lines_program CLOSECURLYBRACKET SEMICOLON  */
#line 971 "scanner.y"
                                                                                  {
                char * final = malloc(strlen((yyvsp[-4].valString))*sizeof(char) + strlen((yyvsp[-2].valString))*sizeof(char) + strlen("struct { } \n\n"));
                memset(final, 0 , sizeof(final));
                strcat(final, "struct ");
                strcat(final, (yyvsp[-4].valString));
                strcat(final, " {\n");
                strcat(final, (yyvsp[-2].valString));
                strcat(final, "}\n");
                replaceSemicolon(final);

                (yyval.valString) = final; 
        }
#line 2960 "scanner.tab.c"
    break;

  case 76: /* array: term COMMA array  */
#line 989 "scanner.y"
                        {
                char * final = malloc(strlen((yyvsp[-2].valString))*sizeof(char) + strlen((yyvsp[0].valString))*sizeof(char)) ;
                memset(final,0,sizeof(final));

                strcat(final,(yyvsp[-2].valString));
                strcat(final,",");
                strcat(final,(yyvsp[0].valString));
                (yyval.valString) = final;
        }
#line 2974 "scanner.tab.c"
    break;

  case 77: /* array: term  */
#line 998 "scanner.y"
             {
                (yyval.valString) = (yyvsp[0].valString);
        }
#line 2982 "scanner.tab.c"
    break;

  case 78: /* precontentWrite: contentWrite  */
#line 1004 "scanner.y"
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
#line 3052 "scanner.tab.c"
    break;

  case 79: /* precontentWrite: contentWrite LOWER LOWER ENDL  */
#line 1069 "scanner.y"
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
#line 3116 "scanner.tab.c"
    break;

  case 80: /* contentWrite: contentWrite COMMA QUOTESTRING  */
#line 1132 "scanner.y"
                                      {
                char * final = malloc(strlen((yyvsp[-2].valString)) * sizeof(char) + strlen((yyvsp[0].valString)) * sizeof(char) + strlen("{}") * sizeof(char)+strlen("println!(\"")); 
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
#line 3139 "scanner.tab.c"
    break;

  case 81: /* contentWrite: contentWrite COMMA STRINGV  */
#line 1150 "scanner.y"
                                   {
                char * final = malloc(strlen((yyvsp[-2].valString)) * sizeof(char) + strlen((yyvsp[0].valString)) * sizeof(char) + strlen("{}") * sizeof(char)); 
                memset(final, 0, sizeof(final));

                strcat(printV,(yyvsp[0].valString));
                strcat(printV,",");

                
                strcat(final, (yyvsp[-2].valString));
                deleteQuotes(final);
                (yyval.valString) = final;
        }
#line 3156 "scanner.tab.c"
    break;

  case 82: /* contentWrite: QUOTESTRING  */
#line 1163 "scanner.y"
                      {

                (yyval.valString) = (yyvsp[0].valString);}
#line 3164 "scanner.tab.c"
    break;

  case 83: /* contentWrite: STRINGV  */
#line 1166 "scanner.y"
                  {
                (yyval.valString) = (yyvsp[0].valString);}
#line 3171 "scanner.tab.c"
    break;

  case 84: /* term: atom  */
#line 1192 "scanner.y"
             {
                (yyval.valString) = (yyvsp[0].valString);}
#line 3178 "scanner.tab.c"
    break;

  case 85: /* term: LPAREN term RPAREN  */
#line 1194 "scanner.y"
                             {
                char * final = malloc(strlen((yyvsp[-1].valString)) * sizeof(char) + sizeof("()") + 1);
                memset(final, 0, sizeof(final));
                strcpy(final, "(");
                strcat(final, (yyvsp[-1].valString));
                strcat(final, ")");
                free((yyvsp[-1].valString));
                (yyval.valString) = final;
                }
#line 3192 "scanner.tab.c"
    break;

  case 86: /* term: HYPHEN atom  */
#line 1203 "scanner.y"
                      {
                char * final = malloc(strlen((yyvsp[0].valString)) * sizeof(char) + sizeof("-()") + 1);
                memset(final, 0, sizeof(final));
                strcpy(final, "-(");
                strcat(final, (yyvsp[0].valString));
                strcat(final, ")");
                free((yyvsp[0].valString));
                (yyval.valString) = final;
                }
#line 3206 "scanner.tab.c"
    break;

  case 87: /* term: EX term  */
#line 1212 "scanner.y"
                  {
                char * final = malloc(strlen((yyvsp[0].valString)) * sizeof(char) + sizeof("!()") + 1);
                memset(final, 0, sizeof(final));
                strcpy(final, "!(");
                strcat(final, (yyvsp[0].valString));
                strcat(final, ")");
                free((yyvsp[0].valString));
                (yyval.valString) = final;
                }
#line 3220 "scanner.tab.c"
    break;

  case 88: /* term: term operand term SEMICOLON  */
#line 1221 "scanner.y"
                                     {
                char * final = malloc(strlen((yyvsp[-3].valString)) * sizeof(char) + strlen((yyvsp[-1].valString)) * sizeof(char) + strlen((yyvsp[-2].valString)) * sizeof(char));
                memset(final, 0 , sizeof(final));
                strcat(final, (yyvsp[-3].valString));
                strcat(final, (yyvsp[-2].valString));
                strcat(final, (yyvsp[-1].valString));
                (yyval.valString) = final;
        }
#line 3233 "scanner.tab.c"
    break;

  case 89: /* operand: PLUS  */
#line 1232 "scanner.y"
             {
                (yyval.valString) = strdup(" + ");
        }
#line 3241 "scanner.tab.c"
    break;

  case 90: /* operand: PLUS EQ  */
#line 1235 "scanner.y"
                 {(yyval.valString) = strdup(" += ");}
#line 3247 "scanner.tab.c"
    break;

  case 91: /* operand: HYPHEN  */
#line 1236 "scanner.y"
                {(yyval.valString) = strdup(" - ");}
#line 3253 "scanner.tab.c"
    break;

  case 92: /* operand: HYPHEN EQ  */
#line 1237 "scanner.y"
                   {(yyval.valString) = strdup(" -= ");}
#line 3259 "scanner.tab.c"
    break;

  case 93: /* operand: HYPHEN HIGHER  */
#line 1238 "scanner.y"
                      {(yyval.valString) = strdup("");}
#line 3265 "scanner.tab.c"
    break;

  case 94: /* operand: PROD  */
#line 1239 "scanner.y"
              {(yyval.valString) = strdup(" * ");}
#line 3271 "scanner.tab.c"
    break;

  case 95: /* operand: DIV  */
#line 1240 "scanner.y"
             {(yyval.valString) = strdup(" / ");}
#line 3277 "scanner.tab.c"
    break;

  case 96: /* operand: DIVINT  */
#line 1241 "scanner.y"
                {(yyval.valString) = strdup(" / ");}
#line 3283 "scanner.tab.c"
    break;

  case 97: /* operand: MOD  */
#line 1242 "scanner.y"
             {(yyval.valString) = strdup(" % ");}
#line 3289 "scanner.tab.c"
    break;

  case 98: /* operand: LOWER  */
#line 1243 "scanner.y"
               {(yyval.valString) = strdup(" < ");}
#line 3295 "scanner.tab.c"
    break;

  case 99: /* operand: HIGHER  */
#line 1244 "scanner.y"
                {(yyval.valString) = strdup(" > ");}
#line 3301 "scanner.tab.c"
    break;

  case 100: /* operand: LOWER EQ  */
#line 1245 "scanner.y"
                  {(yyval.valString) = strdup(" <= ");}
#line 3307 "scanner.tab.c"
    break;

  case 101: /* operand: HIGHER EQ  */
#line 1246 "scanner.y"
                   {(yyval.valString) = strdup(" >= ");}
#line 3313 "scanner.tab.c"
    break;

  case 102: /* operand: EQ EQ  */
#line 1247 "scanner.y"
               {(yyval.valString) = strdup(" == ");}
#line 3319 "scanner.tab.c"
    break;

  case 103: /* operand: AND  */
#line 1248 "scanner.y"
             {(yyval.valString) = strdup(" && ");}
#line 3325 "scanner.tab.c"
    break;

  case 104: /* operand: PLUS PLUS  */
#line 1249 "scanner.y"
                   {(yyval.valString) = strdup(" ++ ");}
#line 3331 "scanner.tab.c"
    break;

  case 105: /* operand: OR  */
#line 1250 "scanner.y"
           {(yyval.valString) = strdup(" || ");}
#line 3337 "scanner.tab.c"
    break;

  case 106: /* atom: STRINGV  */
#line 1255 "scanner.y"
                {
			
            (yyval.valString) = (yyvsp[0].valString);
		}
#line 3346 "scanner.tab.c"
    break;

  case 107: /* atom: values  */
#line 1259 "scanner.y"
                 {
                        
			(yyval.valString) = (yyvsp[0].valString);
		}
#line 3355 "scanner.tab.c"
    break;

  case 108: /* atom: STRINGV LSQUAREPAREN atom RSQUAREPAREN  */
#line 1263 "scanner.y"
                                               {
                (yyval.valString) = (yyvsp[-3].valString);
        }
#line 3363 "scanner.tab.c"
    break;


#line 3367 "scanner.tab.c"

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

#line 1268 "scanner.y"


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

char *reemplazar(const char *cadena, const char *busqueda, const char *reemplazo) {
    if (cadena == NULL || busqueda == NULL || reemplazo == NULL) {
        return NULL;
    }

    int longitudBusqueda = strlen(busqueda);
    int longitudReemplazo = strlen(reemplazo);
    const char *posicion;
    const char *inicio = cadena;
    int nuevaLongitud = 0;

    // Calcular la longitud del nuevo string
    while ((posicion = strstr(inicio, busqueda)) != NULL) {
        nuevaLongitud += posicion - inicio + longitudReemplazo;
        inicio = posicion + longitudBusqueda;
    }
    nuevaLongitud += strlen(inicio); // Agregar el resto de la cadena

    // Asignar memoria para el nuevo string
    char *nuevoString = (char *)malloc(nuevaLongitud + 1);

    if (nuevoString == NULL) {
        return NULL; // Error en la asignación de memoria
    }

    char *destino = nuevoString;
    inicio = cadena;

    // Construir el nuevo string
    while ((posicion = strstr(inicio, busqueda)) != NULL) {
        int longitudSegmento = posicion - inicio;
        strncpy(destino, inicio, longitudSegmento);
        destino += longitudSegmento;
        strcpy(destino, reemplazo);
        destino += longitudReemplazo;
        inicio = posicion + longitudBusqueda;
    }

    strcpy(destino, inicio); // Copiar el resto de la cadena

    return nuevoString;
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


void saveGType(char *tipo) {
    strncpy(gType, tipo, sizeof(gType) - 1); // Copiar tipo en gType
    gType[sizeof(gType) - 1] = '\0'; // Asegurarse de que gType esté terminado en null
}

char *getGType() {
    return gType;
}


void replaceSemicolon(char *string) {
    if (string == NULL) {
        return; // Verificar si la cadena es nula
    }

    int length = strlen(string);

    for (int i = 0; i < length; i++) {
        if (string[i] == ';') {
            string[i] = ','; // Reemplazar el punto y coma por una coma
        }
    }
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
void yyerror(const char *msg) {
        fprintf(stderr, "Error: %s\n", msg);
        fprintf(stderr, "Error at line %d: %s\n", yylineno, msg);
        fprintf(stderr, "Syntax error: %s. Expected token: %d\n", msg, yychar);
        fprintf(stderr, "   %s\n", yytext); // Imprime el token que causó el error
}



int searchString(char **arr, char *toFind, int size) {
    for (int i = 0; i < size; i++) {
        if (strcmp(arr[i], toFind) == 0) {
            return 1; // Se encontró la cadena
        }
    }
    return 0; // No se encontró la cadena
}

char *insertTabsBetweenBraces( char *input) {
    if (input == NULL) {
        return NULL;
    }

    int input_length = strlen(input);
    int countCurly = 0;
    int count = 0;

    // Calcula una estimación inicial de la longitud de salida
    int max_output_length = input_length * 2;
    char *output = (char *)malloc((max_output_length + 1) * sizeof(char));

    if (output == NULL) {
        return NULL; // Comprueba si malloc falla
    }

    for (int i = 0; i < input_length; i++) {
        if (input[i] == '{') {
            countCurly++;
        } else if (input[i] == '}') {
            countCurly--;
        }

        if (input[i] != '\\' && input[i] != '\n') {
            output[count++] = input[i];

        }  else if (input[i] == '\n' && input[i + 1] == '}') {
            output[count++] = input[i];
            // Inserta tabulaciones según countCurly
            for (int j = 0; j < countCurly-1; j++) {
                output[count++] = '\t';
            }
        } else if (input[i] == '\n') {
            output[count++] = input[i];
            // Inserta tabulaciones según countCurly
            for (int j = 0; j < countCurly; j++) {
                output[count++] = '\t';
            }
        } else {
            // Copia el carácter de escape y el siguiente carácter
            output[count++] = input[i];
            output[count++] = input[i + 1];
            i++; // Salta el siguiente carácter
        }
    }

    output[count] = '\0'; // Agrega el carácter nulo al final

    return output;
}

int main(int argc, char *argv[]) {
       
        printf("Número de argumentos (argc): %d\n", argc);

        printf("Argumentos (argv):\n");
        for (int i = 0; i < argc; ++i) {
                printf("argv[%d] = %s\n", i, argv[i]);
        }
        char ruta[100] = "entrada/";
        char *archivo_c = argv[1];

        strcat(ruta, archivo_c);
        
        
        InitializeListT(&typelist);
        InitializeListN(&queue);
	//pthread_mutex_lock(&file_mutex);
	switch (argc) {
		case 1:	printf("Syntax : ./traductorP <archivoC> [-s size_string]\n");
			exit(-1);
                        break;
		case 2: int i = 0;
                        arraySize++;
                        YY_BUFFER_STATE bufferState = NULL;
                        arrayCabeceras = (char**)realloc(arrayCabeceras, arraySize * sizeof(char*));
                        arrayCabeceras[arraySize - 1] = (char*)malloc(strlen(ruta) * sizeof(char));
                        strcpy(arrayCabeceras[arraySize - 1], ruta);
                        strcpy(filePath, ruta);
                        
                        #pragma omp parallel shared(arrayCabeceras, arraySize, yyin, filePath) private(i)
                        {
                                #pragma omp for
                                for (i = 0; i < arraySize; i++) {
                                        printf("\n-------%i--------\n", arraySize);
                                        #pragma omp critical
                                        {/*     extern void yy_flush_buffer( YY_BUFFER_STATE buffer );
                                                extern void yy_switch_to_buffer( YY_BUFFER_STATE new_buffer );
                                                extern YY_BUFFER_STATE yy_create_buffer( FILE *file, int size );
                                                extern YY_BUFFER_STATE yy_current_buffer();*/
                                                bufferState = yy_current_buffer();
                                                yy_flush_buffer(bufferState);
                                                yyin = fopen(arrayCabeceras[i], "r");
                                                bufferState = yy_create_buffer(yyin, 1024);
                                                yy_switch_to_buffer(bufferState);
                                        }
                                        // Ejecutar la función que trabaja con el array
                                        if (yyin == NULL) {
                                                printf("ERROR: No se ha podido abrir el fichero.\n");
                                        } else {
                                                #pragma omp critical
                                                {
                                                strcpy(filePath, arrayCabeceras[i]);
                                                }
                                                yyparse();
                                                #pragma omp critical
                                                {
                                                fclose(yyin);
                                                }
                                        }

                                        // Hacer algo después de la función
                                        #pragma omp critical
                                        {
                                                printf("Thread %d realizando manipulaciones posteriores.\n", omp_get_thread_num());
                                        }
                                }
                        }

                                



                        printf("array size final %i", arraySize);
                        
                        
                        
                
                        break;
                
                
                case 4 : if((strcmp(argv[2], "-s") != 0) || (isNumber(argv[3])==0)) {
                                printf("Syntax : ./traductorP <archivoC> [-s size_string]\n");
			        exit(-1);
                        }
                        else {
                                strcpy(sizeS, argv[3]);
                                yyin = fopen(ruta, "r");
			        if (yyin == NULL) {
				        printf("ERROR: No se ha podido abrir el fichero.\n");
			        }
			        else {
				        yyparse();
				        fclose(yyin);
			        }
                        }
                        break;
		default: printf("ERROR: Demasiados argumentos.\nSyntax : ./traductorP <archivoC> [-s size_string]\n\n");
	}
        //pthread_mutex_unlock(&file_mutex);
        //ShowListT(&typelist);
        
	return 0;
}
/*#pragma omp parallel private(yyin) shared(z)
                {
                        int tid = omp_get_thread_num();

                        // Definir las variables threadprivate
                        #pragma omp threadprivate(yyin, filepath)


                        #pragma omp sections
                        {
                                #pragma omp section
                                {
                                        printf("hola esta es la cuarta section\n");
                                        strcpy(filePath, "entrada/archivo4.c");
                                        yyin = fopen(filePath, "r");
                                        if (yyin == NULL) {
                                                printf("ERROR: No se ha podido abrir el fichero.\n");
                                        }
                                        else {
                                                yyparse();
                                                fclose(yyin);
                                        }    
                                        
                                }

                                #pragma omp section
                                {
                                        printf("hola esta es la segunda section\n");
                                        strcpy(filePath, "entrada/archivo1.c");
                                        yyin = fopen(filePath, "r");
                                        if (yyin == NULL) {
                                                printf("ERROR: No se ha podido abrir el fichero.\n");
                                        }
                                        else {
                                                yyparse();
                                                fclose(yyin);
                                        }
                                        
                                }
                        }
                        {
                                #pragma omp section
                                {
                                        printf("hola esta es la primera section\n");
                                        strcpy(filePath, "entrada/archivo2.c");
                                        yyin = fopen(filePath, "r");
                                        if (yyin == NULL) {
                                                printf("ERROR: No se ha podido abrir el fichero.\n");
                                        }
                                        else { 
                                                yyparse();
                                                fclose(yyin);
                                        }
                                        
                                }

                                #pragma omp section
                                {
                                        printf("hola esta es la segunda section\n");
                                        strcpy(filePath, "entrada/archivo3.c");
                                        yyin = fopen(filePath, "r");
                                        if (yyin == NULL) {
                                                printf("ERROR: No se ha podido abrir el fichero.\n");
                                        }
                                        else {
                                                yyparse();
                                                fclose(yyin);
                                        }
                                        
                                }
                        }
                }*/
