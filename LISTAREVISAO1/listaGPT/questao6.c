#include <stdio.h>
#include <stdlib.h>
//QUESTAO DE FILA
typedef struct Node{

    int numero;
    struct Node *prox;

}Node;

int main () {

    Node *head = NULL;
    Node *tail = NULL;

    Node *head2 = NULL;
    Node *tail2 = NULL;

    return 0;

}


void adicionar (Node **head, Node **tail, int valor){

    Node *novo = (Node *)malloc(sizeof(Node));

    novo->numero = valor;
    novo->prox = NULL;

    if (*head == NULL){

        *head = novo;
        *tail = novo;

    }else{

        (*tail)->numero = novo;
        *tail = novo;

    }


}


void inverterFila (Node *head, Node **headInvertida, Node *tail, Node **tailInvertida){

    if (head == NULL){

        printf("A lista está vazia!\n");

    }else{
        while (1){

            Node *novo = (Node *)malloc(sizeof(Node));

                if (novo != NULL){

                    novo->numero = head->numero;
                    novo->prox = *headInvertida;
                    *headInvertida = novo;
                }
            }

        }

    }
