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


struct peca *InputEscolhaJogada();
struct peca *InputEscolhaNovaPosJogada();
int existePecaDoJogadorAli(struct peca **headjogada, int X, int Y, struct peca *escolhaDaPeca);
void addPeca(struct peca **head, int Y, int X, char time);


//validar se existe uma peca daquele jogador naquela posição que ele deseja mover a peca
int existePecaDoJogadorAli(struct peca **headjogada, int X, int Y, struct peca *escolhaDaPeca){
    struct peca *n = *headjogada;
    while(n != NULL)
    {
        if(n->X == X && n->Y == Y) 
        {
            escolhaDaPeca = n;
            return(TRUE);
        }
        n = n->next;
    }
    return(FALSE);
}

//validar se ele não está movendo para uma peça ja existente dele
int validacaopecajogo(struct peca **head, int X, int Y){
    struct peca *n = *head;
    while(n != NULL && (n->X != X || n->Y != Y))
    {
        n = n->next;
    }
    if(n->X == X && n->Y == Y)
    {
        return(FALSE);
    }
    else
    {
        return(TRUE);
    }
}


//valida se não está tentando mover uma peca para muito longe
int validacaopecalonge(int X, int Y, int Xdest, int Ydest){
    if((Xdest == X-1 && Xdest == X+1) && (Ydest == Y+1 && Ydest == Y-1))
    {
        return(TRUE);
    }
    else
    {
        return(FALSE);
    }
}


//valida se não está tentando mover uma peca para fora do tabuleiro
int validacaopecaoor(int X, int Y){
    if(X > 8 && X < 0)
    {
        return FALSE;
    }
    else if(Y > 8 && Y < 0)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

//deleta a peca do adversário que foi comida
int comerpeca(struct peca **head, int X, int Y){
    struct peca *n = *head;
    struct peca *temp;
    
    while(n->next->next != NULL && (n->next->X == X && n->next->Y == Y))
    {
        n = n->next;
    }
    if(n->next->next == NULL)
    {
        return FALSE;
    }
    else
    {
        temp = n->next;
        n->next = n->next->next;
        free(temp);
        return TRUE;
    }
}



//valida se ele não está tentando comer uma peca
int validacaopecacontra(struct peca **headcontra, int X, int Y){ 
    
    struct peca *n = *headcontra;
    while(n != NULL && (n->X != X || n->Y != Y))
    {
        n = n->next;
    }
    if(n->X == X && n->Y == Y)
    {
        return(FALSE);
    }
    else
    {
        return(TRUE);
    }
}




int user_jogada(struct peca **headjogada, struct peca **headcontra,int jogada){
    int val1, val2, val3, val4,val5, comeuPeca;
    struct peca *escolhaDaPeca,*tentativaDeJogada;
    char resposta;
    while(1)
    {
        escolhaDaPeca = InputEscolhaJogada();
        val1 = existePecaDoJogadorAli(headjogada,escolhaDaPeca->X,escolhaDaPeca->Y,escolhaDaPeca);
        if(!val1)
        {
            puts("*Você não tem peças nessa posição, por favor digite outra*");
            break;
        }
        else
        {
            tentativaDeJogada = InputEscolhaNovaPosJogada();
            val2 = validacaopecajogo(headjogada, tentativaDeJogada->X,tentativaDeJogada->Y);
            val3 = validacaopecalonge(escolhaDaPeca->X,escolhaDaPeca->Y,tentativaDeJogada->X,tentativaDeJogada->Y);
            val4 = validacaopecaoor(tentativaDeJogada->X,tentativaDeJogada->Y);
            val5 = validacaopecacontra(headcontra,tentativaDeJogada->X,tentativaDeJogada->Y);
            if(!val2 || !val3 || !val4)
            {
                puts("*jogada inválida*");
                break;
            }
            else if(val5)
            {
                printf("voce deseja comer a peça na posição X=%d, Y=%d\nY ou N: ", tentativaDeJogada->X,tentativaDeJogada->Y);
                scanf("%c", &resposta);
                while ((getchar()) != '\n');
                if(resposta == 'Y'|| resposta == 'y')
                {
                    comeuPeca = comerpeca(headcontra, tentativaDeJogada->X,tentativaDeJogada->Y);
                    if(tentativaDeJogada->X == escolhaDaPeca->X-1)
                    {
                        tentativaDeJogada->Y = tentativaDeJogada->Y+1;
                        tentativaDeJogada->X = tentativaDeJogada->X-1;
                    }
                    else if(tentativaDeJogada->X == escolhaDaPeca->X+1)
                    {
                        tentativaDeJogada->Y = tentativaDeJogada->Y+1;
                        tentativaDeJogada->X = tentativaDeJogada->X+1;                  
                    }
                    break;
                }
                else
                {
                    break;
                }
            }
        }
    }
    escolhaDaPeca->X = tentativaDeJogada->X;
    escolhaDaPeca->Y = tentativaDeJogada->Y;
    if(comeuPeca)
    {
        puts("*Como o Jogador comeu uma peça é ele novamente*");
        return jogada;
    }
    else if(jogada)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

void iniciarpecas(struct peca **headbranco, struct peca **headpreto){
    int validacao = TRUE;
    int linha, coluna;
    
    for(linha=0;linha<8;linha++)
    {
        for(coluna=0;coluna<8;coluna++)
        {
            if(linha<4)
            {
                if(validacao)
                {
                    addPeca(headpreto, linha, coluna, 'P');
                    validacao = FALSE;
                }
                else
                {
                    validacao = TRUE;
                }                    
            }
            else if(linha >= 6)
            {
                if(validacao)
                {
                    addPeca(headbranco, linha, coluna, 'B');
                    validacao = FALSE;
                }
                else
                {
                    validacao = TRUE;
                }
            }
        }
    }
}


struct partida VerificadorDeFimDePartida(struct peca *preto, struct peca *branco,struct jogadas *historico){
    struct partida vitoria;
    if(preto == NULL)
    {
        vitoria.fimDeJogo = TRUE;
        vitoria.vencedor = 'B';
        vitoria.historicoJogadas = historico;
    }
    else if(branco == NULL)
    {
        vitoria.fimDeJogo = TRUE;
        vitoria.vencedor = 'P';
        vitoria.historicoJogadas = historico;
    }
    else
    {
        vitoria.fimDeJogo = FALSE;
        vitoria.historicoJogadas = historico;
    }
    return vitoria;
}


void addPeca(struct peca **head, int Y, int X, char time){
    struct peca *novo = (struct peca *)malloc(sizeof(struct peca));
    struct peca *n = *head;

    novo->time = time;
    novo->X = X;
    novo->Y = Y;
    novo->next = NULL;

    if(head == NULL)
    {
        *head = novo;
    }
    else
    {
        while(n->next != NULL)
        {
            n = n->next;
        }
        n->next = novo;
    }
}

