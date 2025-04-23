#include<stdio.h>
#include<stdlib.h>

typedef struct elemento {
    int valor;
    struct elemento *prox;
}lista;

void inserirElemento(lista **list, int valor) {
    lista *novo, *aux;
    novo = (lista *) malloc(sizeof(lista));
    
    novo->valor = valor;
    novo->prox = NULL;

    if((*list) != NULL) {
        aux = *list;
        while(aux->prox != NULL) {
            aux = aux->prox;
        }

        aux->prox = novo;
    } else {
        *list = novo;
    }
}

void mostrarLista(lista *list) {
    lista *aux = list;
    
    printf("LISTA -> ");
    do {
        printf("%d->", aux->valor);
        aux = aux->prox;
    } while(aux != NULL);
    printf("||");
}

int main() {
    lista *novaLista = NULL;

    inserirElemento(&novaLista,5);
    inserirElemento(&novaLista,12);
    inserirElemento(&novaLista,13);
    inserirElemento(&novaLista,19);
    inserirElemento(&novaLista,20);
    inserirElemento(&novaLista,23);

    mostrarLista(novaLista);

    return 0;
}