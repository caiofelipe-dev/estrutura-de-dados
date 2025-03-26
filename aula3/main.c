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

void ordenar() {
    
}

void inserirOrdenado() {

}

void mostrarLista() {
    printf("LISTA -> ");
    for(int i = 0; i<final; i++)
        printf("%d ", lista[i]);
}

int main() {
    int opcao, valor, posicao;
    do {
        printf("\nLISTA SEQUENCIAL ESTATICA\n\n:: MENU ::\n\n");
        printf("1 - Mostrar a lista\n");
        printf("2 - Buscar Elemento pelo valor\n");
        printf("3 - Buscar Elemento pela posicao\n");
        printf("4 - inserir Elemento\n");
        printf("5 - Remover Elemento\n");
        printf("0 - Digite 0 para SAIR.\n");
        
        scanf("%d", &opcao);
        
        if(opcao == 1) {
            mostrarLista();
            system("pause");
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

        // ÁREA PERIGOSA PRA SAPEKAGEM
        system("cls");
    } while (opcao != 0);

    return 0;
}