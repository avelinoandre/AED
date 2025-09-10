#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char valor;
    struct Node* next;
} Node;

void enqueue(Node **head, Node **tail, char valor) {
    Node *novo = (Node*)malloc(sizeof(Node));
    novo->valor = valor;
    novo->next = NULL;
    if (*tail == NULL) {
        *head = *tail = novo;
    } else {
        (*tail)->next = novo;
        *tail = novo;
    }
}

char dequeue(Node **head, Node **tail) {
    if (*head == NULL) return '\0';
    Node *temp = *head;
    char v = temp->valor;
    *head = temp->next;
    if (*head == NULL) *tail = NULL; 
    free(temp);
    return v;
}

void push(Node **topo, char valor) {
    Node *novo = (Node*)malloc(sizeof(Node));
    novo->valor = valor;
    novo->next = *topo;
    *topo = novo;
}

char pop(Node **topo) {
    if (*topo == NULL) return '\0';
    Node *temp = *topo;
    char v = temp->valor;
    *topo = temp->next;
    free(temp);
    return v;
}

int main() {
    int n;
    while (scanf("%d", &n) && n != 0) {

        Node *entradaHead = NULL, *entradaTail = NULL;

        Node *saidaHead = NULL, *saidaTail = NULL;

        Node *pilha = NULL;

        Node *movHead = NULL, *movTail = NULL;

        for (int i = 0; i < n; i++) {
            char c;
            scanf(" %c", &c);
            enqueue(&entradaHead, &entradaTail, c);
        }

        for (int i = 0; i < n; i++) {
            char c;
            scanf(" %c", &c);
            enqueue(&saidaHead, &saidaTail, c);
        }

        int impossivel = 0;
        while (saidaHead != NULL) {
            if (pilha != NULL && pilha->valor == saidaHead->valor) {
                pop(&pilha);
                dequeue(&saidaHead, &saidaTail);
                enqueue(&movHead, &movTail, 'R');
            } else if (entradaHead != NULL) {
                char v = dequeue(&entradaHead, &entradaTail);
                push(&pilha, v);
                enqueue(&movHead, &movTail, 'I');
            } else {
                impossivel = 1;
                break;
            }
        }

        // imprime movimentos na ordem correta (já é fila)
        while (movHead != NULL) {
            printf("%c", dequeue(&movHead, &movTail));
        }

        if (impossivel) printf(" Impossible");
        printf("\n");
    }
    return 0;
}