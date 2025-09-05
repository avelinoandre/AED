#include <stdio.h>
#include <stdlib.h>

typedef struct Node{

    int numero;
    struct Node *prox;

}Node;

void adicionar (Node **head, Node **tail, int valor);
int tamanho (Node *head);
void divisao(Node *head, Node *tail);

// QUESTÃO 05 - Um determinado programa será implementado em C e deve permitir
// manipular números em uma Fila. Crie uma nova função que imprima a divisão dos valores
// de duplas de nós que estão nesta fila. Se tiver uma quantidade ímpar de nós (sobrando
// um nó), para o nó restante, divida o valor dele por 10. E se a fila tiver menos que 2 nós,
// exiba a seguinte mensagem: “Tamanho da fila é insuficiente :(” e também não pode ocorrer
// divisão por zero.
// Protótipo da função: void divisão(Node *head, Node *tail);

int main (){

    Node *head = NULL;
    Node *tail = NULL;

    int quantidade;

    scanf("%d", &quantidade);


    for (int i = 0; i < quantidade; i++){
        
        int valor;
        scanf("%d", &valor);

        adicionar(&head, &tail, valor);

    }

    int situacao = verificar(head);

    if (situacao == 1){

        divisao(head, tail);

    }else{

        printf("\nLista muito pequena...");

    }

    return 0;

}

void adicionar (Node **head, Node **tail, int valor){

    Node *novo = (Node *)malloc(sizeof(Node));

    novo->numero = valor;
    novo->prox = NULL;

    if (head == NULL){
        *head = novo;
        *tail = novo;
    }else{

        (*tail)->prox= novo;
        *tail = novo;

    }

}

int tamanho (Node *head){

    int cont = 0;
    Node *temp = head;

    while (temp){

        cont += 1;
        temp = temp->prox;

    }
    
    if (cont < 2){

        return 0;

    }else{

        return 1;

    }

}

void divisao(Node *head, Node *tail){
    
    
    
    if (head == tail){

        printf("Lista está vazia!");

    }else{

        Node *temp = head;

        while (temp != NULL){

            if (temp->prox == NULL){

                printf("%d\n",temp->numero / 10);

            }else{

                if (temp->prox->numero != 0){

                    printf("%d\n", temp->numero / temp->prox->numero);

                } else{

                    printf("erro, divisao por zero.");

                }



            }
            
            temp = temp->prox->prox;

        }

    }
    



    


    


}