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

struct jogadas
{
  struct peca posicaoAntiga;
  struct peca posicaoNova;
  struct peca pecaComida;
  struct jogadas *next;
}

void Tabuleiro(struct node **head)
void iniciarpecas(struct node **headbranco, struct node **headpreto)
int vitoria(struct node *preto, struct node *branco)
int Menu()
#endif