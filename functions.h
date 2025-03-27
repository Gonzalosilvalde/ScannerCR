
#ifndef FUNCTIONS_H
#define FUNCTIONS_H



char * insertTabsBetweenBraces(char *);
char * getType(int);
void replaceSemicolon(char *);
void deleteQuotes (char *);
char * replace(const char *, const char *, const char *);
char * getEndNumber(char *);
int searchString(char **, char *, int);
char * getStringFromExp(char *);
void ifCreation(char *, char *, char *);
void funCreation(char *, char *, char *);
void typeSwitch(char *, int type);
void concatenateArray(char *, char *[], int n);
char * transformDollarVarsInsideParentheses(const char *str);
char * transformVariadic(const char * str);
char * wrapInParentheses(const char *str);
void toLowercase(char* str);
char * transformStringOutput(const char *input);
char * transformStringInput(const char *input);

#endif
