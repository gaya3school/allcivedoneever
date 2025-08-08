#include <stdio.h>
#include <stdlib.h>

#define size 10

struct node {
	int data;
	struct node *link;
} *HT[size];

void innit (){
	int i=0;
	while (i<size) {
		HT[i] = NULL;
		i++;
	}
}

void insert (int value) {
	struct node *temp, *newnode = (struct node *)malloc(sizeof(struct node));
	newnode -> data = value;
	newnode -> link = NULL;
	
	int index = value % size;
	if (HT[index] == NULL)
		HT[index] = newnode;
	else {
		temp = HT[index];
		while (temp->link!=NULL)
			temp = temp->link;
		temp -> link = newnode;
	}
}

void display() {
	struct node *temp = HT[0];
	int i=0;
	for (i=0;i<size;i++) {
		temp = HT[i];
		while (temp!=NULL) {
			printf("%d -> ", temp->data);
			temp = temp->link;
		}
		printf("NULL\n");
	}	
}

void search(int value) {
	int index = value % size, position=1;
	struct node *temp;
	
	if (HT[index]==NULL) {
		printf("Value not found\n");
		return;
	}	
	
	if (HT[index]->data == value) {
		printf("Value found at %d index %d position\n", index, position);
		return;
	} else {
		temp = HT[index]->link;
		while (temp!=NULL) {
			position++;
			if (temp->data==value) {
				printf("Value found at %d index %d position\n", index, position);
				return;
			}
			temp = temp->link;
		}
		printf("value not found\n");
	}
}

int main() {
	int choice, value;
	printf("0 - Exit\n1 - insert\n2 - Display\n3 - Search\n");
	innit();
	while (1) {
		printf("Enter choice: ");
		scanf(" %d", &choice);
		
		switch (choice) {
			case 0:
				printf("Exiting...");
				return 0;
			case 1:
				printf("Enter value: ");
				scanf(" %d", &value);
				
				insert(value);
				break;
			case 2:
				display();
				break;
			case 3:
				printf("Enter the value to search for: ");
				scanf(" %d", &value);
				
				search(value);
				break;
			default:
				printf("Invalid choice\n");
		}
	}
}