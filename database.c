#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void InputsJogadores(struct partida *NovaPartida);

void SalvarPartida(struct partida *partidaAtual){
    FILE *partidas = fopen("HistoricoPartidas.dat","ab+");
    fwrite(partidaAtual,sizeof(struct partida),1,partidas);
    fclose(partidas);
}

void CriarPartida(struct partida **headPartidas,struct partida *novaPartida,struct jogadas *historico){
    struct partida *n = *headPartidas;
    novaPartida = (struct partida *)malloc(sizeof(struct partida));
    InputsJogadores(novaPartida);
    novaPartida->historicoJogadas =(struct jogadas *)malloc(sizeof(struct jogadas));
    novaPartida->fimDeJogo = FALSE;
    novaPartida->next = NULL; 
    if(headPartidas == NULL)
    {
        headPartidas = &novaPartida;
    }
    else
    {
        while(n != NULL)
        {
           n = n->next;
        }
        n->next = novaPartida;
        historico = novaPartida->historicoJogadas;
    }
    SalvarPartida(novaPartida);
}


struct partida *CarregarPartidas(){
    FILE *arquivo = fopen("HistoricoPartidas.dat","rb");
    struct partida *headPartidas = NULL;
    struct partida partidaAtual;
    size_t bytesLidos;
    if (arquivo == NULL)
    {
        FILE *partidas = fopen("HistoricoPartidas.dat","wb+");
    }
    else
    {
        while ((bytesLidos = fread(&partidaAtual, sizeof(struct partida), 1, arquivo)) > 0)
        {
            struct partida *novaPartida = (struct partida *)malloc(sizeof(struct partida));

            memcpy(novaPartida, &partidaAtual, sizeof(struct partida));
            
            novaPartida->next = headPartidas;
            headPartidas = novaPartida;
        }
    }

    fclose(arquivo);

    return headPartidas;
}