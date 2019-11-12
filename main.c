#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "forca.h"
//Nome:Gulherme de Souza Seyfart RA: 18130

void copyright(){
    CLEAR_SCREEN;
    printf("=============================================================\n\n");
    printf("JOGO DA FORCA\n");
    printf("Desenvolvido por: \n\t Guilherme de Souza Seyfart \n\n\t");
    printf("\tXXXXX - NNNNNNNNNNNNNNNNNNN\n");
    printf("=============================================================\n\n");
}

int main()
{
    setbuf(stdout, 0);
    char nome[34] = "", aux, letra, letraM;
    int n, cont, h, i, resp;
    int a = 0, b = 0;
do{
     CLEAR_SCREEN;
     printf("Voce entrou no jogo da forca %s\n",nome);
     printf("Sair(0)\n");
     printf("Jogar(1)\n");
     printf("Configuracoes(2)\n");
     scanf("%d",&a);
    fflush(stdin);
      if(a == 1)
      {
        b = 0;
        copyright();
        int x;
        NoSecreto * lstSecreta = inicializaListaSecreta();
        NoSecreto * sorteada;
        char  aux1[31];
        NoSecreto * usadas = inicializaListaSecreta();
        lstSecreta = carregaListaArquivo(lstSecreta,"palavras.dat");
        imprimeListaSecreta(lstSecreta);

      do{
        cont = 0;
        CLEAR_SCREEN;
        sorteada= sorteiaPalavra(lstSecreta);
        if(sorteada!=NULL)
            {
                strcpy(aux1,sorteada->palavra);
            n = conta(sorteada->palavra);
            i = n*3;
            for(int i = 0; i<n; i++)
            {
                    sorteada->palavra[i] = '*';
            }
            for(int x = 0; x<n*3; x++)
            {
                h = 0;
                if(strcmp(aux1,sorteada->palavra) == 0)
                {
                    printf("\nAcertou!!!\n");
                    h = 1;
                    break;
                }
                else
                {
                cont++;
                }
            copyright();
            printf("Numero de Tentativas: %d\n", i);
            printf("%s ", sorteada->palavra);
            printf("%s\n", sorteada->assunto);
            printf("Faca sua tentativa: ");
            scanf("%c",&letraM);
            i--;
            letra = tolower(letraM);
            CLEAR_SCREEN;
            fflush(stdin);
            for(int i = 0; i<n; i++)
                {
                if(aux1[i] == letra)
                {
                    sorteada->palavra[i] = aux1[i];
                }
            }
            }
            if(h == 1)
            {
            CLEAR_SCREEN;
            printf("\nParabens! Voce ganhou em %d tentaivas\n",cont);
            printf("Deseja jogar novamente?\nSim(1)\nNao(2)\nresposta: ");
                scanf("%d",&resp);
                if(resp == 2)
                {
                    exit(0);
                }
                else if(resp == 1)
                {
                    a = 1;
                }
                else
                {
                    printf("Não reconhecido, fechando programa");
                    exit(0);
                }
            }
            else
            {
                CLEAR_SCREEN;
                printf("\nSuas tentativas acabaram\n");
                printf("Numero de tentativas: %d\n",cont);
                printf("jogar novamente?\nSim(1)\nNao(2)\nResposta: ");
                scanf("%d",&resp);
                if(resp == 2)
                {
                    exit(0);
                }
                else if(resp == 1)
                {
                    a = 1;
                }
                else
                {
                    printf("Não reconhecido, fechando programa");
                    exit(0);
                }
            }
            lstSecreta = retiraUmElemento(lstSecreta,sorteada->palavra);
            aux = lstSecreta;
      }
            else
            {
                printf("As palavras acabaram.\n\n");
                b = 1;
                printf("Deseja jogar novamente?\nSim(1)\nNao(2)\nResposta: ");
                scanf("%d",&resp);
                if(resp == 2)
                {
                    exit(0);
                }
                else if(resp == 1)
                {
                    a = 1;
                }
                else
                {
                    printf("Não reconhecido, fechando programa");
                    exit(0);
                }
            }
      }
        while(getchar()!='f' && b == 0);
      }

    else if(a == 0)
    {
        return (0);
    }

    else if(a == 2)
    {
         CLEAR_SCREEN;
         printf("Digite seu nome: ");
         gets(nome);
    }
}while(a != 0);
    return 0;
}
