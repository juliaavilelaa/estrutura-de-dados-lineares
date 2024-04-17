#include <stdio.h>
#include <stdlib.h>

typedef struct NoLDE {
    int info;
    struct NoLDE* prox;
    struct NoLDE* anterior;
} TNoLDE;

typedef struct listaDE {
    TNoLDE* inicio;
    TNoLDE* fim;
    int qtd;
} LDE;

void remover(LDE* lista, int valor) {
    TNoLDE* retorno = buscar(*lista, valor);
    if (retorno == NULL) {
        printf("Valor nao encontrado");
    }
    else if (retorno == lista->inicio) {
        if (lista->qtd == 1) {
            lista->inicio = NULL;
            lista->fim = NULL;
        }
        else {
            lista->inicio = lista->inicio->prox;
            lista->inicio->anterior = NULL;
        }
        lista->qtd--;
        free(retorno);
    }
    else if (retorno == lista->fim) {
        lista->fim = lista->fim->anterior;
        lista->fim->prox = NULL;
        lista->qtd--;
        free(retorno);
    }
    else {
        retorno->anterior->prox = retorno->prox;
        retorno->prox->anterior = retorno->anterior;
        lista->qtd--;
        free(retorno);
    }
}