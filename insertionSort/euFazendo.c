#include <stdio.h>
#include <stdlib.h>

int main () {

    int array[5] = {10, 3, 4, 11, 1};

    for (int i =  1; i < 5; i++){ 
        int j = i;
        while ((array[j] < array[j - 1]) && j > 0) {
            int temp = array[j - 1];
            array[j - 1] = array[j];
            array[j] = temp;
            --j;
            printf("\n\n");
            for(int i = 0; i < 5; i++){
               printf(" %d ", array[i]);
            }
        }


    }

    printf("\n\n");
    for(int i = 0; i < 5; i++){
   	 printf(" %d ", array[i]);
    }

    return 0;

}