 void removerPorPosicao(node **head, int posicao) {
    node *aux = *head;
    int i = 0;
    if (posicao == 0) {
        *head = aux->next;
        free(aux);
        return;
    }
    while (aux->next && i < posicao - 1) {
        aux = aux->next;
        i++;
    }
    if (aux == NULL || aux->next == NULL) {
        return;
    }
    node *delete = aux->next;
    aux->next = delete->next;
    free(delete);
} 