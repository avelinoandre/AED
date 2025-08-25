#include <stdio.h>

typedef struct {
    int id, chegada, burst, espera, turnaround, concluido;
} Processo;

int main() {
    int n, tempo = 0, concluidos = 0;

    printf("Quantos processos? ");
    scanf("%d", &n);

    Processo p[n];

    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Processo %d (chegada e burst): ", i+1);
        scanf("%d %d", &p[i].chegada, &p[i].burst);
        p[i].concluido = 0;
    }

    printf("\nOrdem de Execucao (SJF Nao-Preemptivo):\n");

   
    while (concluidos < n) {
        int idx = -1, menor = 1000;

        for (int i = 0; i < n; i++)
            if (!p[i].concluido && p[i].chegada <= tempo && p[i].burst < menor)
                menor = p[i].burst, idx = i;

        if (idx == -1) { tempo++; continue; } 

        p[idx].espera = tempo - p[idx].chegada;
        if (p[idx].espera < 0) p[idx].espera = 0;

        tempo += p[idx].burst;
        p[idx].turnaround = p[idx].espera + p[idx].burst;
        p[idx].concluido = 1;
        concluidos++;

        printf("P%d ", p[idx].id);
    }

    printf("\n\nTabela de processos:\n");
    printf("ID | Chegada | Burst | Espera | Turnaround\n");
    for (int i = 0; i < n; i++) {
        printf("%2d | %7d | %5d | %6d | %10d\n",
               p[i].id, p[i].chegada, p[i].burst,
               p[i].espera, p[i].turnaround);
    }
    return 0;
}