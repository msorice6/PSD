#include <stdlib.h>
#include "entry.h"
#include "key.h"
#include "item.h"

struct entry{
  Key key;
  Item value;
};

Entry newEntry(Key key, Item item){
  Entry e=malloc(sizeof(struct entry));
  e->key=key;
  e->value=item;
  return e;
}

Key getKey(Entry e){
  if(e==NULL)
    return NULL;
  return e->key;
}

Item getValue(Entry e){
  if(e==NULL)
    return NULL;
  return e->value;
}
