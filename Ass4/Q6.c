#include <stdio.h>

int localShift(int x, int n) {
    
    x >>= n;
    int mask = ~((  (1 << 31)  >> n) << 1);
    return x & mask;
    

}

int main() {

    int x = 0x87654321, n = 4;
    printf( "0x%08x\n", localShift(x, n) );
    return 0;
}

