#include <stdio.h>
#include <stdlib.h>

typedef struct Node{

    int numero;
    struct Node *prox;

}Node;

void imprimir(Node *head, Node *tail);

void adicionarNoInicio(Node **head, Node **tail, int valor);
void removerNoInicio(Node **head, Node **tail);

void adicionarNoFinal(Node **head, Node **tail, int valor);
void removerNoFinal(Node **head, Node **tail);

void adicionarNoMeio(Node **head, Node **tail, int valor);
void removerNoMeio(Node **head, Node **tail);

int tamanho (Node *head, Node *tail);

int main (){

    Node *head = NULL;
    Node *tail = NULL;

    // adicionarNoInicio(&head, &tail, 1);
    // adicionarNoInicio(&head, &tail, 2);
    // adicionarNoInicio(&head, &tail, 3);
    // adicionarNoInicio(&head, &tail, 4);
    // adicionarNoInicio(&head, &tail, 5);

    // imprimir(head, tail);

    // removerNoInicio(&head, &tail);

    // imprimir(head, tail);

    adicionarNoMeio(&head, &tail, 1);
    adicionarNoMeio(&head, &tail, 2);
     adicionarNoMeio(&head, &tail, 3);

    imprimir(head, tail);

    removerNoMeio(&head, &tail);

    imprimir(head, tail);

    removerNoMeio(&head, &tail);

    imprimir(head, tail);

    return 0;

}

void imprimir (Node *head, Node *tail){

    if (head != NULL){

        do{

            printf("%d -> ", head->numero);
            head = head->prox;

        }while (tail->prox != head);

        printf("NULL\n");

    }

}

void adicionarNoInicio(Node **head, Node **tail, int valor){

    Node *novo = (Node *)malloc(sizeof(Node));

    if (novo != NULL){

        novo->numero = valor;
        novo->prox = NULL;

        if (*head == NULL){

            novo->prox = *head;
            *head = novo;
            *tail = novo;

        }else{

            novo->prox = *head;
            *head = novo;
            (*tail)->prox = *head;

        }

    }

}

void removerNoInicio(Node **head, Node **tail){

    if (*head != NULL){

        if (*head == *tail){

            *head = NULL;
            *tail = NULL;

        }else{

            Node *temp = *head;

            *head = (*head)->prox;
            free(temp);

        }

    }

}

void adicionarNoFinal(Node **head, Node **tail, int valor){

    Node *novo = (Node *)malloc(sizeof(Node));

    if (novo != NULL){

        novo->numero = valor;
        novo->prox = NULL;

        if (*head == NULL){

            novo->prox = *head;
            *head = novo;
            *tail = novo;

        }else{

            (*tail)->prox = novo;
            novo->prox = *head;
            *tail = novo;

        }

    }

}

void removerNoFinal(Node **head, Node **tail){

    if (*head != NULL){

        if (*head == *tail){

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

}

int tamanho (Node *head, Node *tail){

    int cont = 0;

    while(head != tail){

        cont += 1;
        head = head->prox;

    }

    return cont;

}

void adicionarNoMeio(Node **head, Node **tail, int valor){

    Node *novo = (Node *)malloc(sizeof(Node));

    if (novo != NULL){

        novo->numero = valor;
        novo->prox = NULL;

        if (*head == NULL){

            novo->prox = *head;
            *head = novo;
            *tail = novo;

        }else{

            int parar = (tamanho(*head, *tail))/2;

            Node *temp = *head;

            for (int i = 0; i < parar; i++){

                temp = temp->prox;

            }

            Node *temp2 = temp->prox;
            temp->prox = novo;
            novo->prox = temp2;

            if (temp == *tail){

                *tail = novo;

            }

        }

    }

}

void removerNoMeio(Node **head, Node **tail){

    if (head != NULL){

        if (*head == *tail){

            free(*head);
            *head = NULL;
            *tail = NULL;

        }else{

            int parar = (tamanho(*head, *tail))/2;

            Node *temp = *head;

            for (int i = 0; i < parar - 1; i++){

                temp = temp->prox;

            }

            Node *temp2 = temp->prox;
            temp->prox = temp2->prox;
            free(temp2);

            if (temp2 == *tail){

                *tail = temp;

            }

            (*tail)->prox = *head;

        }

    }

}