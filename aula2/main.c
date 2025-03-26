#include<stdio.h>
#include<math.h>

// EXERCÍCIO 01 - Crie uma lista sequencial estática e realize uma busca simples através de uma chave inteira.

int main() {
    int lista[50] = {
        12, 45, 23, 37, 19, 8, 29, 40, 18, 50,
        11, 31, 27, 6, 48, 25, 34, 9, 14, 42,
        7, 24, 39, 16, 33, 3, 46, 21, 10, 44,
        17, 4, 38, 22, 1, 43, 5, 15, 36, 28,
        32, 13, 41, 26, 2, 35, 30, 20, 49, 47
    };
    
    int chave, flag = 0;

    printf("Que elemento voce quer encontrar? ");
    scanf("%d", &chave);
    
    for(int i=0; i<50; i++) {
        if(lista[i] == chave) {
            printf("O elemento %d foi encontrado na posicao %d da lista.\n", chave, (i+1));
            flag = 1;
        }
    }
    if(flag == 0)
        printf("Elemento nao encontrado.\n");

    return 0;
}