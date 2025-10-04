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
void removerNoMeio(Node **head);

void imprimir(Node *head);

int main (){

    struct Node *head = NULL;

    adicionarInicio(&head, 1);
    adicionarInicio(&head, 2);
    adicionarInicio(&head, 3);
    adicionarInicio(&head, 4);

    imprimir(head);

    adicionarNoMeio(&head, 9);

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

void adicionarNoMeio(Node **head, int valor){

    Node *novo = (Node *)malloc(sizeof(Node));

    if (novo != NULL){

        novo->numero = valor;
        novo->prox = NULL;
        novo->ant = NULL;

        if (*head == NULL){

            novo->prox = *head;
            *head = novo;

        }else{

            Node *temp = *head;
            int tamanho = 0;

            while(temp != NULL) {
                
                tamanho += 1;
                temp = temp->prox;

            }            

            int parar = (tamanho / 2);
                
            Node *temp2 = *head;

            for (int i = 0; i < parar; i++){

                temp2 = temp2->prox;

            }

            //1 -> 2 - > 3 -> 4
            //1-> 2 -> 9 -> 3 -> 4

            novo->prox = temp2;
            novo->ant = temp2->ant;

            temp2->ant->prox = novo;

            temp2->ant = novo;

        }

    }

}

void removerNoMeio(Node **head){

    

}

void imprimir(Node *head) {
    while(head != NULL) {
        printf("%d -> ",head->numero);
        head = head->prox;
    }
    printf("NULL\n");
}