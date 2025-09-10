#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{

    char palavra[1001];
    struct Node *prox;

}Node;

void remover(Node **head);
void adicionar(Node **head, char nome[25001], int *cont);
void separar(Node **head, char palavras[25001], int *cont);
void bubbleSort(Node **head, int cont);
int existeNaLista(Node *head, char palavra[]);
void imprimir(Node *head);

int main () {

    int quantidade;

    scanf("%d", &quantidade);

    getchar(); 

    for (int i = 0; i < quantidade; i++) {

        Node *head = NULL;
        int cont = 0;

        char palavras[25001];

        fgets(palavras, sizeof(palavras), stdin);

        palavras[strcspn(palavras, "\n")] = '\0';

        separar(&head, palavras, &cont);

        bubbleSort(&head, cont);

        imprimir(head);

        remover(&head);
    }

    return 0;

}
void remover (Node **head){

    Node *temp;

    while (*head != NULL) {

        temp = *head;
        *head = (*head)->prox;
        free(temp);

    }

}


void adicionar (Node **head, char nome[1001], int *cont){

    Node *novo = (Node *)malloc(sizeof(Node));
    
    if (novo != NULL){

        strcpy(novo->palavra, nome);
        novo->prox = *head;
        *head = novo;

        (*cont)++;

    }

}


void separar (Node **head, char palavras[1001], int *cont){

    char *palavra;

    palavra = strtok(palavras, " ");

    while (palavra != NULL ){

        int existe = existeNaLista(*head, palavra);

        if (existe == 0){
            
            adicionar(head, palavra, cont);

        }

        palavra = strtok(NULL, " ");

    }


}


void bubbleSort(Node **head, int cont) {
    if (*head == NULL) return;

    int troca = 1;
    int i = 0;

    while (i < cont && troca == 1) {

        troca = 0;

        Node *atual = *head;

        while (atual != NULL && atual->prox != NULL) {
            if (strcmp(atual->palavra, atual->prox->palavra) > 0) {

                char temp[1001];

                strcpy(temp, atual->palavra);

                strcpy(atual->palavra, atual->prox->palavra);

                strcpy(atual->prox->palavra, temp);

                troca = 1;
            }

            atual = atual->prox;

        }

        i++;

    }

}

int existeNaLista(Node *head, char palavra[]) {

    while (head != NULL) {

        if (strcmp(head->palavra, palavra) == 0) {

            return 1;
        }
        head = head->prox;
    }

    return 0;

}

void imprimir(Node *head) {

    while (head != NULL) {

        printf("%s", head->palavra);

        if (head->prox != NULL) {

            printf(" ");

        }

        head = head->prox;

    }

    printf("\n");

}