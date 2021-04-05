/*
	- udajova struktura na reprezentaciu mnozin
	- konecne mnoziny malych prirodzenych cisel
	- algoritmus (funkcia)
		- konstrukcia zjednotenia mnozin
		- konstrukcia prieniku mnozin
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
	int an, bn;
	int	*a;
	int *b;

}TWOSETS; 

TWOSETS *intersection(TWOSETS *m){
	
	TWOSETS *mI = malloc(sizeof(TWOSETS));
	mI->an = 0;
	int i,j;
	
	for(i = 0; i < m->an; i++)
	{
		for(j = 0; j < m->bn; j++)
		{
			if(m->a[i] == m->b[j])
			{
				mI->a[mI->an] = m->a[i];
				mI->an++;
				break;
			}									
		}
	}
	
	return mI;
}

TWOSETS *union_sets(TWOSETS *m){
	
	TWOSETS *mU = malloc(sizeof(TWOSETS));
    int i, j;
    int k,tmp;
	mU->an = m->an;
	
    for(k = 0; k < mU->an; k++){
    	mU->a[k] = m->a[k];
	}
	
	for(i = 0; i < mU->bn; i++)
	{
		tmp = 0;
		for(j = 0; j < mU->an; j++)
		{
			if(m->b[i] == m->a[j])
				tmp = 1;
		}
		if(tmp == 0)
		{
			k++;
			mU->a[k] = m->b[i];
		}
	}
	
	return mU;
}

main(){
	TWOSETS *x = malloc(sizeof(TWOSETS));
	TWOSETS *y = malloc(sizeof(TWOSETS));
	
	x->an = 4;
	x->bn = 3;

	
	int i;
	srand(time(0));
	for(i = 0; i < x->an; i++){
		x->a[i] = rand()%9+1;
	}
	for(i = 0; i < x->bn; i++){
		x->b[i] = rand()%9+1;
	}

	printf("Intersection: ");
	y = intersection(x);
	
	for(i = 0; i < y->an; i++){
		printf("%d ",y->a[i]);
	}
	
	printf("Union: ");
	y = union_sets(x);
	
	for(i = 0; i < y->an; i++){
		printf("%d ",y->a[i]);
	}
	
	free(x);
	free(y);
	
}

