void adicionarNoMeio(Node **head, int valor) {
    Node *novo = (Node *)malloc(sizeof(Node));
    if (novo == NULL) return; // erro de alocação

    novo->numero = valor;
    novo->prox = NULL;
    novo->ant = NULL;

    // Caso a lista esteja vazia
    if (*head == NULL) {
        *head = novo;
        return;
    }

    // 1. Contar tamanho
    Node *temp = *head;
    int tamanho = 0;
    while (temp != NULL) {
        tamanho++;
        temp = temp->prox;
    }

    // 2. Calcular posição do meio
    int pos = tamanho / 2;

    // 3. Percorrer até o nó anterior ao meio
    temp = *head;
    for (int i = 0; i < pos - 1 && temp->prox != NULL; i++) {
        temp = temp->prox;
    }

    // 4. Inserir no meio
    novo->prox = temp->prox;
    novo->ant = temp;

    if (temp->prox != NULL)
        temp->prox->ant = novo;

    temp->prox = novo;
}