#include <stdio.h>
#include <stdlib.h>


// 1 — Soma dos elementos de uma lista encadeada
// Implemente uma função em linguagem C que receba uma lista encadeada de números inteiros e retorne a soma de todos os seus elementos.
// EX: Se a lista contiver os elementos 10 -> 20 -> 30 -> NULL, a função deverá retornar 60.

typedef struct node {
    int num;
    struct node *next;
} node;

void add(node **head, int num);
void listar(node **head);
int somar(node **head);
void limpar(node **head);

int main() {
    node *head = NULL;

    listar(&head);

    add(&head, 10);
    add(&head, 20);
    add(&head, 30);

    listar(&head);

    printf("Soma: %d\n", somar(&head));
    
    limpar(&head);

    listar(&head);

    return 0;
}

void add(node **head, int num) {
    node *novoNum = (node *)malloc(sizeof(node));
    novoNum->num = num;
    novoNum->next = NULL;

    if (*head == NULL) {
        novoNum->next = *head;
        *head = novoNum;
    } else {
        node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        novoNum->next = temp->next;
        temp->next = novoNum;
    }

}

// HEAD -> NULL
// HEAD -> 10 -> NULL
// HEAD -> 10 -> 20 -> NULL
// HEAD -> 10 -> 20 -> 30 -> NULL

void listar(node **head) {
    node *temp = *head;
    if (*head == NULL) {
        printf("\nLista Vazia\n\n");
    }

    while (temp != NULL) {
        printf("%d\n", temp->num);
        temp = temp->next;
    }
}

int somar(node **head) {
    node *temp = *head;

    int soma = 0;
    while(temp != NULL) {
        soma += temp->num;
        temp = temp->next;
    }
    
    return soma;
}

void limpar(node **head) {
    node *temp;
    
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}




// HEAD(NULL) -> NULL

// HEAD -> 1 -> NULL

// HEAD -> 1 -> 2 -> NULL

// HEAD -> 1 -> 2 -> 3 -> NULL

//[num, char, struct node *next]