#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Menu() {
  int opcao;

  printf("====================================\n");
  printf("| O que você deseja fazer:         |\n");
  printf("| (1)Iniciar jogo                  |\n");
  printf("| (2)Verificar histórico           |\n");
  printf("| (3)                              |\n");
  printf("| (4)Sair                          |\n");
  printf("====================================\n");
  printf("Opção: ");
  scanf("%d", &opcao);

  return opcao;
}

void Escolha(int escolha) {

  switch (escolha) {
  case 1:

    break;

  case 2:
    break;

  case 3:

    break;

  case 4:
    exit(0);
  }
}

int main(void) {

  int escolha;

  do {
    escolha = Menu();
    Escolha(escolha);
  } while (1);

  return 0;
}
