//stack and queue with linked list
#include <stdio.h>
#include <stdlib.h>

struct queue {
	int data;
	struct queue *link;
};

struct queue *front = NULL, *rear = NULL;

void enqueue (int element);
void dequeue();
void display();

int main() {
	int choice, element;
	printf("0 - exit\n1 - enqueue\n2 - dequeue\n3 - display");
	
	while (1) {
		printf("\nEnter your choice: ");
		scanf(" %d", &choice);
		
		switch (choice) {
			case 0:
				printf("Exiting...");
				return 0;
			case 1:
				printf("Enter the element you want to enqueue: ");
				scanf(" %d", &element);
				
				enqueue(element);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			default: 
				printf("Invalid choice. ");
		}
	}
}

void enqueue(int element) {
	struct queue *newnode;
	newnode = (struct queue *)malloc(sizeof(struct queue));
	newnode -> data = element;
	newnode -> link = NULL;
	if (front==NULL) {
		front = newnode;
		rear = newnode;
	} else {
		rear -> link = newnode;
		rear = newnode;
	}	
}

void dequeue() {
	struct queue *temp = front;
	if (front==NULL) {
		printf("Queue is empty");
		return;
	}
	
	printf("Element being dequeued is %d", front->data);
	
	if (front==rear) {
		front = NULL;
		rear = NULL;
	} else {
		front = front -> link;
		temp -> link = NULL;
	}
	free (temp);
}

void display() {
	struct queue *temp;
	if (front==NULL) {
		printf("Queue is empty");
		return;
	}
	
	for (temp = front;temp !=NULL;temp = temp -> link) {
		printf("%d ", temp -> data);
	}
}


/* struct stack {
	int data;
	struct stack *link;
};

struct stack *top = NULL;

void push(int element);
void pop();
void display();
void peek();

int main() {
	int choice, element;
	printf("0 - exit\n1 - push\n2 - pop\n3 - display\n4 - peek");
	
	while (1) {
		printf("\nEnter your choice: ");
		scanf(" %d", &choice);
		
		switch (choice) {
			case 0:
				printf("Exiting...");
				return 0;
			case 1:
				printf("Enter the element you want to push: ");
				scanf(" %d", &element);
				
				push(element);
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				peek();
				break;
			default: 
				printf("Invalid choice. ");
		}
	}
}

void push(int element) {
	struct stack *newnode;
	newnode = (struct stack *)malloc(sizeof(struct stack));
	newnode -> data = element;
	newnode -> link = top;
	top = newnode;
	return;
}

void pop() {
	if (top==NULL) {
		printf("Stack Underflow");
		return;
	}
	
	struct stack *temp = top;
	top = top -> link;
	printf("Element being popped is %d", temp -> data);
	temp -> link = NULL;
	free (temp);
}

void display () {
	if (top==NULL) {
		printf("Stack underflow");
		return;
	}
	
	struct stack *temp = top;
	while (temp!=NULL) {
		printf("%d ", temp->data);
		temp = temp->link;
	}
}

void peek() {
	if (top==NULL) {
		printf("Stack is empty");
		return;
	}
	
	printf("The topmost element is %d", top->data);
} */

