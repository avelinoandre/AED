#include <stdio.h>
#include <stdlib.h>

typedef struct tree{

    int value;
    struct tree *right;
    struct tree *left;

}tree;

int main (){

}

void maiorValor(tree *root, int *number){

    if (root == NULL){

        return;

    }if (*number < root->value){

        *number = root->value;

    }

        return maiorValor(root->left, number);
        return maiorValor(root->right, number);

}

void alturaDaArvore(tree *root, int nivelAtual, int *alturaMaxima) {
    if (root == NULL){
        
        return;
    }

    if (nivelAtual > *alturaMaxima){
        
        *alturaMaxima = nivelAtual;

    }

    alturaDaArvore(root->left, nivelAtual + 1, alturaMaxima);
    alturaDaArvore(root->right, nivelAtual + 1, alturaMaxima);
}

void imprimir(tree *root) {
    if (root == NULL)

        return;

    if (root->left == NULL && root->right == NULL) {

        printf("%d ", root->value);
        return;

    }

    imprimir(root->left);
    imprimir(root->right);
    
}