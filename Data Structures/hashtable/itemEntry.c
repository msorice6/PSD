#include "entry.h"
#include "key.h"


int cmpItem(Item it1,Item it2){
  Entry e1=it1,e2=it2;
  if(equals(getKey(e1),getKey(e2)))
    return 0;
  else
    return -1;
}
