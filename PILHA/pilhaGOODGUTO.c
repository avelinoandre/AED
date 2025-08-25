#include <stdio.h>
#include <stdlib.h>


typedef struct node{
      int numero; 
      struct node *next;
} node;

int main(){
    node **head = NULL;
    return 0;
}

void insert(node **head, int numero){
    node *new = (node *) malloc(sizeof(node));

    new->next= numero;
    new->next = *head;
    *head = new;

    if(*head == NULL){
        *head = NULL;
    }else{
        (*head)->numero= new;
        *head = new;
    }


}
void remove(node **head){
    if(*head !=NULL){
        node *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

void printar(node *head){
    if(head == NULL){
        printf("lista vazia\n");
    }
    while(head!=NULL){
        printf("[%d]-> ", head->numero);
        head=head->next;
    }

}

