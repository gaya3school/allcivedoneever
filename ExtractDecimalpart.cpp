#include <stdio.h>

int main() 
{
   float n;
   int r = n;
   int r1 = n - r;
   printf ("Enter a number: ");
   scanf ("%f", &n);
   printf ("r is %d", r);
   printf ("The fraction part of the given number is %d",r1 );
   return 0;
}
