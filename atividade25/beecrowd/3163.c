#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {

    char aviao[10];
    int local; 
    struct Node* prox;

} Node;

void adicionar (Node **head, Node** tail, char aviao[], int ponto);
void remover(Node **head, Node** tail);
void organizar(Node **headFinal, Node **tailFinal,Node **headNorte, Node **tailNorte,Node **headSul, Node **tailSul,Node **headLeste, Node **tailLeste,Node **headOeste, Node **tailOeste);
void imprimir(Node *head);

int main() {
    Node *headNorte = NULL; 
    Node *tailNorte = NULL;

    Node *headSul = NULL; 
    Node *tailSul = NULL;

    Node *headLeste = NULL; 
    Node *tailLeste = NULL;

    Node *headOeste = NULL; 
    Node *tailOeste = NULL;

    Node *headFinal = NULL;
    Node *tailFinal = NULL;

    int localAtual = 0;  
    char entrada[20];

    while (1) {
        scanf("%s", entrada);

        if (strcmp(entrada, "0") == 0) {
            break;
        }

        if (entrada[0] == '-') {

            if (strcmp(entrada, "-1") == 0) {

                localAtual = -1;

            } 
            else if (strcmp(entrada, "-2") == 0) {

                localAtual = -2;

            } 
            else if (strcmp(entrada, "-3") == 0) {

                localAtual = -3;

            } 
            else if (strcmp(entrada, "-4") == 0) {

                localAtual = -4;

            } 
            else {

                localAtual = 0;

            }
        }

        else { 

            if (localAtual == 0) {

                continue;

            }

            if (localAtual == -1) {

                adicionar(&headOeste, &tailOeste, entrada, localAtual); 

            } 
            else if (localAtual == -2) {
                
                adicionar(&headSul, &tailSul, entrada, localAtual); 
                
            } 
            else if (localAtual == -3) {

                adicionar(&headNorte, &tailNorte, entrada, localAtual); 

            } 
            else if (localAtual == -4) {

                adicionar(&headLeste, &tailLeste, entrada, localAtual); 

            }
        }
    }

    organizar(&headFinal, &tailFinal,&headNorte, &tailNorte,&headSul, &tailSul,&headLeste, &tailLeste,&headOeste, &tailOeste);

    imprimir(headFinal);

    return 0;
}

void adicionar(Node **head, Node **tail, char aviao[], int posicao) {
    Node *novo = (Node*) malloc(sizeof(Node));
    
    if (novo != NULL){

        strcpy(novo->aviao, aviao);
        novo->local = posicao;
        novo->prox = NULL;

        if (*head == NULL) {
            
            *head = novo;
            *tail = novo;

        } else {

            (*tail)->prox = novo;
            *tail = novo;

        }
    }
}

void remover(Node **head, Node **tail) {

    if (*head == NULL){
        return;
    }

    Node* temp = *head;

    *head = temp->prox;

    free(temp);

    if (*head == NULL){

        *tail = NULL;

    }

  }

void organizar(Node **headFinal, Node **tailFinal,Node **headNorte, Node **tailNorte,Node **headSul, Node **tailSul,Node **headLeste, Node **tailLeste,Node **headOeste, Node **tailOeste){

    while (*headOeste || *headNorte || *headSul || *headLeste) {

        if (*headOeste) {
            adicionar(headFinal, tailFinal, (*headOeste)->aviao, (*headOeste)->local);
            remover(headOeste, tailOeste);
        }
        if (*headNorte) {
            adicionar(headFinal, tailFinal, (*headNorte)->aviao, (*headNorte)->local);
            remover(headNorte, tailNorte);
        }
        if (*headSul) {
            adicionar(headFinal, tailFinal, (*headSul)->aviao, (*headSul)->local);
            remover(headSul, tailSul);
        }
        if (*headLeste) {
            adicionar(headFinal, tailFinal, (*headLeste)->aviao, (*headLeste)->local);
            remover(headLeste, tailLeste);
        }
    }
}

void imprimir(Node *head) {
    Node* temp = head;

    while (temp != NULL) {

        printf("%s", temp->aviao);
        
        temp = temp->prox;

        if (temp != NULL){
            printf(" ");
        }  
    }
    printf("\n");
}