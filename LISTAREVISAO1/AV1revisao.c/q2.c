#include <stdio.h>
#include <stdlib.h>


typedef struct Node {

    int numero;
    struct Node *prox;

}Node;


int main () {

    Node *head = NULL;
    Node *tail = NULL;

    return 0;

}


void adicionar (Node **head, Node **tail, int valor){

    Node *novo = (Node *)malloc(sizeof(Node));

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


void questaoToda (Node **head, Node **tail, Node **head1, Node **tail1, Node **head2, Node **tail2, int referencia){

    int cont = 0;
    int verdade = 0;
    Node *temp = *head;

    while (temp->prox != NULL){

        if (temp->numero == referencia){
            
            verdade = 1;
            
        }
        temp = temp->prox;
        cont += 1;

    }

    if (cont < 2){

        printf("Tamanho da lista inválido!\n");

    }else{

        if (verdade == 1){

            Node *temp1 = *head;

            while(temp1->prox->prox->numero != referencia){

                Node *novo1 = (Node *)malloc(sizeof(Node));
    
                novo1->numero = temp1->numero;
                novo1->prox = NULL;

                if (*head1 == NULL){

                    *head1 = novo1;
                    *tail1 = novo1;

                }else{

                    (*tail1)->prox = novo1;
                    *tail1 = novo1;

                }

                temp1 = temp1->prox;

            }while (temp1->prox != NULL){

                Node *novo2 = (Node *)malloc(sizeof(Node));
    
                novo2->numero = temp1->numero;
                novo2->prox = NULL;

                if (*head2 == NULL){

                    *head2 = novo2;
                    *tail2= novo2;

                }else{

                    (*tail2)->prox = novo2;
                    *tail2 = novo2;

                }

                temp1 = temp1->prox;

            }

        }
        
    }

    if (cont % 2 == 0 ){

        Node *temp2 = *head;

        for (int i = 0; i < cont/2; i++){

            Node *novo1 = (Node *)malloc(sizeof(Node));
    
                novo1->numero = temp2->numero;
                novo1->prox = NULL;

                if (*head1 == NULL){

                    *head1 = novo1;
                    *tail1= novo1;

                }else{

                    (*tail1)->prox = novo1;
                    *tail1 = novo1;

                }

            temp2 = temp2->prox;

        } while (temp2->prox != NULL){

            Node *novo2 = (Node *)malloc(sizeof(Node));
    
                novo2->numero = temp2->numero;
                novo2->prox = NULL;

                if (*head2 == NULL){

                    *head2 = novo2;
                    *tail2= novo2;

                }else{

                    (*tail2)->prox = novo2;
                    *tail2 = novo2;

                }

            temp2 = temp2->prox;

        }

    }else if (cont % 2 != 0){

        Node *temp3 = *head;

        for (int i = 0; i < ((cont - 1)/2 + 1); i++){

            Node *novo1 = (Node *)malloc(sizeof(Node));
    
                novo1->numero = temp3->numero;
                novo1->prox = NULL;

                if (*head1 == NULL){

                    *head1 = novo1;
                    *tail1= novo1;

                }else{

                    (*tail1)->prox = novo1;
                    *tail1 = novo1;

                }

            temp3 = temp3->prox;

        } while (temp3->prox != NULL){

            Node *novo2 = (Node *)malloc(sizeof(Node));
    
                novo2->numero = temp3->numero;
                novo2->prox = NULL;

                if (*head2 == NULL){

                    *head2 = novo2;
                    *tail2= novo2;

                }else{

                    (*tail2)->prox = novo2;
                    *tail2 = novo2;

                }

            temp3 = temp3->prox;

        }


    }


}
