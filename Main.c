#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "header.h"

#define TRUE 1
#define FALSE 0
struct peca{
  char time;
  int Y;
  int X;
  struct peca *next;
};

struct jogadas{
  struct peca posicaoAnterior;
  struct peca posicaoNova;
  struct peca pecaComida;
  struct jogadas *next;
};

struct partida{
  char jogadorPecasPretas[50];
  char jogadorPecasBrancas[50];
  int fimDeJogo;
  char vencedor;
  struct jogadas *historicoJogadas;
  struct partida *next;
};


int Menu();
void iniciarpecas(struct peca **headbranco, struct peca **headpreto);
void CriarPartida(struct partida **headPartidas,struct partida *novaPartida,struct jogadas *historico);
struct partida *CarregarPartidas();
void MostrarTabuleiroCompleto(struct peca **headPreta,struct peca **headBranca);
struct partida VerificadorDeFimDePartida(struct peca *preto, struct peca *branco,struct jogadas *historico);
int user_jogada(struct peca **headjogada, struct peca **headcontra,int jogada);

/*jogada do branco: jogada=TRUE
jogada do preto: jogada=FALSE*/

int main(void){
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
      struct partida partidaAtual;
      struct jogadas *historicoJogadas = NULL;
      CriarPartida(&headPartidas,&partidaAtual,historicoJogadas);
      do{
        MostrarTabuleiroCompleto(&headbranco,&headpreto);
        if(jogada)
        {
          //jogada do branco
          jogada = user_jogada(&headbranco,&headpreto,jogada);
        }
        else
        {
          //jogada do preto
          jogada = user_jogada(&headpreto,&headbranco,jogada);
        }
        partidaAtual = VerificadorDeFimDePartida(headbranco, headpreto,historicoJogadas);
      }
      while(partidaAtual.fimDeJogo);
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

