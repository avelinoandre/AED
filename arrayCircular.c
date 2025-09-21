#include <stdio.h>
#include <stdlib.h>

typedef struct Node{

    int valor;
    struct Node *prox;

}Node;

int main (){
    int tamanho;
    scanf("%d", &tamanho);
    int array[tamanho];

    for (int i = 0; i < tamanho; i++){
        scanf("%d", &array[i]);
    }
    
    for (int j = 0; j < tamanho; j++){
        int temporaria = array[j];
        array[j] = array[j + 1];
        
    }

}


void removerNoFinal(Node **head, Node **tail){

    if(*head == NULL){

        *tail = NULL;

    }
    if((*head)->prox == *head){

        free(*head);
        *head = NULL;
        *tail = NULL;
        
        
    }else{

        Node *temp = *head;

        while(temp->prox != *tail){

            temp = temp->prox;

        }

        free(*tail);
        *tail = temp;
        (*tail)->prox = *head;

    }

}



void adicionarNoFinal(Node **head, Node **tail, int valor){

    Node *novo = (Node *)malloc(sizeof(Node));

    if(novo != NULL){

        novo->valor = valor;
        novo->prox = *head;

        if(*head == NULL){

            *head = novo;
            *tail = novo;
            novo->prox = novo;

        }else{

            (*tail)->prox = novo;
            *tail = novo;

        }
    }
}

