#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int numero;
    struct Node* ant;
    struct Node* next;
} Node;

void inserirNoFim(Node **head, Node **tail, int numero);
void removerElemento(Node **head, Node **tail, Node *alvo);
void executarProcesso(int n, int k, int m);

int main() {

    int n, k, m;

    while (scanf("%d %d %d", &n, &k, &m) == 3 && (n || k || m)) {

        executarProcesso(n, k, m);

    }

    return 0;

}

void inserirNoFim(Node** head, Node** tail, int numero) {
    Node* novo = (Node*)malloc(sizeof(Node));
    if (novo == NULL) return;
    novo->numero = numero;

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

void removerElemento(Node **head, Node **tail, Node *alvo) {
    if (*head == NULL || alvo == NULL) return;

    if (alvo->next == alvo) {
        free(alvo);
        *head = NULL;
        *tail = NULL;
        return;
    }

    if (alvo == *head) *head = alvo->next;
    if (alvo == *tail) *tail = alvo->ant;

    alvo->ant->next = alvo->next;
    alvo->next->ant = alvo->ant;

    free(alvo);
}

void executarProcesso(int n, int k, int m) {
    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 1; i <= n; i++) {
        inserirNoFim(&head, &tail, i);
    }

    Node* pDireita = head;
    Node* pEsquerda = tail;
    int primeiro = 1;

    while (head != NULL) {
        for (int i = 1; i < k; i++) pDireita = pDireita->next;
        for (int i = 1; i < m; i++) pEsquerda = pEsquerda->ant;

        if (!primeiro) printf(",");
        primeiro = 0;

        if (pDireita == pEsquerda) {
            printf("%3d", pDireita->numero);
            Node* prox = pDireita->next;
            Node* ant = pEsquerda->ant;
            removerElemento(&head, &tail, pDireita);
            if (head == NULL) break;
            pDireita = prox;
            pEsquerda = ant;
        } else {
            printf("%3d%3d", pDireita->numero, pEsquerda->numero);
            Node* dirNext = pDireita->next;
            Node* dirAnt = pDireita->ant;
            Node* esqNext = pEsquerda->next;
            Node* esqAnt = pEsquerda->ant;

            Node* tempD = pDireita;
            Node* tempE = pEsquerda;

            removerElemento(&head, &tail, tempD);
            removerElemento(&head, &tail, tempE);

            if (head == NULL) break;

            if (dirNext == tempE) pDireita = esqNext;
            else pDireita = dirNext;

            if (esqAnt == tempD) pEsquerda = dirAnt;
            else pEsquerda = esqAnt;
        }
    }

    printf("\n");
}