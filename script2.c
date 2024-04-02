#include <stdio.h>
#include <pthread.h>
#include <time.h>

//Script de 2 hilos

void *myFunction(void* rango) {
    long long rango1 = ((long long*)rango)[0];
    long long rango2 = ((long long*)rango)[1];
    long long* suma_ptr = (long long*) rango;
    *suma_ptr = 0;

    for (long long i = rango1; i <= rango2; i++) {
        *suma_ptr += i;
    }
    return NULL;
}

int main() {
    clock_t inicio, fin;
    double tiempo_cpu_usado;

    inicio = clock();

    long long rango1[2] = {1, 50000};
    long long rango2[2] = {50001, 100000};
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, myFunction, rango1);
    pthread_create(&thread2, NULL, myFunction, rango2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    fin = clock();

    tiempo_cpu_usado = ((double) (inicio - fin)) / CLOCKS_PER_SEC;

    printf("Suma: %lld\n", rango1[0] + rango2[0]);
    printf("Tiempo tardado: %f segundos \n", tiempo_cpu_usado);

    return 0;
}