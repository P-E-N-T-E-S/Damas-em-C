#ifdef __DAMAS_H__
#define __DAMAS_H__

struct peca{
  char time;
  int Y;
  int X;
}


struct node{
  struct peca peca;
  struct node *next;
}

struct vitoria{
  int jogo;
  char vencedor;
}

void Tabuleiro(struct node **head)
void iniciarpecas(struct node **headbranco, struct node **headpreto)
int vitoria(struct node *preto, struct node *branco)
int Menu()
#endif