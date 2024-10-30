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
extern void yy_delete_buffer ( YY_BUFFER_STATE b  );
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

char tipoStruct[50] = "";

int inputCount = 0;////////////////por ahora no hace nada, pero en el futuro usar para escribir en el cargo.toml

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
char* getStringFromExp(char* str);

#line 143 "scanner.tab.c"

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
  YYSYMBOL_SWITCH = 18,                    /* SWITCH  */
  YYSYMBOL_CASE = 19,                      /* CASE  */
  YYSYMBOL_DEFAULT = 20,                   /* DEFAULT  */
  YYSYMBOL_AND = 21,                       /* AND  */
  YYSYMBOL_OR = 22,                        /* OR  */
  YYSYMBOL_LOWER = 23,                     /* LOWER  */
  YYSYMBOL_HIGHER = 24,                    /* HIGHER  */
  YYSYMBOL_PLUS = 25,                      /* PLUS  */
  YYSYMBOL_HYPHEN = 26,                    /* HYPHEN  */
  YYSYMBOL_PROD = 27,                      /* PROD  */
  YYSYMBOL_DIV = 28,                       /* DIV  */
  YYSYMBOL_DIVINT = 29,                    /* DIVINT  */
  YYSYMBOL_MOD = 30,                       /* MOD  */
  YYSYMBOL_COMMA = 31,                     /* COMMA  */
  YYSYMBOL_DOT = 32,                       /* DOT  */
  YYSYMBOL_PERCENT = 33,                   /* PERCENT  */
  YYSYMBOL_EQ = 34,                        /* EQ  */
  YYSYMBOL_COMMENTLINE = 35,               /* COMMENTLINE  */
  YYSYMBOL_MULTILINE = 36,                 /* MULTILINE  */
  YYSYMBOL_VAR = 37,                       /* VAR  */
  YYSYMBOL_CONST = 38,                     /* CONST  */
  YYSYMBOL_DEFINE = 39,                    /* DEFINE  */
  YYSYMBOL_LISTCONTENT = 40,               /* LISTCONTENT  */
  YYSYMBOL_VALUE = 41,                     /* VALUE  */
  YYSYMBOL_LPAREN = 42,                    /* LPAREN  */
  YYSYMBOL_STRINGQUOTE = 43,               /* STRINGQUOTE  */
  YYSYMBOL_RPAREN = 44,                    /* RPAREN  */
  YYSYMBOL_RSQUAREPAREN = 45,              /* RSQUAREPAREN  */
  YYSYMBOL_LSQUAREPAREN = 46,              /* LSQUAREPAREN  */
  YYSYMBOL_COLON = 47,                     /* COLON  */
  YYSYMBOL_SEMICOLON = 48,                 /* SEMICOLON  */
  YYSYMBOL_INTEGER = 49,                   /* INTEGER  */
  YYSYMBOL_SHORT = 50,                     /* SHORT  */
  YYSYMBOL_LONG = 51,                      /* LONG  */
  YYSYMBOL_LONG_LONG = 52,                 /* LONG_LONG  */
  YYSYMBOL_UNSIGNED_INT = 53,              /* UNSIGNED_INT  */
  YYSYMBOL_UNSIGNED_SHORT = 54,            /* UNSIGNED_SHORT  */
  YYSYMBOL_UNSIGNED_LONG = 55,             /* UNSIGNED_LONG  */
  YYSYMBOL_UNSIGNED_LONG_LONG = 56,        /* UNSIGNED_LONG_LONG  */
  YYSYMBOL_FLOAT = 57,                     /* FLOAT  */
  YYSYMBOL_DOUBLE = 58,                    /* DOUBLE  */
  YYSYMBOL_VOID = 59,                      /* VOID  */
  YYSYMBOL_OPENCURLYBRACKET = 60,          /* OPENCURLYBRACKET  */
  YYSYMBOL_CLOSECURLYBRACKET = 61,         /* CLOSECURLYBRACKET  */
  YYSYMBOL_BOOLEAN = 62,                   /* BOOLEAN  */
  YYSYMBOL_CHAR = 63,                      /* CHAR  */
  YYSYMBOL_PRINTF = 64,                    /* PRINTF  */
  YYSYMBOL_SCANF = 65,                     /* SCANF  */
  YYSYMBOL_STRING = 66,                    /* STRING  */
  YYSYMBOL_STRINGV = 67,                   /* STRINGV  */
  YYSYMBOL_QUOTESTRING = 68,               /* QUOTESTRING  */
  YYSYMBOL_TRUEVAL = 69,                   /* TRUEVAL  */
  YYSYMBOL_FALSEVAL = 70,                  /* FALSEVAL  */
  YYSYMBOL_INTNUM = 71,                    /* INTNUM  */
  YYSYMBOL_REALNUM = 72,                   /* REALNUM  */
  YYSYMBOL_RETURN = 73,                    /* RETURN  */
  YYSYMBOL_STRUCT = 74,                    /* STRUCT  */
  YYSYMBOL_AMPERSAND = 75,                 /* AMPERSAND  */
  YYSYMBOL_EX = 76,                        /* EX  */
  YYSYMBOL_YYACCEPT = 77,                  /* $accept  */
  YYSYMBOL_S = 78,                         /* S  */
  YYSYMBOL_comment = 79,                   /* comment  */
  YYSYMBOL_cabecera = 80,                  /* cabecera  */
  YYSYMBOL_constdef = 81,                  /* constdef  */
  YYSYMBOL_vardef = 82,                    /* vardef  */
  YYSYMBOL_types = 83,                     /* types  */
  YYSYMBOL_type = 84,                      /* type  */
  YYSYMBOL_values = 85,                    /* values  */
  YYSYMBOL_preprograma = 86,               /* preprograma  */
  YYSYMBOL_programa = 87,                  /* programa  */
  YYSYMBOL_prod = 88,                      /* prod  */
  YYSYMBOL_args = 89,                      /* args  */
  YYSYMBOL_lines_program = 90,             /* lines_program  */
  YYSYMBOL_if_statement = 91,              /* if_statement  */
  YYSYMBOL_case_chain = 92,                /* case_chain  */
  YYSYMBOL_fun_cre = 93,                   /* fun_cre  */
  YYSYMBOL_line_program = 94,              /* line_program  */
  YYSYMBOL_array = 95,                     /* array  */
  YYSYMBOL_precontentWrite = 96,           /* precontentWrite  */
  YYSYMBOL_contentWrite = 97,              /* contentWrite  */
  YYSYMBOL_exp = 98,                       /* exp  */
  YYSYMBOL_term = 99,                      /* term  */
  YYSYMBOL_operand = 100,                  /* operand  */
  YYSYMBOL_atom = 101                      /* atom  */
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
typedef yytype_int16 yy_state_t;

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
#define YYLAST   2042

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  77
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  128
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  285

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   331


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
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   193,   193,   244,   247,   252,   257,   263,   304,   308,
     313,   349,   369,   380,   406,   429,   464,   495,   538,   599,
     674,   690,   710,   720,   740,   743,   749,   750,   751,   752,
     753,   754,   755,   756,   757,   758,   759,   760,   761,   762,
     763,   773,   776,   777,   778,   779,   783,   798,   807,   854,
     900,   904,   915,   957,   973,   978,   982,   988,  1013,  1112,
    1132,  1155,  1174,  1183,  1196,  1209,  1221,  1231,  1249,  1275,
    1286,  1300,  1312,  1330,  1342,  1352,  1359,  1367,  1375,  1383,
    1386,  1389,  1434,  1463,  1479,  1494,  1495,  1505,  1516,  1528,
    1535,  1555,  1583,  1602,  1605,  1636,  1784,  1799,  1802,  1809,
    1826,  1836,  1841,  1859,  1879,  1882,  1883,  1884,  1885,  1886,
    1887,  1888,  1889,  1890,  1891,  1892,  1893,  1894,  1895,  1896,
    1897,  1898,  1899,  1900,  1905,  1909,  1913,  1917,  1935
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
  "END", "IF", "THEN", "ELSE", "SWITCH", "CASE", "DEFAULT", "AND", "OR",
  "LOWER", "HIGHER", "PLUS", "HYPHEN", "PROD", "DIV", "DIVINT", "MOD",
  "COMMA", "DOT", "PERCENT", "EQ", "COMMENTLINE", "MULTILINE", "VAR",
  "CONST", "DEFINE", "LISTCONTENT", "VALUE", "LPAREN", "STRINGQUOTE",
  "RPAREN", "RSQUAREPAREN", "LSQUAREPAREN", "COLON", "SEMICOLON",
  "INTEGER", "SHORT", "LONG", "LONG_LONG", "UNSIGNED_INT",
  "UNSIGNED_SHORT", "UNSIGNED_LONG", "UNSIGNED_LONG_LONG", "FLOAT",
  "DOUBLE", "VOID", "OPENCURLYBRACKET", "CLOSECURLYBRACKET", "BOOLEAN",
  "CHAR", "PRINTF", "SCANF", "STRING", "STRINGV", "QUOTESTRING", "TRUEVAL",
  "FALSEVAL", "INTNUM", "REALNUM", "RETURN", "STRUCT", "AMPERSAND", "EX",
  "$accept", "S", "comment", "cabecera", "constdef", "vardef", "types",
  "type", "values", "preprograma", "programa", "prod", "args",
  "lines_program", "if_statement", "case_chain", "fun_cre", "line_program",
  "array", "precontentWrite", "contentWrite", "exp", "term", "operand",
  "atom", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-195)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-129)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       9,    -9,    34,  1751,    10,     9,  -195,    14,  -195,  -195,
    1968,    19,  1968,  -195,  -195,  -195,  -195,  -195,  -195,  -195,
    -195,  -195,  -195,  -195,  -195,  -195,  -195,   304,  -195,  -195,
    -195,  -195,  -195,    35,  -195,  1751,  1751,    41,    14,  -195,
    1751,  -195,    64,  -195,   -17,    71,  -195,  -195,    67,    57,
      68,  -195,  -195,    83,   101,    50,    45,  -195,  -195,  -195,
    -195,  1850,  -195,  -195,   105,  1661,  1712,   108,  1850,  -195,
    -195,  -195,  1288,    99,  -195,  -195,  -195,  1712,  -195,     9,
      79,   115,  -195,   -37,  -195,  -195,  -195,  -195,  -195,  -195,
    -195,    84,  -195,  1694,  -195,   -27,  1712,  -195,    94,  1342,
    -195,  -195,  1356,  -195,  -195,   110,   119,   102,   141,   123,
       3,  1712,  1916,   130,   131,   304,   222,  -195,  -195,    44,
     424,  -195,    33,  -195,  1850,  1712,  1942,  1475,  -195,  1381,
    -195,   150,    57,   133,  -195,    51,  1412,   -10,  -195,  1694,
    1712,  -195,  1712,  1968,  1288,   154,  1712,   136,  1288,  1437,
     113,   -43,   -43,  1784,  -195,  1451,  1288,   134,  -195,  -195,
      22,   -22,   116,   144,   151,   146,  -195,     9,   153,  -195,
    -195,  -195,  1482,   132,   496,   -43,  1507,  1712,   568,    54,
     158,  -195,  -195,   159,   167,   160,  -195,  -195,   640,  -195,
    1850,  -195,  -195,  1288,   -18,   149,  1712,    46,  -195,  -195,
     152,   176,   208,   165,   712,  1538,  -195,    87,   169,   156,
    1650,   170,  1712,   173,   174,  -195,   784,  1968,   182,  1288,
    1563,   168,  -195,  1288,   161,   188,  -195,  1288,  -195,   179,
     187,   189,  1288,  -195,   192,  -195,  1650,  -195,  -195,  -195,
    -195,   211,   856,  -195,  1694,   928,   197,  1712,  1000,  1288,
    1288,  1288,  1288,  -195,  1968,  -195,   191,  -195,  1712,  1594,
    -195,  1072,   352,   352,  -195,   206,  1619,   207,  -195,  -195,
    -195,  -195,  1883,  -195,   304,   212,  1817,   199,   200,  1288,
    1288,  1144,  1216,  -195,  -195
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     7,     1,    56,     3,     4,
       0,     0,     0,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    39,    38,    37,    36,   124,    45,    41,
      42,    43,    44,     0,    54,     0,     0,     0,    24,   126,
       2,    47,     0,   128,     0,     0,    10,    55,     0,     0,
       0,   118,   120,   113,   114,   104,   106,   109,   110,   111,
     112,     0,   121,   122,     0,     0,     0,     0,     0,    40,
      53,    51,     0,     0,    25,    46,   125,     0,    22,     5,
       0,     0,    11,     0,   115,   116,   119,   105,   108,   107,
      21,     0,   117,     0,    74,   124,     0,    94,     0,    93,
     100,   101,     0,   123,    20,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   124,     0,    85,    90,     0,
       0,    80,    79,    62,     0,     0,     0,     0,    13,     0,
       8,     0,     0,     0,    75,     0,     0,   103,    73,     0,
       0,   127,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    89,     0,     0,     0,    61,    18,
       0,     0,     0,     0,     0,     0,    23,     6,     0,   102,
      92,    99,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    98,    97,     0,    95,     0,    86,    88,     0,    52,
       0,    15,    50,     0,    58,     0,     0,     0,     9,    12,
       0,     0,     0,     0,     0,     0,    66,     0,     0,     0,
       0,     0,     0,     0,     0,    19,     0,     0,     0,     0,
       0,     0,    14,     0,     0,     0,    76,     0,    63,     0,
       0,     0,     0,    67,     0,    77,    96,    78,    91,    49,
      57,    60,     0,    17,     0,     0,     0,     0,     0,     0,
       0,     0,    72,    87,     0,    48,     0,    84,     0,     0,
      64,     0,    71,    69,    59,     0,     0,     0,    65,    70,
      68,    16,     0,    83,   124,     0,     0,     0,     0,     0,
       0,     0,     0,    82,    81
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -195,  -195,    36,    -1,  -195,     0,    -3,  -195,   -39,  -195,
      70,     4,  -194,  -136,  -195,  -143,   -56,    59,  -137,  -146,
    -195,   142,   117,   -26,   104
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,   117,     3,    35,   118,   119,    38,    39,    40,
      41,    42,   163,   120,   121,   209,    43,   123,    98,   183,
     184,    99,   100,   140,    44
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      37,    68,   170,    36,    46,    12,   185,    48,   174,    50,
      82,    47,   178,   217,     4,    65,   122,    77,   147,    66,
     188,     1,    62,   240,   181,   182,   192,   134,   218,   203,
     133,    78,    37,    37,     6,    36,    36,    37,   193,    34,
      36,     7,    74,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,   190,    62,    63,    64,   216,    91,     5,
     264,    90,    97,   148,   122,    91,    67,  -128,   104,    88,
     191,    34,    34,   207,   208,    86,    34,    45,   130,    89,
     221,  -128,   124,   242,    87,   125,    49,   245,   122,   153,
      50,   248,   122,   168,   222,    79,   252,   127,    67,   128,
     122,    72,    69,    80,   156,    70,    71,   256,    73,    50,
      75,   135,    83,   261,   262,   263,   150,    84,   122,   269,
     270,    91,   122,   162,   159,    28,    29,    30,    31,    32,
     124,    76,   122,   125,    81,    85,    97,   122,   138,    92,
     173,   126,   103,   281,   282,   127,   131,   128,   122,   132,
      91,   135,   142,   104,   230,    28,    29,    30,    31,    32,
     122,   143,   144,   122,   145,   146,   198,   122,   231,   101,
     101,   122,   151,   152,   167,    65,   122,   175,   177,   158,
     180,   101,   189,   194,   234,   196,   122,    91,   195,   122,
     215,   197,   122,   122,   122,   122,   122,   101,   212,   201,
     101,   199,   210,   211,   213,   122,   122,   122,   102,   219,
     224,   225,   223,   226,   162,   101,   232,   233,   235,   129,
     101,   237,   238,   122,   122,   122,   122,   241,   244,   101,
     247,   165,   246,   158,   250,   136,   251,   158,   137,   249,
     253,    97,   254,   101,   101,   258,   101,   158,   276,     7,
     101,   162,   265,   149,   271,   273,   277,   171,   155,   279,
     280,     0,     0,   228,    93,     0,     0,   160,     0,    91,
     154,     0,   275,    91,     0,   158,   104,     0,     0,     0,
       0,   101,     0,     0,   172,     0,     0,     0,   176,    95,
      28,    29,    30,    31,    32,     0,     0,     0,    96,     0,
     101,   158,     0,     0,   158,     0,     0,   158,     0,     0,
       0,   158,     0,     0,     0,     0,   101,     0,     0,   205,
     158,   158,   158,     0,     0,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,   220,     0,
     158,   158,     0,     0,     0,     0,    65,     0,   101,     0,
      66,   101,     0,     0,   236,   105,   106,   107,     0,     0,
     108,     0,   101,     0,     0,     0,     0,   109,     0,   110,
     111,   207,   208,     0,     0,     0,     0,     0,     0,     7,
      67,     0,     0,     0,     0,     0,     0,     8,     9,   259,
       0,     0,     0,     0,   112,     0,     0,     0,     0,     0,
     266,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,     0,     0,    24,    25,   113,   114,    26,   115,
      28,    29,    30,    31,    32,   116,    33,   105,   106,   107,
       0,     0,   108,     0,     0,     0,     0,     0,     0,   109,
       0,   110,   111,     0,     0,     0,     0,     0,     0,     0,
       0,     7,     0,     0,     0,     0,     0,     0,     0,     8,
       9,     0,     0,     0,     0,     0,   112,     0,     0,     0,
       0,     0,     0,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,     0,   157,    24,    25,   113,   114,
      26,   115,    28,    29,    30,    31,    32,   116,    33,   105,
     106,   107,     0,     0,   108,     0,     0,     0,     0,     0,
       0,   109,     0,   110,   111,     0,     0,     0,     0,     0,
       0,     0,     0,     7,     0,     0,     0,     0,     0,     0,
       0,     8,     9,     0,     0,     0,     0,     0,   112,     0,
       0,     0,     0,     0,     0,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,     0,   202,    24,    25,
     113,   114,    26,   115,    28,    29,    30,    31,    32,   116,
      33,   105,   106,   107,     0,     0,   108,     0,     0,     0,
       0,     0,     0,   109,     0,   110,   111,     0,     0,     0,
       0,     0,     0,     0,     0,     7,     0,     0,     0,     0,
       0,     0,     0,     8,     9,     0,     0,     0,     0,     0,
     112,     0,     0,     0,     0,     0,     0,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,     0,   206,
      24,    25,   113,   114,    26,   115,    28,    29,    30,    31,
      32,   116,    33,   105,   106,   107,     0,     0,   108,     0,
       0,     0,     0,     0,     0,   109,     0,   110,   111,     0,
       0,     0,     0,     0,     0,     0,     0,     7,     0,     0,
       0,     0,     0,     0,     0,     8,     9,     0,     0,     0,
       0,     0,   112,     0,     0,     0,     0,     0,     0,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
       0,   214,    24,    25,   113,   114,    26,   115,    28,    29,
      30,    31,    32,   116,    33,   105,   106,   107,     0,     0,
     108,     0,     0,     0,     0,     0,     0,   109,     0,   110,
     111,     0,     0,     0,     0,     0,     0,     0,     0,     7,
       0,     0,     0,     0,     0,     0,     0,     8,     9,     0,
       0,     0,     0,     0,   112,     0,     0,     0,     0,     0,
       0,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,   227,     0,    24,    25,   113,   114,    26,   115,
      28,    29,    30,    31,    32,   116,    33,   105,   106,   107,
       0,     0,   108,     0,     0,     0,     0,     0,     0,   109,
       0,   110,   111,     0,     0,     0,     0,     0,     0,     0,
       0,     7,     0,     0,     0,     0,     0,     0,     0,     8,
       9,     0,     0,     0,     0,     0,   112,     0,     0,     0,
       0,     0,     0,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,     0,   239,    24,    25,   113,   114,
      26,   115,    28,    29,    30,    31,    32,   116,    33,   105,
     106,   107,     0,     0,   108,     0,     0,     0,     0,     0,
       0,   109,     0,   110,   111,     0,     0,     0,     0,     0,
       0,     0,     0,     7,     0,     0,     0,     0,     0,     0,
       0,     8,     9,     0,     0,     0,     0,     0,   112,     0,
       0,     0,     0,     0,     0,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,     0,   255,    24,    25,
     113,   114,    26,   115,    28,    29,    30,    31,    32,   116,
      33,   105,   106,   107,     0,     0,   108,     0,     0,     0,
       0,     0,     0,   109,     0,   110,   111,     0,     0,     0,
       0,     0,     0,     0,     0,     7,     0,     0,     0,     0,
       0,     0,     0,     8,     9,     0,     0,     0,     0,     0,
     112,     0,     0,     0,     0,     0,     0,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,     0,   257,
      24,    25,   113,   114,    26,   115,    28,    29,    30,    31,
      32,   116,    33,   105,   106,   107,     0,     0,   108,     0,
       0,     0,     0,     0,     0,   109,     0,   110,   111,     0,
       0,     0,     0,     0,     0,     0,     0,     7,     0,     0,
       0,     0,     0,     0,     0,     8,     9,     0,     0,     0,
       0,     0,   112,     0,     0,     0,     0,     0,     0,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
       0,   260,    24,    25,   113,   114,    26,   115,    28,    29,
      30,    31,    32,   116,    33,   105,   106,   107,     0,     0,
     108,     0,     0,     0,     0,     0,     0,   109,     0,   110,
     111,     0,     0,     0,     0,     0,     0,     0,     0,     7,
       0,     0,     0,     0,     0,     0,     0,     8,     9,     0,
       0,     0,     0,     0,   112,     0,     0,     0,     0,     0,
       0,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,     0,   268,    24,    25,   113,   114,    26,   115,
      28,    29,    30,    31,    32,   116,    33,   105,   106,   107,
       0,     0,   108,     0,     0,     0,     0,     0,     0,   109,
       0,   110,   111,     0,     0,     0,     0,     0,     0,     0,
       0,     7,     0,     0,     0,     0,     0,     0,     0,     8,
       9,     0,     0,     0,     0,     0,   112,     0,     0,     0,
       0,     0,     0,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,     0,   283,    24,    25,   113,   114,
      26,   115,    28,    29,    30,    31,    32,   116,    33,   105,
     106,   107,     0,     0,   108,     0,     0,     0,     0,     0,
       0,   109,     0,   110,   111,     0,     0,     0,     0,     0,
       0,     0,     0,     7,     0,     0,     0,     0,     0,     0,
       0,     8,     9,     0,     0,     0,     0,     0,   112,     0,
       0,     0,     0,     0,     0,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,     0,   284,    24,    25,
     113,   114,    26,   115,    28,    29,    30,    31,    32,   116,
      33,   105,   106,   107,     0,     0,   108,     0,     0,     0,
       0,     0,     0,   109,     0,   110,   111,     0,     0,     0,
       0,     0,     0,     0,     0,     7,     0,     0,     0,     0,
       0,     0,     0,     8,     9,     0,     0,     0,     0,     0,
     112,     0,     0,     0,     0,     0,     0,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,     0,     0,
      24,    25,   113,   114,    26,   115,    28,    29,    30,    31,
      32,   116,    33,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,   139,    62,    63,    64,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,     0,    62,    63,
      64,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   141,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,     0,    62,    63,    64,     0,     0,    67,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   166,
       0,     0,    67,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,     0,    62,    63,    64,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   169,    67,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,     0,    62,
      63,    64,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,     0,    62,    63,    64,     0,     0,    67,     0,
       0,     0,     0,     0,     0,     0,     0,   179,     0,   187,
       0,     0,     7,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    67,    62,    63,    64,    12,     0,     0,
     164,     0,     0,     0,     0,     0,   200,    67,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,     0,    62,
      63,    64,    95,    28,    29,    30,    31,    32,     0,     0,
       0,   204,     0,     0,     0,     0,     0,     0,    67,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,     0,
      62,    63,    64,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   229,    67,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,     0,    62,    63,    64,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   243,     0,     0,    67,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,     0,    62,    63,    64,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   267,    67,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
       0,    62,    63,    64,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   272,     0,     0,
      67,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,     0,    62,    63,    64,     0,     0,     0,     7,     0,
       0,     0,     0,     0,     0,    67,     0,     0,     0,     0,
       0,     0,     0,    93,     0,    94,     0,     0,     0,     0,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,     7,     0,    24,    25,     0,    67,    26,    95,    28,
      29,    30,    31,    32,     0,    33,    93,    96,     0,     7,
       0,     0,     0,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    93,     0,    24,    25,     0,     0,
      26,    95,    28,    29,    30,    31,    32,     0,    33,     0,
      96,     0,     0,     0,     0,     0,     0,     0,     7,    95,
      28,    29,    30,    31,    32,     0,     8,     9,    96,    10,
      11,     0,     0,    12,     0,     0,     0,     0,     0,     0,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,     7,     0,    24,    25,     0,     0,    26,    27,    28,
      29,    30,    31,    32,     0,    33,    12,     0,     0,     0,
       0,     0,   186,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,     7,     0,    24,    25,     0,     0,
      26,    27,    28,    29,    30,    31,    32,     0,    33,    12,
       0,   278,     0,     0,     0,     0,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,     7,     0,    24,
      25,     0,     0,    26,    27,    28,    29,    30,    31,    32,
       0,    33,    12,     0,     0,     0,     0,     0,     0,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
       7,     0,    24,    25,     0,     0,    26,    27,    28,    29,
      30,    31,    32,     0,    33,    12,     0,     0,     0,     0,
       0,     0,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,     7,     0,    24,    25,     0,     0,    26,
     274,    28,    29,    30,    31,    32,     0,    33,     0,     0,
       0,     0,     0,     0,     0,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,     0,     0,    24,    25,
       0,     0,    26,     0,     0,     0,   161,     0,     0,     0,
      33,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,     0,     0,    24,    25,     0,     0,    26,     0,
       0,     0,     0,     0,     0,     0,    33,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,     0,     0,
      24,    25,     0,     0,    26,     0,     0,     0,     0,     0,
       0,     0,    33
};

static const yytype_int16 yycheck[] =
{
       3,    27,   139,     3,     5,    42,   152,    10,   144,    12,
      49,     7,   148,    31,    23,    42,    72,    34,    15,    46,
     156,    12,    32,   217,    67,    68,    48,    83,    46,   175,
      67,    48,    35,    36,     0,    35,    36,    40,    60,     3,
      40,    27,    38,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,   193,    61,    68,
     254,    61,    65,    60,   120,    68,    76,    34,    68,    24,
      48,    35,    36,    19,    20,    25,    40,    67,    79,    34,
      34,    48,    31,   219,    34,    34,    67,   223,   144,   115,
      93,   227,   148,   132,    48,    24,   232,    46,    76,    48,
     156,    60,    67,    32,    60,    35,    36,   244,    67,   112,
      40,    67,    44,   249,   250,   251,   112,    34,   174,   262,
     263,   124,   178,   126,   124,    68,    69,    70,    71,    72,
      31,    67,   188,    34,    67,    34,   139,   193,    44,    34,
     143,    42,    34,   279,   280,    46,    67,    48,   204,    34,
     153,    67,    42,   153,    67,    68,    69,    70,    71,    72,
     216,    42,    60,   219,    23,    42,   167,   223,   207,    65,
      66,   227,    42,    42,    24,    42,   232,    23,    42,   120,
      67,    77,    48,    67,   210,    34,   242,   190,    44,   245,
     190,    45,   248,   249,   250,   251,   252,    93,    31,    67,
      96,    48,    44,    44,    44,   261,   262,   263,    66,    60,
      34,     3,    60,    48,   217,   111,    47,    61,    48,    77,
     116,    48,    48,   279,   280,   281,   282,    45,    60,   125,
      42,   127,    71,   174,    47,    93,    47,   178,    96,    60,
      48,   244,    31,   139,   140,    48,   142,   188,   274,    27,
     146,   254,    61,   111,    48,    48,    44,   140,   116,    60,
      60,    -1,    -1,   204,    42,    -1,    -1,   125,    -1,   272,
      48,    -1,   272,   276,    -1,   216,   276,    -1,    -1,    -1,
      -1,   177,    -1,    -1,   142,    -1,    -1,    -1,   146,    67,
      68,    69,    70,    71,    72,    -1,    -1,    -1,    76,    -1,
     196,   242,    -1,    -1,   245,    -1,    -1,   248,    -1,    -1,
      -1,   252,    -1,    -1,    -1,    -1,   212,    -1,    -1,   177,
     261,   262,   263,    -1,    -1,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,   196,    -1,
     281,   282,    -1,    -1,    -1,    -1,    42,    -1,   244,    -1,
      46,   247,    -1,    -1,   212,     3,     4,     5,    -1,    -1,
       8,    -1,   258,    -1,    -1,    -1,    -1,    15,    -1,    17,
      18,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    27,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,   247,
      -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,
     258,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    -1,    -1,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,     3,     4,     5,
      -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      -1,    17,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      36,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    -1,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,     3,
       4,     5,    -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    -1,    17,    18,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    27,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    36,    -1,    -1,    -1,    -1,    -1,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    -1,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,     3,     4,     5,    -1,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    -1,    17,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    36,    -1,    -1,    -1,    -1,    -1,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    -1,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,     3,     4,     5,    -1,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    -1,    17,    18,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    36,    -1,    -1,    -1,
      -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      -1,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,     3,     4,     5,    -1,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,    17,
      18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    -1,
      -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    -1,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,     3,     4,     5,
      -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      -1,    17,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      36,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    -1,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,     3,
       4,     5,    -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    -1,    17,    18,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    27,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    36,    -1,    -1,    -1,    -1,    -1,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    -1,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,     3,     4,     5,    -1,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    -1,    17,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    36,    -1,    -1,    -1,    -1,    -1,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    -1,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,     3,     4,     5,    -1,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    -1,    17,    18,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    36,    -1,    -1,    -1,
      -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      -1,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,     3,     4,     5,    -1,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,    17,
      18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    -1,
      -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    -1,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,     3,     4,     5,
      -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      -1,    17,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      36,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    -1,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,     3,
       4,     5,    -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    -1,    17,    18,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    27,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    36,    -1,    -1,    -1,    -1,    -1,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    -1,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,     3,     4,     5,    -1,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    -1,    17,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    36,    -1,    -1,    -1,    -1,    -1,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    -1,    -1,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    -1,    32,    33,
      34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    -1,    32,    33,    34,    -1,    -1,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      -1,    -1,    76,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    -1,    32,    33,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    76,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    -1,    32,
      33,    34,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    -1,    32,    33,    34,    -1,    -1,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,    48,
      -1,    -1,    27,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    76,    32,    33,    34,    42,    -1,    -1,
      45,    -1,    -1,    -1,    -1,    -1,    44,    76,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    -1,    32,
      33,    34,    67,    68,    69,    70,    71,    72,    -1,    -1,
      -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,    76,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    -1,
      32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    76,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    -1,    32,    33,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    48,    -1,    -1,    76,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    -1,    32,    33,    34,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    76,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      -1,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    -1,    -1,
      76,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    -1,    32,    33,    34,    -1,    -1,    -1,    27,    -1,
      -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    -1,    44,    -1,    -1,    -1,    -1,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    27,    -1,    62,    63,    -1,    76,    66,    67,    68,
      69,    70,    71,    72,    -1,    74,    42,    76,    -1,    27,
      -1,    -1,    -1,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    42,    -1,    62,    63,    -1,    -1,
      66,    67,    68,    69,    70,    71,    72,    -1,    74,    -1,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    67,
      68,    69,    70,    71,    72,    -1,    35,    36,    76,    38,
      39,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    27,    -1,    62,    63,    -1,    -1,    66,    67,    68,
      69,    70,    71,    72,    -1,    74,    42,    -1,    -1,    -1,
      -1,    -1,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    27,    -1,    62,    63,    -1,    -1,
      66,    67,    68,    69,    70,    71,    72,    -1,    74,    42,
      -1,    44,    -1,    -1,    -1,    -1,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    27,    -1,    62,
      63,    -1,    -1,    66,    67,    68,    69,    70,    71,    72,
      -1,    74,    42,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      27,    -1,    62,    63,    -1,    -1,    66,    67,    68,    69,
      70,    71,    72,    -1,    74,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    27,    -1,    62,    63,    -1,    -1,    66,
      67,    68,    69,    70,    71,    72,    -1,    74,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    -1,    -1,    62,    63,
      -1,    -1,    66,    -1,    -1,    -1,    44,    -1,    -1,    -1,
      74,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    -1,    -1,    62,    63,    -1,    -1,    66,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    74,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    -1,    -1,
      62,    63,    -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    74
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    12,    78,    80,    23,    68,     0,    27,    35,    36,
      38,    39,    42,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    62,    63,    66,    67,    68,    69,
      70,    71,    72,    74,    79,    81,    82,    83,    84,    85,
      86,    87,    88,    93,   101,    67,    80,    88,    83,    67,
      83,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    42,    46,    76,   100,    67,
      87,    87,    60,    67,    88,    87,    67,    34,    48,    24,
      32,    67,    85,    44,    34,    34,    25,    34,    24,    34,
      82,    83,    34,    42,    44,    67,    76,    83,    95,    98,
      99,   101,    98,    34,    82,     3,     4,     5,     8,    15,
      17,    18,    42,    64,    65,    67,    73,    79,    82,    83,
      90,    91,    93,    94,    31,    34,    42,    46,    48,    98,
      80,    67,    34,    67,    93,    67,    98,    98,    44,    31,
     100,    45,    42,    42,    60,    23,    42,    15,    60,    98,
      88,    42,    42,   100,    48,    98,    60,    61,    94,    82,
      98,    44,    83,    89,    45,   101,    48,    24,    85,    44,
      95,    99,    98,    83,    90,    23,    98,    42,    90,    60,
      67,    67,    68,    96,    97,    96,    48,    48,    90,    48,
      31,    48,    48,    60,    67,    44,    34,    45,    80,    48,
      44,    67,    61,    96,    44,    98,    61,    19,    20,    92,
      44,    44,    31,    44,    61,    82,    90,    31,    46,    60,
      98,    34,    48,    60,    34,     3,    48,    60,    94,    44,
      67,    85,    47,    61,   100,    48,    98,    48,    48,    61,
      89,    45,    90,    48,    60,    90,    71,    42,    90,    60,
      47,    47,    90,    48,    31,    61,    95,    61,    48,    98,
      61,    90,    90,    90,    89,    61,    98,    44,    61,    92,
      92,    48,    48,    48,    67,    82,   100,    44,    44,    60,
      60,    90,    90,    61,    61
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    77,    78,    79,    79,    80,    80,    80,    80,    80,
      80,    81,    81,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    83,    83,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    85,    85,    85,    85,    85,    86,    86,    87,    87,
      87,    87,    87,    87,    87,    88,    88,    89,    89,    89,
      89,    90,    90,    91,    91,    91,    91,    91,    92,    92,
      92,    92,    92,    93,    93,    93,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    95,    95,    95,    96,    97,    97,    97,    98,
      98,    99,    99,    99,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   101,   101,   101,   101,   101
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     4,     6,     2,     5,     7,
       3,     3,     6,     3,     6,     5,    10,     7,     4,     6,
       3,     3,     2,     4,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     1,     1,     1,     1,     2,     1,     8,     7,
       5,     2,     5,     2,     1,     2,     1,     4,     2,     6,
       4,     2,     1,     5,     7,     8,     4,     5,     5,     4,
       5,     4,     3,     4,     3,     4,     5,     5,     5,     1,
       1,    15,    14,     9,     7,     1,     3,     6,     3,     2,
       1,     5,     3,     1,     1,     1,     3,     1,     1,     3,
       1,     1,     3,     2,     1,     2,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     2,     2,     2,     1,     2,
       1,     1,     1,     2,     1,     2,     1,     4,     1
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
#line 193 "scanner.y"
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
        			free(resultado); // Libera la memoria asignada por insertTabsBetweenBraces
        			fclose(fp);
    			}
		}

                free((yyvsp[0].valString));
                
        }
#line 2086 "scanner.tab.c"
    break;

  case 3: /* comment: COMMENTLINE  */
#line 244 "scanner.y"
                     {
                (yyval.valString) = (yyvsp[0].valString);
                }
#line 2094 "scanner.tab.c"
    break;

  case 4: /* comment: MULTILINE  */
#line 247 "scanner.y"
                    {;}
#line 2100 "scanner.tab.c"
    break;

  case 5: /* cabecera: PROGRAM LOWER STRINGV HIGHER  */
#line 252 "scanner.y"
                                             {
	 		free((yyvsp[-1].valString));
			(yyval.valString) = "";

		}
#line 2110 "scanner.tab.c"
    break;

  case 6: /* cabecera: PROGRAM LOWER STRINGV DOT STRINGV HIGHER  */
#line 257 "scanner.y"
                                                          {
			
			free((yyvsp[-3].valString));
			free((yyvsp[-1].valString));
			(yyval.valString) = "";
		}
#line 2121 "scanner.tab.c"
    break;

  case 7: /* cabecera: PROGRAM QUOTESTRING  */
#line 263 "scanner.y"
                                     {
                        #pragma omp critical
			{       
    				char final[100] = "";
    				char fichero[50] = "";

   	 			strcat(fichero, (yyvsp[0].valString));
    				free((yyvsp[0].valString));
    				deleteQuotes(fichero);

    				// Asegurarse de que no se elimina más caracteres de los necesarios
    				if (strlen(fichero) > 2) {
        				fichero[strlen(fichero) - 2] = '\0';
    				}

    				char ruta[100] = "entrada/";

    				strcat(final, fichero);
    				strcat(final, ".c");
    				printf("-----------------%s------------------ \n", final);

    				strcat(ruta, final);
    				if (searchString(arrayCabeceras, ruta, arraySize) == 0) {
        				arraySize++;
        				arrayCabeceras = (char**)realloc(arrayCabeceras, arraySize * sizeof(char*));
        
        				// Asignar espacio suficiente para ruta con terminador nulo
        				arrayCabeceras[arraySize - 1] = (char*)malloc((strlen(ruta) + 1) * sizeof(char)); 
        				if (arrayCabeceras[arraySize - 1] == NULL) {
            					printf("Error al asignar memoria para arrayCabeceras[%d]\n", arraySize - 1);
            					exit(1);
        				}

        				strcpy(arrayCabeceras[arraySize - 1], ruta);

        				printf("array size %i\n\n", arraySize);
        				printf("array cabeceras %s\n\n", arrayCabeceras[arraySize - 1]);
        				printf("ruta  %s\n\n", ruta);
    				}
			}
		}
#line 2167 "scanner.tab.c"
    break;

  case 8: /* cabecera: PROGRAM LOWER STRINGV HIGHER cabecera  */
#line 304 "scanner.y"
                                                       {
			free((yyvsp[-2].valString));	
			(yyval.valString) = "";
		}
#line 2176 "scanner.tab.c"
    break;

  case 9: /* cabecera: PROGRAM LOWER STRINGV DOT STRINGV HIGHER cabecera  */
#line 308 "scanner.y"
                                                                  {
			free((yyvsp[-4].valString));
			free((yyvsp[-2].valString));
			(yyval.valString) = "";
		}
#line 2186 "scanner.tab.c"
    break;

  case 10: /* cabecera: PROGRAM QUOTESTRING cabecera  */
#line 313 "scanner.y"
                                             {
                                                
			#pragma omp critical
			{       
				char final[100] = "";
				char fichero[50] = "";
				strcat(fichero, (yyvsp[-1].valString));
				free((yyvsp[-1].valString));
				deleteQuotes(fichero);
				fichero[strlen(fichero) - 2] = '\0';

				char ruta[100] = "entrada/";

				strcat(final, fichero);
				strcat(final, ".c");
				printf("-----------------%s------------------ \n", final);
				strcat(ruta, final);

				if (searchString(arrayCabeceras, ruta, arraySize) == 0) {
					arraySize++;
					arrayCabeceras = (char**)realloc(arrayCabeceras, arraySize * sizeof(char*));

					// Cambiado para incluir el espacio del terminador nulo
					arrayCabeceras[arraySize - 1] = (char*)malloc((strlen(ruta) + 1) * sizeof(char)); 

					strcpy(arrayCabeceras[arraySize - 1], ruta);
					printf("array size %i\n\n", arraySize);
					printf("array cabeceras %s\n\n", arrayCabeceras[arraySize - 1]);
					printf("ruta  %s\n\n", ruta);
				}
			}

                }
#line 2224 "scanner.tab.c"
    break;

  case 11: /* constdef: DEFINE STRINGV values  */
#line 349 "scanner.y"
                              {
		// Calcular el tamaño total necesario para `final`
		size_t size_final = strlen((yyvsp[-1].valString)) + strlen((yyvsp[0].valString)) + 6 + 10 + 2 + 1; // +1 para el terminador nulo
		char *final = malloc(size_final * sizeof(char));

		// Inicializar toda la memoria asignada con ceros
		memset(final, 0, size_final * sizeof(char));

		strcat(final, "const ");
		strcat(final, (yyvsp[-1].valString));
		strcat(final, ": usize = ");
		strcat(final, (yyvsp[0].valString));
		strcat(final, ";\n");

		free((yyvsp[0].valString));
		free((yyvsp[-1].valString));
		(yyval.valString) = final;
	}
#line 2247 "scanner.tab.c"
    break;

  case 12: /* constdef: CONST types STRINGV EQ values SEMICOLON  */
#line 369 "scanner.y"
                                                 {
                
		free((yyvsp[-3].valString));
		free((yyvsp[-1].valString));
	}
#line 2257 "scanner.tab.c"
    break;

  case 13: /* vardef: types STRINGV SEMICOLON  */
#line 380 "scanner.y"
                                {
		char *tipo;
		if (strcmp(obtenerTipo((yyvsp[-2].valInt)), "struct") == 0) {
			printf("\n\n TIPO TIPO %s TIPO TIPO \n \n", obtenerTipo((yyvsp[-2].valInt)));
			tipo = tipoStruct;
		} else {
			tipo = obtenerTipo((yyvsp[-2].valInt));
		}

		// Asigna espacio suficiente para `final` y el terminador nulo
		char *final = malloc(strlen(tipo) + strlen((yyvsp[-1].valString)) + strlen("let\n: ;") + 1);

		// Inicializa la memoria asignada
		memset(final, 0, strlen(tipo) + strlen((yyvsp[-1].valString)) + strlen("let\n: ;") + 1);

		// Concatenación de strings
		strcat(final, "let ");
		strcat(final, (yyvsp[-1].valString));
		strcat(final, ":");
		strcat(final, tipo);
		strcat(final, ";\n");

		free((yyvsp[-1].valString));
		(yyval.valString) = final;
	}
#line 2287 "scanner.tab.c"
    break;

  case 14: /* vardef: types STRINGV LSQUAREPAREN atom RSQUAREPAREN SEMICOLON  */
#line 406 "scanner.y"
                                                                {
                char *tipo;
                if (strcmp(obtenerTipo((yyvsp[-5].valInt)), "struct") == 0) {
                        tipo = tipoStruct;
                        
                }else{
                        tipo = obtenerTipo((yyvsp[-5].valInt));

                }
                char * final = malloc(strlen(tipo)* sizeof(char) +strlen((yyvsp[-4].valString))* sizeof(char) + strlen((yyvsp[-2].valString))*sizeof(char) + sizeof("[]; : ;\n"));
                memset(final, 0 , sizeof(final));
                strcat(final, (yyvsp[-4].valString));
                strcat(final, ": [");
                strcat(final, tipo);
                strcat(final, ";");
                strcat(final, (yyvsp[-2].valString));
                strcat(final, "];\n");
		free((yyvsp[-4].valString));
		free((yyvsp[-2].valString));
                (yyval.valString) = final;
        }
#line 2313 "scanner.tab.c"
    break;

  case 15: /* vardef: types STRINGV EQ exp SEMICOLON  */
#line 429 "scanner.y"
                                         {//2
		char *tipo;
		if (strcmp(obtenerTipo((yyvsp[-4].valInt)), "struct") == 0) {
			tipo = tipoStruct; // tipoStruct no debe liberarse si no está en el heap
		} else {
			// Asignar una copia de `obtenerTipo($1)` si es necesario
			tipo = strdup(obtenerTipo((yyvsp[-4].valInt))); // strdup asigna memoria dinámica y copia la cadena
		}

		// Calcular el tamaño correctamente para `final` e incluir el terminador nulo
		char *final = malloc(strlen(tipo) + strlen((yyvsp[-1].valString)) + strlen((yyvsp[-3].valString)) + strlen("=let\n: ;") + 1);

		// Inicializar `final` correctamente
		final[0] = '\0';

		// Concatenación de las cadenas en `final`
		strcat(final, "let ");
		strcat(final, (yyvsp[-3].valString));
		strcat(final, ":");
		strcat(final, tipo);
		strcat(final, "=");
		strcat(final, (yyvsp[-1].valString));
		strcat(final, ";\n");

		// Liberar la memoria de las variables temporales
		free((yyvsp[-3].valString));
		//free($4);

		// Liberar `tipo` solo si fue asignado dinámicamente
		if (tipo != tipoStruct) {
			free(tipo);
		}
		(yyval.valString) = final;
        }
#line 2352 "scanner.tab.c"
    break;

  case 16: /* vardef: types STRINGV LSQUAREPAREN atom RSQUAREPAREN EQ OPENCURLYBRACKET array CLOSECURLYBRACKET SEMICOLON  */
#line 464 "scanner.y"
                                                                                                            {//4
		char *tipo;
		if (strcmp(obtenerTipo((yyvsp[-9].valInt)), "struct") == 0) {
		    tipo = tipoStruct;
		} else {
		    tipo = obtenerTipo((yyvsp[-9].valInt));
		}

		// Calcular correctamente el tamaño de `malloc` y asegurar espacio para el terminador nulo
		char *final = malloc(strlen((yyvsp[-8].valString)) + strlen(tipo) + strlen((yyvsp[-6].valString)) + strlen((yyvsp[-2].valString)) + strlen("let ::[] [] ; \n") + 1);

		// Inicializar `final`
		final[0] = '\0';

		// Concatenar las cadenas de manera segura
		strcat(final, "let ");
		strcat(final, (yyvsp[-8].valString));
		strcat(final, ": [");
		strcat(final, tipo);
		strcat(final, ":");
		strcat(final, (yyvsp[-6].valString));
		strcat(final, "] = [");
		strcat(final, (yyvsp[-2].valString));
		strcat(final, "];\n");

		// Liberar la memoria de las variables temporales
		free((yyvsp[-8].valString));
		free((yyvsp[-6].valString));
		free((yyvsp[-2].valString));
		(yyval.valString) = final;
        }
#line 2388 "scanner.tab.c"
    break;

  case 17: /* vardef: types STRINGV LSQUAREPAREN RSQUAREPAREN EQ exp SEMICOLON  */
#line 495 "scanner.y"
                                                                  {//4
                char *tipo;
                if (strcmp(obtenerTipo((yyvsp[-6].valInt)), "struct") == 0) {
                        tipo = tipoStruct;
                        
                }else{
                        tipo = obtenerTipo((yyvsp[-6].valInt));

                }                
		char * final = malloc(strlen((yyvsp[-5].valString))*sizeof(char) + strlen(tipo)*sizeof(char) + strlen((yyvsp[-1].valString))*sizeof(char) + sizeof("let ::[] [] ; \n"));
                memset(final,0,sizeof(final));
                
                strcat(final,"let ");
                strcat(final,(yyvsp[-5].valString));
                strcat(final,"=");
                strcat(final,(yyvsp[-1].valString));
                strcat(final,";");
		free((yyvsp[-5].valString));
		free((yyvsp[-1].valString));
                (yyval.valString) = final;
        }
#line 2414 "scanner.tab.c"
    break;

  case 18: /* vardef: types STRINGV COMMA vardef  */
#line 538 "scanner.y"
                                     {  //7
		char *tipo;
		if (strcmp(obtenerTipo((yyvsp[-3].valInt)), "struct") == 0) {
			tipo = tipoStruct;
		} else {
			tipo = obtenerTipo((yyvsp[-3].valInt));
		}                
		strcpy(gType, tipo);

		// Reserva memoria suficiente para la cadena final
		size_t longitud_final = strlen((yyvsp[-2].valString)) + strlen((yyvsp[0].valString)) + strlen(tipo) + strlen("let :;\n") + 1;
		char *final = malloc(longitud_final * sizeof(char));
		if (final == NULL) {
			(yyval.valString) = "";  // Asigna NULL en caso de fallo en la reserva
			
		}
		final[0] = '\0';  // Inicializa final con el terminador nulo

		strcat(final, "let ");
		strcat(final, (yyvsp[-2].valString));
		strcat(final, ":;\n");
		strcat(final, (yyvsp[0].valString));
		free((yyvsp[-2].valString));
		free((yyvsp[0].valString));

		char modTipo1[4 + strlen(tipo) + 3]; // Buffer para reemplazo de ":;\n" (3 caracteres adicionales para '\0')
		char modTipo2[4 + strlen(tipo) + 2]; // Buffer para reemplazo de ":=" (2 caracteres adicionales para '\0')

		// Inicializa modTipo1 y modTipo2 antes de concatenar en ellos
		modTipo1[0] = '\0';
		modTipo2[0] = '\0';

		if (strstr(final, ":;") != NULL) {
			strcat(modTipo1, ":");
			strcat(modTipo1, tipo);
			strcat(modTipo1, ";\n");
		}

		if (strstr(final, ":=") != NULL) {
			strcat(modTipo2, ":");
			strcat(modTipo2, tipo);
			strcat(modTipo2, "=");
		}

		// Primera llamada a reemplazar
		char *finalMod = reemplazar(final, ":;", modTipo1);

		if (finalMod != NULL) {
			char *temp = reemplazar(finalMod, ":=", modTipo2);  // Segunda llamada a reemplazar
			free(finalMod);  // Liberar la memoria asignada por la primera llamada

			if (temp != NULL) {
    				(yyval.valString) = temp;
			} else {
    				(yyval.valString) = final;  // Usar el resultado de la primera llamada si la segunda falla
			}
		} else {
			// Manejar el error si la primera llamada a reemplazar falla
			(yyval.valString) = final;  // Devolver la cadena original si falla
		}
	}
#line 2480 "scanner.tab.c"
    break;

  case 19: /* vardef: types STRINGV EQ exp COMMA vardef  */
#line 599 "scanner.y"
                                           {//8
                // Asignación de tipo en base al valor de $1
char *tipo;
if (strcmp(obtenerTipo((yyvsp[-5].valInt)), "struct") == 0) {
    tipo = tipoStruct;
} else {
    tipo = obtenerTipo((yyvsp[-5].valInt));
}

// Asignación y verificación de memoria para 'final'
size_t size_final = strlen("let ") + strlen((yyvsp[-4].valString)) + strlen(":=") + strlen((yyvsp[-2].valString)) + strlen(";\n") + strlen((yyvsp[0].valString)) + 1;
char *final = malloc(size_final);

if (final) {
    final[0] = '\0';  // Inicializa el string como vacío

    // Construcción de la cadena `final`
    strcat(final, "let ");
    strcat(final, (yyvsp[-4].valString));
    strcat(final, ":=");
    strcat(final, (yyvsp[-2].valString));
    strcat(final, ";\n");
    strcat(final, (yyvsp[0].valString));
}

// Liberar las variables temporales
free((yyvsp[-4].valString));
free((yyvsp[-2].valString));
free((yyvsp[0].valString));

// Inicializar y construir `modTipo1` y `modTipo2` sin asignación dinámica
char modTipo1[4 + strlen(tipo) + 2];
char modTipo2[4 + strlen(tipo) + 2];
modTipo1[0] = '\0';
modTipo2[0] = '\0';

if (strstr(final, ":;") != NULL) {
    strcat(modTipo1, ":");
    strcat(modTipo1, tipo);
    strcat(modTipo1, ";\n");
}

if (strstr(final, ":=") != NULL) {
    strcat(modTipo2, ":");
    strcat(modTipo2, tipo);
    strcat(modTipo2, "=");
}

printf("modTipo1 tiene: '%s'\n", modTipo1);  
printf("modTipo2 tiene: '%s'\n", modTipo2);

// Reemplazo de patrones en `final`
char *finalMod = reemplazar(final, ":;", modTipo1);
if (finalMod != NULL) {
    finalMod = reemplazar(finalMod, ":=", modTipo2);
    if (finalMod != NULL) {
        (yyval.valString) = finalMod;
    } else {
        // Manejar el error si la segunda llamada a reemplazar falla
    }
} else {
    // Manejar el error si la primera llamada a reemplazar falla
}
}
#line 2549 "scanner.tab.c"
    break;

  case 20: /* vardef: STRINGV operand vardef  */
#line 674 "scanner.y"
                                 {
    		size_t total_size = strlen((yyvsp[-2].valString)) + strlen((yyvsp[-1].valString)) + strlen((yyvsp[0].valString)) + strlen("; : \n") + 1;
    		char *final = malloc(total_size);

    		if (final) {  // Siempre es buena práctica verificar si malloc fue exitoso
        		final[0] = '\0'; // Inicializar el string final como vacío
        		strcat(final, (yyvsp[-2].valString));
        		strcat(final, (yyvsp[-1].valString));
        		strcat(final, (yyvsp[0].valString));
    		}

    		free((yyvsp[-2].valString)); // Libera $1 después de usarlo
		free((yyvsp[-1].valString));
		free((yyvsp[0].valString));
    		(yyval.valString) = final; // Asigna el resultado a $$
	}
#line 2570 "scanner.tab.c"
    break;

  case 21: /* vardef: STRINGV COMMA vardef  */
#line 690 "scanner.y"
                             {//10
                char * final = malloc(strlen((yyvsp[-2].valString))*sizeof(char) + sizeof("; : \n") + strlen((yyvsp[0].valString))* sizeof(char));
                memset(final, 0, sizeof(final));
                strcat(final, "");
                strcat(final, (yyvsp[-2].valString));
                strcat(final, ":;\n");
                strcat(final, (yyvsp[0].valString));
		free((yyvsp[-2].valString));
		free((yyvsp[0].valString));
                (yyval.valString) = final;
        }
#line 2586 "scanner.tab.c"
    break;

  case 22: /* vardef: atom SEMICOLON  */
#line 710 "scanner.y"
                       {//11

                char * final = malloc(strlen((yyvsp[-1].valString))*sizeof(char) + sizeof(";  \n") );
                memset(final, 0, sizeof(final));
                
                strcat(final, (yyvsp[-1].valString));
                strcat(final, ";\n");
		free((yyvsp[-1].valString));
                (yyval.valString) = final;
        }
#line 2601 "scanner.tab.c"
    break;

  case 23: /* vardef: atom EQ exp SEMICOLON  */
#line 720 "scanner.y"
                              {//12
                char * final = malloc(strlen((yyvsp[-3].valString))*sizeof(char) + sizeof("; : let \n") + strlen((yyvsp[-1].valString))*sizeof(char) );
                memset(final, 0, sizeof(final));
                strcat(final, "");
                strcat(final, (yyvsp[-3].valString));
                strcat(final, ":=");
                strcat(final, (yyvsp[-1].valString));
                strcat(final,";\n");
		free((yyvsp[-3].valString));
		free((yyvsp[-1].valString));
                (yyval.valString) = final;
        }
#line 2618 "scanner.tab.c"
    break;

  case 24: /* types: type  */
#line 740 "scanner.y"
             {
		(yyval.valInt)=(yyvsp[0].valInt);
	}
#line 2626 "scanner.tab.c"
    break;

  case 25: /* types: type prod  */
#line 743 "scanner.y"
                  {
		(yyval.valInt) = (yyvsp[-1].valInt);
	}
#line 2634 "scanner.tab.c"
    break;

  case 26: /* type: INTEGER  */
#line 749 "scanner.y"
                {(yyval.valInt) = 0;}
#line 2640 "scanner.tab.c"
    break;

  case 27: /* type: SHORT  */
#line 750 "scanner.y"
                {(yyval.valInt) = 1;}
#line 2646 "scanner.tab.c"
    break;

  case 28: /* type: LONG  */
#line 751 "scanner.y"
               {(yyval.valInt) = 2;}
#line 2652 "scanner.tab.c"
    break;

  case 29: /* type: LONG_LONG  */
#line 752 "scanner.y"
                    {(yyval.valInt) = 2;}
#line 2658 "scanner.tab.c"
    break;

  case 30: /* type: UNSIGNED_INT  */
#line 753 "scanner.y"
                       {(yyval.valInt) = 3;}
#line 2664 "scanner.tab.c"
    break;

  case 31: /* type: UNSIGNED_SHORT  */
#line 754 "scanner.y"
                         {(yyval.valInt) = 4;}
#line 2670 "scanner.tab.c"
    break;

  case 32: /* type: UNSIGNED_LONG  */
#line 755 "scanner.y"
                        {(yyval.valInt) = 5;}
#line 2676 "scanner.tab.c"
    break;

  case 33: /* type: UNSIGNED_LONG_LONG  */
#line 756 "scanner.y"
                             {(yyval.valInt) = 5;}
#line 2682 "scanner.tab.c"
    break;

  case 34: /* type: FLOAT  */
#line 757 "scanner.y"
                {(yyval.valInt) = 6;}
#line 2688 "scanner.tab.c"
    break;

  case 35: /* type: DOUBLE  */
#line 758 "scanner.y"
                 {(yyval.valInt) = 7;}
#line 2694 "scanner.tab.c"
    break;

  case 36: /* type: STRING  */
#line 759 "scanner.y"
                 {(yyval.valInt) = 8;}
#line 2700 "scanner.tab.c"
    break;

  case 37: /* type: CHAR  */
#line 760 "scanner.y"
               {(yyval.valInt) = 9;}
#line 2706 "scanner.tab.c"
    break;

  case 38: /* type: BOOLEAN  */
#line 761 "scanner.y"
                  {(yyval.valInt) = 10;}
#line 2712 "scanner.tab.c"
    break;

  case 39: /* type: VOID  */
#line 762 "scanner.y"
               {;}
#line 2718 "scanner.tab.c"
    break;

  case 40: /* type: STRUCT STRINGV  */
#line 763 "scanner.y"
                         {
                strcpy(tipoStruct, (yyvsp[0].valString));
		free((yyvsp[0].valString));
                (yyval.valInt) = 11;
        }
#line 2728 "scanner.tab.c"
    break;

  case 41: /* values: TRUEVAL  */
#line 773 "scanner.y"
                {
                (yyval.valString) = strdup("true");
        }
#line 2736 "scanner.tab.c"
    break;

  case 42: /* values: FALSEVAL  */
#line 776 "scanner.y"
                   {(yyval.valString) = (yyvsp[0].valString);}
#line 2742 "scanner.tab.c"
    break;

  case 43: /* values: INTNUM  */
#line 777 "scanner.y"
                 {(yyval.valString) = (yyvsp[0].valString);}
#line 2748 "scanner.tab.c"
    break;

  case 44: /* values: REALNUM  */
#line 778 "scanner.y"
                  {(yyval.valString) = (yyvsp[0].valString);}
#line 2754 "scanner.tab.c"
    break;

  case 45: /* values: QUOTESTRING  */
#line 779 "scanner.y"
                      {(yyval.valString) = (yyvsp[0].valString);}
#line 2760 "scanner.tab.c"
    break;

  case 46: /* preprograma: preprograma programa  */
#line 783 "scanner.y"
                            {
		char *final = malloc(strlen((yyvsp[-1].valString)) + strlen((yyvsp[0].valString)) + 1); // +1 para '\0'
		if (final == NULL) {
    		// Manejar el caso en que malloc falla
    			return 0;
		}

		final[0] = '\0'; // Iniciar la cadena para evitar problemas en strcat
		strcat(final, (yyvsp[-1].valString));
		strcat(final, (yyvsp[0].valString));

		free((yyvsp[0].valString));
		free((yyvsp[-1].valString));
		(yyval.valString) = final; // Asegúrate de liberar $$ cuando ya no se necesite
        }
#line 2780 "scanner.tab.c"
    break;

  case 47: /* preprograma: programa  */
#line 798 "scanner.y"
                   {
		char *final = malloc((strlen((yyvsp[0].valString)) + 1) * sizeof(char)); // Reservar espacio suficiente incluyendo el terminador nulo
    		memset(final, 0, (strlen((yyvsp[0].valString)) + 1) * sizeof(char)); // Inicializar toda la memoria a 0
    		strcat(final, (yyvsp[0].valString)); // Concatenar $1 en `final`
    		free((yyvsp[0].valString)); // Liberar memoria de $1
    		(yyval.valString) = final; // Asignar el resultado a $$
	}
#line 2792 "scanner.tab.c"
    break;

  case 48: /* programa: types STRINGV LPAREN args RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET  */
#line 807 "scanner.y"
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
                                strcat(final, "");
                        }
                        strcat(final, "{\n");
                        strcat(final, (yyvsp[-1].valString));
                        strcat(final, "\n");
                        strcat(final, "}\n\n");
                        free((yyvsp[-1].valString));
                        free((yyvsp[-4].valString));
			free((yyvsp[-6].valString));
                        DeleteListT (&flist);
                        
                        (yyval.valString) = final;
                
        }
#line 2843 "scanner.tab.c"
    break;

  case 49: /* programa: types STRINGV LPAREN RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET  */
#line 854 "scanner.y"
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
                free((yyvsp[-5].valString));
                free((yyvsp[-1].valString));
                DeleteListT (&flist);

                (yyval.valString) = final;
                                
                
        }
#line 2893 "scanner.tab.c"
    break;

  case 50: /* programa: types STRINGV LPAREN RPAREN SEMICOLON  */
#line 900 "scanner.y"
                                              {
                free((yyvsp[-3].valString));
		(yyval.valString) = "";
        }
#line 2902 "scanner.tab.c"
    break;

  case 51: /* programa: vardef programa  */
#line 904 "scanner.y"
                          {
                char * final = malloc(strlen((yyvsp[-1].valString))*sizeof(char) + strlen((yyvsp[0].valString))*sizeof(char) + sizeof("\n\n"));
                strcat(final,(yyvsp[-1].valString));
                strcat(final,"\n");
                strcat(final, (yyvsp[0].valString));
                strcat(final,"\n");
                free((yyvsp[-1].valString));
		free((yyvsp[0].valString));
                (yyval.valString) = final;
        }
#line 2917 "scanner.tab.c"
    break;

  case 52: /* programa: types OPENCURLYBRACKET lines_program CLOSECURLYBRACKET SEMICOLON  */
#line 915 "scanner.y"
                                                                         {
		char *tipo;

		if (strcmp(obtenerTipo((yyvsp[-4].valInt)), "struct") == 0) {
			// Calcular el tamaño total y asignar memoria para el caso de "struct"
			tipo = malloc((strlen(tipoStruct) + 1) * sizeof(char));

			if (tipo == NULL) {
				// Manejar error de asignación
				exit(1);
			}

			// Copiar el contenido de tipoStruct a tipo
			strcpy(tipo, tipoStruct);

			printf("\n\n TIPO TIPO %s TIPO TIPO \n \n", tipo);
		} else {
			// Calcular el tamaño total y asignar memoria para el caso general
			const char *tipo_obtenido = obtenerTipo((yyvsp[-4].valInt));
			tipo = malloc((strlen(tipo_obtenido) + 1) * sizeof(char));

			if (tipo == NULL) {
				// Manejar error de asignación
				exit(1);
			}

			// Copiar el contenido de tipo_obtenido a tipo
			strcpy(tipo, tipo_obtenido);
		}

                char * final = malloc(strlen(tipo) + strlen((yyvsp[-2].valString))*sizeof(char) + strlen("struct { } \n\n"));
                memset(final, 0 , sizeof(final));
                strcat(final, "struct ");
                strcat(final, tipo);
                strcat(final, " {\n");
                strcat(final, (yyvsp[-2].valString));
                strcat(final, "}\n");
                replaceSemicolon(final);
		free(tipo);
		free((yyvsp[-2].valString));
                (yyval.valString) = final; 
        }
#line 2964 "scanner.tab.c"
    break;

  case 53: /* programa: constdef programa  */
#line 957 "scanner.y"
                            {
		// Asigna espacio suficiente para `final` y el terminador nulo
		char * final = malloc(strlen((yyvsp[0].valString)) + strlen((yyvsp[-1].valString)) + 1);

		// Inicializa la memoria asignada con ceros
		memset(final, 0, strlen((yyvsp[0].valString)) + strlen((yyvsp[-1].valString)) + 1);

		// Concatenación de strings
		strcat(final, (yyvsp[-1].valString));
		strcat(final, (yyvsp[0].valString));

		free((yyvsp[-1].valString));
		free((yyvsp[0].valString));
		(yyval.valString) = final;
	}
#line 2984 "scanner.tab.c"
    break;

  case 54: /* programa: comment  */
#line 973 "scanner.y"
                {;}
#line 2990 "scanner.tab.c"
    break;

  case 55: /* prod: PROD prod  */
#line 978 "scanner.y"
                 {
		(yyval.valString)="";

	}
#line 2999 "scanner.tab.c"
    break;

  case 56: /* prod: PROD  */
#line 982 "scanner.y"
              {
		(yyval.valString)="";
	}
#line 3007 "scanner.tab.c"
    break;

  case 57: /* args: types STRINGV COMMA args  */
#line 988 "scanner.y"
                                 {
                char * final;
                
                char *tipo;
                if (strcmp(obtenerTipo((yyvsp[-3].valInt)), "struct") == 0) {
                        tipo = tipoStruct;
                        
                        
                }else{
                        tipo = obtenerTipo((yyvsp[-3].valInt));

                }                
		final = malloc(strlen(tipo)  + strlen((yyvsp[-2].valString)) * sizeof(char) + strlen((yyvsp[0].valString)) * sizeof(char) + sizeof(",  ") + 3*sizeof(char));
                memset(final, 0, sizeof(final));
                strcat(final, (yyvsp[0].valString));
                strcat(final, ",");
                strcat(final, " ");
                strcat(final, tipo);
                strcat(final, " ");
                strcat(final, (yyvsp[-2].valString));
                free((yyvsp[-2].valString));
		free((yyvsp[0].valString));
                (yyval.valString) = final;
                
                }
#line 3037 "scanner.tab.c"
    break;

  case 58: /* args: types STRINGV  */
#line 1013 "scanner.y"
                       {
		char *final;
		char *tipo;
		if (strcmp(obtenerTipo((yyvsp[-1].valInt)), "struct") == 0) {
			// Calcular el tamaño total y asignar memoria
			tipo = malloc((strlen(tipoStruct) + strlen((yyvsp[0].valString)) + strlen(": &mut ") + 1) * sizeof(char));

			if (tipo == NULL) {
				// Manejar error de asignación
				exit(1);
			}

			// Inicializar y construir la cadena `tipo`
			tipo[0] = '\0';  // Aseguramos terminador nulo inicial
			strcat(tipo, (yyvsp[0].valString));
			strcat(tipo, ": &mut ");
			strcat(tipo, tipoStruct);
			free((yyvsp[0].valString));
			(yyval.valString) = tipo;

		} else {
			tipo = obtenerTipo((yyvsp[-1].valInt));
			// Calcular el tamaño total y asignar memoria
			final = malloc((strlen(tipo) + strlen((yyvsp[0].valString)) + 2) * sizeof(char)); // +2 para " " y '\0'

			if (final == NULL) {
				// Manejar error de asignación
				exit(1);
			}

			// Inicializar y construir la cadena `final`
			final[0] = '\0';  // Aseguramos terminador nulo inicial
			strcat(final, tipo);
			strcat(final, " ");
			strcat(final, (yyvsp[0].valString));
			free((yyvsp[0].valString));
			(yyval.valString) = final;
		}
			
        }
#line 3082 "scanner.tab.c"
    break;

  case 59: /* args: types STRINGV LSQUAREPAREN RSQUAREPAREN COMMA args  */
#line 1112 "scanner.y"
                                                           {
                char *tipo;
                if (strcmp(obtenerTipo((yyvsp[-5].valInt)), "struct") == 0) {
                        tipo = tipoStruct;
                        
                }else{
                        tipo = obtenerTipo((yyvsp[-5].valInt));

                }
                char * final = malloc(strlen(tipo)* sizeof(char) +strlen((yyvsp[-4].valString))* sizeof(char) +strlen((yyvsp[0].valString))*sizeof(char) + sizeof("[] : ,\n"));
                memset(final, 0 , sizeof(final));
                strcat(final, (yyvsp[-4].valString));
                strcat(final, ": [");
                strcat(final, tipo);
                strcat(final, "], ");
		strcat(final, (yyvsp[0].valString));
		free((yyvsp[-4].valString));
		free((yyvsp[0].valString));
                (yyval.valString) = final;
        }
#line 3107 "scanner.tab.c"
    break;

  case 60: /* args: types STRINGV LSQUAREPAREN RSQUAREPAREN  */
#line 1132 "scanner.y"
                                                {
                char *tipo;
                if (strcmp(obtenerTipo((yyvsp[-3].valInt)), "struct") == 0) {
                        tipo = tipoStruct;
                        
                }else{
                        tipo = obtenerTipo((yyvsp[-3].valInt));

                }
                char * final = malloc(strlen(tipo)* sizeof(char) +strlen((yyvsp[-2].valString))* sizeof(char) + sizeof("[] : ,\n"));
                memset(final, 0 , sizeof(final));
                strcat(final, (yyvsp[-2].valString));
                strcat(final, ": [");
                strcat(final, tipo);
                strcat(final, "]");
		free((yyvsp[-2].valString));
                (yyval.valString) = final;
        }
#line 3130 "scanner.tab.c"
    break;

  case 61: /* lines_program: lines_program line_program  */
#line 1155 "scanner.y"
                                   {
	// Calcular el tamaño total necesario para el buffer
		char *final = malloc(strlen((yyvsp[-1].valString)) + strlen((yyvsp[0].valString)) + 1); // +2 para "\n" y '\0'
		if (final == NULL) {
    		// Manejo del error si malloc falla
    			return 0;
		}

		// Copiar las cadenas
		strcpy(final, (yyvsp[-1].valString));
		strcat(final, (yyvsp[0].valString));

		// Liberar las cadenas individuales
		free((yyvsp[-1].valString));
		free((yyvsp[0].valString));

		// Asignar el resultado a $$
		(yyval.valString) = final;
        }
#line 3154 "scanner.tab.c"
    break;

  case 62: /* lines_program: line_program  */
#line 1174 "scanner.y"
                       {
                (yyval.valString) = (yyvsp[0].valString);
                
                }
#line 3163 "scanner.tab.c"
    break;

  case 63: /* if_statement: IF LPAREN exp RPAREN line_program  */
#line 1183 "scanner.y"
                                           {
                char * final = malloc(strlen((yyvsp[-2].valString))* sizeof(char) + strlen((yyvsp[0].valString))*sizeof(char) + sizeof("if ( ) { } \t \n \n"));
                memset(final, 0, sizeof(final));
                strcat(final, "if (");
                strcat(final, (yyvsp[-2].valString));
                strcat(final, "){\n");
                strcat(final, (yyvsp[0].valString));
                strcat(final, "\n}");
                free((yyvsp[-2].valString));
                free((yyvsp[0].valString));
                (yyval.valString) = final;

	}
#line 3181 "scanner.tab.c"
    break;

  case 64: /* if_statement: IF LPAREN exp RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET  */
#line 1196 "scanner.y"
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
#line 3199 "scanner.tab.c"
    break;

  case 65: /* if_statement: ELSE IF LPAREN exp RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET  */
#line 1209 "scanner.y"
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
#line 3216 "scanner.tab.c"
    break;

  case 66: /* if_statement: ELSE OPENCURLYBRACKET lines_program CLOSECURLYBRACKET  */
#line 1221 "scanner.y"
                                                                {
                char* final = malloc(strlen((yyvsp[-1].valString))*sizeof(char)+ sizeof("else {} \n \n \t"));
                memset(final, 0, sizeof(final));
                strcat(final, "else{\n\t");
                strcat(final, (yyvsp[-1].valString));
                strcat(final, "}\n");
		free((yyvsp[-1].valString));
                (yyval.valString) = final;
        
        }
#line 3231 "scanner.tab.c"
    break;

  case 67: /* if_statement: SWITCH exp OPENCURLYBRACKET case_chain CLOSECURLYBRACKET  */
#line 1231 "scanner.y"
                                                                  {
		char *final = malloc(strlen("match {}\n\n") + strlen((yyvsp[-3].valString)) + strlen((yyvsp[-1].valString)) + 1);
		final[0] = '\0';
		strcat(final, "match ");
		strcat(final, (yyvsp[-3].valString));
		strcat(final, "{\n");
		strcat(final, (yyvsp[-1].valString));
		strcat(final, "}\n");
		free((yyvsp[-3].valString));
		free((yyvsp[-1].valString));
		(yyval.valString) = final;
 
	}
#line 3249 "scanner.tab.c"
    break;

  case 68: /* case_chain: CASE values COLON lines_program case_chain  */
#line 1249 "scanner.y"
                                                   {
		// Cálculo de la longitud total necesaria para `final`
		size_t longitud_final = strlen(" => {\n") + strlen((yyvsp[-3].valString)) + strlen((yyvsp[-1].valString)) + strlen("\n}, ") + strlen((yyvsp[0].valString)) + 1;
		char *final = malloc(longitud_final);
		if (final == NULL) {
			// Manejar error de asignación de memoria
			(yyval.valString) = "";
		}
		final[0] = '\0'; // Inicializa `final` como una cadena vacía

		// Concatenación en `final` paso a paso
		strcat(final, (yyvsp[-3].valString));
		strcat(final, " => {\n");
		strcat(final, (yyvsp[-1].valString));
		strcat(final, "\n}, ");
		strcat(final, (yyvsp[0].valString));

		// Liberación de memoria de las variables temporales
		free((yyvsp[-3].valString));
		free((yyvsp[-1].valString));
		free((yyvsp[0].valString));

		// Asignación del resultado a $$
		(yyval.valString) = final;
	}
#line 3279 "scanner.tab.c"
    break;

  case 69: /* case_chain: CASE values COLON lines_program  */
#line 1275 "scanner.y"
                                         {
		char *final = malloc(strlen("=> ,  \n") + strlen((yyvsp[-2].valString)) + strlen((yyvsp[0].valString)) + 1);
		final[0] = '\0';
		strcat(final, (yyvsp[-2].valString));
		strcat(final, " => {\n");
		strcat(final, (yyvsp[0].valString));
		strcat(final, "\n}");
		free((yyvsp[-2].valString));
		free((yyvsp[0].valString));
		(yyval.valString) = final;
	}
#line 3295 "scanner.tab.c"
    break;

  case 70: /* case_chain: CASE STRINGV COLON lines_program case_chain  */
#line 1286 "scanner.y"
                                                     {
		char *final = malloc(strlen("=> ,  \n\n") + strlen((yyvsp[-3].valString)) + strlen((yyvsp[-1].valString)) + strlen((yyvsp[0].valString))+ 1);
		final[0] = '\0';
		strcat(final, (yyvsp[-3].valString));
		strcat(final, " => {\n");
		strcat(final, (yyvsp[-1].valString));
		strcat(final, "\n}, ");
		strcat(final, (yyvsp[0].valString));
		free((yyvsp[-3].valString));
		free((yyvsp[-1].valString));
		free((yyvsp[0].valString));
		(yyval.valString) = final;

	}
#line 3314 "scanner.tab.c"
    break;

  case 71: /* case_chain: CASE STRINGV COLON lines_program  */
#line 1300 "scanner.y"
                                          {
		char *final = malloc(strlen("=> ,  \n") + strlen((yyvsp[-2].valString)) + strlen((yyvsp[0].valString)) + 1);
		final[0] = '\0';
		strcat(final, (yyvsp[-2].valString));
		strcat(final, " => {\n");
		strcat(final, (yyvsp[0].valString));
		strcat(final, "\n}");
		free((yyvsp[-2].valString));
		free((yyvsp[0].valString));
		(yyval.valString) = final;

	}
#line 3331 "scanner.tab.c"
    break;

  case 72: /* case_chain: DEFAULT COLON lines_program  */
#line 1312 "scanner.y"
                                     {
		char *final = malloc(strlen("_ => ,  \n") + strlen((yyvsp[0].valString)) + 1);
		final[0] = '\0';
		strcat(final, "_ => {\n");
		strcat(final, (yyvsp[0].valString));
		strcat(final, "\n}");
		free((yyvsp[0].valString));
		(yyval.valString) = final;

	}
#line 3346 "scanner.tab.c"
    break;

  case 73: /* fun_cre: STRINGV LPAREN array RPAREN  */
#line 1330 "scanner.y"
                                    {
                char * final = malloc(strlen((yyvsp[-3].valString))* sizeof(char) + strlen((yyvsp[-1].valString))*sizeof(char) + sizeof("()") + 1);
                memset(final,0, sizeof(final));
                strcat(final, (yyvsp[-3].valString));
                strcat(final, "(");
                strcat(final,(yyvsp[-1].valString));
                strcat(final,")");
		free((yyvsp[-3].valString));
		free((yyvsp[-1].valString));
                (yyval.valString) = final;

        }
#line 3363 "scanner.tab.c"
    break;

  case 74: /* fun_cre: STRINGV LPAREN RPAREN  */
#line 1342 "scanner.y"
                              {
                char * final = malloc(strlen((yyvsp[-2].valString))* sizeof(char) +  sizeof("()") + 1);
                memset(final,0, sizeof(final));
                strcat(final, (yyvsp[-2].valString));
                strcat(final, "(");
                strcat(final,")");
		free((yyvsp[-2].valString));
                (yyval.valString) = final;

        }
#line 3378 "scanner.tab.c"
    break;

  case 75: /* fun_cre: LPAREN types RPAREN fun_cre  */
#line 1352 "scanner.y"
                                    {
		(yyval.valString) = ""	;
	}
#line 3386 "scanner.tab.c"
    break;

  case 76: /* line_program: WRITE LOWER LOWER precontentWrite SEMICOLON  */
#line 1359 "scanner.y"
                                                    {
        	char * final = malloc(strlen((yyvsp[-1].valString))*sizeof(char));
		memset(final, 0, sizeof(final));
		strcat(final, (yyvsp[-1].valString));
		free((yyvsp[-1].valString));
                (yyval.valString) = final;
                
        }
#line 3399 "scanner.tab.c"
    break;

  case 77: /* line_program: PRINTF LPAREN precontentWrite RPAREN SEMICOLON  */
#line 1367 "scanner.y"
                                                         {
                char * final = malloc(strlen((yyvsp[-2].valString))*sizeof(char)+ sizeof("print!"));
                memset(final, 0, sizeof(final));
                strcat(final, "print!");
                strcat(final, (yyvsp[-2].valString));
		free((yyvsp[-2].valString));
                (yyval.valString) = final;
        }
#line 3412 "scanner.tab.c"
    break;

  case 78: /* line_program: SCANF LPAREN precontentWrite RPAREN SEMICOLON  */
#line 1375 "scanner.y"
                                                       {
                char * final = malloc(strlen((yyvsp[-2].valString))*sizeof(char)+ sizeof("let mut input = String::new();\nio::stdin()\n.read_line(&mut input)\n.expect(\"Failed to read line\");"));
                memset(final, 0, sizeof(final));
                strcpy(final, "let mut input = String::new();\nio::stdin()\n.read_line(&mut input)\n.expect(\"Failed to read line\");");
                inputCount = inputCount + 1;
		free((yyvsp[-2].valString));
                (yyval.valString) = final;
        }
#line 3425 "scanner.tab.c"
    break;

  case 79: /* line_program: fun_cre  */
#line 1383 "scanner.y"
                 {
		(yyval.valString) = (yyvsp[0].valString);
	}
#line 3433 "scanner.tab.c"
    break;

  case 80: /* line_program: if_statement  */
#line 1386 "scanner.y"
                      {
		(yyval.valString) = (yyvsp[0].valString);
	}
#line 3441 "scanner.tab.c"
    break;

  case 81: /* line_program: FOR LPAREN types STRINGV EQ INTNUM SEMICOLON exp SEMICOLON STRINGV operand RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET  */
#line 1389 "scanner.y"
                                                                                                                                             {
		// Calcular el tamaño de `final` correctamente y asegurar espacio para el terminador nulo
		char str3[12];  // Asumiendo que INT_MAX es el tamaño máximo
		char str4[12];
		char str8[12];
		sprintf(str3, "%d", (yyvsp[-12].valInt));
		sprintf(str4, "%d", (yyvsp[-11].valString));
		sprintf(str8, "%d", (yyvsp[-7].valString));

		char *final = malloc(strlen(str3) + strlen(str8) + strlen("for ; ; {}") + strlen((yyvsp[-11].valString)) +
                     strlen((yyvsp[-9].valString)) + strlen((yyvsp[-6].valString)) + strlen((yyvsp[-5].valString)) + strlen((yyvsp[-1].valString)) + 1);
		// Inicializar `final` correctamente
		final[0] = '\0';

		// Obtener valor de `octavo`
		char *numero = getEndNumber((yyvsp[-7].valString));
		char *octavo;
		if (strcmp(numero, "") == 0) {
		octavo = getStringFromExp((yyvsp[-7].valString));
		} else {
		octavo = strdup(numero);  // Asegurar que octavo siempre esté inicializado
		}

		// Concatenación de las cadenas en `final`
		strcat(final, "for ");
		strcat(final, (yyvsp[-11].valString));
		strcat(final, " in ");
		strcat(final, (yyvsp[-9].valString));
		strcat(final, "..");
		strcat(final, octavo);
		strcat(final, "{\n");
		strcat(final, (yyvsp[-1].valString));
		strcat(final, "\n}");

		// Liberar la memoria de las variables temporales
		free((yyvsp[-11].valString));
		free((yyvsp[-9].valString));
		free((yyvsp[-7].valString));
		free((yyvsp[-5].valString));
		free((yyvsp[-4].valString));
		free((yyvsp[-1].valString));
		free(numero);
		free(octavo);  // Asegurarse de liberar `octavo` después de usarlo
		(yyval.valString) = final;
	}
#line 3491 "scanner.tab.c"
    break;

  case 82: /* line_program: FOR LPAREN types STRINGV EQ INTNUM SEMICOLON exp SEMICOLON vardef RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET  */
#line 1434 "scanner.y"
                                                                                                                                     {
                char * final = malloc ((yyvsp[-11].valInt)*sizeof(int) + strlen((yyvsp[-10].valString))*sizeof(char) + strlen((yyvsp[-8].valString))*sizeof(char) + strlen((yyvsp[-6].valString))*sizeof(char)  + strlen((yyvsp[-4].valString))*sizeof(char) + strlen((yyvsp[-1].valString))*sizeof(char)+ sizeof("for ; ; {} .step_by( )"));
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
                strcat(final, "{\n");
                strcat(final, (yyvsp[-1].valString));
                strcat(final, "\n}");
		free((yyvsp[-10].valString));
		free((yyvsp[-8].valString));
		free((yyvsp[-6].valString));
		free((yyvsp[-4].valString));
		free((yyvsp[-1].valString));
		free(numero);
		free(numero2);
                (yyval.valString)=final;
        
        
        }
#line 3525 "scanner.tab.c"
    break;

  case 83: /* line_program: DO OPENCURLYBRACKET lines_program CLOSECURLYBRACKET WHILE LPAREN exp RPAREN SEMICOLON  */
#line 1463 "scanner.y"
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
		free((yyvsp[-6].valString));
		free((yyvsp[-2].valString));
                (yyval.valString) = final;
        
        }
#line 3546 "scanner.tab.c"
    break;

  case 84: /* line_program: WHILE LPAREN exp RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET  */
#line 1479 "scanner.y"
                                                                                  {
                char * final = malloc(strlen((yyvsp[-4].valString))*sizeof(char) + strlen((yyvsp[-1].valString))*sizeof(char) + sizeof("while () {} \n\n"));
                memset(final, 0, sizeof(final));

                strcat(final, "while(");
                strcat(final, (yyvsp[-4].valString));
                strcat(final, "){\n");
                strcat(final, (yyvsp[-1].valString));
                strcat(final, "\n}");
		free((yyvsp[-4].valString));
		free((yyvsp[-1].valString));
                (yyval.valString) = final;
                
        }
#line 3565 "scanner.tab.c"
    break;

  case 85: /* line_program: comment  */
#line 1494 "scanner.y"
                 {;}
#line 3571 "scanner.tab.c"
    break;

  case 86: /* line_program: STRINGV operand SEMICOLON  */
#line 1495 "scanner.y"
                                   {
                char * final = malloc (strlen((yyvsp[-1].valString))*sizeof(char) + strlen((yyvsp[-2].valString))*sizeof(char));
                memset(final, 0, sizeof(final));
                strcat(final, (yyvsp[-2].valString));
                strcat(final, (yyvsp[-1].valString));
                strcat(final, ";");
		free((yyvsp[-2].valString));
		free((yyvsp[-1].valString));
                (yyval.valString) = final;
        }
#line 3586 "scanner.tab.c"
    break;

  case 87: /* line_program: LPAREN prod STRINGV RPAREN operand SEMICOLON  */
#line 1505 "scanner.y"
                                                      {
                char * final = malloc (strlen((yyvsp[-3].valString))*sizeof(char) + strlen((yyvsp[-1].valString))*sizeof(char));
                memset(final, 0, sizeof(final));
                strcat(final, (yyvsp[-3].valString));
                strcat(final, (yyvsp[-1].valString));
                strcat(final, ";");
		free((yyvsp[-3].valString));
		free((yyvsp[-1].valString));
                (yyval.valString) = final;

	}
#line 3602 "scanner.tab.c"
    break;

  case 88: /* line_program: RETURN exp SEMICOLON  */
#line 1516 "scanner.y"
                               {
		char *final = malloc((strlen((yyvsp[-1].valString)) + 1) * sizeof(char)); // Reservar espacio para $2 y el terminador nulo
		if (final == NULL) {
		    // Manejo de error de asignación
		    exit(1);
		}

		final[0] = '\0'; // Inicializar el primer carácter con `\0` para que `strcat` funcione correctamente
		strcat(final, (yyvsp[-1].valString)); // Concatenar $2 en `final`
		(yyval.valString) = final; // Asignar `final` a $$
			
        }
#line 3619 "scanner.tab.c"
    break;

  case 89: /* line_program: RETURN SEMICOLON  */
#line 1528 "scanner.y"
                           {
                char * final = malloc(sizeof("return;"));
                memset(final, 0 , sizeof(final));
                strcat(final, "return;");
                (yyval.valString) = final;
                
        }
#line 3631 "scanner.tab.c"
    break;

  case 90: /* line_program: vardef  */
#line 1535 "scanner.y"
                {
                char * final = malloc(strlen((yyvsp[0].valString))*sizeof(char)  + sizeof("\n"));
                memset(final,0,sizeof(final));
                strcat(final,(yyvsp[0].valString));
                strcat(final,"\n");

          	free((yyvsp[0].valString));      
                (yyval.valString) = final;
                
        }
#line 3646 "scanner.tab.c"
    break;

  case 91: /* line_program: types OPENCURLYBRACKET lines_program CLOSECURLYBRACKET SEMICOLON  */
#line 1555 "scanner.y"
                                                                         {
		char *tipo;

		if (strcmp(obtenerTipo((yyvsp[-4].valInt)), "struct") == 0) {
			printf("\n\n TIPO TIPO %s TIPO TIPO \n \n", obtenerTipo((yyvsp[-4].valInt)));
			tipo = tipoStruct;
		} else {
			tipo = obtenerTipo((yyvsp[-4].valInt));
		}

                char * final = malloc(strlen(tipo) + strlen((yyvsp[-2].valString))*sizeof(char) + strlen("struct { } \n\n"));
                memset(final, 0 , sizeof(final));
                strcat(final, "struct ");
                strcat(final, tipo);
                strcat(final, " {\n");
                strcat(final, (yyvsp[-2].valString));
                strcat(final, "}\n");
                replaceSemicolon(final);
		free(tipo);
		free((yyvsp[-2].valString));
                (yyval.valString) = final; 
        }
#line 3673 "scanner.tab.c"
    break;

  case 92: /* array: exp COMMA array  */
#line 1583 "scanner.y"
                       {
                // Calcular el tamaño total necesario para `final`
		size_t size_final = strlen((yyvsp[-2].valString)) * sizeof(char) + strlen((yyvsp[0].valString)) * sizeof(char) + sizeof(","); // +1 para la coma

		// Asignar memoria para `final` y asegurar que se incluye espacio para el terminador nulo
		char *final = malloc(size_final + 1);  // +1 para '\0'

		// Inicializar toda la memoria asignada con ceros
		memset(final, 0, size_final + 1);

		strcat(final, (yyvsp[-2].valString));
		strcat(final, ",");
		strcat(final, (yyvsp[0].valString));

		free((yyvsp[-2].valString));
		free((yyvsp[0].valString));
		(yyval.valString) = final;

        }
#line 3697 "scanner.tab.c"
    break;

  case 93: /* array: exp  */
#line 1602 "scanner.y"
            {
                (yyval.valString) = (yyvsp[0].valString);
        }
#line 3705 "scanner.tab.c"
    break;

  case 94: /* array: types  */
#line 1605 "scanner.y"
                {
		// Obtener el tipo y asignarlo a una nueva cadena con malloc
		const char *obtenido = obtenerTipo((yyvsp[0].valInt));
		if (obtenido == NULL) {
			perror("Error: obtenerTipo devolvió NULL");
			exit(1);  // Manejo de error si obtenerTipo falla
		}

		// Reservar memoria suficiente para el tipo
		char *tipo = malloc(strlen(obtenido) + 1);  // +1 para el terminador nulo
		if (tipo == NULL) {
			perror("Error al asignar memoria para 'tipo'");
			exit(1);
		}
		strcpy(tipo, obtenido);

		// Modificar `tipo` si es necesario
		if (strcmp(tipo, "struct") == 0) {
			free(tipo);  // Liberar memoria previamente asignada
			tipo = malloc(strlen(tipoStruct) + 1);  // Reservar nueva memoria
			if (tipo == NULL) {
				perror("Error al asignar memoria para 'tipoStruct'");
				exit(1);
			}
			strcpy(tipo, tipoStruct);
		}
		// Asignar el valor a $$
		(yyval.valString) = tipo;
	}
#line 3739 "scanner.tab.c"
    break;

  case 95: /* precontentWrite: contentWrite  */
#line 1636 "scanner.y"
                     {
	    	if (strlen(printV) == 0) {
        		char *final = malloc(strlen((yyvsp[0].valString)) + strlen(printV) + strlen("();") + 1);  // +1 para '\0'
        		if (final) {
            			final[0] = '\0';  // Inicializa la cadena a vacía
            			strcat(final, "(");
            			strcat(final, (yyvsp[0].valString));
            			strcat(final, ");");
            			(yyval.valString) = final;
        		}
    		} else {
	        	int longitud = strlen(printV);
        		char *final = malloc(strlen((yyvsp[0].valString)) + strlen("{},,,") + longitud + strlen("(\"") + strlen("\");") + 1);
        		if (final) {
            			final[0] = '\0';  // Inicializa a vacío

            			// Reservamos memoria para nueva_cadena y la inicializamos
            			char *nueva_cadena = malloc(longitud + 1);
            			if (nueva_cadena) {
                			nueva_cadena[0] = '\0';  // Inicializa a vacío

                			// Quita la última coma en printV
                			for (int i = longitud - 1; i >= 0; i--) {
                    				if (printV[i] == ',') {
                        				printV[i] = '\0';
                        				break;
                    				}
                			}
                			strcpy(nueva_cadena, printV);

                			// Conteo de '{' en $1
                			int contador = 0;
                			for (int i = 0; (yyvsp[0].valString)[i] != '\0'; i++) {
                    				if ((yyvsp[0].valString)[i] == '}') {
                        				contador++;
                    				}
                			}

                			strcat(final, "(");
                			if (strlen(printV) == contador) {
                    				strcat(final, "\"");
                    				strcat(final, (yyvsp[0].valString));
                    				strcat(final, "\"");
                    				strcat(final, ",");
                    				strcat(final, nueva_cadena);
                			} else if (strlen(printV) > contador) {
                    				strcat(final, "\"");
                    				strcat(final, (yyvsp[0].valString));
                    				strcat(final, "{}");
                    				strcat(final, "\"");
                    				strcat(final, ",");
                    				strcat(final, nueva_cadena);
                			} else {
                    				printf("Error: valores no coinciden\n");
                			}
                			strcat(final, ");");

                			// Liberación de memoria
                			memset(printV, 0, strlen(printV));  // Limpia printV pero sin liberar
                			free(nueva_cadena);  // Libera nueva_cadena
            			}
            			(yyval.valString) = final;  // Asigna el resultado final
        		}
        		free((yyvsp[0].valString));  // Libera $1 en ambas ramas
    		}
	}
#line 3810 "scanner.tab.c"
    break;

  case 96: /* contentWrite: contentWrite COMMA exp  */
#line 1784 "scanner.y"
                              {
                char * final = malloc(strlen((yyvsp[-2].valString)) * sizeof(char) + strlen((yyvsp[0].valString)) * sizeof(char) + strlen("{}") * sizeof(char)); 
                memset(final, 0, sizeof(final));

                strcat(printV,(yyvsp[0].valString));
                strcat(printV,",");

                
                strcat(final, (yyvsp[-2].valString));
                deleteQuotes(final);
		free((yyvsp[-2].valString));
		free((yyvsp[0].valString));
                (yyval.valString) = final;
        }
#line 3829 "scanner.tab.c"
    break;

  case 97: /* contentWrite: QUOTESTRING  */
#line 1799 "scanner.y"
                      {

                (yyval.valString) = (yyvsp[0].valString);}
#line 3837 "scanner.tab.c"
    break;

  case 98: /* contentWrite: STRINGV  */
#line 1802 "scanner.y"
                  {
                (yyval.valString) = (yyvsp[0].valString);
	}
#line 3845 "scanner.tab.c"
    break;

  case 99: /* exp: exp operand term  */
#line 1809 "scanner.y"
                         {
                
                char *final = malloc(strlen((yyvsp[-2].valString)) + strlen((yyvsp[-1].valString)) + strlen((yyvsp[0].valString)) + 1); // +1 para el terminador nulo

		// Inicializar el bloque de memoria completo
		memset(final, 0, strlen((yyvsp[-2].valString)) + strlen((yyvsp[-1].valString)) + strlen((yyvsp[0].valString)) + 1);

		// Concatenar las cadenas
		strcpy(final, (yyvsp[-2].valString));
		strcat(final, (yyvsp[-1].valString));
		strcat(final, (yyvsp[0].valString));

		// Liberar las variables temporales
		free((yyvsp[-2].valString));
		free((yyvsp[-1].valString));
		(yyval.valString) = final;
        }
#line 3867 "scanner.tab.c"
    break;

  case 100: /* exp: term  */
#line 1826 "scanner.y"
              {
                                

        	(yyval.valString) = (yyvsp[0].valString);
		
	}
#line 3878 "scanner.tab.c"
    break;

  case 101: /* term: atom  */
#line 1836 "scanner.y"
             {

                (yyval.valString) = (yyvsp[0].valString);
	}
#line 3887 "scanner.tab.c"
    break;

  case 102: /* term: LPAREN exp RPAREN  */
#line 1841 "scanner.y"
                            {
                char * final = malloc(strlen((yyvsp[-1].valString)) * sizeof(char) + sizeof("()") + 1);
                memset(final, 0, sizeof(final));
                strcpy(final, "(");
                strcat(final, (yyvsp[-1].valString));
                strcat(final, ")");
                free((yyvsp[-1].valString));
                (yyval.valString) = final;
                }
#line 3901 "scanner.tab.c"
    break;

  case 103: /* term: EX exp  */
#line 1859 "scanner.y"
                 {
                char * final = malloc(strlen((yyvsp[0].valString)) * sizeof(char) + sizeof("!()") + 1);
                memset(final, 0, sizeof(final));
                strcpy(final, "!(");
                strcat(final, (yyvsp[0].valString));
                strcat(final, ")");
                free((yyvsp[0].valString));
                (yyval.valString) = final;
                }
#line 3915 "scanner.tab.c"
    break;

  case 104: /* operand: PLUS  */
#line 1879 "scanner.y"
             {
                (yyval.valString) = strdup(" + ");
        }
#line 3923 "scanner.tab.c"
    break;

  case 105: /* operand: PLUS EQ  */
#line 1882 "scanner.y"
                 {(yyval.valString) = strdup(" += ");}
#line 3929 "scanner.tab.c"
    break;

  case 106: /* operand: HYPHEN  */
#line 1883 "scanner.y"
                {(yyval.valString) = strdup(" - ");}
#line 3935 "scanner.tab.c"
    break;

  case 107: /* operand: HYPHEN EQ  */
#line 1884 "scanner.y"
                   {(yyval.valString) = strdup(" -= ");}
#line 3941 "scanner.tab.c"
    break;

  case 108: /* operand: HYPHEN HIGHER  */
#line 1885 "scanner.y"
                      {(yyval.valString) = strdup(".");}
#line 3947 "scanner.tab.c"
    break;

  case 109: /* operand: PROD  */
#line 1886 "scanner.y"
              {(yyval.valString) = strdup(" * ");}
#line 3953 "scanner.tab.c"
    break;

  case 110: /* operand: DIV  */
#line 1887 "scanner.y"
             {(yyval.valString) = strdup(" / ");}
#line 3959 "scanner.tab.c"
    break;

  case 111: /* operand: DIVINT  */
#line 1888 "scanner.y"
                {(yyval.valString) = strdup(" / ");}
#line 3965 "scanner.tab.c"
    break;

  case 112: /* operand: MOD  */
#line 1889 "scanner.y"
             {(yyval.valString) = strdup(" % ");}
#line 3971 "scanner.tab.c"
    break;

  case 113: /* operand: LOWER  */
#line 1890 "scanner.y"
               {(yyval.valString) = strdup(" < ");}
#line 3977 "scanner.tab.c"
    break;

  case 114: /* operand: HIGHER  */
#line 1891 "scanner.y"
                {(yyval.valString) = strdup(" > ");}
#line 3983 "scanner.tab.c"
    break;

  case 115: /* operand: LOWER EQ  */
#line 1892 "scanner.y"
                  {(yyval.valString) = strdup(" <= ");}
#line 3989 "scanner.tab.c"
    break;

  case 116: /* operand: HIGHER EQ  */
#line 1893 "scanner.y"
                   {(yyval.valString) = strdup(" >= ");}
#line 3995 "scanner.tab.c"
    break;

  case 117: /* operand: EQ EQ  */
#line 1894 "scanner.y"
               {(yyval.valString) = strdup(" == ");}
#line 4001 "scanner.tab.c"
    break;

  case 118: /* operand: AND  */
#line 1895 "scanner.y"
             {(yyval.valString) = strdup(" && ");}
#line 4007 "scanner.tab.c"
    break;

  case 119: /* operand: PLUS PLUS  */
#line 1896 "scanner.y"
                   {(yyval.valString) = strdup(" ++ ");}
#line 4013 "scanner.tab.c"
    break;

  case 120: /* operand: OR  */
#line 1897 "scanner.y"
           {(yyval.valString) = strdup(" || ");}
#line 4019 "scanner.tab.c"
    break;

  case 121: /* operand: DOT  */
#line 1898 "scanner.y"
             {(yyval.valString) = strdup(".");}
#line 4025 "scanner.tab.c"
    break;

  case 122: /* operand: PERCENT  */
#line 1899 "scanner.y"
                 {(yyval.valString) = strdup(" % ");}
#line 4031 "scanner.tab.c"
    break;

  case 123: /* operand: EX EQ  */
#line 1900 "scanner.y"
               {(yyval.valString) = strdup(" != ");}
#line 4037 "scanner.tab.c"
    break;

  case 124: /* atom: STRINGV  */
#line 1905 "scanner.y"
                {

		(yyval.valString) = (yyvsp[0].valString);
	}
#line 4046 "scanner.tab.c"
    break;

  case 125: /* atom: prod STRINGV  */
#line 1909 "scanner.y"
                      {
	
		(yyval.valString) = (yyvsp[0].valString);
	}
#line 4055 "scanner.tab.c"
    break;

  case 126: /* atom: values  */
#line 1913 "scanner.y"
                 {

		(yyval.valString) = (yyvsp[0].valString);		
	}
#line 4064 "scanner.tab.c"
    break;

  case 127: /* atom: STRINGV LSQUAREPAREN exp RSQUAREPAREN  */
#line 1917 "scanner.y"
                                              {

                char *final = malloc(strlen((yyvsp[-3].valString)) * sizeof(char) + strlen((yyvsp[-1].valString)) * sizeof(char) + sizeof("[]"));

		// Usar el tamaño total asignado en `malloc` para `memset`
		memset(final, 0, strlen((yyvsp[-3].valString)) * sizeof(char) + strlen((yyvsp[-1].valString)) * sizeof(char) + sizeof("[]"));

		strcat(final, (yyvsp[-3].valString));
		strcat(final, "[");
		strcat(final, (yyvsp[-1].valString));
		strcat(final, "]");

		free((yyvsp[-3].valString));
		free((yyvsp[-1].valString));
		(yyval.valString) = final;
        }
#line 4085 "scanner.tab.c"
    break;

  case 128: /* atom: fun_cre  */
#line 1935 "scanner.y"
                 {
		(yyval.valString) = (yyvsp[0].valString);
	}
#line 4093 "scanner.tab.c"
    break;


#line 4097 "scanner.tab.c"

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

#line 1942 "scanner.y"


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
        case 11: tipo = "struct" ; break;
        default: tipo = ""; break;
    }
    return tipo;
}

char* getEndNumber(char* number) {
	int len = strlen(number);
	char* numero = (char*) malloc(len + 1); // Reservar espacio para el nuevo número (+1 por el '\0')
    	if (numero == NULL) return NULL; // Verificar si la asignación fue exitosa

    		int j = 0;
    		// Recorremos `number` desde el final para encontrar los dígitos
    		for (int i = len - 1; i >= 0; i--) {
        		if (!isdigit(number[i])) {
          	  		break;
        		} else {
        	    		numero[j++] = number[i]; // Guardar el dígito en `numero`
        		}
    		}
    		numero[j] = '\0'; // Terminar la cadena con '\0'

    		// Invertir `numero` para obtener los dígitos en el orden correcto
    		for (int k = 0; k < j / 2; k++) {
        		char temp = numero[k];
        		numero[k] = numero[j - k - 1];
        		numero[j - k - 1] = temp;
    		}

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
    char *nuevoString = (char *)malloc(nuevaLongitud + 1); // +1 para el terminador nulo
    if (nuevoString == NULL) {
        return NULL; // Error en la asignación de memoria
    }
    
    nuevoString[0] = '\0';  // Inicializar `nuevoString` con terminador nulo para evitar valores no inicializados.

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

    // Copiar el resto de la cadena y asegurar el terminador nulo
    strcpy(destino, inicio);

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
        if (string[i] == ';' && string[i + 1] == '\n') {
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

char* getStringFromExp(char* str) {
    int len = strlen(str);
    char* subcadena = NULL;
    char* delimitadores[4] = {"<", ">", ">=", "<="};
    int i, j, k, pos;
    for (i = 0; i < 4; i++) {
        char* ptr = strstr(str, delimitadores[i]);
        if (ptr != NULL) {
            pos = ptr - str + strlen(delimitadores[i]);
            subcadena = (char*)malloc(len - pos + 1);
            if (subcadena == NULL) {
                printf("Error de asignación de memoria\n");
                exit(1);
            }
            for (j = pos, k = 0; j < len; j++, k++) {
                subcadena[k] = str[j];
            }
            subcadena[k] = '\0';
            break;
        }
    }
    return subcadena;
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

			// Asegurar espacio suficiente en arrayCabeceras
			arrayCabeceras = (char**)realloc(arrayCabeceras, arraySize * sizeof(char*));
			if (arrayCabeceras == NULL) {
    				printf("Error al reasignar memoria para arrayCabeceras\n");
    				exit(1); // Termina si realloc falla
			}

			// Asignar memoria para la nueva cadena en arrayCabeceras[arraySize - 1]
			// Añadimos +1 para el terminador nulo '\0'
			arrayCabeceras[arraySize - 1] = (char*)malloc((strlen(ruta) + 1) * sizeof(char));
			if (arrayCabeceras[arraySize - 1] == NULL) {
    				printf("Error al asignar memoria para arrayCabeceras[%d]\n", arraySize - 1);
    				exit(1); // Termina si malloc falla
			}

			// Copiar la cadena 'ruta' a la nueva posición en arrayCabeceras
			strcpy(arrayCabeceras[arraySize - 1], ruta);

			// Copiar la ruta también en filePath
			strcpy(filePath, ruta);

			#pragma omp parallel shared(arrayCabeceras, arraySize, yyin, filePath) private(i)
			{
    			#pragma omp for
    			for (i = 0; i < arraySize; i++) {
        			printf("\n-------%i--------\n", arraySize);

        			#pragma omp critical
        			{
            				bufferState = yy_current_buffer();
            				yy_flush_buffer(bufferState);
            				yyin = fopen(arrayCabeceras[i], "r");

            				if (yyin == NULL) {
                				printf("ERROR: No se ha podido abrir el fichero %s.\n", arrayCabeceras[i]);
                				continue; // Saltar a la siguiente iteración si el archivo no se abre
            				}

           				bufferState = yy_create_buffer(yyin, 1024);
            				yy_switch_to_buffer(bufferState);
        			}
		
        			// Ejecutar la función que trabaja con el array
        			#pragma omp critical
        			{
            				strcpy(filePath, arrayCabeceras[i]);
        			}
        			yyparse();

        			#pragma omp critical
        			{
            				fclose(yyin);
        			}

        			#pragma omp critical
        			{
            				printf("Thread %d realizando manipulaciones posteriores.\n", omp_get_thread_num());
        			}

        			yy_delete_buffer(bufferState);
    			}
		}

		printf("array size final %i\n", arraySize);
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
