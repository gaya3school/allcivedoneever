#include <stdio.h>
#include <stdlib.h>

void create(int element);
void display();
void insert_at_begin(int elemento);
void insert_at_end (int elementi);
void insert_at_position (int elemente, int position);
void insert_after_position (int elementio, int position);
int linear_search(int element);
int find_min();
int find_max();
int count();
int sum();
int product ();
void delete_at_beginning();
void delete_at_end();
void delete_at_position(int positi);
void bubblesort();
void reverse();

struct node {
	int data;
	struct node *link;
};

struct node *head=NULL, *curr;

int main() {
	printf("1 - create\n2 - display\n3 - insert at the beginning\n4 - insert at end\n5 - insert at position\n6 - count\n7 - find maximum\n8 - find minimum\n9 - search\n10 - insert after position\n11 - sum\n12 - product\n13 - delete at beginning\n14 - delete at end\n15 - delete by position\n16 - bubble sort\n17 - reverse\n0 - exit \n");
	int choice, element, position, findmax, findmin, pos, counte, sume, producte;
	while (1) {
		printf("\nEnter your choice: ");
		scanf(" %d", &choice);
	
		switch(choice) {
			case 0:
				printf("Exiting...");
				return 0;
			case 1: 
				printf("Enter data part: ");
				scanf(" %d", &element);
				create (element);
				break;
			case 2: 
				display();
				break;
			case 3: 
				printf("Enter data part: ");
				scanf(" %d", &element);
			
				insert_at_begin(element);
				break;
			case 4:
				printf("Enter data part: ");
				scanf(" %d", &element);
			
				insert_at_end(element);
				break;
			case 5:
				printf("Enter position: ");
				scanf(" %d", &position);
				
				printf("Enter element: ");
				scanf(" %d", &element);
				insert_at_position (element, position);
				break;
			case 6:
				counte = count();
				if (count==0) {
					printf("The list is empty. ");
				} else {
					printf("The number of nodes is %d", counte);
				}
				break;
			case 7:
				findmax = find_max();
				if (findmax != -1){
					printf("The maximum data is %d", findmax);
				}
				break;
			case 8:
				findmin = find_min();
				if (findmin != -1){
					printf("The minimum data is %d", findmin);
				}
				break;
			case 9:
				printf("Enter element to search for: ");
				scanf(" %d", &element);
				
				pos = linear_search(element);
				if (pos!=0) {
					printf("Element was found at %d node.", pos);
				} else {
					printf("Element was not found.");
				}
				break;
			case 10:
				printf("Enter position: ");
				scanf(" %d", &position);
				
				printf("Enter element: ");
				scanf(" %d", &element);
				insert_after_position (element, position);
				break;
			case 11:
				sume = sum();
				if (sume==-1) {
					printf("The list is empty.");
				} else {
					printf("The sum of all data parts is %d", sume);
				}
				break;
			case 12:
				producte = product();
				if (producte==-1) {
					printf("The list is empty");
				} else {
					printf("The product of all data parts is %d", producte);
				}
				break;
			case 13:
				delete_at_beginning();
				break;
			case 14:
				delete_at_end();
				break;
			case 15:
				printf("Enter position (starting from 1): ");
				scanf(" %d", &position);
				delete_at_position(position);
				break;
			case 16:
				bubblesort();
				break;
			case 17:
				reverse();
				break;
			default: 
				printf("Invalid choice. ");
		}
	}
}

void create (int element) {
	struct node *newnode; 
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode -> data = element;
	newnode -> link = NULL;
	if (head==NULL) {
		head = newnode; 
	} else {
		curr -> link = newnode;
	}
	curr = newnode;
}

void display () {
	struct node *temp = head; 
	if (temp == NULL) {
		printf("List is empty. ");
	} else {
		printf("The list is: ");
		while (temp!=NULL) {
			printf("%d ", temp -> data);
			temp = temp -> link;
		}
	}
}

void insert_at_begin(int elemento) {
	struct node *newnode; 
	newnode = (struct node *)malloc (sizeof (struct node));
	newnode -> data = elemento;
	newnode -> link = head;
	head = newnode; 
}

void insert_at_end (int elementi) {
	struct node *newnode; 
	newnode = (struct node *)malloc (sizeof (struct node));
	newnode -> data = elementi;
	newnode -> link = NULL;
	curr -> link = newnode;
	curr = newnode;
}

void insert_at_position (int elemente, int position) {
	struct node *newnode, *temp = head;
	int counte = 0;
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode -> data = elemente;
	newnode -> link = NULL;
	
	if (position==1){
		insert_at_begin(elemente);
	} else if (position==count()){
		insert_at_end (elemente);
	} else {
		while (temp != NULL) {
			counte++;
			if (counte==position-1) {
				newnode -> link = temp -> link;
				temp -> link = newnode;
				return;
			}
			temp = temp -> link;
		}
	}
}

void insert_after_position (int elementio, int position) {
	struct node *newnode, *temp = head;
	int countio = 0;
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode -> data = elementio;
	newnode -> link = NULL;
	
	if (position==0){
		insert_at_begin(elementio);
	} else if (position==count()-1){
		insert_at_end (elementio);
	} else {
		while (temp != NULL) {
			countio++;
			if (countio==position) {
				newnode -> link = temp -> link;
				temp -> link = newnode;
				return;
			}
			temp = temp -> link;
		}
	}
}

int count() {
	struct node *temp = head;
	int count = 0;
	while (temp!=NULL) {
		count++;
		temp = temp -> link;
	}
	return count;
}

int find_max() {
	struct node *temp = head;
	int max = temp -> data;
	if (head==NULL) {
		printf("List is empty");
	} else {
		while (temp!=NULL) {
			if (temp->data > max) {
				max = temp -> data;
			}
			temp = temp -> link;
		}
		
		return max;
	}
}

int find_min() {
	struct node *temp = head;
	int min = temp -> data;
	if (head==NULL) {
		printf("List is empty");
	} else {
		while (temp!=NULL) {
			if (temp->data < min) {
				min = temp -> data;
			}
			temp = temp -> link;
		}
		
		return min;
	}
}

int linear_search(int element) {
	struct node *temp = head;
	int found = 0, count=0;
	while (temp!=NULL) {
		count++;
		if (temp -> data == element) {
			found = count;
		}
		temp = temp -> link;
	}
	
	return found;
}

int sum(){
	struct node *temp = head;
	int sume = 0;
	if (temp==NULL) {
		return -1;
	} else {
		while (temp!=NULL) {
			sume += temp -> data;
			temp = temp -> link;
		}
		return sume;
	}
}

int product () {
	struct node *temp = head;
	int producte = 1;
	if (temp==NULL) {
		return -1;
	} else {
		while (temp!=NULL) {
			producte *= temp -> data;
			temp = temp -> link;
		}
		return producte;
	}
}

void delete_at_beginning() {
	struct node *temp = head;
	if (temp==NULL) {
		printf("List is empty. ");
		return;
	} else {
		printf("\nData being deleted is %d", temp -> data);
		head = head -> link;
		free(temp);
		return;
	}
}

void delete_at_end () {
	struct node *temp=head;
	if (temp==NULL) {
		printf("List is empty.");
		return;
	} else if (head->link==NULL) {
		printf("\nData being deleted is %d", temp -> data);
		free(head);
		head = NULL;
		return;	
	} else {
		while (temp->link!=curr){
			temp = temp -> link;
		}
		printf("\nData being deleted is %d", temp -> data);
		temp -> link = NULL;
		free(curr);
		curr = temp;
	}
}

void delete_at_position(int positi) {
	struct node *temp=head, *prev=NULL;
	int countio = 1;
	if (positi==1){
		delete_at_beginning();
	} else if (positi==count()){
		delete_at_end();
	} else {
		while (temp != NULL && countio<positi) {
			prev = temp;
			temp = temp -> link;
			countio++;
		}
		
		prev->link = temp -> link;
		free(temp);
	}
}

void bubblesort() {
	struct node *temp = head, *next;
	if (temp==NULL) {
		printf("List is empty");
		return; 
	} else {
		while (temp!=NULL) {
			next = temp;
			while (next->link!=NULL){
				if (next -> data >  next->link-> data) {
					int tempio = next -> data;
					next -> data = next -> link -> data;
					next -> link -> data = tempio;
				}
				next = next -> link;
			}
			temp = temp -> link;
		}
	}
}

void reverse() {
	struct node *temp=head, *next, *prev=NULL;
	if (temp==NULL) {
		printf("List is empty");
		return;
	}
	
	while (temp!=NULL) {
		next = temp -> link;
		temp -> link = prev;
		prev = temp;
		temp = next;
	}
	curr = head;
	head = prev;	
}
