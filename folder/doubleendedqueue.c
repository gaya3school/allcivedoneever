#include <stdio.h>

#define size 5
int deque[size];
int front = -1;
int rear = -1;

int isfull() {
	if ( (front==0 && rear == size-1) || (front == rear + 1) )
		return 1;
	else 
		return 0;
}

int isempty() {
	if (front==-1) 
		return 1;
	else
		return 0;
}

void insert_rear(int ele) {
	if (isfull()) {
		printf("Queue is full.");
		return;
	}
	
	if (rear==-1) {
		front = rear = 0;
	} else if (rear == size-1) {
		rear=0;
	} else {
		rear++;
	}
	deque[rear] = ele;
}

void insert_front(int ele) {
	if (isfull()) {
		printf("Queue is full.");
		return;
	}
	
	if (front==-1) {
		front = rear = 0;
	} else if (front == 0) {
		front = size-1;
	} else {
		front --;
	}
	deque[front] = ele;
}

void delete_front() {
	if (isempty()) {
		printf("Queue is empty. ");
		return;
	}
	
	printf("The element being deleted is %d\n", deque[front]);
	if (front==rear) {
		front = rear = -1;
		printf("Front is %d rear is %d\n", front, rear);
	} else if (front==size-1) {
		front = 0;
		printf("Front is %d rear is %d\n", front, rear);
	} else {
		front++;
		printf("Front is %d rear is %d\n", front, rear);
	}
}

void delete_rear() {
	if (isempty()) {
		printf("Queue is empty. ");
		return;
	}
	
	printf("The element being deleted is %d\n", deque[rear]);
	if (front==rear) {
		front = rear = -1;
		printf("Front is %d rear is %d\n", front, rear);
	} else if (rear==0) {
		rear = size -1;
	} else {
		rear--;
	}
}


void display() {
	int i;
	printf("The queue is: ");
	for (i=front;i!=rear;) {
		printf("%d ", deque[i]);
		i = (i+1) % size;
	}
	printf("%d \n", deque[rear]);
}

int main() {
	int choice, ele;
	printf("0 - Exit\n1 - Insert at rear\n2 - Insert at front\n3 - Delete at front\n4 - Delete at rear\n5 - Display\n");
	
	while (1) {
		printf("Enter your choice: ");
		scanf(" %d", &choice);
		
		switch(choice) {
			case 0:
				printf("Exiting...");
				return 0;
			case 1:
				printf("Enter element you want to insert: ");
				scanf(" %d", &ele);
				
				insert_rear(ele);
				break;
			case 2:
				printf("Enter element you want to insert: ");
				scanf(" %d", &ele);
				
				insert_front(ele);
				break;
			case 3:
				delete_front();
				break;
			case 4:
				delete_rear();
				break;
			case 5:
				display();
				break;
			default: 
				printf("Invalid choice entered.");
		}
	}
}