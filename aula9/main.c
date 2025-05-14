#include<stdio.h>
#include<stdlib.h>

typedef struct elemento{
    int valor;
    struct elemento *ant;
    struct elemento *prox;
}lista;

void InserirElemento(lista **list, int valor){
    lista *novo,*aux;
    novo = (lista*) malloc(sizeof(lista));
    // Malloc aloca dinamicamente um espaço de memória do tamanho de um elemento 'lista'.
    
    novo->valor = valor;
    novo->ant = NULL;
    novo->prox = NULL;

    if((*list) != NULL){
        //Inserção em lista pré-existente
        aux = *list;
        while(aux->prox != NULL){
            aux = aux->prox;
        }

        aux->prox = novo;
        novo->ant = aux;
    }else{
        //Inserção em lista vazia
        *list = novo;
    }
}


void InserirOrdenado(lista **list, int valor){

    lista *novo,*aux;
    novo = (lista*) malloc(sizeof(lista));
    // Malloc aloca dinamicamente um espaço de memória do tamanho de um elemento 'lista'.
    
    novo->valor = valor;
    novo->ant = NULL;
    novo->prox = NULL;

    if((*list) != NULL){
        //Inserção em lista pré-existente
        aux = *list;

        if(aux->valor > valor){
            novo->prox = aux;
            aux->ant = novo;
            *list = novo;
        }
        else{
            while(aux->prox != NULL && (aux->prox)->valor < valor){
                aux = aux->prox;
            }
            if(aux->prox == NULL) {
                aux->prox = novo;
                novo->ant = aux;
            } else {
                novo->prox = aux->prox;
                (aux->prox)->ant = novo;
                novo->ant = aux;
                aux->prox = novo;
            }
        }
    }else{
        //Inserção em lista vazia
        *list = novo;
    }
}

void RemoverElemento(lista **list, int valor){
    lista *aux = *list;
    if(aux != NULL){
        if(aux->valor == valor){
            *list = aux->prox;
            (aux->prox)->ant = NULL;
            free(aux);
        }else{        
            do{
                lista *tmp = aux->prox;
                if(tmp->valor == valor){
                    if(tmp->prox == NULL) {
                        aux->prox = NULL;
                    } else {
                        aux->prox = tmp->prox;
                        (tmp->prox)->ant = aux;
                    }
                    //Garbage Collector
                    free(tmp);
                    return;
                }else{
                    aux = aux->prox;
                }
            }while(aux != NULL);
            printf("\nElemento não encontrado\n");
        }
    }else{
        //LISTA VAZIA
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

void MostrarListaInvertido(lista *list){
    lista *aux = list;

    printf("LISTA -> ");
    
    if(list == NULL){
        printf("LISTA VAZIA\n");
        return;
    }
    
    while(aux->prox != NULL){
        aux = aux->prox;
    }

    do{
        printf("%d -> ",aux->valor);
        aux = aux->ant;
    }while(aux != NULL);

    printf("||\n");
}


int main(){

    lista *novaLista = NULL;
    InserirOrdenado(&novaLista,5);
    MostrarLista(novaLista);
    InserirOrdenado(&novaLista,12);
    InserirOrdenado(&novaLista,7);
    InserirOrdenado(&novaLista,36);
    InserirOrdenado(&novaLista,1);
    InserirOrdenado(&novaLista,50);

    MostrarLista(novaLista);
    RemoverElemento(&novaLista,36);
    MostrarLista(novaLista);
    MostrarListaInvertido(novaLista);


    return 0;
}