#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
      char nome[30]; 
      struct Node *prox;
} Node;


void enqueue(Node **head, Node **tail, char nome[30]);
void remover (Node **head, Node **tail, int *atendidos);
int verificarPosicaoPorNome(Node *head, char nome[30]);

int main (){

    int atendidos = 0;
    
    Node *head = NULL;
    Node *tail = NULL;
    
    while (1){
        int opcao;
        printf("-======SISTEMA MEDICO=====-\n");
        printf("Selecione oque fazer:\n");
        printf("1 - Incluir Paciente\n");
        printf("2 - Realizar atendimento do paciente\n"); //remover paciente
        printf("3 - Consultar a posicao atual do paciente pelo nome\n");
        printf("4 - Exibir a quantidade de pacientes ja atendidos\n");
        printf("5 - Sair\n");
        scanf("%d", &opcao);

        if (opcao == 1){
            char nome[30];
            printf("Informe um nome: \n");
            scanf("%s", nome);
            enqueue(&head, &tail, nome);
        }else if (opcao == 2){
            printf("Paciente atendido!\n");
            remover(&head, &tail, &atendidos);
        }else if (opcao == 3){
            char nome[30];
            printf("Informe um nome: \n");
            scanf("%s", nome);

            int posicao = verificarPosicaoPorNome(head, nome);
            if (posicao != 0){
                printf("A posicao do paciente %s e %d\n", nome, posicao);
            }else{
                printf("O paciente nao existe.\n");
            }
        }else if (opcao == 4){
            printf("%d pacientes foram atendidos\n", atendidos);
        }else if (opcao == 5){
            break;
        }else{
            printf("Opção inválida!\n");
        }
    }

    return 0;
}

void enqueue(Node **head, Node **tail, char nome[30]) {
  Node *novo = (Node *)malloc(sizeof(Node));

  if (novo != NULL) {
    strcpy(novo->nome, nome);
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

//jeito normal de fazer
// void remover (Node **head, Node **tail, int *atendidos){
//     Node *temp;

//     if (*head != NULL){
//         temp = *head;
//         *head = (*head)->prox;
//         free(temp);

//         if (*head == NULL){
//             *tail = NULL;
//         }

//         (*atendidos)++;
//     }
// }

//jeito que eu fiz
void remover (Node **head, Node **tail, int *atendidos){ 
    Node *temp; 
    if (*head == NULL){ 
        *tail = NULL; 
    }else { 
        temp = *head; 
        *head = (*head)->prox; 
        free(temp); 
        (*atendidos)++; 
        } 
    }

int verificarPosicaoPorNome(Node *head, char nome[30]){
    int posicao = 1;

    while (head != NULL){
        if (strcmp(head->nome,nome) == 0){
            return posicao;
        }
        else{ 
            posicao += 1;
            head = head->prox;
        }
    }
    
    return 0;

}