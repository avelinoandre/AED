#include <stdio.h>
#include <stdlib.h>

typedef struct Node{

    int numero;
    struct Node *prox;

}Node;



int main () {

    Node *head = NULL;

    return 0;

}

void adicionar(Node **head, int valor){
    Node *novo = (Node *)malloc(sizeof(Node));

    if (novo != NULL){
        novo->numero = valor;
        novo->prox = *head;
        *head = novo;
    }

}

void imprimir (Node *head){

    if (head == NULL){

        printf("A lista está vazia...\n");

    }else{

        while(head->prox != NULL){

            printf("%d -> ", head->numero);

            head = head->prox;

        }
        printf("NULL.\n");

    }

}

