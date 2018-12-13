/*P3.c*/
/*Vinicius Carvalho Festozo*/
/*11811EEL018*/


#include <stdio.h>


int main()
{
    char s1[256], s2[256];
    int i, k=0, cum=0;
    printf("Coloque sua sequencia de caracteres: ");
    scanf("%s",s1);
    for(i=0;s1[i]!='\0';i++)
    {
        if(s1[i]>='0' && s1[i]<='9')
        {
            s2[k]=s1[i];
            k++;}
    }
    s2[k]='\0';
    for(i=0;s2[i]!='\0';i++)
    {
			cum = cum*10 + s2[i] - '0';
    }
    printf("\n\n%d",cum);
    return 0;
}
