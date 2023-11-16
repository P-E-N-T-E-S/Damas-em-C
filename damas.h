#ifdef __FUNCTION__

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

#endif