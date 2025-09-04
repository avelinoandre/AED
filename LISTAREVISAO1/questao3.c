//QUESTÃO 03 - Revise a implementação das funções a seguir para as Filas:
// Inserção, Remoção e Impressão

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{

    int numero;
    struct Node *prox;

}Node;

int main () {

    Node *head = NULL;
    Node *tail = NULL;

}


void adicionarFila(Node **head, Node **tail, int valor){
    Node *novo = (Node *)malloc(sizeof(Node));

    if (novo != NULL){

        novo->numero = valor;
        novo->prox = NULL;

        if (*head == NULL){
            *head = novo;
            *tail = novo;

        } else{

            (*tail)->prox = novo;
            *tail = novo;

        }

    }

}

void percorrer (Node *head){

    if (head == NULL){

        printf("Lista vazia!\n");

    }else{
        while (head != NULL){
            
            printf("%d -> ", head->numero);
            head = head->prox;

        }

        printf("NULL.");

    }

}

void removerToda (Node **head, Node **tail){

    if (*head == NULL){
        *tail == NULL;
        printf("Lista vazia!\n");
    } else {

       Node *temp = *head;

        while (temp != NULL){

            *head = (*head)->prox;
            free(temp);

        }

    }

}