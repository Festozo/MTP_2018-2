/*P5.c*/
/*Vinicius Carvalho Festozo*/
/*11811EEL018*/



#include <stdio.h>
typedef
	unsigned long long int
Bytes8;

typedef
	struct LCG{ Bytes8 a, c, m, rand_max, atual; }
LCG;
void semente(LCG * r, Bytes8 seed) 
{
	r->a = 0x5DEECE66DULL;
	r->c = 11ULL;
	r->m = (1ULL << 48);
	r->rand_max = r->m - 1;
	r->atual = seed;
}

Bytes8 lcg_rand(LCG * r)
 {
		r->atual = (r->a * r->atual + r->c) % r->m;
		return r->atual;
 }
 
double lcg_rand_01(LCG * r)
 {
		return ((double) lcg_rand(r))/(r->rand_max);
}
 float soma(float *i_num, float *f_num)
 {
 	float j=0;
 	while(i_num<f_num)	{
 	return *f_num + soma(i_num,f_num-1);
	}
	if(i_num==f_num)
	{
		return *i_num;
	}
 }
 float produto(float *i_num, float *f_num){
	float X=1;
	float *memoria = i_num;
	while(memoria!=f_num)
		{
			X*=*memoria;
			memoria++;
		}
	return X;
}
 
void alea(float * vetor, int tam, float min, float max, LCG*r)
{
	int i;
	for(i=0; i<tam; i++)
	vetor[i] = (max-min)*lcg_rand_01(r) + min;
}
int main()
{
	LCG random;
	semente(&random,123456);
	float  num[51];
	int i;
	printf("\n**********************Numeros aleatorios*********************");
	alea(num, 50, 0.5, 1.5, &random);
	printf("\nDigite uma opcao para os numeros aleatorios gerados: \n1-Soma \n2-Produto\n");
	scanf("%i",&i);
	getchar();
	if(i==1)
	{
		printf("\nA soma dos numeros eh :%f ",soma(num,num+50));
	}
	if(i==2)
	{
		printf("\nO produto dos numeros eh :%f",produto(num,num+50));
	}
return 0;
}
