/*P1.c*/
*/Vinicius Carvalho Festozo*/
*/11811EEL018*/




#include <stdio.h>
int main()
{
	int estado=0, i;
	char bits[256];
	printf("\nDigite o numero binario desejado : ");
	scanf("%s", bits);

for(i=0; bits[i]!= '\0'; i++){
	if(estado==0 && bits[i]== '0')
	{
		estado=0;
	}
	else if(estado==0 && bits[i]=='1')
	{
		estado=1;
	}
	else if(estado==1 && bits[i]=='0')
	{
		estado=2;
	}
	else if(estado==1 && bits[i]=='1')
	{
		estado=0;
	}
	else if(estado==2 && bits[i]=='0')
	{
		estado=1;
	}
	else if(estado==2 && bits[i]=='1')
	{
		estado=2;
	}
}
printf("\n A sequencia digitada foi: %s ",bits);
printf("\n O estado final eh: %i",estado);
if(estado==0)
{
printf("\n O seu numero eh multiplo de 3 ! ");
}
else
{
printf("\n O seu numero nao eh multiplo de 3");
}
return 0;
}
