#include <stdio.h>
#include <stdlib.h>


int main (){

    int array[5] = {4,7,9,6,1};

    for (int i = 1; i < 5; i++){

        int j = i;

        while (array[j] < array[j - 1] && j > 0){

            int temp = array[j - 1];
            array[j - 1] = array[j];
            array[j] = temp;
            j--;

        }



    }


     for (int i = 0; i < 5; i++){

        printf("%d", array[i]);

    }


    return 0;
}