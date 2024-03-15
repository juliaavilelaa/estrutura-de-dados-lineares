// Esboço do código de uma Queue de números inteiros implementada utilizando o conceito de lista encadeada.
// Implementar as partes do código que estão incompletas.

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct noQueue {
    int info;
    struct noQueue* prox;
}TNoQueue;

typedef struct queue {
    TNoQueue* inicio, * fim;
} Queue;

void inicializar(Queue* fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}

void enqueue(Queue* fila, int valor) { // enfileirar
    TNoQueue* novo = (TNoQueue*)malloc(sizeof(TNoQueue));
    if (novo != NULL) {
        novo->info = valor;
        novo->prox = NULL;
        if (fila->fim != NULL) {
            fila->fim->prox = novo;
        }
        fila->fim = novo;
        if (fila->inicio == NULL) {
            fila->inicio = novo;
        }
    }
}

int dequeue(Queue* fila) {  // desenfileirar
    if (fila->inicio != NULL) {
        TNoQueue* aux = fila->inicio;
        int valor = aux->info;
        fila->inicio = fila->inicio->prox;
        if (fila->inicio == NULL) {
            fila->fim = NULL;
        }
        free(aux);
        return valor;
    }
    return -1;
}

int head(Queue fila) {   // retornar o valor que está no início da fila
    if (fila.inicio != NULL) {
        return fila.inicio->info;
    }
    return -1;
}

// int isFull(Queue fila) { // checa se a fila está cheia
    // a fila nunca está cheia! não precisa usar essa função pra listas encadeadas.
// }

int isEmpty(Queue fila) { // checa se a fila está vazia
    return fila.inicio == NULL;
}

void exibirOpcoes() {
    printf("Opcoes: \n");
    printf("1 - Enqueue \n");
    printf("2 - Dequeue \n");
    printf("3 - Head \n");
    printf("0 - Encerrar programa \n");
    printf("Informe a opcao desejada: ");
}

int main()
{
    Queue minhaFila;
    inicializar(&minhaFila);
    int op, num;
    do {
        exibirOpcoes();
        scanf("%d", &op);
        switch (op) {
        case 1: printf("Informe o valor: ");
            scanf("%d", &num);
            enqueue(&minhaFila, num);
            printf("Valor enfileirado!\n");
            break;
        case 2:
            if (!isEmpty(minhaFila)) {
                num = dequeue(&minhaFila);
                printf("Valor desenfileirado = %d\n", num);
            } else {
                printf("Queue empty!\n");
            }
            break;
        case 3: 
            if (!isEmpty(minhaFila)) {
                num = head(minhaFila);
                printf("Valor no inicio da fila = %d\n", num);
            } else {
                printf("Queue empty!\n");
            }
            break;
        case 0: printf("Fim de programa!");
            break;
        default: printf("Opcao invalida!");
        }
    } while (op != 0);
    return 0;
}