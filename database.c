#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header.h"

#define TRUE 1
#define FALSE 0


void CriarPartida(struct partida **headPartidas,struct partida *novaPartida,struct jogadas *historico)
{
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


void SalvarPartida(struct partida *partidaAtual)
{
    FILE *partidas = fopen("HistoricoPartidas.dat","ab+");
    fwrite(partidaAtual,sizeof(struct partida),1,partidas);
}


struct partida *CarregarPartidas()
{
    FILE *partidas = fopen("HistoricoPartidas.dat","rb");
    if (partidas == NULL)
    {
        FILE *partidas = fopen("HistoricoPartidas.dat","wb+");
    }
    
    struct partida *headPartidas = NULL;
    struct partida partidaAtual;
    size_t bytesLidos;
    
    while ((bytesLidos = fread(&partidaAtual, sizeof(struct partida), 1, partidas)) > 0)
    {
        struct partida *novaPartida = (struct partida *)malloc(sizeof(struct partida));

        memcpy(novaPartida, &partidaAtual, sizeof(struct partida));
        
        novaPartida->next = partidas;
        partidas = novaPartida;
    }

    fclose(partidas);

    return partidas;
}