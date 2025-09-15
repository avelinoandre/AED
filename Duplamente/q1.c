#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int valor;
    struct Node *prox;
    struct Node *ant;
} Node;

void adicionarOrdenado(Node **head, int valor);
void imprimir(Node *head);

int main() {
    Node *head = NULL;

    for (int i = 0; i < 4; i++) {
        int num;
        scanf("%d", &num);
        adicionarOrdenado(&head, num);
    }

    imprimir(head);

    return 0;
}

void imprimir(Node *head) {
    while (head != NULL) {
        printf("%d\n", head->valor);
        head = head->prox;
    }
}

void adicionarOrdenado(Node **head, int valor) {
    Node *novo = (Node *)malloc(sizeof(Node));

    if (novo != NULL){

        novo->valor = valor;
        novo->prox = NULL;
        novo->ant = NULL;

        if (*head == NULL) {
            *head = novo;
            return;
        }

        Node *temp = *head;

        if (valor < temp->valor) {
            novo->prox = temp;
            temp->ant = novo;
            *head = novo;
            return;
        }

        while (temp->prox != NULL && temp->prox->valor < valor) {

            temp = temp->prox;

        }

        novo->prox = temp->prox;
        novo->ant = temp;

        if (temp->prox != NULL) {

            temp->prox->ant = novo;

        }

        temp->prox = novo;
    }


    }
    