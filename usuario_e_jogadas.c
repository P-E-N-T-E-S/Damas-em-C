#include <stdio.h>
#include <stdlib.h>

#include "damas.h"

#define TRUE 1
#define FALSE 0


void user_jogada(struct node **headjogada, struct node **headcontra){
    int X, Y, Xdest, Ydest;
    while(1){
        printf("insira a posição da peça que deseja mover:\nX: ");
        scanf("%d", &X);
        printf("Y: ");
        scanf("%d", &Y);

        while(njoga != NULL && (njoga->peca.X != X && njoga->peca.Y != Y)){
            njoga = njoga->next;
        }
        if(njoga == NULL){
            printf("Não existe peça nessa posição");
        }else{
            break;
        }
    }
    while(1){
        printf("insira o destino da peça:\nX:");
        scanf("%d", &Xdest);
        printf("Y: ");
        scanf("%d", &Ydest);
        val1 = validacaopecajog();
        val2 = validacaopecacontra();
        val3 = validacaopecalonge();
    }
}

int validacaopecajog(struct node **head, int X, int Y){ //validar se ele não está movendo para uma peça ja existente dele
    struct node *n = *head
    while(n != NULL && (n->peca.X != X || n->peca.Y != Y)){
        n = n->next;
    }
    if(n->peca.X == X && n->peca.Y == Y){
        return(FALSE);
    }else{
        return(TRUE);
    }
}

int validacaopecacontra(struct node **headcontra, int X, int Y){ //valida se ele não está tentando comer uma peca
    struct node *n = *headcontra
    while(n != NULL && (n->peca.X != X || n->peca.Y != Y)){
        n = n->next;
    }
    if(n->peca.X == X && n->peca.Y == Y){
        return(FALSE);
    }else{
        return(TRUE);
    }
}

int validacaopecalonge(int X, int Y, int Xdest, int Ydest){ //valida se não está tentando mover uma peca para muito longe
    if((Xdest == X-1 && Xdest == X+1) && (Ydest == Y+1 && Ydest == Y-1)){
        return(TRUE);
    }else{
        return(FALSE);
    }
}