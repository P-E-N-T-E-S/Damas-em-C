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

int validacaopecajog(){ //validar se ele não está movendo para uma peça ja existente dele

}

int validacaopecacontra(){ //valida se ele não está tentando comer uma peca

}

int validacaopecalonge(){ //valida se não está tentando mover uma peca para muito longe

}