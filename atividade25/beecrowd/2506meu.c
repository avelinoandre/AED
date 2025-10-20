#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char nome[31];
    int numero;
    struct Node *prox;
    struct Node *ant;
} Node;

Node *criarNo(char nome[], int numero) {
    Node *novo = (Node *)malloc(sizeof(Node));
    strcpy(novo->nome, nome);
    novo->numero = numero;
    novo->prox = NULL;
    novo->ant = NULL;
    return novo;
}

void inserir(Node **head, Node **tail, Node *novo) {
    if (*head == NULL) {
        *head = *tail = novo;
        novo->prox = novo;
        novo->ant = novo;
    } else {
        (*tail)->prox = novo;
        novo->ant = *tail;
        novo->prox = *head;
        (*head)->ant = novo;
        *tail = novo;
    }
}

Node *remover(Node **head, Node **tail, Node *atual, int direcao) {
    if (atual->prox == atual) {
        *head = *tail = NULL;
        free(atual);
        return NULL;
    }

    Node *proxNo;
    if (direcao == 1)
        proxNo = atual->prox;
    else
        proxNo = atual->ant;

    atual->ant->prox = atual->prox;
    atual->prox->ant = atual->ant;

    if (*head == atual)
        *head = atual->prox;
    if (*tail == atual)
        *tail = atual->ant;

    free(atual);
    return proxNo;
}

int main() {
    int N;

    while (scanf("%d", &N) && N != 0) {
        Node *head = NULL, *tail = NULL;

        for (int i = 0; i < N; i++) {
            char nome[31];
            int numero;
            scanf("%s %d", nome, &numero);
            inserir(&head, &tail, criarNo(nome, numero));
        }

        Node *atual = head;
        int valor = atual->numero;

        while (head != NULL && head->prox != head) {
            int passos = valor;
            if (valor % 2 == 0) {
                for (int i = 0; i < passos; i++)
                    atual = atual->prox;
                valor = atual->numero;
                atual = remover(&head, &tail, atual, 1);
            } else {
                for (int i = 0; i < passos; i++)
                    atual = atual->ant;
                valor = atual->numero;
                atual = remover(&head, &tail, atual, -1);
            }
        }

        printf("Vencedor(a): %s\n", head->nome);
        free(head);
    }

    return 0;
}
