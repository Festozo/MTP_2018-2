/*P4.c*/
/*Vinicius Carvalho Festozo*/
/*11811EEL018*/



#include <stdio.h>

int  func(int m, int n)
{
	if(m ==0)
	{
	return n+1;
	}             
	else if(m>0&&n==0)
	{
	func(m-1, 1);
	}
	else if(m>0&&n>0)
	{
	func(m-1,func(m,n-1));
	}
}
int main ()
{
	int m,n;
	printf("Coloque os valores para m e n nesta ordem.\n: ");
	scanf("%i %i", &m, &n);
	printf("O resultado final obtido eh : %i" ,func(m, n));
	
	return 0;
}
