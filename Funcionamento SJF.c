#include <stdio.h>

typedef struct {
    int id;
    int chegada;
    int burst;
    int espera;
    int turnaround;
    int concluido;
} Processo;

int main() {
    int n, tempo = 0, concluídos = 0;
    float soma_espera = 0, soma_turnaround = 0;

    printf("Digite o número de processos: ");
    scanf("%d", &n);

    Processo p[n];

    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Tempo de chegada do processo %d: ", i + 1);
        scanf("%d", &p[i].chegada);
        printf("Burst time do processo %d: ", i + 1);
        scanf("%d", &p[i].burst);
        p[i].concluido = 0;
        p[i].espera = 0;
        p[i].turnaround = 0;
    }

    printf("\n=== Escalonamento SJF Não-Preemptivo ===\n");

    while (concluídos < n) {
        int idx = -1;
        int menor_burst = 1e9;

        // Seleciona processo disponível com menor burst time
        for (int i = 0; i < n; i++) {
            if (!p[i].concluido && p[i].chegada <= tempo) {
                if (p[i].burst < menor_burst) {
                    menor_burst = p[i].burst;
                    idx = i;
                }
            }
        }

        if (idx == -1) {
            tempo++; // nenhum processo chegou ainda, avança tempo
        } else {
            p[idx].espera = tempo - p[idx].chegada;
            if (p[idx].espera < 0) p[idx].espera = 0;

            tempo += p[idx].burst;
            p[idx].turnaround = p[idx].espera + p[idx].burst;
            p[idx].concluido = 1;
            concluídos++;

            soma_espera += p[idx].espera;
            soma_turnaround += p[idx].turnaround;

            printf("Processo %d executado | Espera: %d | Turnaround: %d\n",
                   p[idx].id, p[idx].espera, p[idx].turnaround);
        }
    }

    printf("\nTempo médio de espera: %.2f", soma_espera / n);
    printf("\nTempo médio de turnaround: %.2f\n", soma_turnaround / n);

    return 0;
}