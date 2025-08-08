// operations wrt. linked list
#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *link;	
};
typedef struct node node;
node *head = NULL;

void create();
void display();
int count();
int findmax();
int findmin();
int sum();
int search(int x);

int main()
{
	int x, ch;
	printf("\n1 - create \n2 - display \n3 - Find maximum element \n4 - Find minimum element \n5 - Find the sum of elements \n6 - Search for an element \n7 - Count number of elements \n0 - EXIT");
	
	//printf("\n%d head", head);
	
	while (1)
	{
		printf("\nEnter what you want to do: ");
		scanf(" %d", &ch);
		switch (ch)
		{
			case 0:
				printf("Exiting....");
				exit(0); //can be used only when stdlib is declared. works similar to the way return works in main function. 
			case 1: 
				create();
				break;
			case 2: 
				display();
				break;
			case 3: 
				
				if (findmax()==-1)
				{
					printf("The list is empty\n");
				}
				else
				{
					printf("The maximum element is %d", findmax());
				}
				break;
			case 4: 
				
				if (findmin()==-1)
				{
					printf("The list is empty\n");
				}
				else
				{
					printf("The minimum element is %d", findmin());
				}
				break;
			case 5: 
				if (sum()==-1)
				{
					printf("The list is empty\n");
				}
				else
				{
					printf("The sum of all the elements is %d", sum());
				}
				break;
			case 6: 
				printf("Enter the element you want to search for: ");
				scanf(" %d", &x);
				if (search(x))
				{
					printf("The element was found\n");
				}
				else
				{
					printf("The element was not found\n");
				}
				break;
			case 7: 
				if (count()==-1)
				{
					printf("The list is empty\n");
				}
				else
				{
					printf("The number of elements is %d", count());
				}
				break;
			default: 
				printf("Invalid Choice");
		}
	}
}

void create () 
{
	node *t, *temp;
	int x1;
	
	t = (node *)malloc(sizeof(node));
	t -> link = NULL;
	printf("Enter data part: ");
	scanf(" %d", &x1);
	t -> data = x1;
	
	if (head==NULL)
	{
		head = t;
		//printf("\n%d head", head);
	}
	else
	{
		temp = head;
		while (temp->link != NULL)
		{
			temp = temp -> link; 
		}
		temp -> link = t;
	}
}

void display ()
{
	node *temp = head;
	
	if (temp == NULL)
	{
		printf("The list is empty\n");
		return;
	}
	
	while (temp!=NULL)
	{
		printf("%d ", temp->data);
		temp = temp -> link;
	}
	//printf("\n%d temp -> link", temp);
}

int findmax ()
{
	if (head==NULL)
	{
		return -1;
	}
	node *temp = head;
	int max = head -> data;
	/*printf("\n%d head -> link", head -> link);
	printf("\n%d max", max); */
	
	do {
			if (temp -> data > max)
			{
				max = temp -> data;
			}
			
			temp = temp -> link;
		} while (temp != NULL);
	return max;
}

int findmin ()
{
	if (head==NULL)
	{
		return -1;
	}
	
	node *temp = head -> link;
	int min = head -> data;
	
	do {
		if (temp -> data < min)
		{
			min = temp -> data;
		}
		
		temp = temp -> link;
	} while (temp != NULL);	
	return min;
}

int sum()
{
	node *temp;
	int s = 0;
	temp = head;
	if (head==NULL)
	{
		return -1;
	}
	else
	{	
		while (temp!=NULL)
		{
			s = s + temp -> data;
			temp = temp -> link;
		}
	}
	return s;
}

int search (int x) 
{
	node *temp;
	int found = 0;
	temp = head;
	while (temp!=NULL)
	{
		if (temp->data == x)
		{
			found = 1;
			break;
		}
		
		temp = temp->link;
	}
	
	return found;
}

int count ()
{
	node *temp;
	int c =0;
	temp = head;
	if (head==NULL)
	{
		return -1;
	}
	else
	{	
		while (temp!=NULL)
		{		
			c++;
			temp = temp->link;
		}
	}
	return c;
}




