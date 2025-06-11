#include<stdio.h>

// EXEMPLO 01 - Função recursiva

int f(int x) {
    if(x == 1)
        return 2;
    else if (x>1)
        return f(x-1) + 1;
}

// EXEMPLO 02 - Fatorial

int fatorial(int x) {
    if(x > 1)
        return x * fatorial(x-1);
    else
        return 1;
}

// EXEMPLO 03 - Soma dos elementos de um vetor

int vetor[5] = {2, 3, 1, 1, 2};
int somaVetor(int tam) {
    if(tam != 1)
        return vetor[tam-1] + somaVetor(tam-1);
    else
        return vetor[0];
}

int main() {
    //Teste do exemplo 01
    printf("O valor de f(4) eh %d.\n", f(4));

    //Teste do exemplo 02
    printf("O fatorial de 5 eh %d.\n", fatorial(5));

    //Teste do exemplo 03
    printf("A soma dos elementos do vetor eh %d.\n", somaVetor(5));

    return 0;
}