#include<stdio.h>
int main()
{
int a = 20,b=7,c;
c=a&b;
printf("And Result in decimal is %d, octal is %o,hexa decimal is %x ",c,c,c);
c=a|b;
printf("\nOr Result in decimal is %d, octal is %o,hexa decimal is %X ",c,c,c);
c=~a;
printf("\nNot Result in decimal is %d, octal is %o,hexa decimal is %X ",c,c,c);
c=a^b;
printf("\nXor Result in decimal is %d, octal is %o,hexa decimal is %X ",c,c,c);
c = a<<b;
printf("\nLeft shift Result in decimal is %d, octal is %o,hexa decimal is %X ",c,c,c);
c = 110>>2;
printf("\nRight shift Result in decimal is %d, octal is %o,hexa decimal is %X ",c,c,c);

return 0;
}

