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
  YYSYMBOL_UNSIGNED_INT = 52,              /* UNSIGNED_INT  */
  YYSYMBOL_UNSIGNED_SHORT = 53,            /* UNSIGNED_SHORT  */
  YYSYMBOL_UNSIGNED_LONG = 54,             /* UNSIGNED_LONG  */
  YYSYMBOL_FLOAT = 55,                     /* FLOAT  */
  YYSYMBOL_DOUBLE = 56,                    /* DOUBLE  */
  YYSYMBOL_VOID = 57,                      /* VOID  */
  YYSYMBOL_OPENCURLYBRACKET = 58,          /* OPENCURLYBRACKET  */
  YYSYMBOL_CLOSECURLYBRACKET = 59,         /* CLOSECURLYBRACKET  */
  YYSYMBOL_BOOLEAN = 60,                   /* BOOLEAN  */
  YYSYMBOL_CHAR = 61,                      /* CHAR  */
  YYSYMBOL_PRINTF = 62,                    /* PRINTF  */
  YYSYMBOL_SCANF = 63,                     /* SCANF  */
  YYSYMBOL_STRING = 64,                    /* STRING  */
  YYSYMBOL_STRINGV = 65,                   /* STRINGV  */
  YYSYMBOL_QUOTESTRING = 66,               /* QUOTESTRING  */
  YYSYMBOL_TRUEVAL = 67,                   /* TRUEVAL  */
  YYSYMBOL_FALSEVAL = 68,                  /* FALSEVAL  */
  YYSYMBOL_INTNUM = 69,                    /* INTNUM  */
  YYSYMBOL_REALNUM = 70,                   /* REALNUM  */
  YYSYMBOL_RETURN = 71,                    /* RETURN  */
  YYSYMBOL_STRUCT = 72,                    /* STRUCT  */
  YYSYMBOL_AMPERSAND = 73,                 /* AMPERSAND  */
  YYSYMBOL_EX = 74,                        /* EX  */
  YYSYMBOL_YYACCEPT = 75,                  /* $accept  */
  YYSYMBOL_S = 76,                         /* S  */
  YYSYMBOL_comment = 77,                   /* comment  */
  YYSYMBOL_cabecera = 78,                  /* cabecera  */
  YYSYMBOL_constdef = 79,                  /* constdef  */
  YYSYMBOL_vardef = 80,                    /* vardef  */
  YYSYMBOL_type = 81,                      /* type  */
  YYSYMBOL_values = 82,                    /* values  */
  YYSYMBOL_preprograma = 83,               /* preprograma  */
  YYSYMBOL_programa = 84,                  /* programa  */
  YYSYMBOL_args = 85,                      /* args  */
  YYSYMBOL_lines_program = 86,             /* lines_program  */
  YYSYMBOL_if_statement = 87,              /* if_statement  */
  YYSYMBOL_case_chain = 88,                /* case_chain  */
  YYSYMBOL_fun_cre = 89,                   /* fun_cre  */
  YYSYMBOL_line_program = 90,              /* line_program  */
  YYSYMBOL_array = 91,                     /* array  */
  YYSYMBOL_precontentWrite = 92,           /* precontentWrite  */
  YYSYMBOL_contentWrite = 93,              /* contentWrite  */
  YYSYMBOL_exp = 94,                       /* exp  */
  YYSYMBOL_term = 95,                      /* term  */
  YYSYMBOL_operand = 96,                   /* operand  */
  YYSYMBOL_atom = 97                       /* atom  */
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
#define YYLAST   1641

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  75
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  118
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  268

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   329


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
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   190,   190,   241,   244,   249,   254,   260,   301,   305,
     310,   345,   365,   376,   402,   423,   452,   483,   526,   578,
     642,   658,   678,   688,   709,   710,   711,   712,   713,   714,
     715,   716,   717,   718,   719,   720,   721,   731,   734,   735,
     736,   737,   741,   756,   765,   813,   859,   863,   874,   887,
     903,   908,   933,   956,   979,  1018,  1038,  1047,  1060,  1073,
    1085,  1094,  1112,  1126,  1137,  1151,  1163,  1177,  1189,  1204,
    1212,  1220,  1228,  1231,  1234,  1279,  1308,  1324,  1339,  1340,
    1350,  1357,  1364,  1384,  1403,  1414,  1420,  1568,  1584,  1587,
    1594,  1611,  1620,  1625,  1643,  1663,  1666,  1667,  1668,  1669,
    1670,  1671,  1672,  1673,  1674,  1675,  1676,  1677,  1678,  1679,
    1680,  1681,  1682,  1683,  1684,  1689,  1693,  1699,  1711
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
  "INTEGER", "SHORT", "LONG", "UNSIGNED_INT", "UNSIGNED_SHORT",
  "UNSIGNED_LONG", "FLOAT", "DOUBLE", "VOID", "OPENCURLYBRACKET",
  "CLOSECURLYBRACKET", "BOOLEAN", "CHAR", "PRINTF", "SCANF", "STRING",
  "STRINGV", "QUOTESTRING", "TRUEVAL", "FALSEVAL", "INTNUM", "REALNUM",
  "RETURN", "STRUCT", "AMPERSAND", "EX", "$accept", "S", "comment",
  "cabecera", "constdef", "vardef", "type", "values", "preprograma",
  "programa", "args", "lines_program", "if_statement", "case_chain",
  "fun_cre", "line_program", "array", "precontentWrite", "contentWrite",
  "exp", "term", "operand", "atom", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-173)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-119)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       9,   -17,    23,  1542,   -19,     9,  -173,  -173,  -173,   751,
      -5,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,
    -173,  -173,  -173,  1200,  -173,  -173,  -173,  -173,  -173,    17,
    -173,  1542,  1542,    20,  -173,  1542,  -173,  -173,    -6,    56,
    -173,    32,    35,   162,  -173,  -173,    57,    61,     2,   -12,
    -173,  -173,  -173,  -173,   614,  -173,  -173,    42,   333,   116,
      70,   614,   -32,  -173,  -173,    25,  -173,  -173,     9,    48,
    -173,    80,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,
      52,  -173,   153,    37,   153,  1271,  -173,  -173,  -173,    71,
    1308,    12,  -173,  -173,  1201,   614,   153,   471,    78,  -173,
    -173,    94,   162,    41,  1325,   -21,    85,  -173,   153,  -173,
     153,  -173,    83,    86,    64,   104,    87,    -8,   153,    89,
      92,  1200,   395,    73,  -173,  -173,   361,  -173,    88,  -173,
    -173,  1254,   -23,   -18,    91,   105,    95,     9,    93,  -173,
    -173,  -173,   153,   751,  1201,   127,   153,   109,  1201,  1351,
     -46,   -46,   544,  -173,  1368,    96,   110,  -173,   614,  -173,
    -173,  1201,    98,   122,    99,   153,   -24,  -173,  -173,  1405,
     101,   431,   -46,  1429,   153,   501,    50,  -173,  -173,   115,
     136,   124,  -173,  -173,  1201,  -173,  -173,   571,   140,   751,
    1201,  1459,   114,  -173,   117,   139,   173,   129,   641,  1487,
    -173,   215,   142,   132,   144,   153,   148,   711,  -173,   751,
    -173,   781,  -173,   153,  1201,   131,   156,  -173,  1201,  -173,
     145,   159,   160,  1201,  -173,  -173,  1288,  -173,   161,  -173,
    -173,   152,   851,   164,   153,   921,  1201,  1201,  1201,  1201,
    -173,   166,  -173,   153,  1513,  -173,   991,   291,   291,  -173,
    1541,   167,  -173,  -173,  -173,   684,  -173,  1200,   181,  1569,
     168,   176,  1201,  1201,  1061,  1131,  -173,  -173
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     7,     1,     3,     4,     0,
       0,    24,    25,    26,    27,    28,    29,    30,    31,    35,
      34,    33,    32,   115,    41,    37,    38,    39,    40,     0,
      50,     0,     0,     0,   116,     2,    43,   118,     0,     0,
      10,     0,     0,     0,   109,   111,   104,   105,    95,    97,
     100,   101,   102,   103,     0,   112,   113,     0,     0,     0,
       0,     0,    36,    49,    47,     0,    42,    22,     5,     0,
      36,     0,    11,   106,   107,   110,    96,    99,    98,    21,
       0,   108,     0,   115,     0,     0,    91,    92,    68,     0,
      85,     0,   114,    20,     0,     0,     0,     0,     0,    13,
       8,     0,     0,     0,     0,    94,     0,    23,     0,    67,
       0,   117,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   115,     0,     0,    78,    82,     0,    73,    72,    56,
      18,     0,     0,     0,     0,     0,     0,     6,     0,    93,
      90,    84,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    81,     0,    36,     0,    55,     0,    15,
      46,     0,     0,    52,     0,     0,     0,     9,    12,     0,
       0,     0,     0,     0,     0,     0,     0,    89,    88,     0,
      86,     0,    79,    80,     0,    48,    19,     0,    54,     0,
       0,     0,     0,    14,     0,     0,     0,     0,     0,     0,
      60,     0,     0,     0,     0,     0,     0,     0,    45,     0,
      51,     0,    17,     0,     0,     0,     0,    69,     0,    57,
       0,     0,     0,     0,    61,    70,    87,    71,     0,    53,
      44,     0,     0,     0,     0,     0,     0,     0,     0,    66,
      83,     0,    77,     0,     0,    58,     0,    65,    63,    16,
       0,     0,    59,    64,    62,     0,    76,   115,     0,     0,
       0,     0,     0,     0,     0,     0,    75,    74
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -173,  -173,    30,     0,  -173,    -3,    -1,   -39,  -173,    13,
    -172,   -58,  -173,  -154,    26,    68,  -107,  -133,  -173,   -41,
     128,   -22,   -44
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,   124,     3,    31,   125,    80,    34,    35,    36,
     134,   126,   127,   203,    37,   129,    89,   179,   180,    90,
      86,   108,    38
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      32,    61,    33,   141,    72,    40,     4,   147,    42,   162,
     192,    55,    77,    87,    87,    91,    85,   210,   181,   177,
     178,     1,    78,     6,   193,   160,    94,    75,    32,    32,
      33,    33,    32,    30,    33,   161,    76,   229,    87,   197,
      87,   104,    67,   105,    63,    64,    39,   163,    66,     5,
     148,    79,    87,    60,   136,   131,    95,   111,    93,    96,
      43,    30,    30,   138,    87,    30,    87,    97,   100,   201,
     202,    98,    95,    99,    87,    96,    81,   149,    87,    58,
      68,   154,    62,    59,    82,    65,   171,    98,    69,    99,
     175,    73,   130,   253,   254,    74,   133,    70,    87,   152,
      71,   169,    87,   187,    92,   173,   231,    83,    24,    25,
      26,    27,    28,   101,   102,   109,    84,   103,   137,    81,
     128,    87,   144,   135,   191,   142,   207,   145,   143,   146,
      87,   150,   211,   199,   151,   164,  -118,   167,   155,   165,
     166,   168,   170,    83,    24,    25,    26,    27,    28,    93,
     172,   174,   128,   189,   184,   186,   232,   190,   185,   204,
     235,    87,   222,   188,   226,   239,   195,   205,   206,    87,
     128,   209,   213,   215,   128,   214,   216,   217,   246,   247,
     248,    83,    24,    25,    26,    27,    28,   128,   133,   223,
      87,   224,   225,   244,   157,    82,   227,   128,   234,    87,
     233,   128,   250,   236,   264,   265,   237,   238,   133,   240,
     128,   241,   243,   128,   249,   256,   128,     0,    83,    24,
      25,    26,    27,    28,   128,   260,   262,    84,    24,    25,
      26,    27,    28,   128,   263,   259,   140,   128,     0,   157,
     128,     0,     0,   157,   128,     0,     0,     0,     0,   128,
       0,     0,   258,     0,     0,   157,    93,     0,   128,     0,
       0,   128,   128,   128,   128,   128,   219,     0,     0,     0,
       0,     0,   128,   128,   128,   157,     0,     0,     0,   157,
     221,    24,    25,    26,    27,    28,     0,     0,   128,   128,
     128,   128,     0,     0,   112,   113,   114,     0,     0,   115,
     157,     0,     0,   157,     0,     0,   116,   157,   117,   118,
     201,   202,     0,     0,   157,   157,   157,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     7,     8,     0,     0,
       0,     0,   157,   157,     0,     0,     0,     0,     0,     0,
      11,    12,    13,    14,    15,    16,    17,    18,    19,     0,
       0,    20,    21,   119,   120,    22,   121,    24,    25,    26,
      27,    28,   122,   123,   112,   113,   114,     0,     0,   115,
       0,     0,     0,     0,     0,    82,   116,    88,   117,   118,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     7,     8,    83,    24,
      25,    26,    27,    28,     0,     0,     0,    84,     0,     0,
      11,    12,    13,    14,    15,    16,    17,    18,    19,     0,
     156,    20,    21,   119,   120,    22,   121,    24,    25,    26,
      27,    28,   122,   123,   112,   113,   114,    82,     0,   115,
       0,     0,     0,   153,     0,     0,   116,     0,   117,   118,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      83,    24,    25,    26,    27,    28,     7,     8,     0,    84,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      11,    12,    13,    14,    15,    16,    17,    18,    19,     0,
     196,    20,    21,   119,   120,    22,   121,    24,    25,    26,
      27,    28,   122,   123,   112,   113,   114,     0,     0,   115,
       0,     0,     0,     0,     0,   132,   116,     0,   117,   118,
      11,    12,    13,    14,    15,    16,    17,    18,    19,     0,
       0,    20,    21,     0,     0,    22,     7,     8,     0,     0,
       0,     0,     0,    41,     0,     0,     0,     0,     0,     0,
      11,    12,    13,    14,    15,    16,    17,    18,    19,     0,
     200,    20,    21,   119,   120,    22,   121,    24,    25,    26,
      27,    28,   122,   123,   112,   113,   114,     0,     0,   115,
       0,     0,     0,     0,     0,     0,   116,     0,   117,   118,
       0,     0,   182,    11,    12,    13,    14,    15,    16,    17,
      18,    19,     0,     0,    20,    21,     7,     8,    22,    23,
      24,    25,    26,    27,    28,     0,    41,     0,     0,     0,
      11,    12,    13,    14,    15,    16,    17,    18,    19,     0,
     208,    20,    21,   119,   120,    22,   121,    24,    25,    26,
      27,    28,   122,   123,   112,   113,   114,     0,     0,   115,
       0,     0,     0,     0,     0,     0,   116,     0,   117,   118,
       0,     0,     0,    11,    12,    13,    14,    15,    16,    17,
      18,    19,     0,     0,    20,    21,     7,     8,    22,    23,
      24,    25,    26,    27,    28,     0,    41,     0,     0,     0,
      11,    12,    13,    14,    15,    16,    17,    18,    19,   218,
       0,    20,    21,   119,   120,    22,   121,    24,    25,    26,
      27,    28,   122,   123,   112,   113,   114,     0,     0,   115,
       0,     0,     0,     0,     0,     0,   116,     0,   117,   118,
       0,     0,     0,    11,    12,    13,    14,    15,    16,    17,
      18,    19,     0,     0,    20,    21,     7,     8,    22,   257,
      24,    25,    26,    27,    28,     0,    41,     0,     0,     0,
      11,    12,    13,    14,    15,    16,    17,    18,    19,     0,
     228,    20,    21,   119,   120,    22,   121,    24,    25,    26,
      27,    28,   122,   123,   112,   113,   114,     0,     0,   115,
       0,     0,     0,     0,     0,     0,   116,     0,   117,   118,
      11,    12,    13,    14,    15,    16,    17,    18,    19,     0,
       0,    20,    21,     0,     0,    22,     7,     8,     0,     0,
       0,     0,     0,    41,     0,     0,     0,     0,     0,     0,
      11,    12,    13,    14,    15,    16,    17,    18,    19,     0,
     230,    20,    21,   119,   120,    22,   121,    24,    25,    26,
      27,    28,   122,   123,   112,   113,   114,     0,     0,   115,
       0,     0,     0,     0,     0,     0,   116,     0,   117,   118,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     7,     8,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      11,    12,    13,    14,    15,    16,    17,    18,    19,     0,
     242,    20,    21,   119,   120,    22,   121,    24,    25,    26,
      27,    28,   122,   123,   112,   113,   114,     0,     0,   115,
       0,     0,     0,     0,     0,     0,   116,     0,   117,   118,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     7,     8,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      11,    12,    13,    14,    15,    16,    17,    18,    19,     0,
     245,    20,    21,   119,   120,    22,   121,    24,    25,    26,
      27,    28,   122,   123,   112,   113,   114,     0,     0,   115,
       0,     0,     0,     0,     0,     0,   116,     0,   117,   118,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     7,     8,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      11,    12,    13,    14,    15,    16,    17,    18,    19,     0,
     252,    20,    21,   119,   120,    22,   121,    24,    25,    26,
      27,    28,   122,   123,   112,   113,   114,     0,     0,   115,
       0,     0,     0,     0,     0,     0,   116,     0,   117,   118,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     7,     8,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      11,    12,    13,    14,    15,    16,    17,    18,    19,     0,
     266,    20,    21,   119,   120,    22,   121,    24,    25,    26,
      27,    28,   122,   123,   112,   113,   114,     0,     0,   115,
       0,     0,     0,     0,     0,     0,   116,     0,   117,   118,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     7,     8,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      11,    12,    13,    14,    15,    16,    17,    18,    19,     0,
     267,    20,    21,   119,   120,    22,   121,    24,    25,    26,
      27,    28,   122,   123,   112,   113,   114,     0,     0,   115,
       0,     0,     0,     0,     0,     0,   116,     0,   117,   118,
       0,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,     0,     7,     8,     0,     0,
       0,     0,    58,     0,     0,     0,    59,     0,     0,     0,
      11,    12,    13,    14,    15,    16,    17,    18,    19,     0,
       0,    20,    21,   119,   120,    22,   121,    24,    25,    26,
      27,    28,   122,   123,    60,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,   158,    55,    56,   106,     0,
       0,     0,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,   159,    55,    56,   106,     0,     0,     0,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,   107,
      55,    56,   106,     0,     0,     0,     0,     0,    60,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,   110,
      55,    56,   106,     0,     0,    60,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,     0,    55,    56,   106,
       0,     0,    60,     0,     0,     0,     0,     0,     0,   139,
       0,     0,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    60,    55,    56,   106,     0,     0,     0,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    60,
      55,    56,   106,     0,     0,     0,     0,     0,     0,   176,
       0,     0,     0,     0,     0,     0,   183,     0,     0,     0,
       0,     0,     0,     0,     0,    60,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,     0,    55,    56,   106,
       0,     0,    60,     0,     0,     0,     0,     0,     0,   194,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
       0,    55,    56,   106,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   198,     0,     0,     0,     0,     0,    60,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
       0,    55,    56,   106,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    60,     0,     0,     0,   212,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,     0,    55,
      56,   106,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   220,     0,    60,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,     0,    55,    56,   106,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   251,     0,     0,
       0,    60,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,     0,    55,    56,   106,     0,     7,     8,     0,
       9,    10,     0,     0,     0,     0,     0,    60,     0,   255,
       0,    11,    12,    13,    14,    15,    16,    17,    18,    19,
       0,     0,    20,    21,     0,     0,    22,    23,    24,    25,
      26,    27,    28,   261,    29,    60,     0,     0,    11,    12,
      13,    14,    15,    16,    17,    18,    19,     0,     0,    20,
      21,     0,     0,    22,    23,    24,    25,    26,    27,    28,
       0,    41
};

static const yytype_int16 yycheck[] =
{
       3,    23,     3,   110,    43,     5,    23,    15,     9,    27,
      34,    32,    24,    57,    58,    59,    57,   189,   151,    65,
      66,    12,    34,     0,    48,    48,    58,    25,    31,    32,
      31,    32,    35,     3,    35,    58,    34,   209,    82,   172,
      84,    82,    48,    84,    31,    32,    65,    65,    35,    66,
      58,    54,    96,    74,    98,    96,    31,    45,    61,    34,
      65,    31,    32,   102,   108,    35,   110,    42,    68,    19,
      20,    46,    31,    48,   118,    34,    34,   118,   122,    42,
      24,   122,    65,    46,    42,    65,   144,    46,    32,    48,
     148,    34,    95,   247,   248,    34,    97,    65,   142,   121,
      65,   142,   146,   161,    34,   146,   213,    65,    66,    67,
      68,    69,    70,    65,    34,    44,    74,    65,    24,    34,
      94,   165,    58,    45,   165,    42,   184,    23,    42,    42,
     174,    42,   190,   174,    42,    44,    48,   137,    65,    34,
      45,    48,   143,    65,    66,    67,    68,    69,    70,   152,
      23,    42,   126,    31,    58,   158,   214,    58,    48,    44,
     218,   205,   201,    65,   205,   223,    65,    31,    44,   213,
     144,    31,    58,    34,   148,    58,     3,    48,   236,   237,
     238,    65,    66,    67,    68,    69,    70,   161,   189,    47,
     234,    59,    48,   234,   126,    42,    48,   171,    42,   243,
      69,   175,   243,    58,   262,   263,    47,    47,   209,    48,
     184,    59,    48,   187,    48,    48,   190,    -1,    65,    66,
      67,    68,    69,    70,   198,    44,    58,    74,    66,    67,
      68,    69,    70,   207,    58,   257,   108,   211,    -1,   171,
     214,    -1,    -1,   175,   218,    -1,    -1,    -1,    -1,   223,
      -1,    -1,   255,    -1,    -1,   187,   259,    -1,   232,    -1,
      -1,   235,   236,   237,   238,   239,   198,    -1,    -1,    -1,
      -1,    -1,   246,   247,   248,   207,    -1,    -1,    -1,   211,
      65,    66,    67,    68,    69,    70,    -1,    -1,   262,   263,
     264,   265,    -1,    -1,     3,     4,     5,    -1,    -1,     8,
     232,    -1,    -1,   235,    -1,    -1,    15,   239,    17,    18,
      19,    20,    -1,    -1,   246,   247,   248,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    -1,    -1,
      -1,    -1,   264,   265,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    -1,
      -1,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,     3,     4,     5,    -1,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    42,    15,    44,    17,    18,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    65,    66,
      67,    68,    69,    70,    -1,    -1,    -1,    74,    -1,    -1,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,     3,     4,     5,    42,    -1,     8,
      -1,    -1,    -1,    48,    -1,    -1,    15,    -1,    17,    18,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      65,    66,    67,    68,    69,    70,    35,    36,    -1,    74,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,     3,     4,     5,    -1,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    44,    15,    -1,    17,    18,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    -1,
      -1,    60,    61,    -1,    -1,    64,    35,    36,    -1,    -1,
      -1,    -1,    -1,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,     3,     4,     5,    -1,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,    17,    18,
      -1,    -1,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    -1,    -1,    60,    61,    35,    36,    64,    65,
      66,    67,    68,    69,    70,    -1,    72,    -1,    -1,    -1,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,     3,     4,     5,    -1,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,    17,    18,
      -1,    -1,    -1,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    -1,    -1,    60,    61,    35,    36,    64,    65,
      66,    67,    68,    69,    70,    -1,    72,    -1,    -1,    -1,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      -1,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,     3,     4,     5,    -1,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,    17,    18,
      -1,    -1,    -1,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    -1,    -1,    60,    61,    35,    36,    64,    65,
      66,    67,    68,    69,    70,    -1,    72,    -1,    -1,    -1,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,     3,     4,     5,    -1,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,    17,    18,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    -1,
      -1,    60,    61,    -1,    -1,    64,    35,    36,    -1,    -1,
      -1,    -1,    -1,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,     3,     4,     5,    -1,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,    17,    18,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,     3,     4,     5,    -1,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,    17,    18,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,     3,     4,     5,    -1,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,    17,    18,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,     3,     4,     5,    -1,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,    17,    18,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,     3,     4,     5,    -1,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,    17,    18,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,     3,     4,     5,    -1,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,    17,    18,
      -1,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    35,    36,    -1,    -1,
      -1,    -1,    42,    -1,    -1,    -1,    46,    -1,    -1,    -1,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    -1,
      -1,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    74,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    -1,
      -1,    -1,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    48,    32,    33,    34,    -1,    -1,    -1,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    48,
      32,    33,    34,    -1,    -1,    -1,    -1,    -1,    74,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,    74,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    -1,    32,    33,    34,
      -1,    -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      -1,    -1,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    74,    32,    33,    34,    -1,    -1,    -1,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    74,
      32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    58,
      -1,    -1,    -1,    -1,    -1,    -1,    48,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    74,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    -1,    32,    33,    34,
      -1,    -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      -1,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    -1,    -1,    -1,    -1,    -1,    74,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      -1,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    74,    -1,    -1,    -1,    48,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    -1,    32,
      33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    -1,    74,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    -1,    32,    33,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    -1,    -1,
      -1,    74,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    -1,    32,    33,    34,    -1,    35,    36,    -1,
      38,    39,    -1,    -1,    -1,    -1,    -1,    74,    -1,    48,
      -1,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      -1,    -1,    60,    61,    -1,    -1,    64,    65,    66,    67,
      68,    69,    70,    44,    72,    74,    -1,    -1,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    -1,    -1,    60,
      61,    -1,    -1,    64,    65,    66,    67,    68,    69,    70,
      -1,    72
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    12,    76,    78,    23,    66,     0,    35,    36,    38,
      39,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      60,    61,    64,    65,    66,    67,    68,    69,    70,    72,
      77,    79,    80,    81,    82,    83,    84,    89,    97,    65,
      78,    72,    81,    65,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    42,    46,
      74,    96,    65,    84,    84,    65,    84,    48,    24,    32,
      65,    65,    82,    34,    34,    25,    34,    24,    34,    80,
      81,    34,    42,    65,    74,    94,    95,    97,    44,    91,
      94,    97,    34,    80,    58,    31,    34,    42,    46,    48,
      78,    65,    34,    65,    94,    94,    34,    48,    96,    44,
      31,    45,     3,     4,     5,     8,    15,    17,    18,    62,
      63,    65,    71,    72,    77,    80,    86,    87,    89,    90,
      80,    94,    44,    81,    85,    45,    97,    24,    82,    44,
      95,    91,    42,    42,    58,    23,    42,    15,    58,    94,
      42,    42,    96,    48,    94,    65,    59,    90,    31,    48,
      48,    58,    27,    65,    44,    34,    45,    78,    48,    94,
      81,    86,    23,    94,    42,    86,    58,    65,    66,    92,
      93,    92,    48,    48,    58,    48,    80,    86,    65,    31,
      58,    94,    34,    48,    44,    65,    59,    92,    44,    94,
      59,    19,    20,    88,    44,    31,    44,    86,    59,    31,
      85,    86,    48,    58,    58,    34,     3,    48,    58,    90,
      44,    65,    82,    47,    59,    48,    94,    48,    59,    85,
      59,    91,    86,    69,    42,    86,    58,    47,    47,    86,
      48,    59,    59,    48,    94,    59,    86,    86,    86,    48,
      94,    44,    59,    88,    88,    48,    48,    65,    80,    96,
      44,    44,    58,    58,    86,    86,    59,    59
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    75,    76,    77,    77,    78,    78,    78,    78,    78,
      78,    79,    79,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    82,    82,    82,
      82,    82,    83,    83,    84,    84,    84,    84,    84,    84,
      84,    85,    85,    85,    85,    86,    86,    87,    87,    87,
      87,    87,    88,    88,    88,    88,    88,    89,    89,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    91,    91,    92,    93,    93,    93,
      94,    94,    95,    95,    95,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    97,    97,    97,    97
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     4,     6,     2,     5,     7,
       3,     3,     6,     3,     6,     5,    10,     7,     4,     6,
       3,     3,     2,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     1,     1,
       1,     1,     2,     1,     8,     7,     5,     2,     6,     2,
       1,     4,     2,     5,     3,     2,     1,     5,     7,     8,
       4,     5,     5,     4,     5,     4,     3,     4,     3,     5,
       5,     5,     1,     1,    15,    14,     9,     7,     1,     3,
       3,     2,     1,     6,     3,     1,     1,     3,     1,     1,
       3,     1,     1,     3,     2,     1,     2,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     1,
       2,     1,     1,     1,     2,     1,     1,     4,     1
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
#line 190 "scanner.y"
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
#line 1991 "scanner.tab.c"
    break;

  case 3: /* comment: COMMENTLINE  */
#line 241 "scanner.y"
                     {
                (yyval.valString) = (yyvsp[0].valString);
                }
#line 1999 "scanner.tab.c"
    break;

  case 4: /* comment: MULTILINE  */
#line 244 "scanner.y"
                    {;}
#line 2005 "scanner.tab.c"
    break;

  case 5: /* cabecera: PROGRAM LOWER STRINGV HIGHER  */
#line 249 "scanner.y"
                                             {
	 		free((yyvsp[-1].valString));
			(yyval.valString) = "";

		}
#line 2015 "scanner.tab.c"
    break;

  case 6: /* cabecera: PROGRAM LOWER STRINGV DOT STRINGV HIGHER  */
#line 254 "scanner.y"
                                                          {
			
			free((yyvsp[-3].valString));
			free((yyvsp[-1].valString));
			(yyval.valString) = "";
		}
#line 2026 "scanner.tab.c"
    break;

  case 7: /* cabecera: PROGRAM QUOTESTRING  */
#line 260 "scanner.y"
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
#line 2072 "scanner.tab.c"
    break;

  case 8: /* cabecera: PROGRAM LOWER STRINGV HIGHER cabecera  */
#line 301 "scanner.y"
                                                       {
			free((yyvsp[-2].valString));	
			(yyval.valString) = "";
		}
#line 2081 "scanner.tab.c"
    break;

  case 9: /* cabecera: PROGRAM LOWER STRINGV DOT STRINGV HIGHER cabecera  */
#line 305 "scanner.y"
                                                                  {
			free((yyvsp[-4].valString));
			free((yyvsp[-2].valString));
			(yyval.valString) = "";
		}
#line 2091 "scanner.tab.c"
    break;

  case 10: /* cabecera: PROGRAM QUOTESTRING cabecera  */
#line 310 "scanner.y"
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
#line 2128 "scanner.tab.c"
    break;

  case 11: /* constdef: DEFINE STRINGV values  */
#line 345 "scanner.y"
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
#line 2151 "scanner.tab.c"
    break;

  case 12: /* constdef: CONST type STRINGV EQ values SEMICOLON  */
#line 365 "scanner.y"
                                                {
                
		free((yyvsp[-3].valString));
		free((yyvsp[-1].valString));
	}
#line 2161 "scanner.tab.c"
    break;

  case 13: /* vardef: type STRINGV SEMICOLON  */
#line 376 "scanner.y"
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
#line 2191 "scanner.tab.c"
    break;

  case 14: /* vardef: type STRINGV LSQUAREPAREN atom RSQUAREPAREN SEMICOLON  */
#line 402 "scanner.y"
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
#line 2217 "scanner.tab.c"
    break;

  case 15: /* vardef: type STRINGV EQ exp SEMICOLON  */
#line 423 "scanner.y"
                                        {//2
		char *tipo;
		if (strcmp(obtenerTipo((yyvsp[-4].valInt)), "struct") == 0) {
			tipo = tipoStruct;
		} else {
			tipo = obtenerTipo((yyvsp[-4].valInt));
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
		free((yyvsp[-1].valString));
		(yyval.valString) = final;
        }
#line 2250 "scanner.tab.c"
    break;

  case 16: /* vardef: type STRINGV LSQUAREPAREN atom RSQUAREPAREN EQ OPENCURLYBRACKET array CLOSECURLYBRACKET SEMICOLON  */
#line 452 "scanner.y"
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
#line 2286 "scanner.tab.c"
    break;

  case 17: /* vardef: type STRINGV LSQUAREPAREN RSQUAREPAREN EQ exp SEMICOLON  */
#line 483 "scanner.y"
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
#line 2312 "scanner.tab.c"
    break;

  case 18: /* vardef: type STRINGV COMMA vardef  */
#line 526 "scanner.y"
                                   {//7
                char *tipo;
                if (strcmp(obtenerTipo((yyvsp[-3].valInt)), "struct") == 0) {
                        tipo = tipoStruct;
                        
                }else{
                        tipo = obtenerTipo((yyvsp[-3].valInt));

                }                
		strcpy(gType, tipo);
                char * final = malloc(strlen((yyvsp[-2].valString))*sizeof(char) + strlen((yyvsp[0].valString))*sizeof(char)+ strlen(tipo)*sizeof(char) + sizeof(", "));
                memset(final, 0 , sizeof(final));

                strcat(final, "let ");
                strcat(final, (yyvsp[-2].valString));
                strcat(final, ":;\n");;
                strcat(final, (yyvsp[0].valString));
		free((yyvsp[-2].valString));
		free((yyvsp[0].valString));
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
#line 2369 "scanner.tab.c"
    break;

  case 19: /* vardef: type STRINGV EQ exp COMMA vardef  */
#line 578 "scanner.y"
                                          {//8
                char *tipo;
                if (strcmp(obtenerTipo((yyvsp[-5].valInt)), "struct") == 0) {
                        tipo = tipoStruct;
                        
                }else{
                        tipo = obtenerTipo((yyvsp[-5].valInt));

                }                
		char * final = malloc(strlen((yyvsp[-4].valString))*sizeof(char) + strlen((yyvsp[-2].valString))*sizeof(char)+ strlen((yyvsp[0].valString))*sizeof(char)+ strlen(tipo)*sizeof(char) + sizeof(", "));
                memset(final, 0 , sizeof(final));

                strcat(final, "let ");
                strcat(final, (yyvsp[-4].valString));
                strcat(final, ":=");
                strcat(final, (yyvsp[-2].valString));
                strcat(final,";\n");
                strcat(final, (yyvsp[0].valString));
		free((yyvsp[-4].valString));
		free((yyvsp[-2].valString));
		free((yyvsp[0].valString));
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
#line 2426 "scanner.tab.c"
    break;

  case 20: /* vardef: STRINGV operand vardef  */
#line 642 "scanner.y"
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
#line 2447 "scanner.tab.c"
    break;

  case 21: /* vardef: STRINGV COMMA vardef  */
#line 658 "scanner.y"
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
#line 2463 "scanner.tab.c"
    break;

  case 22: /* vardef: atom SEMICOLON  */
#line 678 "scanner.y"
                       {//11

                char * final = malloc(strlen((yyvsp[-1].valString))*sizeof(char) + sizeof(";  \n") );
                memset(final, 0, sizeof(final));
                
                strcat(final, (yyvsp[-1].valString));
                strcat(final, ";\n");
		free((yyvsp[-1].valString));
                (yyval.valString) = final;
        }
#line 2478 "scanner.tab.c"
    break;

  case 23: /* vardef: STRINGV EQ exp SEMICOLON  */
#line 688 "scanner.y"
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
#line 2495 "scanner.tab.c"
    break;

  case 24: /* type: INTEGER  */
#line 709 "scanner.y"
                {(yyval.valInt) = 0;}
#line 2501 "scanner.tab.c"
    break;

  case 25: /* type: SHORT  */
#line 710 "scanner.y"
                {(yyval.valInt) = 1;}
#line 2507 "scanner.tab.c"
    break;

  case 26: /* type: LONG  */
#line 711 "scanner.y"
               {(yyval.valInt) = 2;}
#line 2513 "scanner.tab.c"
    break;

  case 27: /* type: UNSIGNED_INT  */
#line 712 "scanner.y"
                       {(yyval.valInt) = 3;}
#line 2519 "scanner.tab.c"
    break;

  case 28: /* type: UNSIGNED_SHORT  */
#line 713 "scanner.y"
                         {(yyval.valInt) = 4;}
#line 2525 "scanner.tab.c"
    break;

  case 29: /* type: UNSIGNED_LONG  */
#line 714 "scanner.y"
                        {(yyval.valInt) = 5;}
#line 2531 "scanner.tab.c"
    break;

  case 30: /* type: FLOAT  */
#line 715 "scanner.y"
                {(yyval.valInt) = 6;}
#line 2537 "scanner.tab.c"
    break;

  case 31: /* type: DOUBLE  */
#line 716 "scanner.y"
                 {(yyval.valInt) = 7;}
#line 2543 "scanner.tab.c"
    break;

  case 32: /* type: STRING  */
#line 717 "scanner.y"
                 {(yyval.valInt) = 8;}
#line 2549 "scanner.tab.c"
    break;

  case 33: /* type: CHAR  */
#line 718 "scanner.y"
               {(yyval.valInt) = 9;}
#line 2555 "scanner.tab.c"
    break;

  case 34: /* type: BOOLEAN  */
#line 719 "scanner.y"
                  {(yyval.valInt) = 10;}
#line 2561 "scanner.tab.c"
    break;

  case 35: /* type: VOID  */
#line 720 "scanner.y"
               {;}
#line 2567 "scanner.tab.c"
    break;

  case 36: /* type: STRUCT STRINGV  */
#line 721 "scanner.y"
                         {
                strcpy(tipoStruct, (yyvsp[0].valString));
		free((yyvsp[0].valString));
                (yyval.valInt) = 11;
        ;}
#line 2577 "scanner.tab.c"
    break;

  case 37: /* values: TRUEVAL  */
#line 731 "scanner.y"
                {
                (yyval.valString) = strdup("true");
        }
#line 2585 "scanner.tab.c"
    break;

  case 38: /* values: FALSEVAL  */
#line 734 "scanner.y"
                   {(yyval.valString) = (yyvsp[0].valString);}
#line 2591 "scanner.tab.c"
    break;

  case 39: /* values: INTNUM  */
#line 735 "scanner.y"
                 {(yyval.valString) = (yyvsp[0].valString);}
#line 2597 "scanner.tab.c"
    break;

  case 40: /* values: REALNUM  */
#line 736 "scanner.y"
                  {(yyval.valString) = (yyvsp[0].valString);}
#line 2603 "scanner.tab.c"
    break;

  case 41: /* values: QUOTESTRING  */
#line 737 "scanner.y"
                      {(yyval.valString) = (yyvsp[0].valString);}
#line 2609 "scanner.tab.c"
    break;

  case 42: /* preprograma: preprograma programa  */
#line 741 "scanner.y"
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
#line 2629 "scanner.tab.c"
    break;

  case 43: /* preprograma: programa  */
#line 756 "scanner.y"
                   {
		char *final = malloc((strlen((yyvsp[0].valString)) + 1) * sizeof(char)); // Reservar espacio suficiente incluyendo el terminador nulo
    		memset(final, 0, (strlen((yyvsp[0].valString)) + 1) * sizeof(char)); // Inicializar toda la memoria a 0
    		strcat(final, (yyvsp[0].valString)); // Concatenar $1 en `final`
    		free((yyvsp[0].valString)); // Liberar memoria de $1
    		(yyval.valString) = final; // Asignar el resultado a $$
	}
#line 2641 "scanner.tab.c"
    break;

  case 44: /* programa: type STRINGV LPAREN args RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET  */
#line 765 "scanner.y"
                                                                                        {                        
			printf("hola2\n");                        
                        
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
#line 2693 "scanner.tab.c"
    break;

  case 45: /* programa: type STRINGV LPAREN RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET  */
#line 813 "scanner.y"
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
#line 2743 "scanner.tab.c"
    break;

  case 46: /* programa: type STRINGV LPAREN RPAREN SEMICOLON  */
#line 859 "scanner.y"
                                             {
                free((yyvsp[-3].valString));
		(yyval.valString) = "";
        }
#line 2752 "scanner.tab.c"
    break;

  case 47: /* programa: vardef programa  */
#line 863 "scanner.y"
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
#line 2767 "scanner.tab.c"
    break;

  case 48: /* programa: STRUCT STRINGV OPENCURLYBRACKET lines_program CLOSECURLYBRACKET SEMICOLON  */
#line 874 "scanner.y"
                                                                                  {
                char * final = malloc(strlen((yyvsp[-4].valString))*sizeof(char) + strlen((yyvsp[-2].valString))*sizeof(char) + strlen("struct { } \n\n"));
                memset(final, 0 , sizeof(final));
                strcat(final, "struct ");
                strcat(final, (yyvsp[-4].valString));
                strcat(final, " {\n");
                strcat(final, (yyvsp[-2].valString));
                strcat(final, "}\n");
                replaceSemicolon(final);
		free((yyvsp[-4].valString));
		free((yyvsp[-2].valString));
                (yyval.valString) = final; 
        }
#line 2785 "scanner.tab.c"
    break;

  case 49: /* programa: constdef programa  */
#line 887 "scanner.y"
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
#line 2805 "scanner.tab.c"
    break;

  case 50: /* programa: comment  */
#line 903 "scanner.y"
                {;}
#line 2811 "scanner.tab.c"
    break;

  case 51: /* args: type STRINGV COMMA args  */
#line 908 "scanner.y"
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
#line 2841 "scanner.tab.c"
    break;

  case 52: /* args: type STRINGV  */
#line 933 "scanner.y"
                      {
                char * final;
                char *tipo;
                if (strcmp(obtenerTipo((yyvsp[-1].valInt)), "struct") == 0) {
                        tipo = malloc(strlen(tipoStruct)*sizeof(char) + strlen((yyvsp[0].valString)) * sizeof(char) + sizeof(": &mut "));
                        strcat(tipo, (yyvsp[0].valString));
                        strcat(tipo, ": &mut ");
                        strcat(tipo, tipoStruct);
			free((yyvsp[0].valString));
                        (yyval.valString) = tipo;

                }else{
                        tipo = obtenerTipo((yyvsp[-1].valInt));
                        final = malloc(strlen(tipo) * sizeof(char) + strlen((yyvsp[0].valString)) * sizeof(char) );
                        memset(final, 0, sizeof(final));
                        strcat(final, tipo);
                        strcat(final, " ");
                        strcat(final, (yyvsp[0].valString));
			free((yyvsp[0].valString));
                        (yyval.valString) = final;

                }                
        }
#line 2869 "scanner.tab.c"
    break;

  case 53: /* args: type PROD STRINGV COMMA args  */
#line 956 "scanner.y"
                                      {
                char * final;
                
                char *tipo;
                if (strcmp(obtenerTipo((yyvsp[-4].valInt)), "struct") == 0) {
                        tipo = tipoStruct;
                        
                }else{
                        tipo = obtenerTipo((yyvsp[-4].valInt));

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
#line 2897 "scanner.tab.c"
    break;

  case 54: /* args: type PROD STRINGV  */
#line 979 "scanner.y"
                            {
		char *final;
		char *tipo;

		if (strcmp(obtenerTipo((yyvsp[-2].valInt)), "struct") == 0) {
			// Asignación de memoria para `tipo` con espacio suficiente y el terminador nulo
			tipo = malloc(strlen(tipoStruct) + strlen((yyvsp[0].valString)) + strlen(": &mut ") + 1);

			// Inicialización de `tipo`
			tipo[0] = '\0';

			// Concatenación
			strcat(tipo, (yyvsp[0].valString));
			strcat(tipo, ": &mut ");
			strcat(tipo, tipoStruct);

			free((yyvsp[0].valString));
			(yyval.valString) = tipo;
		} else {
			tipo = obtenerTipo((yyvsp[-2].valInt));

			// Asignación de memoria para `final` con espacio suficiente y el terminador nulo
			final = malloc(strlen(tipo) + strlen((yyvsp[0].valString)) + 2);  // +2 para el espacio y '\0'

			// Inicialización de `final`
			final[0] = '\0';

			// Concatenación
			strcat(final, tipo);
			strcat(final, " ");
			strcat(final, (yyvsp[0].valString));

			free((yyvsp[0].valString));
			(yyval.valString) = final;
		}
	}
#line 2938 "scanner.tab.c"
    break;

  case 55: /* lines_program: lines_program line_program  */
#line 1018 "scanner.y"
                                   {
	// Calcular el tamaño total necesario para el buffer
		char *final = malloc(strlen((yyvsp[-1].valString)) + strlen((yyvsp[0].valString)) + 2); // +2 para "\n" y '\0'
		if (final == NULL) {
    		// Manejo del error si malloc falla
    			return 0;
		}

		// Copiar las cadenas
		strcpy(final, (yyvsp[-1].valString));
		strcat(final, "\n");
		strcat(final, (yyvsp[0].valString));

		// Liberar las cadenas individuales
		free((yyvsp[-1].valString));
		free((yyvsp[0].valString));

		// Asignar el resultado a $$
		(yyval.valString) = final;
        }
#line 2963 "scanner.tab.c"
    break;

  case 56: /* lines_program: line_program  */
#line 1038 "scanner.y"
                       {
                (yyval.valString) = (yyvsp[0].valString);
                
                }
#line 2972 "scanner.tab.c"
    break;

  case 57: /* if_statement: IF LPAREN exp RPAREN line_program  */
#line 1047 "scanner.y"
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
#line 2990 "scanner.tab.c"
    break;

  case 58: /* if_statement: IF LPAREN exp RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET  */
#line 1060 "scanner.y"
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
#line 3008 "scanner.tab.c"
    break;

  case 59: /* if_statement: ELSE IF LPAREN exp RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET  */
#line 1073 "scanner.y"
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
#line 3025 "scanner.tab.c"
    break;

  case 60: /* if_statement: ELSE OPENCURLYBRACKET lines_program CLOSECURLYBRACKET  */
#line 1085 "scanner.y"
                                                                {
                char* final = malloc(strlen((yyvsp[-1].valString))*sizeof(char)+ sizeof("else {} \n \n \t"));
                memset(final, 0, sizeof(final));
                strcat(final, "else{\n\t");
                strcat(final, (yyvsp[-1].valString));
                strcat(final, "}\n");
                (yyval.valString) = final;
        
        }
#line 3039 "scanner.tab.c"
    break;

  case 61: /* if_statement: SWITCH exp OPENCURLYBRACKET case_chain CLOSECURLYBRACKET  */
#line 1094 "scanner.y"
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
#line 3057 "scanner.tab.c"
    break;

  case 62: /* case_chain: CASE values COLON lines_program case_chain  */
#line 1112 "scanner.y"
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
#line 3076 "scanner.tab.c"
    break;

  case 63: /* case_chain: CASE values COLON lines_program  */
#line 1126 "scanner.y"
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
#line 3092 "scanner.tab.c"
    break;

  case 64: /* case_chain: CASE STRINGV COLON lines_program case_chain  */
#line 1137 "scanner.y"
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
#line 3111 "scanner.tab.c"
    break;

  case 65: /* case_chain: CASE STRINGV COLON lines_program  */
#line 1151 "scanner.y"
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
#line 3128 "scanner.tab.c"
    break;

  case 66: /* case_chain: DEFAULT COLON lines_program  */
#line 1163 "scanner.y"
                                     {
		char *final = malloc(strlen("_ => ,  \n") + strlen((yyvsp[0].valString)) + 1);
		final[0] = '\0';
		strcat(final, "_ => {\n");
		strcat(final, (yyvsp[0].valString));
		strcat(final, "\n}");
		free((yyvsp[0].valString));
		(yyval.valString) = final;

	}
#line 3143 "scanner.tab.c"
    break;

  case 67: /* fun_cre: STRINGV LPAREN array RPAREN  */
#line 1177 "scanner.y"
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
#line 3160 "scanner.tab.c"
    break;

  case 68: /* fun_cre: STRINGV LPAREN RPAREN  */
#line 1189 "scanner.y"
                              {
                char * final = malloc(strlen((yyvsp[-2].valString))* sizeof(char) +  sizeof("()") + 1);
                memset(final,0, sizeof(final));
                strcat(final, (yyvsp[-2].valString));
                strcat(final, "(");
                strcat(final,")");
		free((yyvsp[-2].valString));
                (yyval.valString) = final;

        }
#line 3175 "scanner.tab.c"
    break;

  case 69: /* line_program: WRITE LOWER LOWER precontentWrite SEMICOLON  */
#line 1204 "scanner.y"
                                                    {
        	char * final = malloc(strlen((yyvsp[-1].valString))*sizeof(char));
		memset(final, 0, sizeof(final));
		strcat(final, (yyvsp[-1].valString));
		free((yyvsp[-1].valString));
                (yyval.valString) = final;
                
        }
#line 3188 "scanner.tab.c"
    break;

  case 70: /* line_program: PRINTF LPAREN precontentWrite RPAREN SEMICOLON  */
#line 1212 "scanner.y"
                                                         {
                char * final = malloc(strlen((yyvsp[-2].valString))*sizeof(char)+ sizeof("print!"));
                memset(final, 0, sizeof(final));
                strcat(final, "print!");
                strcat(final, (yyvsp[-2].valString));
		free((yyvsp[-2].valString));
                (yyval.valString) = final;
        }
#line 3201 "scanner.tab.c"
    break;

  case 71: /* line_program: SCANF LPAREN precontentWrite RPAREN SEMICOLON  */
#line 1220 "scanner.y"
                                                       {
                char * final = malloc(strlen((yyvsp[-2].valString))*sizeof(char)+ sizeof("let mut input = String::new();\nio::stdin()\n.read_line(&mut input)\n.expect(\"Failed to read line\");"));
                memset(final, 0, sizeof(final));
                strcpy(final, "let mut input = String::new();\nio::stdin()\n.read_line(&mut input)\n.expect(\"Failed to read line\");");
                inputCount = inputCount + 1;
		free((yyvsp[-2].valString));
                (yyval.valString) = final;
        }
#line 3214 "scanner.tab.c"
    break;

  case 72: /* line_program: fun_cre  */
#line 1228 "scanner.y"
                 {
		(yyval.valString) = (yyvsp[0].valString);
	}
#line 3222 "scanner.tab.c"
    break;

  case 73: /* line_program: if_statement  */
#line 1231 "scanner.y"
                      {
		(yyval.valString) = (yyvsp[0].valString);
	}
#line 3230 "scanner.tab.c"
    break;

  case 74: /* line_program: FOR LPAREN type STRINGV EQ INTNUM SEMICOLON exp SEMICOLON STRINGV operand RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET  */
#line 1234 "scanner.y"
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
#line 3280 "scanner.tab.c"
    break;

  case 75: /* line_program: FOR LPAREN type STRINGV EQ INTNUM SEMICOLON exp SEMICOLON vardef RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET  */
#line 1279 "scanner.y"
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
#line 3314 "scanner.tab.c"
    break;

  case 76: /* line_program: DO OPENCURLYBRACKET lines_program CLOSECURLYBRACKET WHILE LPAREN exp RPAREN SEMICOLON  */
#line 1308 "scanner.y"
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
#line 3335 "scanner.tab.c"
    break;

  case 77: /* line_program: WHILE LPAREN exp RPAREN OPENCURLYBRACKET lines_program CLOSECURLYBRACKET  */
#line 1324 "scanner.y"
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
#line 3354 "scanner.tab.c"
    break;

  case 78: /* line_program: comment  */
#line 1339 "scanner.y"
                 {;}
#line 3360 "scanner.tab.c"
    break;

  case 79: /* line_program: STRINGV operand SEMICOLON  */
#line 1340 "scanner.y"
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
#line 3375 "scanner.tab.c"
    break;

  case 80: /* line_program: RETURN exp SEMICOLON  */
#line 1350 "scanner.y"
                               {
		char *final = malloc((strlen((yyvsp[-1].valString)) + 1) * sizeof(char)); // Reservar espacio suficiente incluyendo el terminador nulo
    		memset(final, 0, (strlen((yyvsp[-1].valString)) + 1) * sizeof(char)); // Inicializar toda la memoria a 0
    		strcat(final, (yyvsp[-1].valString)); // Concatenar $2 en `final`
    		(yyval.valString) = final; // Asignar el resultado a $$
                
        }
#line 3387 "scanner.tab.c"
    break;

  case 81: /* line_program: RETURN SEMICOLON  */
#line 1357 "scanner.y"
                           {
                char * final = malloc(sizeof("return;"));
                memset(final, 0 , sizeof(final));
                strcat(final, "return;");
                (yyval.valString) = final;
                
        }
#line 3399 "scanner.tab.c"
    break;

  case 82: /* line_program: vardef  */
#line 1364 "scanner.y"
                {
                char * final = malloc(strlen((yyvsp[0].valString))*sizeof(char)  + sizeof("\n"));
                memset(final,0,sizeof(final));
                strcat(final,(yyvsp[0].valString));
                strcat(final,"\n");

          	free((yyvsp[0].valString));      
                (yyval.valString) = final;
                
        }
#line 3414 "scanner.tab.c"
    break;

  case 83: /* line_program: STRUCT STRINGV OPENCURLYBRACKET lines_program CLOSECURLYBRACKET SEMICOLON  */
#line 1384 "scanner.y"
                                                                                  {
                char * final = malloc(strlen((yyvsp[-4].valString))*sizeof(char) + strlen((yyvsp[-2].valString))*sizeof(char) + strlen("struct { } \n\n"));
                memset(final, 0 , sizeof(final));
                strcat(final, "struct ");
                strcat(final, (yyvsp[-4].valString));
                strcat(final, " {\n");
                strcat(final, (yyvsp[-2].valString));
                strcat(final, "}\n");
                replaceSemicolon(final);
		free((yyvsp[-4].valString));
		free((yyvsp[-2].valString));
                (yyval.valString) = final; 
        }
#line 3432 "scanner.tab.c"
    break;

  case 84: /* array: exp COMMA array  */
#line 1403 "scanner.y"
                       {
                char * final = malloc(strlen((yyvsp[-2].valString))*sizeof(char) + strlen((yyvsp[0].valString))*sizeof(char)) ;
                memset(final,0,sizeof(final));

                strcat(final,(yyvsp[-2].valString));
                strcat(final,",");
                strcat(final,(yyvsp[0].valString));
		free((yyvsp[-2].valString));
		free((yyvsp[0].valString));
                (yyval.valString) = final;
        }
#line 3448 "scanner.tab.c"
    break;

  case 85: /* array: exp  */
#line 1414 "scanner.y"
            {
                (yyval.valString) = (yyvsp[0].valString);
        }
#line 3456 "scanner.tab.c"
    break;

  case 86: /* precontentWrite: contentWrite  */
#line 1420 "scanner.y"
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
#line 3527 "scanner.tab.c"
    break;

  case 87: /* contentWrite: contentWrite COMMA exp  */
#line 1568 "scanner.y"
                              {
                printf("aqui\n");
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
#line 3547 "scanner.tab.c"
    break;

  case 88: /* contentWrite: QUOTESTRING  */
#line 1584 "scanner.y"
                      {

                (yyval.valString) = (yyvsp[0].valString);}
#line 3555 "scanner.tab.c"
    break;

  case 89: /* contentWrite: STRINGV  */
#line 1587 "scanner.y"
                  {
                (yyval.valString) = (yyvsp[0].valString);
	}
#line 3563 "scanner.tab.c"
    break;

  case 90: /* exp: exp operand term  */
#line 1594 "scanner.y"
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
#line 3585 "scanner.tab.c"
    break;

  case 91: /* exp: term  */
#line 1611 "scanner.y"
              {
                                

        	(yyval.valString) = (yyvsp[0].valString);
	}
#line 3595 "scanner.tab.c"
    break;

  case 92: /* term: atom  */
#line 1620 "scanner.y"
             {

                (yyval.valString) = (yyvsp[0].valString);
	}
#line 3604 "scanner.tab.c"
    break;

  case 93: /* term: LPAREN exp RPAREN  */
#line 1625 "scanner.y"
                            {
                char * final = malloc(strlen((yyvsp[-1].valString)) * sizeof(char) + sizeof("()") + 1);
                memset(final, 0, sizeof(final));
                strcpy(final, "(");
                strcat(final, (yyvsp[-1].valString));
                strcat(final, ")");
                free((yyvsp[-1].valString));
                (yyval.valString) = final;
                }
#line 3618 "scanner.tab.c"
    break;

  case 94: /* term: EX exp  */
#line 1643 "scanner.y"
                 {
                char * final = malloc(strlen((yyvsp[0].valString)) * sizeof(char) + sizeof("!()") + 1);
                memset(final, 0, sizeof(final));
                strcpy(final, "!(");
                strcat(final, (yyvsp[0].valString));
                strcat(final, ")");
                free((yyvsp[0].valString));
                (yyval.valString) = final;
                }
#line 3632 "scanner.tab.c"
    break;

  case 95: /* operand: PLUS  */
#line 1663 "scanner.y"
             {
                (yyval.valString) = strdup(" + ");
        }
#line 3640 "scanner.tab.c"
    break;

  case 96: /* operand: PLUS EQ  */
#line 1666 "scanner.y"
                 {(yyval.valString) = strdup(" += ");}
#line 3646 "scanner.tab.c"
    break;

  case 97: /* operand: HYPHEN  */
#line 1667 "scanner.y"
                {(yyval.valString) = strdup(" - ");}
#line 3652 "scanner.tab.c"
    break;

  case 98: /* operand: HYPHEN EQ  */
#line 1668 "scanner.y"
                   {(yyval.valString) = strdup(" -= ");}
#line 3658 "scanner.tab.c"
    break;

  case 99: /* operand: HYPHEN HIGHER  */
#line 1669 "scanner.y"
                      {(yyval.valString) = strdup(".");}
#line 3664 "scanner.tab.c"
    break;

  case 100: /* operand: PROD  */
#line 1670 "scanner.y"
              {(yyval.valString) = strdup(" * ");}
#line 3670 "scanner.tab.c"
    break;

  case 101: /* operand: DIV  */
#line 1671 "scanner.y"
             {(yyval.valString) = strdup(" / ");}
#line 3676 "scanner.tab.c"
    break;

  case 102: /* operand: DIVINT  */
#line 1672 "scanner.y"
                {(yyval.valString) = strdup(" / ");}
#line 3682 "scanner.tab.c"
    break;

  case 103: /* operand: MOD  */
#line 1673 "scanner.y"
             {(yyval.valString) = strdup(" % ");}
#line 3688 "scanner.tab.c"
    break;

  case 104: /* operand: LOWER  */
#line 1674 "scanner.y"
               {(yyval.valString) = strdup(" < ");}
#line 3694 "scanner.tab.c"
    break;

  case 105: /* operand: HIGHER  */
#line 1675 "scanner.y"
                {(yyval.valString) = strdup(" > ");}
#line 3700 "scanner.tab.c"
    break;

  case 106: /* operand: LOWER EQ  */
#line 1676 "scanner.y"
                  {(yyval.valString) = strdup(" <= ");}
#line 3706 "scanner.tab.c"
    break;

  case 107: /* operand: HIGHER EQ  */
#line 1677 "scanner.y"
                   {(yyval.valString) = strdup(" >= ");}
#line 3712 "scanner.tab.c"
    break;

  case 108: /* operand: EQ EQ  */
#line 1678 "scanner.y"
               {(yyval.valString) = strdup(" == ");}
#line 3718 "scanner.tab.c"
    break;

  case 109: /* operand: AND  */
#line 1679 "scanner.y"
             {(yyval.valString) = strdup(" && ");}
#line 3724 "scanner.tab.c"
    break;

  case 110: /* operand: PLUS PLUS  */
#line 1680 "scanner.y"
                   {(yyval.valString) = strdup(" ++ ");}
#line 3730 "scanner.tab.c"
    break;

  case 111: /* operand: OR  */
#line 1681 "scanner.y"
           {(yyval.valString) = strdup(" || ");}
#line 3736 "scanner.tab.c"
    break;

  case 112: /* operand: DOT  */
#line 1682 "scanner.y"
             {(yyval.valString) = strdup(".");}
#line 3742 "scanner.tab.c"
    break;

  case 113: /* operand: PERCENT  */
#line 1683 "scanner.y"
                 {(yyval.valString) = strdup(" % ");}
#line 3748 "scanner.tab.c"
    break;

  case 114: /* operand: EX EQ  */
#line 1684 "scanner.y"
               {(yyval.valString) = strdup(" != ");}
#line 3754 "scanner.tab.c"
    break;

  case 115: /* atom: STRINGV  */
#line 1689 "scanner.y"
                {

            (yyval.valString) = (yyvsp[0].valString);
		}
#line 3763 "scanner.tab.c"
    break;

  case 116: /* atom: values  */
#line 1693 "scanner.y"
                 {

                        
			(yyval.valString) = (yyvsp[0].valString);
			
		}
#line 3774 "scanner.tab.c"
    break;

  case 117: /* atom: STRINGV LSQUAREPAREN atom RSQUAREPAREN  */
#line 1699 "scanner.y"
                                               {

                char * final = malloc(strlen((yyvsp[-3].valString))* sizeof(char) + strlen((yyvsp[-1].valString))*sizeof(char) + sizeof("[]"));
                memset(final, 0 , sizeof(final));
                strcat(final, (yyvsp[-3].valString));
                strcat(final, "[");
                strcat(final, (yyvsp[-1].valString));
                strcat(final, "]");
		free((yyvsp[-3].valString));
		free((yyvsp[-1].valString));
                (yyval.valString) = final;
        }
#line 3791 "scanner.tab.c"
    break;

  case 118: /* atom: fun_cre  */
#line 1711 "scanner.y"
                 {
		(yyval.valString) = (yyvsp[0].valString);
	}
#line 3799 "scanner.tab.c"
    break;


#line 3803 "scanner.tab.c"

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

#line 1717 "scanner.y"


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
