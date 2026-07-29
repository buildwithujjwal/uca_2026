#include <stdio.h>

int getByte(int x, int n) {

    x >>= (8*n);
    x &= 0xff;

    return x;
}

int main() {
    
    printf("0x%x\n", getByte(0x12345678, 1));
}
