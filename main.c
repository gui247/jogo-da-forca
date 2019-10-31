#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "funcoes.h"
#include <string.h>

void copyright(){
    system("clear");
    printf("=============================================================\n\n");
    printf("JOGO DA FORCA\n");
    printf("Desenvolvido por: \n\tAntonio Orlandini 18122\n\t");
    printf("\tXXXXX - NNNNNNNNNNNNNNNNNNN\n");
    printf("=============================================================\n\n");
}

int limpaTela()
{
puts("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
return 0;
}

int main(int argc, char *argv[])
{

    NoSecreto * lsSecreta = inicializaListaSecreta();
    NoSecreto * lsUsada = inicializaListaSecreta();
    char fNameArq[255];
    NoSecreto * sorteada;
    int posSorteada=0;
    int tamanhoLista=0;
    imprimeListaSecreta(lsSecreta);
    imprimeListaSecreta(lsUsada);

    strcpy(fNameArq,"palavras.dat");

    if(argc>1){
      strcpy(fNameArq,argv[1]);
    }

    printf("Arquivo de dados: %s\n\n",fNameArq);

    copyright();

    lsSecreta = carregaListaArquivo(lsSecreta,fNameArq);
    imprimeListaSecreta(lsSecreta);
    tamanhoLista = tamanhoListaSecreta(lsSecreta);

    do{
        CLEAR_SCREEN;
        imprimeListaSecreta(lsSecreta);
        imprimeListaSecreta(lsUsada);
        sorteada= sorteiaPalavra(lsSecreta);
        if(sorteada!=NULL){
            printf("%s", sorteada->palavra);
            inserePalavraUsada(lsSecreta, lsUsada);
            lsSecreta = retira(lsSecreta, 1);
        }else{
            printf("Nao tem palavra disponivel!\n\n");
        }
    }while(getchar()!='f');
    return 0;
}
