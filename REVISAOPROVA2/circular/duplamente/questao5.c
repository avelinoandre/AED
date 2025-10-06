#include <stdio.h>
#include <stdlib.h>

typedef struct Node{

    int numero;
    struct Node *prox;
    struct Node *ant;

}Node;

void adicionarNoInicio (Node **head, Node **tail, int valor);
void removerNoInicio (Node **head, Node **tail);

void imprimir(Node*head, Node *tail);

int main (){

    Node *head = NULL;
    Node *tail = NULL;

    adicionarNoInicio(&head, &tail, 1);
    adicionarNoInicio(&head, &tail, 2);
    adicionarNoInicio(&head, &tail, 3);
    adicionarNoInicio(&head, &tail, 4);
    adicionarNoInicio(&head, &tail, 5);

    imprimir(head, tail);

    removerNoInicio(&head, &tail);

    imprimir(head, tail);

    removerNoInicio(&head, &tail);
    
    imprimir(head, tail);

    removerNoInicio(&head, &tail);

    imprimir(head, tail);

    removerNoInicio(&head, &tail);

    imprimir(head, tail);

    removerNoInicio(&head, &tail);

    imprimir(head, tail);

    return 0;
}

void imprimir(Node*head, Node *tail) {
    if(head != NULL){

        do{

            printf("%d -> ",head->numero);
            head = head->prox;

        }while(head != tail->prox);

        printf("NULL\n");

    }else{

        printf("VAZIA!!!");

    }

}

void adicionarNoInicio (Node **head, Node **tail, int valor){

    Node *novo = (Node *)malloc(sizeof(Node));

    if (novo != NULL){

        novo->numero = valor;
        novo->prox = NULL;
        novo->ant = NULL;

        if (*head == NULL){
            
            *head = novo;
            *tail = novo;
            novo->prox = *head;
            novo->ant = *head;

        }else{

            novo->prox = *head;
            novo->ant = *tail;
            (*head)->ant = novo;
            (*tail)->prox = novo;
            *head = novo;

        }

    }

}

void removerNoInicio (Node **head, Node **tail){

    if (*head != NULL){

        if (*head == *tail){

            free(*head);
            *head = NULL;
            *tail = NULL;

        }else{

            Node *temp = *head;
            *head = (*head)->prox;
            (*tail)->prox = *head;
            free(temp);

        }

    }

}

void adicionarNoFinal (Node **head, Node **tail, int valor){

    Node *novo = (Node *)malloc(sizeof(Node));

    if (novo != NULL){

        novo->numero = valor;
        novo->prox = NULL;
        novo->ant = NULL;

        if (*head == NULL){

            novo->prox = novo;
            novo->ant = novo;
            *tail = novo;
            *head = novo;

        }else{

            novo->prox = *head;
            novo->ant = *tail;
            (*tail)->prox = novo;
            (*head)->ant = novo;
            *tail = novo;

        }

    }


}

void removerNoFinal(Node **head, Node **tail){

    if (head != NULL){

        if (*head == *tail){

            free(*head);
            *head = NULL;
            *tail = NULL;

        }else{

            Node *temp = *tail;
            *tail = (*tail)->ant;
            free(temp);
            (*tail)->prox = *head;
            (*head)->ant = *tail;

        }

    }

}
