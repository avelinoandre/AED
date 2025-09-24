int palindromo (Node *head, Node *tail){

    if (head == NULL){

        printf("A lista está vazia...\n");
        return 0;

    }else{

        int cont = 0;

        Node *tempTail = tail;
        Node *tempHead = head;

        while (tempHead != tempTail && tempHead->ant != tempTail) {
            if (tempHead->letra != tempTail->letra) {

                return 0;

            }

            tempHead = tempHead->prox;
            tempTail = tempTail->ant;
            cont += 1;
        }


            if (cont < 3){

                return 0;

            }
            
        return 1;

    }

}