#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int numero;
    struct Node* ant;
    struct Node* next;
} Node;

void inserir_final(Node** header, Node** tail, int valor){

    Node* new = (Node*)malloc(sizeof(Node));
    
    if (new == NULL) return;

    new->valor = valor;

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
    int n, k, m;
    scanf("%d %d %d", &n, &k, &m);

    while (n != 0 && k!=0 && m!=0) {

        Node* header = NULL;
        Node* tail = NULL;

        for (int i = 1; i <= n; i++) {
            inserir_final(&header, &tail, i);
        }

        Node* dir = header;
        Node* esq = tail;
        int primeiro = 1;

        while (header != NULL) {

            for (int i = 1; i < k; i++){
                dir = dir->next;
            }

            for (int i = 1; i < m; i++){
                esq = esq->ant;
            }

            if (primeiro==0){
                printf(",");
            }

            primeiro = 0;

            if (dir == esq){

                printf("%3d", dir->valor);

                Node* prox = dir->next;
                Node* ant = esq->ant;

                remover_no(&header, &tail, dir);

                if (header == NULL) {
                    break;
                }
                
                dir = prox;
                esq = ant;

            } else {

                printf("%3d%3d", dir->valor, esq->valor);

                Node* direitanext = dir->next;
                Node* direitaant = dir->ant;
                Node* esquerdanext = esq->next;
                Node* esquerdaant = esq->ant;

                Node* tempdireita = dir;
                Node* tempesquerda = esq;

                remover_no(&header, &tail, tempdireita);
                remover_no(&header, &tail, tempesquerda);

                if (header == NULL){
                    break;
                }

                if (direitanext == tempesquerda){
                    dir = esquerdanext;
                }else{
                    dir = direitanext;
                } 

                if (esquerdaant == tempdireita){
                    esq = direitaant;
                }else{
                    esq = esquerdaant;
                } 
            }

        }

        printf("\n");
        scanf("%d %d %d", &n, &k, &m);
    }

    return 0;
}