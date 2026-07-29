#include <stdio.h>

int bitXor(int x, int y) {
	
    int a = x & y;

    int b = ~x & ~y;

    return ~a & ~b;
}

int main() {

    printf( "%d\n", bitXor(4, 5) );
}
