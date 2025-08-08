#include <stdio.h>
#include <string.h>

void sortnames( int n, char *names);

int main()
{
	int n, i;
	printf("Enter number of students: ");
	scanf(" %d", &n);
	
	char names[33];
	printf("Enter names: ");
	for (i=0;i<n;i++)
	{
		scanf(" %[^\n]s", names[i]);
	}
	
	sortnames(n, names[n] );
	
	return 0;
}

void sortnames(int n, char *names[n]) {
	int i, j;
	char temp[33];
	for (i=1;i<=n-1;i++)
	{
		for (j=0;j<n-i;j++)
		{
			if (strcmp(names[j], names[j+1]) > 0) {
				strcpy(temp, names[j]);
				strcpy(names[j], names[j+1]);
				strcpy(names[j+1], temp);
			}
		}
	}
	
	for (i=0;i<n;i++)
	{
		printf("%s\n", names[i]);
	}
}