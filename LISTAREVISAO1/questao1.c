#include <stdio.h>
#include <stdlib.h>

typedef struct Node {

    int num;
    struct Node *prox;

}Node;

//funções de adicionar
void adicionar (Node **head, int valor);
void adicionarNoFinal(Node **head, int valor);
void adicionarPosicaoEspecifica(Node **head, int valor, int posicao);

//funções de remover
void remover (Node **head);
void removerNoFinal (Node **head);
void removerEmPosicao(Node **head, int posicao);



int main () {

    Node *head;

    return 0;

}



void adicionar (Node **head, int valor){

    Node *novo = (Node *)malloc(sizeof(Node));

    if (novo != NULL){
        novo->num = valor;
        novo->prox = *head;
        *head = novo;
    }
}

void adicionarNoFinal(Node **head, int valor){

    Node *novo = (Node *)malloc(sizeof(Node));
    
    novo->num = valor;
    novo->prox = NULL;

    if (*head == NULL){

        *head = novo;

    }else {

        Node *temp = *head;

        while(temp->prox != NULL){

            temp = temp->prox;

        }

        temp->num = valor;

    }
}

void adicionarPosicaoEspecifica(Node **head, int valor, int posicao){

    Node *novo = (Node *)malloc(sizeof(Node));

    novo->num = valor;
    novo->prox = *head;

    if (*head == NULL){

        *head = novo;

    }else{

        Node *temp = *head;
        int cont = 0;

        while (cont != (posicao - 1)){
            
            temp = temp->prox;
            cont++;

        }

        temp->num = novo;

    }

}

void remover (Node **head){

    if (*head == NULL){

        printf("LISTA VAZIA");

    }else{

        while (*head != NULL){
            
            Node *temp = *head;
            *head = (*head)->prox;
            free(temp);

        }


    }

}

void removerNoFinal (Node **head){

    if (*head == NULL){

        printf("LISTA VAZIA");

    }else{

        Node *temp;

        while ((*head)->prox != NULL){
            temp = *head;
            *head =  (*head)->prox;
        }
        free(temp);

    }

}

void removerEmPosicao(Node **head, int posicao){

    if (*head != NULL){

        Node *temp;
        int cont = 0;

        while (cont != posicao - 1){

            temp = *head;
            *head = (*head)->prox;
            cont++;

        }

        free(temp);

    }

}

void imprimir (Node *head){

    while (head->prox != NULL){

        printf("%d -> ", head->num);

        head = head->prox;

    }

    printf("NULL.");


}