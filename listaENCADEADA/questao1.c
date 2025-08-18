#include <stdio.h>
#include <stdlib.h>

// 1 — Soma dos elementos de uma lista encadeada
// Implemente uma função em linguagem C que receba uma lista encadeada de números inteiros e retorne a soma de todos os seus elementos.
// EX: Se a lista contiver os elementos 10 -> 20 -> 30 -> NULL, a função deverá retornar 60.

typedef struct Node {
    int num;
    struct Node* next;
}Node;

void colocarValores (Node **head, int valor){
    Node* novo = (Node*)malloc(sizeof(Node));
    novo->num = valor;
    novo->next = NULL;
    if (*head == NULL){
        novo->next = *head;
        *head = novo;
    }else{
        Node *temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        novo->next = temp->next;
        temp->next = novo;
    }
}

int main () {
    Node* head = NULL;

    int tamanho;
    scanf("%d", &tamanho);

    for (int i = 0; i < tamanho; i++){
        int valor;

        printf("Valor: ");
        scanf("%d", &valor);
        colocarValores(&head, valor);
    }
}