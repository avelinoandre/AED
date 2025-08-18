#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No* proximo;
} No;

int main() {
    // Criando o primeiro nó
    No* lista = (No*)malloc(sizeof(No));
    (*lista).dado = 10;
    (*lista).proximo = NULL;

    // Criando o segundo nó
    No* segundo = (No*)malloc(sizeof(No));
    (*segundo).dado = 20;
    (*segundo).proximo = NULL;

    // Ligando o primeiro ao segundo
    (*lista).proximo = segundo;

    // Criando o terceiro nó
    No* terceiro = (No*)malloc(sizeof(No));
    (*terceiro).dado = 30;
    (*terceiro).proximo = NULL;

    // Ligando o segundo ao terceiro
    (*segundo).proximo = terceiro;

    // Imprimindo a lista
    No* atual = lista;
    while (atual != NULL) {
        printf("%d -> ", (*atual).dado);
        atual = (*atual).proximo;
    }
    printf("NULL\n");

    // Liberando a memória
    atual = lista;
    while (atual != NULL) {
        No* temp = atual;
        atual = (*atual).proximo;
        free(temp);
    }

    return 0;
}
