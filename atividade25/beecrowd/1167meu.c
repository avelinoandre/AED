#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int numero;
    char nome[50];
    struct Node* ant;
    struct Node* next;
} Node;

int main() {
    int n;
    char nome[50];
    int numero;

    while (scanf("%d", &n) == 1 && n != 0) {
        Node* head = NULL;
        Node* tail = NULL;

        for (int i = 0; i < n; i++) {

            scanf("%s", nome);
            scanf("%d", &numero);
            inserirFinal(&head, &tail, numero, nome);

        }

        if (head == NULL) {

            printf("Vencedor(a): \n");
            continue;

        }

        Node* aux = head;
        int chavenumero = aux->numero;

        while (head != tail) {
            if (chavenumero % 2 == 0) {

                for (int i = 0; i < chavenumero; i++) {

                    aux = aux->ant;

                }

            } else {
                for (int i = 0; i < chavenumero; i++) {

                    aux = aux->next;

                }
            }

            chavenumero = aux->numero;

            Node* temp = aux->next;
            if (chavenumero % 2 != 0) {

                temp = aux->ant;

            }

            removerNo(&head, &tail, aux);
            aux = temp;
        }

        printf("Vencedor(a): %s\n", head->nome);
        free(head);
        head = NULL;
        tail = NULL;
    }

    return 0;
}

void inserirFinal(Node **head, Node **tail, int numero, char nome[]) {
    Node* novo = (Node*)malloc(sizeof(Node));
    if (novo == NULL) return;

    novo->numero = numero;
    strcpy(novo->nome, nome);

    if (*head == NULL) {
        novo->next = novo;
        novo->ant = novo;
        *head = novo;
        *tail = novo;
        return;
    }

    novo->ant = *tail;
    novo->next = *head;
    (*tail)->next = novo;
    (*head)->ant = novo;
    *tail = novo;
}

void removerNo(Node **head, Node **tail, Node *posi) {
    if (*head == NULL || posi == NULL) return;

    if (posi->next == posi) {
        free(posi);
        *head = NULL;
        *tail = NULL;
        return;
    }

    if (posi == *head) *head = posi->next;
    if (posi == *tail) *tail = posi->ant;

    posi->ant->next = posi->next;
    posi->next->ant = posi->ant;

    free(posi);
}
