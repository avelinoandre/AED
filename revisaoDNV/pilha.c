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

void adicionar (Node **head, int valor){


    Node *novo = (Node *)malloc(sizeof(Node));

    if (novo != NULL){
        novo->numero = valor;
        novo->prox = *head;
        *head = novo;
    }

}


void remover (Node **head, int valor){

    if (*head == NULL){

        printf("Lista está vazia!\n");

    }else{

        Node *temp = *head;
        *head = (*head)->prox;
        free(temp);
        
    }

}