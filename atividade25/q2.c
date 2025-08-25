#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pessoa {  
    char nome[30]; 
    struct  Pessoa *prox; 
}   Pessoa ;

void adicionarNaFila (Pessoa **head, Pessoa **tail, char nome[30]);
void adicionarNaPilha (Pessoa **headPilha, Pessoa **headFila1, Pessoa **headFila2);
void AdicionarAlternadoNaPilha (Pessoa **headPilha, Pessoa **headFila1, Pessoa **headFila2);
void imprimir (Pessoa *head);

int main (){
    Pessoa **headFila1 = NULL;
    Pessoa **tailFila1 = NULL;

    Pessoa **headFila2 = NULL;
    Pessoa **tailFila2 = NULL;

    Pessoa **headPilha1 = NULL;
    Pessoa **headPilha2 = NULL;


    for (int i = 0; i < 10; i++){
        char nome[30];
        scanf("%s", nome);
        adicionarNaFila(&headFila1, &tailFila1, nome);
    }
    for (int j = 0; j < 10; j++){
        char nome[30];
        scanf("%s", nome);
        adicionarNaFila(&headFila2, &tailFila2, nome);
    }

    adicionarNaPilha(&headPilha1, &headFila1, &headFila2);

    printf("\nFila 1:\n");
    imprimir(&headFila1);

    printf("\nFila 2:\n");
    imprimir(&headFila2);

    printf("\nPilha 1:\n");
    imprimir(&headPilha1);

    printf("\nPilha 2:\n");
    imprimir(&headPilha2);
    return 0;

}

void adicionarNaFila (Pessoa **head, Pessoa **tail, char nome[30]){

    Pessoa *novo = (Pessoa *)malloc(sizeof(Pessoa));

    if (novo != NULL){
        strcyp(novo->nome, nome);
        novo->prox = NULL;
    } if (*head == NULL){
        *head = novo;
        *tail = novo;
    }else{
        (*tail)->prox = novo;
        *tail = novo;
    }
}
void adicionarNaPilha (Pessoa **headPilha, Pessoa **headFila1, Pessoa **headFila2){
    
    for (int i = 0; i < 10; i++){
        Pessoa *novo = (Pessoa *)malloc(sizeof(Pessoa));
        strcyp(novo->nome,(*headFila1)->nome);
        novo->prox = *headPilha;
        *headPilha = novo;
        *headFila1 = (*headFila1)->prox;
    }
    for (int j = 0; j < 10; j++){
        Pessoa *novo = (Pessoa *)malloc(sizeof(Pessoa));
        strcyp(novo->nome,(*headFila2)->nome);
        novo->prox = *headPilha;
        *headPilha = novo;
        *headFila2 = (*headFila2)->prox;
    }
}

void AdicionarAlternadoNaPilha (Pessoa **headPilha, Pessoa **headFila1, Pessoa **headFila2){

}

void imprimir (Pessoa *head){

    while (head != NULL){
        print("%s -> ", head->nome);
        head = head->prox;
    }
    printf("NULL \n");
}

