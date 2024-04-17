#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct noQueue {
    char info[100]; 
    struct noQueue* prox;
} TNoQueue;

typedef struct queue {
    TNoQueue *inicio, *fim;
} Queue;

void inicializar(Queue* fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}

void enqueue(Queue* fila, char* arquivo) {
    TNoQueue* novo = (TNoQueue*)malloc(sizeof(TNoQueue));
    strcpy(novo->info, arquivo);
    novo->prox = NULL;
    if (fila->fim != NULL) {
        fila->fim->prox = novo;
    }
    fila->fim = novo;
    if (fila->inicio == NULL) {
        fila->inicio = novo;
    }
}

char* dequeue(Queue* fila) {
    TNoQueue* aux = fila->inicio;
    char nomeArquivo[100];
    strcpy(nomeArquivo, aux->info);
    fila->inicio = fila->inicio->prox;
    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }
    free(aux);
    return nomeArquivo;
}

char* head(Queue fila) {
    return fila.inicio->info;
}

void cancel(Queue* fila, char* arquivo) {
    TNoQueue *aux1, *aux2;
    aux1 = fila->inicio->prox;
    aux2 = fila->inicio;
    while (strcmp(arquivo, aux1->info) != 0) {
        aux2 = aux1;
        aux1 = aux1->prox;
    }
    aux2->prox = aux1->prox;
    free(aux1);
}

void list(Queue fila) {
    TNoQueue* aux = fila.inicio;
    while (aux != NULL) {
        printf("%s\n", aux->info);
        aux = aux->prox;
    }
}

int isFull(Queue fila) {
    return 0;
}

int isEmpty(Queue fila) {
    if (fila.inicio == NULL && fila.fim == NULL) {
        return 1;
    }
    return 0;
}

void exibirOpcoes() {
    printf("Opcoes: \n");
    printf("1 - Enqueue \n");
    printf("2 - Dequeue \n");
    printf("3 - Head \n");
    printf("4 - Cancel \n");
    printf("5 - List\n");
    printf("0 - Encerrar programa \n");
    printf("Informe a opcao desejada: ");
}

int main() {    
    Queue minhaFila;
    inicializar(&minhaFila);
    int op;
    char arquivo[100];
    do {
    exibirOpcoes();
        scanf("%d", &op);
        switch (op) {
        case 1: printf("Informe o nome do arquivo: ");
            scanf("%s", arquivo);
            if (!isFull(minhaFila)) {
                enqueue(&minhaFila, arquivo);
                printf("Arquivo enfileirado!\n");
            }
            else {
                printf("Queue full!\n");
            }
            break;
        case 2: if (!isEmpty(minhaFila)) {
            strcpy(arquivo, dequeue(&minhaFila));
            printf("Arquivo desenfileirado!\n");
            } else {
                printf("Queue empty!\n");
            }
            break;
        case 3: if (!isEmpty(minhaFila)) {
            strcpy(arquivo, head(minhaFila));
            printf("Arquivo no inicio da fila: %s\n", arquivo);
            } else {
                printf("Queue empty!\n");
            }
            break;
        case 4: if (!isEmpty(minhaFila)) {
            printf("Informe o nome do arquivo a ser cancelado: ");
            scanf("%s", arquivo);
            cancel(&minhaFila, arquivo);
            } else {
                printf("Queue empty!\n");
            }
            break;
        case 5: if (!isEmpty(minhaFila)) {
            list(minhaFila);
            } else {
                printf("Queue empty!\n");
            }
            break;
        case 0: printf("Fim de programa!\n");
            break;
        default: printf("Opcao invalida!\n");
        }
    } while (op != 0);

    return 0;
}