#include <stdio.h>

void bruteForce(int n) { 
   int a = 0, b = 1, next, sum= 0;
   
   while(a < n) {

      if(a % 2 == 0) sum += a;
      next = a + b;
      a = b;
      b = next;
   }

   printf ("Sum with brute force approach is : %d\n", sum);
}

void optimised(int n) {
   int a = 2, b = 8, sum = 0;	

   while(a <= n) {

      sum += a;
      int next = 4*b + a;
      a = b;
      b = next;
   }

   printf ("Sum with optimised approach : %d\n", sum);

}

int main() {
   int n;
   int a = 0, b = 1, next;

   printf("type n : ");
   scanf("%d" , &n);

   bruteForce(n);
   optimised(n);

   return 0;
}
