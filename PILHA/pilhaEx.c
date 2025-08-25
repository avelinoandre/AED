#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
      int numero; 
      struct Node *prox;
} Node;

int main (){
    Node **head = NULL;
    return 0;
}

void adicionarNaPilha (Node **head, int valor){
    Node *novo = (Node *)malloc(sizeof(Node));

    novo->numero = valor;
    novo->prox = *head;
    *head = novo;

    if (*head == NULL){
        *head = novo;
    }else{
        (*head)->numero = novo;
        *head = novo;
    }
}

void removerNaPilha (Node **head){
    Node *temp;
    if (*head != NULL){
        temp = *head;
        *head = (*head)->prox;
        free(temp);
        if (*head == NULL){
            printf("Pilha está vazia");
        }
    }
}

void imprimirPilha (Node *head){
    while (head != NULL){
        printf("%d",head->numero);
        head = head->prox;
    }
}

void printarUltimo (Node *head){
    int cont = 1;
    while (head != NULL){
        if (head->prox == NULL){ // head->valor % 2 == 0 para printar numeros pares / cont % 2 = 0;
            printf("%d",head->numero);
        }
        head = head->prox;
        cont+= 1;
    }
}