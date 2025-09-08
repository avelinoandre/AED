#include <stdio.h>
#include <stdlib.h>

typedef struct Node{

    int numero;
    struct Node *prox;

}Node;

int main () {

    Node *head = NULL;
    Node *tail = NULL;


    return 0;

}

void adicionar (Node **head, Node **tail, int valor){

    Node *novo = (Node *)malloc(sizeof(Node));

    novo->numero = valor;
    novo->prox = NULL;

    if (head == NULL){

        *head = novo;
        *tail = novo;

    }else{
        (*tail)->prox = novo;
        *tail = novo;

    }


}


void remover (Node **head){

    if (*head == NULL){

        printf("Lista está vazia!\n");

    }else{

        Node *temp = *head;
        *head = (*head)->prox; 
        free(temp);

    }
}




