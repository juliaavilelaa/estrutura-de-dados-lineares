#include <stdio.h>

int main() {
    char key = 'k', choice = 'c';
    int num = 3, count = 20;
    long date = 20240303;
    float yield = 10.3;
    double price = 99.99995;

    printf("key = %p (size = %lu bytes)\n", &key, sizeof(key));
    printf("choice = %p (size = %lu bytes)\n", &choice, sizeof(choice));
    printf("num = %p (size = %lu bytes)\n", &num, sizeof(num));
    printf("count = %p (size = %lu bytes)\n", &count, sizeof(count));
    printf("date = %p (size = %lu bytes)\n", &date, sizeof(date));
    printf("yield = %p (size = %lu bytes)\n", &yield, sizeof(yield));
    printf("price = %p (size = %lu bytes)\n", &price, sizeof(price));

    return 0;
}
