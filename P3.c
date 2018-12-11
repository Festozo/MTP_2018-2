/* P3.c */
/*Vinícius Carvalho Festozo/*
/*11811EEL018/*



#include <stdio.h>

int main ()
{

	char seq[256];
	int num[256], x = 0,j,i;
	printf("\nDigite uma sequencia desejada : ");
	scanf("%s", seq);	
	for(i = 0; seq[i] != '\0'; i++) 
		if(seq[i] >= 48 && seq[i] <= 57) 
		{	
			num[x] = seq[i] - 48; 
			x++;	
		}
	
	for(j = 0; j < x; j++) 
	printf("%d", num[j]); 
	return 0;
}
