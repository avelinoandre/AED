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


void adicionarPilha (Node **head, int valor){
    Node *novo = (Node *)malloc(sizeof(Node));

    if (novo != NULL){

        novo->numero = valor;
        novo->prox = *head;
        *head = novo;

    }
}

void removerPilha(Node **head){

    if (*head == NULL){
        
        printf("Lista vazia.\n");
        
    }else{

        Node *temp = *head;
        *head = (*head)->prox;
        (free(temp));

    }

}

void printarPilha(Node *head){

    if (head == NULL){

        printf("Lista vazia.\n");

    }else{
        while(head != NULL){

            printf("%d -> ", head->numero);
            head = head->prox;

        }

        printf("NULL.\n");

    }

}