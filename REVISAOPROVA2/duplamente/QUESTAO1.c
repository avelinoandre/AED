#include <stdio.h>
#include <stdlib.h>

typedef struct Node{

    int numero;
    struct Node *prox;
    struct Node *ant;

}Node;

void adicionarInicio (Node **head, int valor);
void removerInicio(Node **head);

void adicionarFinal(Node **head, int valor);
void removerFinal (Node **head);

void adicionarNoMeio(Node **head, int valor);
void removerNoMeio(Node **head, int valor);

void imprimir(Node *head);

int main (){

    struct Node *head = NULL;

    adicionarInicio(&head, 1);
    adicionarInicio(&head, 2);
    adicionarInicio(&head, 3);
    adicionarInicio(&head, 4);
    adicionarInicio(&head, 5);

    imprimir(head);

    adicionarFinal(&head, 0);
    removerFinal(&head);

    imprimir(head);

    return 0;

}

void adicionarInicio (Node **head, int valor){

    Node *novo = (Node *)malloc(sizeof(Node));

    if (novo != NULL){

        novo->numero = valor;
        novo->prox = NULL;
        novo->ant = NULL;

        if (*head == NULL){

            novo->prox = *head;
            novo->ant = *head;
            *head = novo;

        }else{

            novo->prox = *head;
            (*head)->ant = novo;
            *head = novo;            

        }

    }

}

void removerInicio(Node **head){

    if (head != NULL){
        
        Node *temp = *head;
        
        *head = (*head)->prox;
        free(temp);

        if (*head != NULL){

            (*head)->ant = NULL;

        }

    }



}

void adicionarFinal(Node **head, int valor){

    Node *novo = (Node *)malloc(sizeof(Node));

    if (novo != NULL){

        novo->numero = valor;
        novo->ant = NULL;
        novo->prox = NULL;


        // 1 -> 2 -> 3
        if (*head == NULL){
            
            novo->prox = *head;
            novo->ant = *head;
            *head = novo;

        }else{
            // 1 -> 2 -> 3!!
            Node *temp = *head;

            while (temp->prox != NULL){

                temp = temp->prox;

            }

            novo->ant = temp;
            temp->prox = novo;            

        }

    }

}

void removerFinal (Node **head){

    if (*head != NULL){

        
        if ((*head)->prox == NULL){
            
            free(*head);
            *head = NULL;
            
        }else{

            Node *temp = *head;

            while(temp->prox != NULL){
        
                temp = temp->prox;
        
            }
    
            temp->ant->prox = NULL;
            free(temp);

        }

    }

}

void imprimir(Node *head) {
    while(head != NULL) {
        printf("%d -> ",head->numero);
        head = head->prox;
    }
    printf("NULL\n");
}