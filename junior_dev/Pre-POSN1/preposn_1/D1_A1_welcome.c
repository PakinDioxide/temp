#include <stdio.h>

int main() {
    int a, b, c;
    scanf("%d %d", &a, &b);
    while (a != 0 && b != 0) {
        a = a % b;
        c = a;
        a = b;
        b = c;
    }
    printf("%d", a);
}