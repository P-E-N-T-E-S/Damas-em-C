#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "header.h"

#define TRUE 1
#define FALSE 0

struct peca;
struct jogadas;
struct partida;


/*jogada do branco: jogada=TRUE
jogada do preto: jogada=FALSE*/

int main(void)
{
  int opcao, jogada = TRUE;
  struct peca *headpreto = (struct peca*)malloc(sizeof(struct peca));
  struct peca *headbranco = (struct peca*)malloc(sizeof(struct peca));
  struct partida *headPartidas = CarregarPartidas();

  while(1)
  {
    opcao = Menu();
    switch (opcao)
    {
    case 1:
      iniciarpecas(&headbranco,&headpreto);
      struct partida *partidaAtual = NULL;
      struct jogadas *historicoJogadas = NULL;
      CriarPartida(&headPartidas,partidaAtual,historicoJogadas);
      do{
        MostrarTabuleiroCompleto(&headbranco,&headpreto);
        if(jogada)
        {
          //jogada do branco
          jogada = userjogada(headbranco,headpreto,jogada);
        }
        else
        {
          //jogada do preto
          jogada = userjogada(headpreto,headbranco,jogada);
        }
        *partidaAtual = VerificadorDeFimDePartida(&headbranco, &headpreto,historicoJogadas);
      }
      while(partidaAtual->fimDeJogo);
    break;
    
    case 2:
      //regras
    break;
    
    case 3:
      //vizualizar histórico
    break;
    case 4:
      exit(1);
    break;
    default:
      break;
    }
    
    return 1;
  
  }

} 
