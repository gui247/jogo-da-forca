#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include<time.h>
#include "funcoes.h"

int main(void)
{
    system("cls");
    printf("Jogo da forca\n");
    printf("Criador: Guilherme de Souza Seyfart\n\n");



  NoSecreto * lsSecreta = inicializaListaSecreta();
  lsSecreta = carregaListaArquivo(lsSecreta, "D:\\pen drive\\2019\\2º Semestre\\ED\\Jogo da forca\\palavras.dat");
  imprimeListaSecreta(lsSecreta);


  return 0;
}
