#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int numero;
    struct Node *prox;
} Node;


void adicionarNasFilas (Node **head, Node **tail, int n);
void imprimirNumeros (Node *head1, Node *head2, int filaIndisponivel);

int main (){

    Node *head1 = NULL;
    Node *tail1 = NULL;

    Node *head2 = NULL;
    Node *tail2 = NULL;

    int quantidade1, quantidade2, filaIndisponivel;

    scanf("%d", &quantidade1);
    scanf("%d", &quantidade2);
    scanf("%d", &filaIndisponivel);

    for (int i = 0; i < quantidade1; i++){
        int n;
        scanf("%d", &n);
        adicionarNasFilas(&head1, &tail1, n);
    }
     for (int j = 0; j < quantidade2; j++){
        int n;
        scanf("%d", &n);
        adicionarNasFilas(&head2, &tail2, n);
    }

    imprimirNumeros (head1, head2, filaIndisponivel);

    return 0;
}

void adicionarNasFilas (Node **head, Node **tail, int n){
    Node *novo = (Node *)malloc(sizeof (Node));

    if (novo != NULL){

        novo->numero = n;
        novo->prox = NULL;

        if (*head == NULL){
            *head = novo;
            *tail = novo;

        }else {
            (*tail)-> prox = novo;
            *tail = novo;
        }
    }
}

void imprimirNumeros (Node *head1, Node *head2, int filaIndisponivel){

    if (filaIndisponivel == 2){
        while (head1 != NULL || head2 != NULL){
            if (head1 != NULL){
                printf("%d\n", head1->numero);
                head1 = head1->prox;
            }
            if (head2 != NULL){
                printf("%d\n", head2->numero);
                head2 = head2->prox;
            }
        }

    }else if (filaIndisponivel == 1){
        while (head1 != NULL || head2 != NULL){
            if (head2 != NULL){
                printf("%d\n", head2->numero);
                head2 = head2->prox;
            }
            if (head1 != NULL){
                printf("%d\n", head1->numero);
                head1 = head1->prox;

            }
        }
    }
}