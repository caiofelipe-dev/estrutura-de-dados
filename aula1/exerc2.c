#include<stdio.h>
#include<math.h>
#include"fisica.h"
// Movimento retilineo uniformente variado/acelerado
// S = S0 + V0 * T  + at²/2 e

int main() {
    float pos_inicial, vel_inicial, aceleracao, tempo;

    printf("Digita a aceleracao inicial (em m/s ao quadrado): ");
    scanf("%f", &aceleracao);
    printf("Digita a posicao inicial (em m/s): ");
    scanf("%f", &pos_inicial);
    printf("Digita a velocidade inicial (em m): ");
    scanf("%f", &vel_inicial);
    printf("Digita o tempo (em s): ");
    scanf("%f", &tempo);
    
    float pos_final = pos_final_mruv(pos_inicial, vel_inicial, aceleracao, tempo);

    printf("\nA posicao final do objeto eh %.2fm.", pos_final);

    return 0;   
}