#include <stdio.h>

void encontra(int v[], int n, int *min, int *max) {
    *min = v[0];
    *max = v[0];

    for (int i = 1; i < n; i++) {
        if (v[i] < *min) {
            *min = v[i];
        }
        if (v[i] > *max) {
            *max = v[i]; 
        }
    }
}

int main() {
    int n, min, max, i;

    printf("Insira o tamanho do vetor: ");
    scanf("%d", &n);
    int v[n];

    for (i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    encontra(v, n, &min, &max);

    printf("Minimo: %d\n", min);
    printf("Maximo: %d\n", max);

    return 0;
}