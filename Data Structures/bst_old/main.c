#include <stdio.h>
#include "btree.h"
#include "item.h"

int main(){
	BTree h,a,c,d,l,p,s,o,q;
	d=buildTree(NULL,NULL,"d");
	o=buildTree(NULL,NULL,"o");
	q=buildTree(NULL,NULL,"q");
	p=buildTree(NULL,NULL,"p");
	s=buildTree(NULL,NULL,"s");
	l=buildTree(o,q,"l");
	c=buildTree(p,s,"c");
	a=buildTree(d,l,"a");
	h=buildTree(a,c,"h");

	printf("Visita in pre ordine: " );
	preOrder(h);
	printf("\nVisita in post ordine: " );
	postOrder(h);
	printf("\nVisita simmetrica: " );
	inOrder(h);

	return 0;
}
