#include <stdio.h>
#include <stdlib.h> // Fun��o rand
#include <time.h> // Fun��o clock
 
// Definindo uma constante
#define MAX 100000

// Fun��o para calcular a posi��o do piv�
long int particiona(long int *vet, long int inicio, long int fim) {
    long int esq, dir, pivo, aux;

    esq = inicio;
    dir = fim;
    pivo = vet[inicio]; // Definindo o piv� como o primeiro n�mero do vetor

    while (esq < dir) {

        // Avan�ando para esquerda at� encontrar um n�mero maior que o piv�
        while (vet[esq] <= pivo)
            esq++;

        // Recuando para direita at� encontrar um n�mero menor ou igual ao piv�
        while (vet[dir] > pivo)
            dir--;

        // Trocando os elementos de posi��o
        if (esq < dir) {
            aux = vet[esq];
            vet[esq] = vet[dir];
            vet[dir] = aux;
        }
    }

    vet[inicio] = vet[dir]; // Trocando os elementos de posi��o
    vet[dir] = pivo; // Definindo a nova posi��o do piv�

    return dir;
}

// Fun��o de Ordena��o por Sele��o
void quick_sort(long int *vet, long int inicio, long int fim) {
    long int pivo;

    if (fim > inicio) {
        pivo = particiona(vet, inicio, fim); // Definindo um piv� pela fun��o particiona

        // Chamandas recursivas para ordenar as parti��es do vetor
        quick_sort(vet, inicio, pivo-1);
        quick_sort(vet, pivo+1, fim);
    }
}
 
// Fun��o main
int main() {
    long int i, vet[MAX], vet1[MAX], vet2[MAX], aux;
    clock_t tempo;
    
    // Definindo um vetor de 100 mil n�meros aleat�rios
    for(i = 0; i < 100000; i++){
        vet[i] = rand() % 100000;
    }
    
    tempo = clock();

    // Ordenando os valores e calculando o tempo gasto para a ordena��o
    quick_sort(vet, 0, MAX - 1);
    tempo = clock() - tempo;


    // Imprimindo o tempo gasto para ordenar um vetor totalmente aleat�rio
    printf("T1: %f s\n", (double)tempo/CLOCKS_PER_SEC);


    tempo = clock();

    // Ordenando os valores e calculando o tempo gasto para a ordena��o
    quick_sort(vet, 0, MAX - 1);
    tempo = clock() - tempo;


    // Imprimindo o tempo gasto para ordenar um vetor ordenado crescentemente
    printf("T2: %f s\n", (double)tempo/CLOCKS_PER_SEC);


    // Invertendo um vetor ordenado
    for(i = 0; i < MAX; i++)
        vet1[i] = vet[(MAX - 1) - i];

    
    tempo = clock();

    // Ordenando os valores e calculando o tempo gasto para a ordena��o
    quick_sort(vet1, 0, MAX - 1);
    tempo = clock() - tempo;


    // Imprimindo o tempo gasto para ordenar um vetor ordenado decrescentemente 
    printf("T3: %f s\n", (double)tempo/CLOCKS_PER_SEC);    
    
    

    // Ordenando decrescentemente a segunda metade de um vetor j� ordenado
    aux = 0;

    for (i = 0; i < 100000; i++) {
        if (i < 50000) {
            vet2[i] = vet1[i];
        } else {
            vet2[i] = vet1[(MAX - 1) - aux];
            aux++;
        }
    }


    tempo = clock();

    // Ordenando os valores e calculando o tempo gasto para a ordena��o
    quick_sort(vet1, 0, MAX - 1);
    tempo = clock() - tempo;


    /* Imprimindo o tempo gasto para ordenar um vetor
    com a primeira metade ordenada crescentemente e a
    segunda metade ordenada decrescentemente */
    printf("T4: %f s\n", (double)tempo/CLOCKS_PER_SEC);


    // Ordenando decrescentemente a primeira metade de um vetor j� ordenado
    aux = 0;

    for (i = 0; i < 100000; i++) {
        if (i < 50000) {
            vet2[i] = vet1[(MAX - 50001) - aux];
            aux++;
        } else {
            vet2[i] = vet1[i];
        }
    }
    

    tempo = clock();

    // Ordenando os valores e calculando o tempo gasto para a ordena��o
    quick_sort(vet1, 0, MAX - 1);
    tempo = clock() - tempo;
  
    
    /* Imprimindo o tempo gasto para ordenar um vetor
    com a primeira metade ordenada decrescentemente e a
    segunda metade ordenada crescentemente */
    printf("T5: %f s\n", (double)tempo/CLOCKS_PER_SEC);
    
    return 0;
}
