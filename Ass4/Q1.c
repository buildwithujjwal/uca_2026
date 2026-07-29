#include<stdio.h>

int bitAnd(int x, int y) {

    x = ~x;
    y = ~y;

    int z = x | y;

    return ~z;
}

int main() {
    
    int x = 5, y = 6;
    printf( "%d\n", bitAnd(x, y) );
    return 0;
}
