#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {

    int numero;
    char nome[50];
    struct Node *prox;
    struct Node *ant;

} Node;

Node *criarNo(char nome[], int numero) {
    Node* novo = (Node*)malloc(sizeof(Node));
    if (novo != NULL) {
        strcpy(novo->nome, nome);
        novo->numero = numero;
        novo->prox = novo;
        novo->ant = novo;
    }
    return novo;
}

void adicionar(Node **head, Node **tail, char nome[], int numero) {
    Node *novo = criarNo(nome, numero);
    if (novo == NULL) {
        return;
    }

    if (*head == NULL) {
        *head = novo;
        *tail = novo;
    } else {
        novo->ant = *tail;
        novo->prox = *head;
        (*tail)->prox = novo;
        (*head)->ant = novo;
        *tail = novo;
    }
}

void remudar(Node **head, Node **tail, Node *atual) {
    if (*head == NULL || atual == NULL) {
        return;
    }

    if (atual->prox == atual) {
        free(atual);
        *head = NULL;
        *tail = NULL;
        
    }

    if (atual == *head) {
        *head = atual->prox;
    }

    if (atual == *tail) {
        *tail = atual->ant;
    }

    atual->ant->prox = atual->prox;
    atual->prox->ant = atual->ant;
    free(atual);
}

Node *mudar(Node *atual, int passos, int sentido) {
    for (int i = 0; i < passos; i++) {
        if (sentido == 1) {
            atual = atual->prox;
        } else {
            atual = atual->ant;
        }
    }
   return atual;
}

int main() {
    int n;

    while (scanf("%d", &n) == 1 && n != 0) {
        Node *head = NULL;
        Node *tail = NULL;
        char nome[50];
        int numero;

        for (int i = 0; i < n; i++) {

            scanf("%s %d", nome, &numero);
            adicionar(&head, &tail, nome, numero);

        }

        if (head == NULL) {

            printf("Vencedor(a): \n");

        } else {

            Node *atual = head;
            int valorAtual = atual->numero;

            while (head != tail) {

                int sentido;

                if (valorAtual % 2 != 0) {

                    sentido = 1;  

                } else {

                    sentido = -1; 

                }

                atual = mudar(atual, valorAtual, sentido);
                valorAtual = atual->numero;

                Node *prox;
                if (valorAtual % 2 != 0) {

                    prox = atual->ant;

                } else {

                    prox = atual->prox;

                }

                remudar(&head, &tail, atual);
                atual = prox;
            }

            printf("Vencedor(a): %s\n", head->nome);
            free(head);
        }
    }

    
}
