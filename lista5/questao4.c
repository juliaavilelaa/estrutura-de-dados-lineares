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

void enqueue(Queue* fila, int valor) {
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

int dequeue(Queue* fila) { 
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

int head(Queue fila) { 
    if (fila.inicio != NULL) {
        return fila.inicio->info;
    }
    return -1;
}

int isEmpty(Queue fila) {
    return fila.inicio == NULL;
}

int isFull(Queue fila) {
    return 0;
}

int main() {
    Queue filaDeSenhas;
    inicializar(&filaDeSenhas);
    int op, senha = 0;
    do {
        printf("1 - Fornecer uma senha de atendimento\n");
        printf("2 - Chamar uma senha para atendimento\n");
        printf("0 - Encerrar programa\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &op);
        switch (op) {
        case 1: 
            if (!isFull(filaDeSenhas)) {
                enqueue(&filaDeSenhas, ++senha);
                printf("Senha de atendimento fornecida: %d\n", senha);
            } else {
                printf("Queue full!\n");
            }
            break;
        case 2:
            if (!isEmpty(filaDeSenhas)) {
                senha = dequeue(&filaDeSenhas);
                if (senha != -1) {
                    printf("Senha chamada para atendimento: %d\n", senha);
                }
            } else {
                printf("Queue empty!\n");
            }
            break;
        case 0:
            printf("Encerrando o programa...\n");
            break;
        default:
            printf("Opcao invalida!\n");
        }
    } while (op != 0);
    return 0;
}