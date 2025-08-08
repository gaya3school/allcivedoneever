#include <stdio.h>
#include <stdlib.h>

int size = 5;
int stack[5];
int top = -1;

void peek();
void display();
int pop();
void push (int x);

int main() {
	int ch, x, popi;
	printf("Size of Stack is 5 \n0 - Exit \n1 - Push \n2 - Pop \n3 - Display \n4 - Peek");
	
	while (1) {
		printf("\nEnter your choice: ");
		scanf(" %d", &ch);
		
		switch (ch) {
			case 0: 
				printf("Exiting..");
				exit(0);
			case 1:
				printf("Enter the element you want to Push: ");
				scanf(" %d", &x);
				push(x);
				break;
			case 2: 
				popi = pop();
				if (popi!=-1)
				{
					printf("Element being popped is: %d", popi);
				}
				break;
			case 3: 
				display();
				break;
			case 4: 
				peek();
				break;
			default: 
				printf("Invalid option entered: ");
		}
	}
	return 0;
}

void push (int x) {
	if (top==size-1) {
		printf("Stack overflow. ");
		return; 
	}
	
	stack[++top] = x;
}

int pop() {
	if (top==-1) {
		printf("Stack empty. ");
		return -1; 
	}
	
	return stack[top--];
}

void display() {
	int i;
	if (top==-1) {
		printf("Stack is empty. ");
		return;
	}
	
	for (i=top;i>=0;i--) {
		printf("%d\n", stack[i]);
	}
}

void peek() {
	if (top==-1) {
		printf("Stack is empty. ");
		return;
	}
	
	printf("%d ", stack[top]);
}