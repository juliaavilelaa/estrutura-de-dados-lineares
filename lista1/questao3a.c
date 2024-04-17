#include <stdio.h>

int main() {
    char key = 'k', choice = 'c';
    int num = 3, count = 20;
    long date = 20240303;
    float yield = 10.3;
    double price = 99.99995;

    printf("key = %p\n", &key);
    printf("choice = %p\n", &choice);
    printf("num = %p\n", &num);
    printf("count = %p\n", &count);
    printf("date = %p\n", &date);
    printf("yield = %p\n", &yield);
    printf("price = %p\n", &price);

    return 0;
}