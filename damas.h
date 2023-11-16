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

void Tabuleiro(struct node **head)
void iniciarpecas(struct node **headbranco, struct node **headpreto)

#endif