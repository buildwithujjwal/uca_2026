#include <stdio.h>

int sign(int x) {

    int y = x >> 31;

    return y | !!(x);
}

int main() {

    printf("%d\n", sign(-23));
    printf("%d\n", sign(0));
    printf("%d\n", sign(130));

    return 0;
}

