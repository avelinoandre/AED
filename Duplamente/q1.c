#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int valor;
    struct Node *prox;
    struct Node *ant;
} Node;

void adicionarOrdenado(Node **head, int valor);
void imprimir(Node *head);

int main() {
    Node *head = NULL;

    for (int i = 0; i < 4; i++) {
        int num;
        scanf("%d", &num);
        adicionarOrdenado(&head, num);
    }

    imprimir(head);

    return 0;
}

void imprimir(Node *head) {
    while (head != NULL) {
        printf("%d\n", head->valor);
        head = head->prox;
    }
}

void adicionarOrdenado(Node **head, int valor) {
    Node *novo = (Node *)malloc(sizeof(Node));

    if (novo != NULL){

        novo->valor = valor;
        novo->prox = NULL;
        novo->ant = NULL;

        if (*head == NULL) {
            *head = novo;
        }

        Node *temp = *head;

        if (valor < temp->valor) {
            novo->prox = temp;
            temp->ant = novo;
            *head = novo;
        }

        while (temp->prox != NULL && temp->prox->valor < valor) {

            temp = temp->prox;

        }

        novo->prox = temp->prox;
        novo->ant = temp;

        if (temp->prox != NULL) {

            temp->prox->ant = novo;

        }

        temp->prox = novo;
    }


    }


void adicionar (Node **head, int numero){

    Node *novo = (Node *)malloc(sizeof(Node));

    if (novo != NULL){

        novo->valor = numero;
        novo->prox = *head;
        novo->ant = NULL;

        if (*head == NULL){

            *head = novo;

        }else{

            (*head)->ant = novo;

        }

    }

}

void AdicionarAlternado(Node **head1, Node **head2, Node **head3){

    Node *temp1 = *head1;
    Node *temp2 = *head2;

    while(temp1 != NULL || temp2 != NULL){

        if(temp1 != NULL){

            adicionar(head3, temp1->valor);
            temp1 = temp1->prox;

        }

        if(temp2 != NULL){

            adicionar(head3, temp2->valor);
            temp2 = temp2->prox;

        }
    }
}



void quantidadeDeNos(Node *head, int valor) {

    if (head != NULL) {

        Node *depois = head;
        Node *antes = NULL;

        while (depois != NULL) {

            if (depois->valor == valor) {
                break;
            }

            depois = depois->prox;

        }


        if (depois == NULL) {
            return;
        }

        antes = depois;

        int qntAntes = 0;

        while (antes->ant != NULL) {
            qntAntes++;
            antes = antes->ant;
        }

        int qntDepois = 0;

        while (depois->prox != NULL) {
            qntDepois++;
            depois = depois->prox;
            
        }


        printf("\nantes: %d\n", qntAntes);
        printf("apos: %d\n", qntDepois);

        
    }
}
    