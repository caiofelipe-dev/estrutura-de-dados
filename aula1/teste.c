#include<stdio.h>

float potencia(x, y) {
    int result = x;
    for(int i = 1; i<y; i++) {
        result = result * x;
    }
    return result;
}

int main() {    
    int sla;
    sla = potencia(2, 2);
    printf("%d", sla);
    return 0;
}