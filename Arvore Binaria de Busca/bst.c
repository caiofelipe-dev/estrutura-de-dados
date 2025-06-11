#include<stdio.h>
#include<stdlib.h>

typedef struct elemento{
    int valor;
    struct elemento *esq;
    struct elemento *dir;
}node;

void inserir (node ** root, int valor){
    node *novo = (node*)malloc(sizeof(node));
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;

    if(*root != NULL){
           if(valor < (*root)->valor)
            inserir(&(*root)->esq,valor);
        else if(valor > (*root)->valor)
            inserir(&(*root)->dir,valor);
    }else *root = novo;
}

void ShowTree(node *root,int level){
    int i;

    if(root != NULL){
        for(i = 0; i<level;i++)
            printf("    |");

        printf("%d --->",root->valor);
        level++;
        printf("\n");
        ShowTree(root->esq,level);
        printf("\n");
        ShowTree(root->dir,level);
    }else {
        for(i = 0; i<level;i++)
            printf("    |");
        
        printf("NULL");
    }
}

int main() {
    node *tree = NULL;

    // inserir(&tree, 8);
    // inserir(&tree, 5);
    // inserir(&tree, 11);
    // inserir(&tree, 9);
    // inserir(&tree, 12);
    // inserir(&tree, 2);
    // inserir(&tree, 6);

    inserir(&tree, 2);
    inserir(&tree, 5);
    inserir(&tree, 6);
    inserir(&tree, 8);
    inserir(&tree, 9);
    inserir(&tree, 11);
    inserir(&tree, 12);
    
    ShowTree(tree, 0);

    return 0;
}