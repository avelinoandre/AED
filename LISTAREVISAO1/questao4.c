///QUESTÃO 04 - Considere que um programa em C manipula duas Filas (Fila01 e Fila02) e
//agora é necessário que seja implementada uma nova função que verifique se existem
//valores repetidos entre as filas, caso tenha valor repetido, deve ser removido apenas da
//Fila2;.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{

    int numero;
    struct Node *prox;

}Node;

void adicionarNaFila (Node **head, Node **tail, int valor);




int main () {

    Node *head1 = NULL;
    Node *tail1 = NULL;

    Node *head2 = NULL;
    Node *tail2 = NULL;


    return 0;
}

void adicionarNaFila (Node **head, Node **tail, int valor){
    Node *novo = (Node *)malloc(sizeof(Node));
    

    if (novo) {

        novo->numero = valor;
        novo->prox = NULL;

        if (*head == NULL){

            *head = novo;
            *tail = novo;

        }else{

            (*tail)->prox = novo;
            *tail = novo; 

        }

    }

}

void verificarSeExisteIgual(Node *head, Node **head2, Node **tail2){

    Node *temp1 = head;
    
    while (temp1 != NULL){
        
        Node *temp2 = *head2;

        
            while (temp2 != NULL){

                if (temp1->numero == temp2->numero){

                    removerValorEspecifico(head2, tail2, temp2->numero);

                }

                temp2 = temp2->prox;
            }

            temp1 = temp1->prox;

    }

}



void removerValorEspecifico (Node **head, Node **tail, int valor){ 
    Node *temp = *head;

    if (*head == NULL){ 
        
        *tail = NULL; 

    }
    
    else { 
        while (temp != NULL){
            if (temp->numero == valor){
                free(temp); 
            }
            *head = (*head)->prox;
        }

        } 
    }


void remover(Node **head, Node **tail, int valor) {
    Node *atual = *head;
    Node *anterior = NULL;

    while (atual != NULL) {
        if (atual->numero == valor) {
            if (anterior == NULL) {

                *head = atual->prox;

                if (*head == NULL) {

                    *tail = NULL;

                }
            } 

            else {

                anterior->prox = atual->prox;
                if (atual == *tail) {
                    *tail = anterior;
                }
            }

            free(atual);
            return;
        }

        anterior = atual;
        atual = atual->prox;
    }
}
