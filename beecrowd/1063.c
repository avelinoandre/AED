#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char vagao;
    struct Node *prox;
} Node;

void adicionar(Node **head, char valor);
void remover(Node **head);
char topoPilha (Node *head);

int main() {

    int quantidade;

    while (scanf("%d", &quantidade) && quantidade != 0) {

        char entrada[1001], saida[1001];

        scanf("%s", entrada);

        scanf("%s", saida);

        Node *head = NULL;
        char operacoes[2002];
        int letras = 0;

        int i = 0, j = 0;
        int possivel = 1;

        while (j < quantidade) {

            if (topoPilha(head) == saida[j]) {

                remover(&head);

                operacoes[letras++] = 'R';

                j++;

            } else if (i < quantidade ) {

                adicionar(&head, entrada[i++]);

                operacoes[letras++] = 'I';

            } else {

                possivel = 0;

                break;

            }
        }

        if (possivel) {

            operacoes[letras] = '\0';

            printf("%s\n", operacoes);

        } else {

            printf("Impossible\n");

        }

        while (head != NULL) {
            
            remover(&head);
            
            }

    }

    return 0;
}


void adicionar(Node **head, char valor) {
    Node *novo = (Node *)malloc(sizeof(Node));

    if (novo != NULL) {

        novo->vagao = valor;
        novo->prox = *head;
        *head = novo;

    }

}

void remover(Node **head) {

    if (*head != NULL) {

        Node *temp = *head;
        *head = (*head)->prox;
        free(temp);

    }
}

char topoPilha (Node *head) {

    if (head != NULL){

        return head->vagao;

    }else {

        return '\0';

    }
}
