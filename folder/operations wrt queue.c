//operations wrt queue
#include <stdio.h>
#include <stdlib.h>

int size = 5;
int front = -1;
int rear = -1;
int queue[5];

void display ();
int dequeue ();
void enqueue (int x);

int main()
{
	int x, ch, dequeuedd;
	printf("Size of queue is 5\n0 - Exit \n1 - Enqueue \n2 - Dequeue \n3 - Display");
	
	while (1)
	{
		printf("\nEnter choice: ");
		scanf(" %d", &ch);
		
		switch (ch)
		{
			case 0:
				printf("Exiting...");
				exit(0);
			case 1:
				printf("Enter the element you want to Enqueue: ");
				scanf(" %d", &x);
				enqueue(x);
				break;
			case 2:
				dequeuedd = dequeue();
				if (dequeuedd!=-1)
				{
					printf("Element being dequeued is %d", dequeuedd);
				}
				break;
			case 3: 
				display();
				break;
			default: 
				printf("Invalid option chosen. ");
		}
	}
	
	return 0;
}

void enqueue (int x)
{
	if (rear==size-1){
		printf("Queue is full");
		return;
	}
	
	if (rear==-1) {
		front = 0;
		rear = 0;
		queue[rear] = x;
	} else {
		queue[++rear] = x;
	}
	return; 
}

int dequeue ()
{
	int dequeued;
	if (front==-1)
	{
		printf("Queue is empty");
		return -1; 
	}
	else if (front==rear)
	{
		dequeued = queue[front];
		front = -1;
		rear = -1;
		return dequeued; 
	}
	else
	{
		dequeued = queue[front++];
		return dequeued; 
	}
}

void display ()
{
	int i; 
	if (front==-1)
	{
		printf("Queue is empty. ");
		return;
	}
	
	for (i=front;i<=rear;i++)
	{
		printf("%d ", queue[i]);
	}
}