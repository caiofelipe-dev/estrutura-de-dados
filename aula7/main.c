#include<stdio.h>
#include<stdlib.h>

typedef struct elemento{
    int valor;
    struct elemento *prox;
}lista;

void InserirElemento(lista **list, int valor){
    lista *novo,*aux;
    novo = (lista*) malloc(sizeof(lista));
    // Malloc aloca dinamicamente um espaço de memória do tamanho de um elemento 'lista'.
    novo->valor = valor;
    novo->prox = NULL;

    if((*list) != NULL){
        //Inserção em lista pré-existente
        aux = *list;
        while(aux->prox != NULL){
            aux = aux->prox;
        }

        aux->prox = novo;

    }else{
        //Inserção em lista vazia
        *list = novo;
    }

}

void InserirOrdenado(lista **list, int valor) {
    lista *novo,*aux;
    novo = (lista*) malloc(sizeof(lista));
    // Malloc aloca dinamicamente um espaço de memória do tamanho de um elemento 'lista'.
    novo->valor = valor;
    novo->prox = NULL;

    if((*list) != NULL){
        //Inserção em lista pré-existente
        aux = *list;

        if(aux->valor > valor) {
            novo->prox = aux;
            *list = novo;
        } else {
            while(aux->prox != NULL && aux->prox->valor < valor){
                aux = aux->prox;
            }
            novo->prox = aux->prox;
            aux->prox = novo;
        }

    }else{
        //Inserção em lista vazia
        *list = novo;
    }
}

void RemoverElemento(lista **list, int valor) {
    lista *aux = *list;

    if(aux != NULL) {
        if(aux->valor == valor) {
            *list = aux->prox;
            free(aux);
        } else {
            do {
                if(aux->prox->valor == valor) {
                    lista *tmp = aux->prox;
                    aux->prox = aux->prox->prox;
                    //Garbage Collector
                    free(tmp);
                    break;
                } else {
                    aux = aux->prox;
                }
            }while(aux != NULL);
        }
    } else {
        printf("LISTA VAZIA");
    }
}

void MostrarLista(lista *list){
    lista *aux = list;

    printf("LISTA -> ");
    
    if(list == NULL){
        printf("LISTA VAZIA\n");
        return;
    }

    do{
        printf("%d -> ",aux->valor);
        aux = aux->prox;
    }while(aux != NULL);

    printf("||\n");
}

int main(){

    lista *novaLista = NULL;

    InserirElemento(&novaLista,5);
    InserirElemento(&novaLista,12);
    InserirOrdenado(&novaLista, 7);
    InserirOrdenado(&novaLista, 1);
    InserirOrdenado(&novaLista, 50);

    MostrarLista(novaLista);
    RemoverElemento(&novaLista,13);
    MostrarLista(novaLista);

    return 0;
}