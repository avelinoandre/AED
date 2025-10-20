#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int numero;
    int chegada;
    struct Node* prox;
    struct Node* ant;
} Node;

void inserir_final(Node** header, int valor, int chegada){

    Node* new = (Node*)malloc(sizeof(Node));

    if (new==NULL){
        return;
    }

    new -> ant = NULL;
    new -> valor = valor;
    new -> chegada = chegada;
    new -> next = NULL;

    if (*header == NULL){
        *header = new;
        return;
    }

    Node* aux = *header;

    while (aux -> next != NULL){
        aux = aux -> next;
    }

    new -> ant = aux;
    aux -> next = new;
}

void remover_comeco(Node** header){

    if (*header==NULL){
        return;
    }   


    Node* aux = *header;

    if (aux -> next == NULL){
        *header = NULL;
        free(aux);
        return;
    }

    *header = aux -> next;
    aux -> next -> ant = NULL;
    free(aux);

}

int main(){

    int N;

    while(scanf("%d",&N)==1 && N>0){

        Node* fila=NULL;

        int H,M,C;

        for(int i=0;i<N;i++){

            scanf("%d %d %d",&H,&M,&C);

            int chegada = (H-7)*60 + M; 

            inserir_final(&fila, C , chegada);

        }

        int tempo_atual=0; 
        int criticos=0;

        while(fila!=NULL){

            Node* aux = fila;
            
            if(aux -> chegada > tempo_atual){

                tempo_atual = aux  -> chegada;

                if(tempo_atual % 30 != 0 ){
                    tempo_atual += 30 - (tempo_atual % 30);
                }
            }

            if(tempo_atual - aux -> chegada > aux -> valor){
                criticos++;
            }

            remover_comeco(&fila); 

            tempo_atual += 30; 
        }

        printf("%d\n",criticos);
    }

    return 0;
}