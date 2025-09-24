void adicionarPosicaoEspecifica(Node **head, Node **tail, int valor, int posicao){

    Node novo = (Node)malloc(sizeof(Node));

    if(novo!= NULL){
        novo->valor = valor;
        novo->ant = NULL;

        if(*head == NULL){

            *head = novo;
            *tail = novo;
            novo->prox = novo;
            novo->ant = novo;

        }else{

            if(posicao == 1){

                novo->prox = *head;
                novo->ant = *tail;
                (*head)->ant = novo; 
                (*tail)->prox = novo; 
                *head = novo; 
            }

            Node *temp = *head;
            for(int i = 1; i < posicao-1 && temp->prox != *head; i++){ 
         
                temp = temp->prox;
                
            }
            
          
            if(temp == *tail){
                novo->prox = *head;
                novo->ant = *tail;
                (*tail)->prox = novo;
                (*head)->ant = novo;
                *tail = novo;

            }else{
            novo->prox = temp->prox;
            novo->ant = temp; 
            temp->prox->ant = novo;
            temp->prox = novo; 

            
            } 
        }
    }
}