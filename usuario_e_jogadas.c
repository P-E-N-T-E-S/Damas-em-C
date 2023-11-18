void user_jogada(struct node **headjogada, struct node **headcontra, int Xida, int Yida, int Xdest, int Ydest){
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
            while(ncontra)

        }
    }
}