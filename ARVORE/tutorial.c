#include <stdio.h>
#include <stdlib.h>

typedef struct tree{

    int value;
    struct tree *left;
    struct tree *right;

}tree;


int main(){
    
}

void add(tree **root, int number){

    if (*root == NULL){
        
        *root = (tree *)malloc(sizeof(tree));
        (*root)->left = NULL;
        (*root)->right = NULL;
        (*root)->value = number;

    }else{

        if (number < (*root)->value){

            add(&(*root)->left, number);

        }else if (number < (*root)->value){

            add(&(*root)->right, number);

        }

    }

}

void imprimirPreOrdem (tree *root){

    if (root == NULL){

        printf("Tree is clean.\n");

    }else{

        printf("%d ", root->value);
        imprimir(root->left);
        imprimir(root->right);

    }

}

void imprimirEmOrdem (tree *root){

    if (root == NULL){

        printf("Tree is clean.\n");

    }else{

        imprimir(root->left);
        printf("%d ", root->value);
        imprimir(root->right);

    }

}

void imprimirPosOrdem (tree *root){

    if (root == NULL){

        printf("Tree is clean.\n");

    }else{

        imprimir(root->left);
        imprimir(root->right);
        printf("%d ", root->value);

    }

}

int buscar(tree *root, int number){

    if (root == NULL){

        return 0;

    }else if (root->value == number){

        return 1;

    }else if (number < root->left){

        return buscar(root->left, number);

    }else{

        return buscar(root->right, number);

    }

}
