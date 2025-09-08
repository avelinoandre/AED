#include <stdio.h>
#include <stdlib.h>


int main () {

    int array[5] = {4,7,9,6,1};

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 4; j++){

            if (array[j] >  array[j + 1]){

                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;

            }

        }

    }

    for (int i = 0; i < 5; i++){

        printf("%d", array[i]);

    }



    return 0;

}