#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "key.h"
#include "item.h"

#define A 128
#define NUMCHAR 20


int equals(Key key1, Key key2){
  char *k1=key1,*k2=key2;
  if(strcmp(k1,k2)==0)
    return 1;
  else
    return 0;
}

int hashValue(Key k, int m){
  int h=0;
  char*key=k;
  for(;*key!='\0';key++)
    h=(h*A+*key)%m;
  return h;
}

Key inputKey(){
  Key k=malloc(sizeof(char)*NUMCHAR);
  scanf("%s",k);
  return k;
}

void outputKey(Key key){
  char*k=key;
  printf("%s\n",k);
}
