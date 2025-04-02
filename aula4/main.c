#include<stdio.h>
#include<math.h>
#include<stdlib.h>

// EXERCÍCIO 01 - Crie uma lista sequencial estática e realize uma busca simples através de uma chave inteira.

int lista[500] = {
    12, 45, 23, 37, 19, 8, 29, 40, 18, 50,
    11, 31, 27, 6, 48, 25, 34, 9, 14, 42,
    7, 24, 39, 16, 33, 3, 46, 21, 10, 44,
    17, 4, 38, 22, 1, 43, 5, 15, 36, 28,
    32, 13, 41, 26, 2, 35, 30, 20, 49, 47
};

int tamanho = 500;
int final = 50;

int buscaPorChaves(int chave) {
    for(int i=0; i<50; i++)
        if(lista[i] == chave)
            return i;
    
    return -1;
}

int buscaPorPosicao(int posicao) {
    return lista[posicao-1];
}

void inserirElemento(int valor) {
    lista[final] = valor;
    final++;
}

void removerElemento(int valor) {
    int pos = buscaPorChaves(valor);
    for(int i = pos; i < final; i++)
        lista[i] = lista[i+1];
    final--;
}

void mostrarMenu() {
    printf("\nLISTA SEQUENCIAL ESTATICA\n\n:: MENU ::\n\n");
    printf("1 - Mostrar a lista\n");
    printf("2 - Buscar Elemento pelo valor\n");
    printf("3 - Buscar Elemento pela posicao\n");
    printf("4 - inserir Elemento\n");
    printf("5 - Remover Elemento\n");
    printf("6 - Ordenar Lista\n");
    printf("7 - Realizar busca binaria pelo valor\n");
    printf("0 - Digite 0 para SAIR.\n");
}

void bubbleSort() {
    int aux;
    for(int i = 0; i < final-1; i++) {
        for(int j = i+1; j < final; j++) {
            if(lista[i] > lista[j]) {
                aux = lista[i];
                lista[i] = lista[j];
                lista[j] = aux;
            }
        }
    }
}

int binarySearch(int valor) {
    int start=0, end=final, mid =(int) start + ((start-end)+1)/2;
    int cont = 0;
    printf("%d\n", mid);
    system("pause");
    while(valor != lista[mid]) {
        cont++;
        if(valor < lista[mid]) {
            final=lista[mid];
            mid =(int) start + ((start-end)+1)/2;
            printf("valor menor %d\n", mid);
            system("pause");
        } else {
            start = lista[mid];
            mid =(int) start + ((start-end)+1)/2;
            printf("valor maior %d\n", mid);
            system("pause");
        }
        if(start == end)
        return -1;
    } 
    return mid;
}

void inserirOrdenado() {

}

void mostrarLista() {
    printf("LISTA -> ");
    for(int i = 0; i<final; i++)
        printf("%d ", lista[i]);
    system("pause");
}

int main() {
    int opcao, valor, posicao;
    do {
        mostrarMenu();
        scanf("%d", &opcao);
        
        if(opcao == 1) {
            mostrarLista();
        }
        if(opcao == 2) {
            printf("Qual valor deseja buscar?\n");
            scanf("%d", &valor);
            int posicao = buscaPorChaves(valor);
            if(posicao == -1)
                printf("\n\nELEMENTO NAO ENCONTRADO");
            else printf("O elemento %d esta na posicao %d da lista\n", valor, posicao);
            system("pause");
        }
        if(opcao == 3) {
            printf("Qual a posicao que sera verificada? Obs.: (MAX %d)\n", final);
            scanf("%d", &posicao);
            if(valor < 0)
                printf("\nELEMENTO NÃO ENCONTRADO\n");
            else printf("Encontramos o valor %d, na posicao %d.\n", buscaPorPosicao(posicao), posicao);
            system("pause");
        }
        if(opcao == 4) {
            printf("Digite o valor a ser inserido: ");
            scanf("%d", &valor);
            inserirElemento(valor);
        }
        if(opcao == 5) {
            printf("Digite o valor a ser removido: ");
            scanf("%d", &valor);
            removerElemento(valor);
        }
        if(opcao == 6) {
            bubbleSort();
            mostrarLista();
        }
        if(opcao == 7) {
            printf("Qual valor deseja buscar?\n");
            scanf("%d", &valor);
            int posicao = binarySearch(valor);
            if(posicao == -1)
                printf("\n\nELEMENTO NAO ENCONTRADO");
            else printf("O elemento foi encontrado em %d passos.\n\nO elemento %d esta na posicao %d da lista\n", cont, valor, posicao);
            system("pause");
        }

        // ÁREA PERIGOSA PRA SAPEKAGEM
        system("cls");
    } while (opcao != 0);

    return 0;
}