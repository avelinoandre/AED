#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int valor;
    int soma = 0;

    printf("Digite valores inteiros para a lista (digite -1 para terminar):\n");

    while (1) {
        printf("Valor: ");
        scanf("%d", &valor);
        if (valor == -1) break;

        // Criar novo nó
        Node* novo = (Node*)malloc(sizeof(Node));
        novo->data = valor;
        novo->next = NULL;

        // Inserir na lista
        if (head == NULL) {
            head = novo;
            tail = novo;
        } else {
            tail->next = novo;
            tail = novo;
        }
    }

    // Calcular a soma
    Node* atual = head;
    while (atual != NULL) {
        soma += atual->data;
        atual = atual->next;
    }

    printf("Soma dos elementos: %d\n", soma);

    // Liberar memória
    atual = head;
    while (atual != NULL) {
        Node* temp = atual;
        atual = atual->next;
        free(temp);
    }

    return 0;
}
