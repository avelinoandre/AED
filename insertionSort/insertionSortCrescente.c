#include <stdio.h>
#include <stdlib.h>

int main () {

    int array[6] = {18, 31, 22, 50, 37, 46};

       printf("\n\n");
        for(int i = 0; i < 6; i++){
   	    printf(" %d ", array[i]);
        }

    for (int i = 1; i < 6; i++){
    
        int j = i;

        while ((array[j] > array[j - 1]) && j > 0){

            int temp = array[j - 1];
            array[j - 1] = array[j];
            array[j] = temp;
            --j;
            printf("\n\n");
            for(int i = 0; i < 6; i++){
               printf(" %d ", array[i]);
            }

        }


    }

    printf("\n\n");
        for(int i = 0; i < 6; i++){
   	    printf(" %d ", array[i]);
        }

}