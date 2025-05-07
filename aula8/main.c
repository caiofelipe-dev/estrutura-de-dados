#include<stdio.h>
#include<stdlib.h>

typedef struct elemento{
    int valor;
    struct elemento *ant;
    struct elemento *prox;
}lista;

int final = 0;

void InserirElemento(lista **list, int valor){
    lista *novo,*aux;
    novo = (lista*) malloc(sizeof(lista));
    // Malloc aloca dinamicamente um espaço de memória do tamanho de um elemento 'lista'.
    novo->valor = valor;
    novo->prox = NULL;

    if((*list) != NULL){
        //Inserção em lista pré-existente
        aux = *list;
        while(aux->prox != NULL && aux->valor != valor){
            aux = aux->prox;
        }
        if(aux->valor == valor) {
            printf("O VALOR QUE DESEJA INSERIR JA EXISTE: %d\n", valor);
            system("pause");
            free(novo);
            return;
        } else
            aux->prox = novo;

    }else{
        //Inserção em lista vazia
        *list = novo;
    }
    final++;
    printf("Valor %d inserido com sucesso na posicao %d!\n", valor, final);
    system("pause");
}

void RemoverElemento(lista **list, int valor){
    lista *aux = *list;
    lista *anterior = NULL;

    while(aux != NULL && aux->valor != valor){
        anterior = aux;
        aux = aux->prox;
    }

    if(aux == NULL){
        printf("Elemento nao encontrado!\n");
        system("pause");
        return;
    }

    if(anterior != NULL){
        anterior->prox = aux->prox;
    }else{
        // O elemento a ser removido é o primeiro da lista
        *list = aux->prox;
    }

    free(aux);
    final--;
    printf("Elemento %d removido com sucesso!\n", valor);
    system("pause");
}

int BuscarPorChaves(lista *list, int valor){
    if(list == NULL){
        printf("LISTA VAZIA\n");
        return 0;
    }

    lista *aux = list;
    int posicao = 1;

    while(aux != NULL && aux->valor != valor){
        aux = aux->prox;
        posicao++;
    }

    if(aux == NULL) {
        printf("ELEMENTO NAO ENCONTRADO\n");
        system("pause");
        return 0;
    } else {
        return posicao;
    }
}

void mostrarMenu() {
    printf("\nLISTA SIMPLESMENTE ENCADEADA\n\n:: MENU ::\n");
    printf("1 - Mostrar a lista\n");
    printf("2 - inserir Elemento\n");
    printf("3 - Remover Elemento\n");
    printf("4 - Buscar Elemento pelo valor\n");
    printf("5 - Quantidade de elementos\n");
    printf("6 - Digite 6 para SAIR.\n");
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

    printf("||");
}

int calcularTamanho(lista *list) {
    if(list == NULL) {
        return 0;
    }
    lista *aux = list;
    int tamanho = 0;
    
    while(aux != NULL) {
        aux = aux->prox;
        tamanho++;
    }
    
    return tamanho;
}

int main(){
    lista *novaLista = NULL;

    int opcao, valor, posicao;
    do {
        system("cls");
        mostrarMenu();
        scanf("%d", &opcao);
        
        if(opcao == 1) {
            MostrarLista(novaLista);
            system("pause");
        }
        if(opcao == 2) {
            printf("Digite o valor a ser inserido: ");
            scanf("%d", &valor);
            InserirElemento(&novaLista, valor);
        }
        if(opcao == 3) {
            printf("Digite o valor a ser removido: ");
            scanf("%d", &valor);
            RemoverElemento(&novaLista, valor);
        }
        if(opcao == 4) {
            printf("Digite o valor a ser buscado: ");
            scanf("%d", &valor);
            posicao = BuscarPorChaves(novaLista, valor);
            if(posicao != 0){
                printf("O valor %d se encontra na posicao %d da lista.\n", valor, posicao);
                system("pause");
            }
        }
        if(opcao == 5) {
            final = calcularTamanho(novaLista);
            printf("Quantidade de elementos: %d\n", final);
            system("pause");
        }
        if(opcao == 6) {
            printf("Saindo...\n");
        }
    } while(opcao != 6);

    // Liberar a memória alocada para a lista
    lista *aux = novaLista;
    while(aux != NULL) {
        lista *temp = aux;
        aux = aux->prox;
        free(temp);
    }


    return 0;
}