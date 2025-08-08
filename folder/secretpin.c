#include <stdio.h>

int sumo (int x) {
	
	int i = x;
	int j, j1, sum;
	
	sum = 10;
	j=i;
	for (sum=10,j=i;sum>=10;j=sum)
	{
		for (sum=0;j>0;j/=10)
		{
		j1 = j %10;
		sum += j1;
		}
	}
	
	return sum;
}


int main()
{
	int a, b, c, d, fd, sd, td, ld, pin;
	printf("Enter three numbers: \n");
	scanf(" %d %d %d", &a, &b, &c);
	
	fd = sumo(a);
	sd = sumo(b);
	td = sumo(c);
	d = fd + sd + td;
	ld = sumo(d);
	
	pin = (fd*1000)+(sd*100)+(td*10)+ld;
	printf("The pin is: %d\n", pin);
	/* printf("%d\n", fd);
	printf("%d\n", sd);
	printf("%d\n", td);
	printf("%d\n", d);
	printf("%d", ld); */
}
