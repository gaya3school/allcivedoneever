#include<stdio.h>
int main()
{
	int n,n1,n2,n3,i;
	printf("Enter first n fib series value");
	scanf("%d",&n);
	printf("Fibnocci series is \n");
	
	for(i=1,n1=0,n2=1;i<=n;n1=n2,n2=n3,i++)
	{
		n3=n1+n2;
		printf("%d  ",n3);    
	}
	
	return 0;
}
