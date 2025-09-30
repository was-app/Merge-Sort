#include <merge_sort.h>
#include <sort.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <string.h>

#define NUM_REP 10
#define SIZE_LIMIT 50000

long double diffTime(struct rusage *start, struct rusage *end) {
    long double s = start->ru_utime.tv_sec + start->ru_utime.tv_usec / 1000000.0L;
    long double e = end->ru_utime.tv_sec + end->ru_utime.tv_usec / 1000000.0L;
    return e - s;
}

void run(const char *algoname, void (*sortfunc)(int[], int, unsigned long*, unsigned long*), long int tamanhos[], int num_tamanhos, int skip_large) {
    char filename[256];
    snprintf(filename, sizeof(filename), "../DADOS/%s_resultados.csv", algoname);

    FILE *arquivo = fopen(filename, "w");
    if (!arquivo) {
        perror("Erro ao abrir arquivo");
        exit(1);
    }

    fprintf(arquivo, "tipo,n,tempo,comparacoes,deslocamentos,memoria\n");

    int *vetor;
    unsigned long comp, desloc;
    struct rusage start, end;
    long double tempo;
    long max_mem;
    const char *tipos_organizacao[] = {"Aleatorio","Crescente","Decrescente"};

    for (int organizacao = 0; organizacao < 3; organizacao++) {
        const char *tipo = tipos_organizacao[organizacao];
        for (int t = 0; t < num_tamanhos; t++) {
            long int n = tamanhos[t];

            // pula inputs grandes para algoritmos quadraticos
            if (skip_large && n >= SIZE_LIMIT) continue;

            long double soma_t = 0;
            unsigned long soma_c = 0, soma_d = 0;
            long soma_mem = 0;

            for (int i = 0; i < NUM_REP; i++) {
                vetor = (int*) malloc(n * sizeof(int));
                if (!vetor) {
                    perror("Erro de malloc");
                    exit(1);
                }

                if (organizacao == 0) {
                    for (int i = 0; i < n; i++) vetor[i] = rand();
                } else if (organizacao == 1) {
                    for (int i = 0; i < n; i++) vetor[i] = i;
                } else {
                    for (int i = 0; i < n; i++) vetor[i] = n - i;
                }

                comp = desloc = 0;

                getrusage(RUSAGE_SELF, &start);
                sortfunc(vetor, n, &comp, &desloc);
                getrusage(RUSAGE_SELF, &end);

                tempo = diffTime(&start, &end);
                max_mem = end.ru_maxrss;

                soma_t += tempo;
                soma_c += comp;
                soma_d += desloc;
                soma_mem += max_mem;

                free(vetor);
            }
            fprintf(arquivo, "%s,%ld,%Lf,%lu,%lu,%ld\n", tipo, n, soma_t/NUM_REP, soma_c/NUM_REP, soma_d/NUM_REP, soma_mem/NUM_REP);
        }
    }

    fclose(arquivo);
    printf("%s resultados salvos em %s\n", algoname, filename);
}

int main() {
    long int tamanhos[] = {10, 100, 1000, 10000, 100000, 1000000};
    int num_tamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);

    system("mkdir -p ../DADOS");

    run("merge", mergeSortWrapper, tamanhos, num_tamanhos, 0);
    run("selection", selectionSort, tamanhos, num_tamanhos, 1);
    run("insertion", insertionSort, tamanhos, num_tamanhos, 1);
    run("bubble", bubbleSort, tamanhos, num_tamanhos, 1);

    return 0;
}