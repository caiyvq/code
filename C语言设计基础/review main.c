#include<stdio.h>
#include<stdlib.h>
#include "review.h"

int main()
{
	node h1=cre_posi();
	ptr(h1);
	
//	appand(h1,1);
//	appand(h1,2);
//	ptr(h1);
//	
//	insert(&h1,3);
//	ptr(h1);

	h1=reverse(h1);
	ptr(h1);
}