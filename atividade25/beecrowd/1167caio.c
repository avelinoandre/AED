#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int valor;
    char nome[50];
    struct Node* ant;
    struct Node* next;
} Node;

void inserir_final(Node** header, Node** tail, int valor, char nome[]){

    Node* new = (Node*)malloc(sizeof(Node));

    if (new == NULL){
        return;
    }

    new -> valor = valor;
    strcpy(new->nome,nome);

    if (*header == NULL) {
        new->next = new;
        new->ant = new;
        *header = new;
        *tail = new;
        return;
    }

    new->ant = *tail;
    new->next = *header;
    (*tail)->next = new;
    (*header)->ant = new;
    *tail = new;

}

void remover_no(Node** header, Node** tail, Node* posi){

    if (*header == NULL || posi == NULL){
        return;
    }

    if (posi->next == posi){
        free(posi);
        *header = NULL;
        *tail = NULL;
        return;
    }

    if (posi == *header){
        *header = posi->next;
    } 

    if (posi == *tail){
        *tail = posi->ant;
    }

    posi->ant->next = posi->next;
    posi->next->ant = posi->ant;

    free(posi);
}


int main(){

    int n;
    char nome[50];
    int valor;

    while (scanf("%d", &n) == 1 && n != 0){

        Node* header = NULL;
        Node* tail = NULL;

        for (int i = 0; i < n; i++) {
            scanf("%s", nome);
            scanf("%d", &valor);
            inserir_final(&header, &tail, valor, nome);
        }

        if (header == NULL) {
            printf("Vencedor(a): \n");
            continue;
        }

        Node* aux = header;
        int chavevalor = aux->valor;

        while (header != tail) {
  
            if (chavevalor % 2 == 0) {
                
                for(int i = 0;i <chavevalor;i++){
                    aux = aux -> ant;
                }

            } else {
                
                for(int i = 0;i <chavevalor;i++){
                    aux = aux -> next;
                }

            }

            chavevalor = aux -> valor;

            Node* temp = aux -> next;

            if(chavevalor % 2 != 0){
                temp = aux -> ant;
            }

            remover_no(&header,&tail,aux);
            aux = temp;
            
        }

        printf("Vencedor(a): %s\n", header->nome);
        free(header);

        header = NULL;
        tail = NULL;
    }

    return 0;
}