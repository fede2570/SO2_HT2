#include <stdio.h>
#include <time.h>

//Script de 1 hilo

int main() {
    clock_t inicio, fin;
    double tiempo_cpu_usado;
    inicio = clock();

    long long suma = 0;
    for (int i = 1; i <= 100000; i++) {
        suma += i;
    }
    fin = clock();

    tiempo_cpu_usado = ((double) (inicio - fin)) / CLOCKS_PER_SEC;

    printf("Suma: %lld\n", suma);
    printf("Tiempo tardado: %f segundos\n", tiempo_cpu_usado);

    return 0;
}