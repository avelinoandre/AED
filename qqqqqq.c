void verificarSeExisteIgual(Node *head1, Node **head2, Node **tail2) {
    Node *temp1 = head1;

    while (temp1 != NULL) {
        Node *temp2 = *head2;
        while (temp2 != NULL) {
            if (temp1->numero == temp2->numero) {
                removerValorEspecifico(head2, tail2, temp2->numero);
                break; // Remove apenas a primeira ocorrência
            }
            temp2 = temp2->prox;
        }
        temp1 = temp1->prox;
    }
}