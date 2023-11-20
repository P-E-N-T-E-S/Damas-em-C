#include <stdio.h>
#include <stdlib.h>

#include "damas.h"

#define TRUE 1
#define FALSE 0


int validacaopecajogo(struct node **head, int X, int Y){ //validar se ele não está movendo para uma peça ja existente dele
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


comerpeca(struct node **head, int X, int Y){
    struct node *n = *head;
    struct node *temp;
    while(n->next->next != NULL && (n->next->peca.X == X && n->next->peca.Y == Y)){
        n = n->next;
    }
    if(n->next->next == NULL){
        return
    }else{
        temp = n->next;
        n->next = n->next->next;
        free(temp);
    }
}


void user_jogada(struct node **headjogada, struct node **headcontra){
    int X, Y, Xdest, Ydest;
    int val1, val2, val3;
    char resposta;
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
        val1 = 1;
        val2 = 1;
        val3 = 3;
        printf("insira o destino da peça:\nX:");
        scanf("%d", &Xdest);
        printf("Y: ");
        scanf("%d", &Ydest);
        val1 = validacaopecajogo(&headjogada, Xdest, Ydest);
        val2 = validacaopecacontra(&headcontra, Xdest, Ydest);
        val3 = validacaopecalonge(X, Y, Xdest, Ydest);
        if(val1 && val3){
            printf("jogada inválida\n");
        }else if(val2){
            printf("voce deseja comer a peça na posição X=%d, Y=%d\nY ou N: ", Xdest, Ydest);
            scanf("%c", &resposta);
            if(resposta == 'Y'){
                comerpeca(&headcontra, Xdest, Ydest);
                if(Xdest == X-1){
                    Ydest = Ydest+1;
                    Xdest = Xdest-1;
                }else if(Xdest == X+1){
                    Ydest = Ydest+1;
                    Xdest = Xdest+1;                  
                }
                break;
            }
        }else{
            break;
        }
    }
    n->peca.X = Xdest;
    n->peca.Y = Ydest;
}

