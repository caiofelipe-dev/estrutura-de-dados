#include<stdio.h>

int main() {
    int idade[10], acc = 0, maior = -1;

    for(int i=0; i<10; i++) {
        scanf("%d", &idade[i]);
        acc = acc + idade[i];
        if(maior < idade[i])
            maior = idade[i];
    }
    
    float media =(float) acc / 10;

    printf("As idades sao: ");
    for(int i=0; i<10; i++) {
        printf("%d, ", idade[i]);
    }

    printf("\nA soma das idades eh: %d\n", acc);
    printf("A media das idades eh: %.1f\n", media);
    printf("A terceira idade eh %d\n", idade[2]);
    printf("A maior idade eh %d", maior);

    return 0;
}