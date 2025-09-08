#include <stdio.h>
#include <stdlib.h>

int main () {

    int array[5] = {4,7,9,6,1};
    
        int troca = 1;
        int i = 0;
        while (i < 5 && troca == 1){
            troca = 0;

            for (int j = 0; j < 5; j++){

                if (array[j] > array[j + 1]){

                    troca = 1;

                    int temp = array[j + 1];
                    array[j + 1] = array[j];
                    array[j] = temp;

                }

            }

            i++;

        }
    

        for (int i = 0; i < 5; i++){

        printf("%d", array[i]);

    }




    return 0;
}