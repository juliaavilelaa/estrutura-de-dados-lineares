#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// strcmp(s1, s2)
// s1 == s2 NULL (o valor não ta na lista)
// positivo s1 > s2 (vem depois)
// negativo s1 < s2 (vem antes)

typedef struct NoLSE {
    char nome[100];
    char fone[20];
    char email[50];
    struct NoLSE* prox;
} TNoLSE;

typedef struct Agenda {
    TNoLSE* inicio;
    TNoLSE* fim;
    int qtd;
} LSEOrdenada;

void inicializar(LSEOrdenada* lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->qtd = 0;
}

TNoLSE* buscar(LSEOrdenada lista, char nome[]) {
    TNoLSE* aux;

    if (isEmpty(lista)) {
        return NULL;
    }
    else {
        if (strcmp(lista.inicio->nome, nome) == 0) {
            return lista.inicio;
        } else if(strcmp(nome, lista.inicio->nome) < 0) {
            return NULL;
        } else if (strcmp(lista.fim->nome, nome) == 0) {
            return lista.fim;
        } else if (strcmp(nome, lista.fim->nome) > 0) {
            return NULL;
        } else {
            aux = lista.inicio->prox;
            while (aux != lista.fim) {
                if (strcmp(aux->nome, nome) == 0) {
                    return aux;
                } else if (strcmp(aux->nome, nome) > 0) {
                    return NULL;
                } else {
                    aux = aux->prox;
                }
            }
        }
    }
}

void procurar(LSEOrdenada lista, char nome[]) {
    TNoLSE* retorno = buscar(lista, nome);

    if (retorno == NULL) {
        printf("Contato nao encontrado.\n");
    } else {
        printf("Fone: %s\n", retorno->fone);
        printf("E-mail: %s\n", retorno->email);
    }
}

void alterar(LSEOrdenada lista, char nome[]) {
    TNoLSE* retorno = buscar(lista, nome);

    if (retorno == NULL) {
        printf("Contato nao encontrado.\n");
    } else {
        printf("Fone atual: %s\n", retorno->fone);
        printf("Informe o novo fone: ");
        gets(retorno->fone);

        printf("E-mail atual: %s\n", retorno->email);
        printf("Informe o novo e-mail: ");
        gets(retorno->email);
    }
}

int isEmpty(LSEOrdenada lista) {
    return lista.inicio == NULL;
}

int isFull(LSEOrdenada lista) {
    return 0;
}

int main() {
    LSEOrdenada agenda;
    inicializar(&agenda);
    int op;

    do {
        scanf("%d", &op);
        switch(op) {
            case 1: //adicionar
                break;
            case 2: //remover
                break;
            case 3: //exibir
                break;
            case 4: //procurar
                break;
            case 5: //alterar
                break;
            case 0:
                printf("Encerrando programa...\n");
                break;
            default:
        }
    } while (op != 0);

    return 0;
}