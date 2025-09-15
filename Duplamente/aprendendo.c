#include <stdio.h>
#include <stdlib.h>

typedef struct Node{

    int valor;
    struct Node *prox;
    struct Node *ant;


}Node;

int main (){


    Node *head = NULL;

    return 0;

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

void imprimir (Node *head){

    while (head != NULL){

        int array[] = {10, 20, 30, 40, 50};
        int tamanho = sizeof(array) / sizeof(array[0]);

        printf("Array de trás pra frente:\n");
        for (int i = tamanho - 1; i >= 0; i--) {
            printf("%d ", array[i]);
        }

        printf("\n");

        return 0;

    }

}

void imprimirDoFinal (Node *head){


    if (head == NULL){

        printf("Lista vazia...");

    }else{
        
        Node *temp = head;
    
        while (temp->prox != NULL){
    
            temp = temp->prox;
    
        }
    
        while (temp != NULL){
    
            printf("%d -> ", temp->valor);
    
            temp = temp->ant;
    
        }
        
    }

}


void removerNoInicio (Node **head){

    if (*head == NULL){

        printf("Lista vazia...");

    }else{

        Node *temp = *head;

        *head = (*head)->prox;
        
        free(temp);

        if (*head != NULL){

            (*head)->ant = NULL;

        }


    }

}

void removerNoFinal(Node **head) {
    if (*head == NULL) {

        printf("Lista vazia...\n");
        return;

    }

    Node *temp = *head;

    if (temp->prox == NULL) {
        free(temp);
        *head = NULL;
        return;
    }

    while (temp->prox != NULL) {
        temp = temp->prox;
    }

    temp->ant->prox = NULL;
    free(temp);
}

void adicionarNoFinalComTail(Node **head, Node **tail, int valor) {
    Node *novo = (Node*)malloc(sizeof(Node));

    novo->valor = valor;
    novo->prox = NULL;
    novo->ant = *tail;

    if (*tail != NULL) {

        (*tail)->prox = novo;

    } else {

        *head = novo;

    }

    *tail = novo;
}


void removerNoFinalComTail(Node **head, Node **tail) {
    if (*tail == NULL) {

        printf("Lista vazia...\n");
        return;

    }

    Node *temp = *tail;

    if (*head == *tail) {  

        *head = NULL;
        *tail = NULL;

    } else {

        *tail = temp->ant;
        (*tail)->prox = NULL;

    }

    free(temp);
}


void inserirNoFinal(Node **head, int valor) {
    Node *novo = (Node*)malloc(sizeof(Node));
    
    novo->valor = valor;
    novo->prox = NULL;
    novo->ant = NULL;

    if (*head == NULL) {

        *head = novo;
        return;

    }

    Node *temp = *head;
    while (temp->prox != NULL) {  
        temp = temp->prox; 
    }

    temp->prox = novo;
    novo->ant = temp;

}