#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int num;
    struct Node* next;
}Node;

// void colocarValores (Node **head, int valor){
//     Node* novo = (Node*)malloc(sizeof(Node));
//     novo->num = valor;
//     novo->next = NULL;
//     if (*head == NULL){
//         novo->next = *head;
//         *head = novo;
//     }else{
//         Node *temp = *head;
//         while(temp->next != NULL){
//             temp = temp->next;
//         }
//         novo->next = temp->next;
//         temp->next = novo;
//     }
// }

//ordenando colocando diretamente
void colocarValores (Node **head, int valor){
    Node* novo = (Node*)malloc(sizeof(Node));
    novo->num = valor;
    novo->next = NULL;
    if (*head == NULL || valor < (*head)->num){
        novo->next = *head;
        *head = novo;
    }else{
        Node *temp = *head;
        while(temp->next != NULL && valor > temp->next->num){
            temp = temp->next;
        }
        novo->next = temp->next;
        temp->next = novo;
    }
}

void listar (Node **head){
    Node *temp = *head;
    while (temp != NULL){
        printf("%d\n",temp->num);
        temp = temp->next;
    }
}

void deletar (Node **head){
    Node *temp = *head;
    while(*head != NULL){
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main (){
    Node *head = NULL;
    colocarValores(&head, 50);
    colocarValores(&head, 10);
    colocarValores(&head, 20);
    colocarValores(&head, 40);

    listar(&head);
    deletar(&head);

    return 0;
}