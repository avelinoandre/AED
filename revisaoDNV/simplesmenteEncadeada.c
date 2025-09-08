#include <stdio.h>
#include <stdlib.h>

typedef struct Node{

    int numero;
    struct Node *prox;

}Node;



int main () {

    Node *head = NULL;

    return 0;

}


void adicionarInicio (Node **head, int valor){

    Node *novo = (Node *)malloc(sizeof(Node));
    
    if (novo != NULL){
        novo->numero = valor;
        novo->prox = *head;
        *head = novo;

    }

}


void adicionarFinal (Node **head, int valor){

    Node *novo = (Node *)malloc(sizeof(Node));

    novo->numero = valor;
    novo->prox = NULL;
    
    if (*head == NULL){

        *head = novo;

    }else{

        Node *temp = *head;
    
        while (temp->prox != NULL){
    
            temp = temp->prox;
    
        }
    
        if (novo != NULL){
    
            temp = novo;
    
        }
        
    }

}

void adicionarNoMeio (Node **head, int valor){
    Node *novo = (Node *)malloc(sizeof(Node));

    novo->numero = valor;
    
    int cont = 0;

    Node *temp = *head;

    while(temp->prox != NULL){

        temp = temp->prox;
        cont += 1;

    }

}


void removerNoComeco (Node **head, int valor) {

    
    if (head == NULL){
        
        printf("A lista está vazia!\n");
        
    }else{
        
        Node *temp = *head;
        *head = (*head)->prox;
        free(temp);

    }

}

void removerNoFinal (Node **head, int valor){

    if (head == NULL){

        printf("A lista está vazia!\n");

    }else{

        Node *temp = *head;

        while (temp->prox != NULL){

            temp = temp->prox;

        }

        free(temp);

    }

}

void imprimir (Node *head){

    while (head->prox != NULL){

        printf("%d -> ", head->numero);

        head = head->prox;

        if (head == NULL){

            printf("NULL.\n");

        }

    }

}