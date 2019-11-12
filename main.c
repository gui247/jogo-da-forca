#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "forca.h"

void copyright(){
    system("clear");
    printf("=============================================================\n\n");
    printf("JOGO DA FORCA\n");
    printf("Desenvolvido por: Guilherme de Souza Seyfart RA: 18130\n");
    printf("=============================================================\n\n");
}

int limpaTela()
{
puts("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
return 0;
}

int main(int argc, char *argv[])
{
    NoSecreto * lstSecreta = inicializaListaSecreta();
    NoSecreto * lstUsadas = inicializaListaSecreta();
    char fNameArq[255];
    NoSecreto * sorteada;
    int posSorteada=0;
    int tamanhoLista=0;

    strcpy(fNameArq,"palavras.dat");

    if(argc>1){
      strcpy(fNameArq,argv[1]);
    }

    printf("Arquivo de dados: %s\n\n",fNameArq);


    lstSecreta = carregaListaArquivo(lstSecreta,fNameArq);
    imprimeListaSecreta(lstSecreta);
    tamanhoLista = tamanhoListaSecreta(lstSecreta);

    do{
        CLEAR_SCREEN;
        copyright();
        imprimeListaSecreta(lstSecreta);
        sorteada= sorteiaPalavra(lstSecreta);
        lstUsadas = insere(lstUsadas, sorteada->palavra);
        if(sorteada!=NULL){
            printf("%s\n", sorteada->palavra);
            lstSecreta = retira(lstSecreta, sorteada->palavra);
        }else{
            printf("nao tem nenhuma palavra disponivel\n\n");
        }

    }while(getchar()!='f');


    return 0;
}

