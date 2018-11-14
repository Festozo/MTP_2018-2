#include<math.h>
#include<stdlib.h>
#include<stdio.h>
typedef struct 
{
	float x , y ;	
}ponto;

void aparece_p (ponto *p_inicial, ponto *p_final)
{
	if(p_final > p_inicial)
	{
		printf("\n\n");
		printf("(%.2f , %.2f)", p_inicial->x , p_inicial->y);
		aparece_p(p_inicial+1, p_final);
	}
}


ponto*make_p(int  k)
{
	int j=0 ;
	ponto *p = (ponto*)calloc(k,sizeof(ponto));
	int i;
	for(i=0; i<k; i++)
	{
		p[i].x = cos(i*2.0*M_PI/(k-1));
		p[i].y = sin(i*2.0*M_PI/(k-1));
	}
	return p;
}
int main()
{
	int k;
	ponto*p;
	printf("Digite a quantidade desejada de pontos: ");
	scanf("%d",&k); 
	getchar();
	p=make_p(k);
	printf("\n\n");
	aparece_p(p, p+k);
	free(p);
	return 0;
}
