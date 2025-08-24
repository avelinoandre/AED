// void enqueue(node **head,node **tail, int valor) {
//     node *new = (node*)malloc(sizeof(node));
//     if (new != NULL) {
//         new->valor = valor;
//         new->next = NULL;
    
//         if (*head == NULL) {
//             *head = new;
//             *tail = new;
//         }else {
//             (*tail)->next = new; 
//             *tail = new;    
//         }
//     }
// }

// void dequeue(node **head, node **tail) {
//     node *aux;
//     if((*head)) {
//         aux = *head;
//         *head = (*head)->next;
//         free(aux);
//         if (*head == NULL) {
//             *tail = NULL;
//         }
//     }
// }