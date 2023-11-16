#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "damas.h"

#define TRUE 1
#define FALSE 0


/*jogada do branco: jogada=TRUE
jogada do preto: jogada=FALSE*/

int main(void){
  int opcao, jogada = TRUE;
  struct node *headpreto = (struct node *)malloc(sizeof(struct node));
  struct node *headbranco = (struct node *)malloc(sizeof(struct node));
  FILE *fptr;

  
  fptr = fopen("jogos.dat", "wb+");

  opcao = menu()

  switch (opcao)
  {
  case 1:
    inciarpecas()
    do{
      tabuleiro()
      if(jogada){
        //jogada do branco
        userjogada()
      }else{
        //jogada do preto
        userjogada()
      }
      jogo = vitoria(&headbranco, &headpreto)
    }while(jogo.jogo)
  break;
  
  default:
    break;
  }
  
  return 1;
}





