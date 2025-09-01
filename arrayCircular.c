#include <stdio.h>
#include <stdlib.h>

int main (){
    int tamanho;
    scanf("%d", &tamanho);
    int array[tamanho];

    for (int i = 0; i < tamanho; i++){
        scanf("%d", &array[i]);
    }
//4 3 2 1 - > 3 2 1 4
    for (int j = 0; j < tamanho; j++){
        int temporaria = array[j];
        array[j] = array[j + 1];
        
    }

}