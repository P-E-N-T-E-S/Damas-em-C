#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "screen.h"
#include "keyboard.h"
#include "timer.h"

#define TRUE 1
#define FALSE 0


typedef struct{
  char time;
  int Y;
  int X;
}peca;


typedef struct{
  peca peca;
  struct node *next;
}node;


int main(void){
  int linha, coluna;
  struct node *head = (struct node *)malloc(sizeof(node));
  
  FILE *fptr;

  
  fptr = fopen("jogos.dat", "wb+");

  
  for(linha=0;linha<8;linha++){
    for(coluna=0;coluna<8;coluna++){
      while(n != NULL){
        if(n->peca.Y == linha && n->peca.X == coluna){
          peca = TRUE;
          break;
        }
      }
      if(peca){
        printf("%c", n->peca.time);
      }else{
        printf("X");
      }
      

      printf("X\t");

    }
    printf("\n");
  }
  
  return 1;
}





