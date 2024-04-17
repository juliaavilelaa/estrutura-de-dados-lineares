#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NoStack {
    char info;
    struct NoStack* prox;
} TNoStack;

typedef TNoStack* Stack;

void inicializar(Stack* pilha) {
    *pilha = NULL;
}

int isEmpty(Stack pilha) {
    return pilha == NULL;
}

void push(Stack* pilha, char valor) {
    TNoStack* novo = (TNoStack*)malloc(sizeof(TNoStack));
    novo->info = valor;
    novo->prox = *pilha;
    *pilha = novo;
}

char pop(Stack* pilha) {
    if (*pilha != NULL) {
        Stack aux = *pilha;
        int valor = aux->info;
        *pilha = aux->prox;
        free(aux);
        return valor;
    } else {
        return -1;
    }
}

int ehPalindromo(char* palavra) {
    Stack pilha;
    inicializar(&pilha);
    int len = strlen(palavra);
    for (int i = 0; i < len; i++) {
        push(&pilha, palavra[i]);
    }
    for (int i = 0; i < len; i++) {
        if (palavra[i] != pop(&pilha)) {
            return 0;  
        }
    }
    return 1; 
}

int main() {
    char palavra[100];
    printf("Digite uma palavra: ");
    scanf("%s", palavra);
    if (ehPalindromo(palavra)) {
        printf("A palavra é um palíndromo.\n");
    }
    else {
        printf("A palavra não é um palíndromo.\n");
    }
    return 0;
}
