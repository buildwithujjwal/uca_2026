#include <stdio.h>

int isPower2(int x) {

    int a = !!x;
    int b = !(x >> 31);
    int c = x + (~0);

    int d = !(x & c);

    return a & b & d;
}

int main() {

    printf( "%d %d %d %d", isPower2(5), isPower2(8), isPower2(0), isPower2(-5) );
    return 0;
}

