#include "list.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>

void InitializeListT (TypeList * array){
  (*array).end = 0;
}

void InsertElementT (TypeList * array, Node * object){
  if ((*array).end==LISTSIZE) {}
  else {
    (*array).list[(*array).end] = (*object);
    (*array).end+=1;
  }
}

Node * getElementT (TypeList * array){
  int end = ((*array).end) -1;
  Node * node = malloc(sizeof((*array).list[end]));
  strcpy((*node).name, (*array).list[end].name);
  (*node).type = (*array).list[end].type;
  (*node).isValue = (*array).list[end].isValue;
  strcpy((*node).value, (*array).list[end].value);
  (*node).isConstant = (*array).list[end].isConstant;

  return node;
  }

void DeleteElementT (TypeList * array) {
  (*array).end-=1;
}

int isEmptyListT (TypeList * array) {
  return ((*array).end == 0);
}

void DeleteListT (TypeList * array){
  (*array).end = 0;
}

void DeleteElementAt(TypeList * array, int pos){
  int i;
  for(i=pos; i<=((*array).end);i++)
    (*array).list[i]=(*array).list[i+1];
  (*array).end-=1;
}

int checkName(TypeList *array, char *name){
  int i, found;
  i=0;found=0;
  while ((i<(*array).end) && (found==0)){
    if (0==strcmp(name, (*array).list[i].name)){
      found=1;
    }
    i++;
  }
  return found;
}

int checkConstant(TypeList *array, char *name){
  int i, found;
  i=0;found=0;
  while ((i<(*array).end) && (found==0)){
    if (0==strcmp(name, (*array).list[i].name)){
      if((*array).list[i].isConstant == 1) {found=1;}
    }
    i++;
  }
  return found;
}

int SearchType(TypeList * array, char * name){
  int i, found;
  int type;
  i=0;found=0;
  while ((i<(*array).end) && (found==0)){
    if (0==strcmp(name, (*array).list[i].name)){
      found=1;
      type = (*array).list[i].type;
    }
    i++;
  }
  return type;
}

void ShowListT(TypeList * array) {
  int i;
  for (i=0; i<((*array).end);i++){
    if ((*array).list[i].isValue) {
      printf("%s : %d = %s\n", (*array).list[i].name,(*array).list[i].type, (*array).list[i].value); 
    }
    else {
      printf("%s : %d\n", (*array).list[i].name,(*array).list[i].type); 
    }
  }
}


void InitializeListN (NodeList * array){
  (*array).end = 0;
}

void InsertElementN (NodeList * array, NameNode * object){
  if ((*array).end==LISTSIZE) {}
  else {
    (*array).list[(*array).end] = (*object);
    (*array).end+=1;
  }
}

char * getElementN (NodeList * array){
  char * name = malloc (sizeof((*array).list[0].name));
  strcpy (name, (*array).list[0].name);

  return name;
}

void DeleteListN (NodeList * array){
  (*array).end = 0;
}

void DeleteElementN (NodeList * array) {
  int i;
  for(i=0; i<=((*array).end);i++)
    (*array).list[i]=(*array).list[i+1];
  (*array).end-=1;
}

int isEmptyListN(NodeList * array) {
  return ((*array).end == 0);
}