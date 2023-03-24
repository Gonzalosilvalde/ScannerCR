#define LISTSIZE 4096

#define MAXLENGTH 100

#include <time.h>


typedef struct NODO {
  char name[MAXLENGTH];
  int type;
  int isValue;
  char value[MAXLENGTH];
  int isConstant;
} Node;

typedef struct LISTATIPOS{
  int end;
  Node list[LISTSIZE];
} TypeList;

typedef struct NODON {
  char  name[MAXLENGTH];
} NameNode;

typedef struct LISTANODOS {
  int end;
  NameNode list [LISTSIZE];
} NodeList;


void InitializeListT (TypeList *);

void InsertElementT (TypeList *, Node *);

void DeleteListT (TypeList *);

Node * getElementT (TypeList *);

void DeleteElementT (TypeList * );

int isEmptyListT(TypeList *);

int checkName(TypeList *, char *);

int checkConstant(TypeList *, char *);

int SearchType(TypeList * , char *);

void ShowListT(TypeList *);

void InitializeListN (NodeList *);

void InsertElementN (NodeList *, NameNode *);

char * getElementN (NodeList *);

void DeleteElementN (NodeList *);

void DeleteListN(NodeList *);

int isEmptyListN(NodeList *);
