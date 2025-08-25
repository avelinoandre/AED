#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int num;
    struct Node* next;
}Node;

void adicionar (Node **head, int n){
    Node *novo = (Node *)malloc(sizeof(Node));
    if (novo != NULL){
        novo->num = n;
        novo->next = *head;
        *head = novo;
    }
}

void imprimir (Node *head){
    while(head != NULL){
        printf("%d\n", head->num);
        head = head->next;
    }
}

int procurarEspecifico(Node *head, int numero){
    int presenca = 0;
    while(head != NULL){

        if (head->next == numero){
            presenca = 1;
        }

        head = head->next;
    }
    return presenca;
}

void remover (Node **head){
    if (*head != NULL){
        Node *temporaria = *head;
        *head = (*head)->next;
        free(temporaria);

    }else{
        printf("A lista já está vazia!");
    }
}

void inserirNoFinal(Node **head, int n){
    Node *novo = (Node *)malloc(sizeof(Node));
    novo->num = n;
    novo->next = NULL;
    
    if (head == NULL){
        *head = novo;
    }else{
        Node *temporario = *head;
        while (temporario != NULL){
            temporario = temporario->next;
        }
        temporario->next = novo;
    }
}
void inserirEmPosicaoEspecifica (Node **head,int valor, int posicao){
    Node *novo = (Node *)malloc(sizeof(Node));
    
    int contador = 0;
    novo->num = valor;
    novo->next = NULL;

    if (head == NULL){
        *head = novo;
    }else{
        Node *temporaria = *head;
        while (temporaria != NULL){
            if (contador == posicao - 1){
                break;
                
            }
            temporaria = temporaria->next;
            contador += 1;
        }
        novo->next = temporaria->next;
        temporaria->next = novo;
    }
}

void removerNoFinal(Node **head){
    if (*head == NULL){
        printf("Lista está vazia!");
    }else if((*head)->next == NULL){
        free(head);
    }else{
        Node *temporaria = *head;
        while (temporaria->next->next != NULL){
            temporaria = temporaria->next;
        }
        free(temporaria->next);
        temporaria->next = NULL;
    }
}

void removerEmPosicaoEspecifica(Node **head, int posicao){
    int contador = 0;

    if (*head == NULL){
        printf("Lista está vazia!");
    }else if((*head)->next == NULL){
        free(head);
    }else{
        Node *temporaria = *head;
        if (posicao == 0){
            *head = temporaria->next;
            free(temporaria);
            return;
        }
        while (temporaria != NULL){ 
            if (contador == posicao - 1){
                break;
            }
            temporaria = temporaria->next;
            contador += 1;
        }

        Node *deletar = temporaria->next;
        temporaria->next = deletar->next;
        free(deletar);
        
    }
}