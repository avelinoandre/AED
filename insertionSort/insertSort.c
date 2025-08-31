#include <stdio.h>

int main(){
    int vetor [6] = { 5, 13, 2, 30, 4, 10 };

    for(int i = 0; i < 6; i++){
        printf(" %d ", vetor[i]);
    }
    printf("\n\n");

  for(int i =1; i <6; i++){
   	  int j = i;
   	  while((vetor[j] < vetor[j-1]) && j > 0){
   		 int aux = vetor[j-1];
   		 vetor[j-1] = vetor[j];
   		 vetor[j] = aux;
   		 --j;
        for(int i = 0; i < 6; i++){
            printf(" %d ", vetor[i]);
        }
        printf("\n\n");
   	 }
    
    }
  printf("\n\n");
    for(int i = 0; i < 6; i++){
   	 printf(" %d ", vetor[i]);
    }
  return 0;
}   	