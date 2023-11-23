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

int Menu() 
{
  int opcao;
  system("clear");
  puts("====================================");
  puts("| O que você deseja fazer:         |");
  puts("| (1)Iniciar jogo                  |");
  puts("| (2)Regras                        |");
  puts("| (3)Verificar histórico           |");
  puts("| (4)Sair                          |");
  puts("====================================");
  puts("Opção: ");
  scanf("%d", &opcao);
  while ((getchar()) != '\n');
  return opcao;
}


void InputsJogadores(struct partida *NovaPartida)
{
    system("clear");
    puts("====================================");
    puts("Digite o nome de quem jogará com as peçaas pretas:");
    fgets(NovaPartida->jogadorPecasPretas,50,stdin);
    puts("Digite o nome de quem jogará com as peças brancas:");
    fgets(NovaPartida->jogadorPecasBrancas,50,stdin);

}


void MostrarTabuleiroCompleto(struct peca **headPreta,struct peca **headBranca)
{
    int linha, coluna, validacao;
    struct peca *p = *headPreta;
    struct peca *b = *headBranca;
    struct peca *n = NULL;
    puts("=================================================================");

    for(linha=0;linha<8;linha++)
    {
        for(coluna=0;coluna<8;coluna++)
        {
            validacao = FALSE;
            while(p != NULL || b != NULL)
            {
                if(p->Y == linha && p->X == coluna)
                {
                    validacao = TRUE;
                    n = p;
                    p = p->next;
                    break;
                }
                else if(b->Y == linha && b->X == coluna)
                {
                    validacao = TRUE;
                    n = b;
                    b = b-> next;
                    break;
                }
            }
            if(validacao)
            {
                printf("%c\t", n->time);
            }
            else
            {
                printf("X\t");
            }
        }
    }
  puts("=================================================================");
}


struct peca *InputEscolhaJogada()
{
  struct peca *tentativaDeJogada;
  puts("insira a posição da peça que deseja mover:");
  printf("X: ");
  scanf("%d", &(tentativaDeJogada->X));
  while ((getchar()) != '\n');
  printf("Y: ");
  scanf("%d", &(tentativaDeJogada->Y));
  while ((getchar()) != '\n');

  return tentativaDeJogada;
}

struct peca InputEscolhaNovaPosJogada()
{
  struct peca NovaPos;
  puts("insira a nova posição em que você deseja mover essa peça:");
  printf("X: ");
  scanf("%d", &(NovaPos.X));
  while ((getchar()) != '\n');
  printf("Y: ");
  scanf("%d", &(NovaPos.Y));
  while ((getchar()) != '\n');

  return NovaPos;
}