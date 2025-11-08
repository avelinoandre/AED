typedef struct equipe{

    char nome[50];
    int numeromembros;
    membro membros(numeromembros);

}equipe;



CRIAR_EQUIPE( char *nome, int qtdMEMBROS){
    equipe e
    e = (equipe*)malloc(1 * sizeof(equipe));

    strcpy(nome, *e->nome);
    *e->numeromembros =qtdMEMBROS;
    membro *membros = (membro*)malloc(qntMEMBROS * sizeof(membros))

}