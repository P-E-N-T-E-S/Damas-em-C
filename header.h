//#ifdef HEADER_H
//#define HEADER_H

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


//controleJogo.c
void addPeca(struct peca **head, int Y, int X, char time);
void iniciarpecas(struct peca **headbranco, struct peca **headpreto);
struct partida VerificadorDeFimDePartida(struct peca *preto, struct peca *branco,struct jogadas *historico);
int user_jogada(struct peca **headjogada, struct peca **headcontra,int jogada);


//Interface.c
int Menu();
void InputsJogadores(struct partida *NovaPartida);
struct peca *InputEscolhaJogada();
struct peca InputEscolhaNovaPosJogada();
void MostrarTabuleiroCompleto(struct peca **headPreta,struct peca **headBranca);

//database.c
void CriarPartida(struct partida **headPartidas,struct partida *novaPartida,struct jogadas *historico)
struct partida *CarregarPartidas();
//#endif