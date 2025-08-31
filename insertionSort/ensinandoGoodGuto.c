#include <stdio.h>
#include <stdlib.h>

int main () {

    int array[5] = {5, 3 , 2, 30 , 4};

    for (int i = 1; i < 5; i++){
        int j = i;// = 3
        while ((array[j] < array[j - 1]) && j > 0){
           int temp = array[j - 1];
           array[j - 1] = array[j];
           array[j] = temp;
           --j;
        }

    

    }

}