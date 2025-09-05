#include <stdio.h>
#include <stdlib.h>
typedef struct Node{

    int numero;
    struct Node *prox;

}Node;

int main () {

    Node *head1 = NULL;
    Node *head2 = NULL;

    return 0;

}

void adicionarNaPilha(Node **head, int valor){

    Node *novo = (Node *)malloc(sizeof(Node));

    if (novo != NULL){

        novo->numero = valor;
        novo->prox = *head;
        *head = novo;

    }

}


void trocarPrimeiroValor (Node **head1, Node **head2){

    if (*head1 == NULL || *head2 == NULL){

        printf("Impossível realizar a troca, as pilhas está vazia.\n");

    }else {

        int temp = (*head1)->numero;
        (*head1)->numero = (*head2)->numero;
        (*head2)->numero = temp;

    }

}