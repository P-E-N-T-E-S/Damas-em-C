#include <stdio.h>
#include <stdlib.h>

#include "damas.h"

#define TRUE 1
#define FALSE 0

void Tabuleiro(struct node **head){
    int linha, coluna, validacao;
    struct node *n = *head;
    
    for(linha=0;linha<8;linha++){
        for(coluna=0;coluna<8;coluna++){
            validacao = FALSE;
            while(n != NULL){
                if(n->peca.Y == linha && n->peca.X == coluna){
                    validacao = TRUE;
                    break;
                }
                n = n->next;
            }
            if(validacao){
                printf("%c\t", n->peca.time);
            }else{
                printf("X\t")
            }
        }
    }
}


void addnode(struct node **head, int Y, int X, char time){
    struct node *novo = (struct node *)malloc(sizeof(struct node));
    struct node *n = *head;

    novo->peca.time = time;
    novo->peca.X = X;
    novo->peca.Y = Y;
    novo->next = NULL;

    if(head == NULL){
        *head = novo;
    }else{
        while(n->next != NULL){
            n = n->next
        }
        n->next = novo;
    }
}


void iniciarpecas(struct node **headbranco, struct node **headpreto){
    int validacao = TRUE;
    int linha, coluna;

    
    for(linha=0;linha<8;linha++){
        for(coluna=0;coluna<8;coluna++){
            if(linha<4){
                if(validacao){
                    addnode(&headpreto, linha, coluna, 'P');
                    validacao = FALSE;
                }else{
                    validacao = TRUE
                }                    
            }else if(linha >= 6){
                if(validacao){
                    addnode(&headbranco, linha, coluna, 'B');
                    validacao = FALSE
                }else{
                    validacao = True
                }
            }
        }
    }
}


int vitoria(struct node *preto, struct node *branco){
    struct vitoria vitoria;
    if(preto == NULL){
        vitoria.jogo = TRUE;
        vitoria.vencedor = 'B';
    }else if(branco == NULL){
        vitoria.jogo = TRUE;
        vitoria.vencedor = 'P';
    }else{
        vitoria.jogo = FALSE;
        vitoria.vencedor = 'N';
    }
    return(vitoria);
}
