#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int valor;
    struct Node *prox;
}Node;

void adicionar (Node **head, int n);

int main (){
    Node *head = NULL;

    while (1){
        int opcao;
        printf("Oque você deseja fazer? \n1 - Adicionar\n2 - Printar base\n3 - Printar Topo\n4 - Printar os pares\n5 - Remover\n 6 - Sair");
        scanf("%d", &opcao);
        if (opcao == 6){
            break;
        }else if (opcao == 1){
            int valor;
            printf("Qual valor você deseja adicionar: ");
            scanf("%d", &valor);
            adicionar(&head, valor);
        }else if (opcao == 2){
            imprimirBase(head);
        }else if (opcao == 3){
            imprimirTopo(head);
        }else if (opcao == 4){
            imprimirNumerosPares(head);
        }else if (opcao == 5){
            remover(&head);
        }
    }

    return  0;
}


void adicionar (Node **head, int n){
    Node *novo = (Node *)malloc(sizeof(Node));
    novo->valor = n;
    novo->prox = *head;
    *head = novo;

    if (*head == NULL){
        *head = novo;
    }else{
        (*head)->valor = novo;
        *head = novo;
    }
}

void remover (Node **head){
    Node *temp;
    if (*head != NULL){
        temp = *head;
        *head = (*head)->prox;
        free(temp);
    }else {
        printf("Pilha está vazia!\n");
    }                      
}

void imprimirTopo (Node *head){
    while (head != NULL){
        printf("%d -> ", head->valor);
        head = head->prox;
    } printf("NULL\n");
}

void imprimirBase (Node *head){
    while (head != NULL){
        if (head->prox == NULL){
            printf("%d e o ultimo valor da pilha.\n", head->valor);
        }
    }
}

void imprimirNumerosPares (Node *head){
    while (head != NULL){
        if ((head->valor) % 2 == 0){
            printf("%d -> ", head->valor);
        }
    }
}