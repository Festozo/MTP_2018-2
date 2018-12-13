/* P7.c */
/* Vinicius Carvalho Festozo */
/* 11811EEL018 */

#include <math.h>
#include <stdlib.h>
#include <stdio.h>


typedef
    struct   ponto{double x,y;}
ponto;

ponto * make_p(int k) {
    ponto * p = (ponto *) calloc(k,sizeof(ponto));
    int i;
    for(i = 0; i < k; i++){
        p[i].x = cos(i*2.0*M_PI/(k-1));
        p[i].y = sin(i*2.0*M_PI/(k-1));
    }
	return p;
}

void aparece_p(ponto * p_inicial, ponto * p_final) {
    if(p_inicial < p_final) {
        printf("(%.3lf, %.3lf) ", p_inicial->x, p_inicial->y);
        aparece_p(p_inicial+1, p_final);
    }
}

void gravar_pontos(ponto * pini, int N) {
    FILE * arquivo;
    arquivo = fopen("pontos.dat", "wb");
    fwrite(pini, N, sizeof(ponto), arquivo);
    fclose(arquivo);
}


ponto * ler_pontos(char * nome_arquivo, unsigned int * pk) {
    ponto * p = (ponto *) malloc(sizeof(ponto));
    unsigned int k = 0;
    FILE * arquivo;
    arquivo = fopen(nome_arquivo, "rb");
    while(1) {
        fread(p, 1, sizeof(ponto), arquivo);
        if(feof(arquivo)) break;
        k++;
    }
    rewind(arquivo);
    p = (ponto *) realloc(p, k*sizeof(ponto));
    fread(p, k, sizeof(ponto), arquivo);
    fclose(arquivo);
    *pk = k;
    return p;
}


int main(){
    
       unsigned int k, opc;
    ponto *p;
	printf("1-Salvar arquivo; 2 - Vizualizar o aquivo salvo: ");
    scanf("%u",&opc); 
	getchar();
    if(opc == 2) {
        p = ler_pontos("pontos.dat", &k);
        aparece_p(p, p + k);
    } else {
        printf("Digite a quantidade desejada de pontos: ");
	scanf("%u", &k); 
	getchar();
        p=make_p(k);
        gravar_pontos(p,k);
        printf("\n\nArquivo gravado !!");
    }
    free(p);
    return 0;
}
