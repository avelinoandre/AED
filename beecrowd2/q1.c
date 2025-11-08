#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int valor;
    struct Node *prox;
} Node;

Node *cria_lista(int N);
Node *remove_Node(Node *atual, Node *anterior);
void resolve(int N, int k, int m);

int main(){
    int N, k, m;
    while (scanf("%d %d %d", &N, &k, &m)) 
    {
        if (N == 0 && k == 0 && m == 0) 
        {
            break;
        }
        resolve(N, k, m);
    }

    return 0;

}

Node *cria_lista(int N){
    Node *inicio = NULL, *atual = NULL;
    int i;
    for (i = 1; i <= N; i++) 
    {
        Node *novo = malloc(sizeof(Node));
        novo->valor = i;
        if (!inicio) 
        {
            inicio = novo;
        } 
        else 
        {
            atual->prox = novo;
        }
        atual = novo;
    }
    if (atual) 
    {
        atual->prox = inicio;
    }
    return inicio;
}

Node *remove_Node(Node *atual, Node *anterior){
    anterior->prox = atual->prox;
    free(atual);
    return anterior->prox;
}

void resolve(int N, int k, int m){
    Node *lista = cria_lista(N);
    Node *h = lista, *a = lista;
    Node *prev_h = lista, *prev_a = lista;
    while (prev_h->prox != h)
    {
        prev_h = prev_h->prox;
    }
    while (prev_a->prox != a)
    {
        prev_a = prev_a->prox;
    }
    int restantes = N;
    int primeiro = 1;
    while (restantes > 0) 
    {
        int i;
        for (i = 1; i < k; i++) 
        {
            prev_h = h;
            h = h->prox;
        }
        for (i = 1; i < m; i++) 
        {
            prev_a = a;
            a = a->prox;
        }
        if (!primeiro) 
        {
            printf(",");
        }
        primeiro = 0;
        if (h == a) 
        {
            printf("%3d", h->valor);
            h = remove_Node(h, prev_h);
            a = h;
            prev_a = prev_h;
            restantes--;
        } 
        else 
        {
            printf("%3d%3d", h->valor, a->valor);
            Node *tmp = h->prox;
            h = remove_Node(h, prev_h);
            if (a == tmp) 
            {
                prev_a = prev_h;
            }
            a = remove_Node(a, prev_a);
            h = tmp;
            restantes -= 2;
        }
        if (restantes == 1) 
        {
            a = h;
        }
    }
    printf("\n");
}
