#include <stdio.h>
#include <stdlib.h>

typedef struct Node{

    char valor;
    struct Node *prox;

}Node;

void adicionar(Node **head, char valor);
void remover(Node **head);

int main(){

    int quantidade;

    while (1) {

        scanf("%d", &quantidade);
    
        if (quantidade == 0){

            break;

        }else{

            Node *entrada = NULL, *saida = NULL, *movimentos = NULL, *pilha = NULL;

            for (int i = 0; i < quantidade; i++){

                char palavra;
                
                scanf(" %c", &palavra);
                adicionar(&entrada, palavra);
            
            }

            Node *entradaOrganizada = NULL;
            
            while (entrada != NULL) {
            
                char palavra = entrada->valor;
            
                remover(&entrada);

                adicionar(&entradaOrganizada, palavra);
            
            }
            
            entrada = entradaOrganizada;

            for (int i = 0; i < quantidade; i++) {

                char palavra;

                scanf(" %c", &palavra);

                adicionar(&saida, palavra);

            }

            Node *saidaOrganizada = NULL;

            while (saida != NULL) {

                char palavra = saida->valor;

                remover(&saida);

                adicionar(&saidaOrganizada, palavra);

            }

            saida = saidaOrganizada;

            int impossivel = 0;

            while (saida != NULL) {

                if (pilha != NULL && pilha->valor == saida->valor) {
                
                    remover(&pilha);

                    remover(&saida);

                    adicionar(&movimentos, 'R');

                } else if (entrada != NULL) {
                
                    char palavra = entrada->valor;
                
                    remover(&entrada);

                    adicionar(&pilha, palavra);

                    adicionar(&movimentos, 'I');
                
                } else {

                    impossivel = 1;

                    break;

                }
            }

            Node *movimento = NULL;
            
            while (movimentos != NULL) {
            
                char palavra = movimentos->valor;
                remover(&movimentos);
                adicionar(&movimento, palavra);
            
            }

            while (movimento != NULL) {
            
                printf("%c", movimento->valor);

                remover(&movimento);
            
            }

            if (impossivel) {

                printf(" Impossible");

            }

            printf("\n");

        }

    }

    return 0;

}


void adicionar(Node **head, char valor){

    Node *novo = (Node*)malloc(sizeof(Node));

    if (novo != NULL){

        novo->valor = valor;
        novo->prox = *head;   
        *head = novo;

    }


}

void remover(Node **head){

    if (*head != NULL){

        Node *temp = *head;
    
        *head = temp->prox;

        free(temp);

    }


}