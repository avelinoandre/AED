void removerPosicaoEspecifica(Node **head, Node **tail, int posicao){

    if(*head != NULL){

        if(*head == *tail){ 

            *head = NULL;
            *tail = NULL;

        }else{
            if(posicao == 1){

                Node *temp1 = *head; 
                *head = (*head)->prox;
                (*head)->ant = *tail;
                (*tail)->prox = *head;
                free(temp1);

            }else{
                Node *temp = *head;
                for(int i = 1; i < posicao - 1 && temp->prox != *head; i++){

                    temp = temp->prox;

                }
                Node *temp2 = temp->prox;
                if( temp2 == *head){ 

                    temp2 = *tail;
                    *tail = (*tail)->ant;
                    (*head)->ant = *tail;
                    (*tail)->prox = *head;
                    free(temp2);
                    
                }else{

                    temp->prox = temp2->prox;
                    temp2->prox->ant = temp;
                    free(temp2);

                }
            }
        }
    }
}