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



void iniciarpecas(struct node **head){
    struct peca branco[12], preto[12];

    for(linha=0;linha<8;linha++){
        for(coluna)
    }

}



