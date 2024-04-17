#include <stdio.h>
#include <stdlib.h>

typedef struct NoLSE {
    int info;
    struct NoLSE* prox;
} TNoLSE;

typedef struct LseInt {
    TNoLSE* inicio;
    TNoLSE* fim;
    int qtd;
} LSEinteiros;

void inicializar(LSEinteiros* lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->qtd = 0;
}

int isEmpty(LSEinteiros lista) {
    return lista.qtd == 0;
} 

void inserir(LSEinteiros* lista, int valor) {
    TNoLSE* novo;
    TNoLSE* anterior;
    TNoLSE* atual;
    int finalizou = 1;

    if (isEmpty(*lista)) {
        novo = (TNoLSE*)malloc(sizeof(TNoLSE));
        novo->info = valor;
        novo->prox = NULL;
        lista->inicio = novo;
        lista->fim = novo;
        lista->qtd = 1;
        printf("Insercao efetuada.\n");
    } 
    else if (valor < lista->inicio->info) {
        novo = (TNoLSE*)malloc(sizeof(TNoLSE));
        novo->info = valor;
        novo->prox = lista->inicio;
        lista->inicio = novo;
        lista->qtd++;
        printf("Insercao efetuada.\n");
    } 
    else if (valor == lista->inicio->info) {
        printf("Valor repetido. Insercao nao efetuada.\n");
    }
    else if (valor > lista->fim->info) {
        novo = (TNoLSE*)malloc(sizeof(TNoLSE));
        novo->info = valor;
        novo->prox = NULL;
        lista->fim->prox = novo;
        lista->fim = novo;
        lista->qtd++;
        printf("Insercao efetuada.\n");
    }
    else if (valor == lista->fim->info) {
        printf("Valor repetido. Insercao nao efetuada.\n");
    }
    else {
        anterior = lista->inicio;
        atual = lista->inicio->prox;
        while (finalizou == 1) {
            if (valor == atual->info) {
                printf("Valor repetido. Insercao nao efetuada.\n");
                break;
            }
            else if (atual->info > valor) {
                novo = (TNoLSE*)malloc(sizeof(TNoLSE));
                novo->info = valor;
                novo->prox = atual;
                anterior->prox = novo;
                lista->qtd++;
                printf("Insercao efetuada.\n");
                finalizou = 0;
            }
            else {
                anterior = atual;
                atual = atual->prox;
            }
        }
    }
}

void remover(LSEinteiros* lista, int valor) {
    TNoLSE* atual = lista->inicio;
    TNoLSE* anterior = NULL;

    while (atual != NULL && atual->info != valor) {
        anterior = atual;
        atual = atual->prox;
    }
    if (atual == NULL) {
        printf("Valor nao encontrado. Remocao nao efetuada.\n");
        return;
    }
    if (anterior == NULL) {
        lista->inicio = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }
    if (atual == lista->fim) {
        lista->fim = anterior;
    }

    free(atual);
    lista->qtd--;
    printf("Remocao efetuada.\n");
}

void exibirLista(LSEinteiros lista) {
    TNoLSE* atual = lista.inicio;

    while (atual != NULL) {
        printf("%d ", atual->info);
        atual = atual->prox;
    }
    printf("\n");
}

void exibirOpcoes() {
    printf("Opcoes:\n");
    printf("1 - Inserir valor\n");
    printf("2 - Remover valor\n");
    printf("3 - Exibir lista\n");
    printf("0 - Encerrar programa\n");
    printf("Informe a opcao desejada: ");
}

int main() {
    LSEinteiros listaInteiros;
    inicializar(&listaInteiros);
    int op, num;

    do {
        exibirOpcoes();
        scanf("%d", &op);
        switch (op) {
            case 1: printf("Informe o valor que deseja inserir: ");
                scanf("%d", &num);
                inserir(&listaInteiros, num);
                break;
            case 2: printf("Informe o valor que deseja remover: ");
                scanf("%d", &num);
                remover(&listaInteiros, num);
                break;
            case 3: exibirLista(listaInteiros);
                break;
            case 0: printf("Fim de programa.\n");
                break;
            default: printf("Opcao invalida.\n");
        }
    } while (op != 0);

    return 0;
}