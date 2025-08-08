#include <stdio.h> 
#include <stdlib.h>

struct cnode {
	int data;
	struct cnode *link;
};

struct cnode *head=NULL, *curr;

void create (int element);
void display();
void insert_at_begin(int elemento);
void insert_at_end(int elementi);
void insert_at_position (int elemente, int position);
int  linear_search(int element);
int count();
void delete_at_position(int positi);
void delete_at_end();
void delete_at_beginning();
int find_max();
int find_min();
void bubblesort();
void reverse();
long long int product();
int sum();

int main() {
	printf("1 - create\n2 - display\n3 - insert at the beginning\n4 - insert at end\n5 - insert at position\n6 - count\n7 - find maximum\n8 - find minimum\n9 - search\n10 - delete at beginning\n11 - delete at end\n12 - delete by position\n13 - bubble sort\n14 - reverse\n14 - product \n15 - sum\n0 - exit \n");
	int choice, element, position, findmax, findmin, counte, sume, producte;
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
				
				position = linear_search(element);
				if (position!=0) {
					printf("Element was found at %d node.", position);
				} else {
					printf("Element was not found.");
				}
				break;
			case 10:
				delete_at_beginning();
				break;
			case 11:
				delete_at_end();
				break;
			case 12:
				printf("Enter position (starting from 1): ");
				scanf(" %d", &position);
				delete_at_position(position);
				break;
			case 13:
				bubblesort();
				break;
			case 14:
				reverse();
				printf("The list reversed is: ");
				display();
				break;
			case 15:
				printf("The product of all the data part is %d", product());
				break;
			case 16:
				printf("The sum of all the data parts is %d", sum());
			default: 
				printf("Invalid choice. ");
		}
	}
}

void create (int element) {
	struct cnode *newnode; 
	newnode = (struct cnode *)malloc(sizeof(struct cnode));
	newnode -> data = element;
	if (head==NULL) {
		head = newnode; 
		curr = newnode;
	} else {
		curr -> link = newnode; 
		curr = newnode;
	}
	newnode -> link = head;
}

void display() {
	struct cnode *temp = head;
	if (temp == NULL) {
		printf("List is empty. ");
		return;
	} else {
		printf("The list is: ");
		do {
			printf("%d ", temp->data);
			temp = temp -> link;
		} while (temp!=head);
	}
}

void insert_at_begin(int elemento) {
	struct cnode *newnode; 
	if (head==NULL) {
		create(elemento);
		return;
	}
	
	newnode = (struct cnode *)malloc (sizeof (struct cnode));
	newnode -> data = elemento;
	curr -> link = newnode;
	newnode -> link = head;
	head = newnode; 
}

void insert_at_end(int elementi) {
	struct cnode *newnode; 
	if (head==NULL) {
		create(elementi);
		return;
	}
	newnode = (struct cnode *)malloc (sizeof (struct cnode));
	newnode -> data = elementi;
	curr -> link = newnode;
	newnode -> link = head;
}

void insert_at_position (int elemente, int position) {
	struct cnode *newnode, *temp=head;
	
	if (head==NULL) {
		printf("List is empty...creating newnode");
		create(elemente);
		return;
	}
	
	int counte = 0;
	newnode = (struct cnode *)malloc(sizeof(struct cnode));
	newnode -> data = elemente;
	
	if (position==1){
		insert_at_begin(elemente);
	} else if (position==count()){
		insert_at_end (elemente);
	} else {
		do {
			counte++;
			if (counte==position-1){
				newnode -> link = temp -> link;
				temp -> link = newnode;
			}
			temp = temp -> link;
		} while (temp != head) ;
	}
}

int  linear_search(int element) {
	struct cnode *temp = head;
	
	if (temp == NULL) {
		return 0;
	}
		
	int found = 0, count=0;
	do {
		count++;
		if (temp -> data == element) {
			found = count;
		}
		temp = temp -> link;
	} while (temp!=head);
	
	return found;
}

int count() {
	struct cnode *temp = head;
	int counte = 0;
	
	if (head==NULL) {
		return counte;
	}
	
	do {
		counte++;
		temp = temp -> link;
	} while (temp != head);
	
	return counte;
}

void delete_at_beginning() {
	if (head==NULL) {
		printf("List is empty. ");
		return;
	}
	
	if (head->link==head) {
		free(head);
		head = NULL;
		return;
	}
	struct cnode *temp = head;
	curr -> link = head -> link;
	head = head -> link;
	free(temp);
}

void delete_at_end () {
	struct cnode *temp = head;
	if (head==NULL) {
		printf("List is empty. ");
		return;
	}
	
	if (head->link==NULL) {
		free(head);
		curr = NULL;
		head = NULL;
		return;
	}
	
	do {
		temp = temp -> link;
	} while (temp->link!=curr);
	
	temp -> link = curr -> link;
	free (curr);
	curr = temp;
	return;
}

void delete_at_position(int positi) {
	struct cnode *temp=head, *prev=NULL;
	int countio = 0;
	if (positi==1){
		delete_at_beginning();
		return;
	} else if (positi==count()){
		delete_at_end();
		return;
	}
	do {
			countio++;
			if (countio==positi-1) {
				prev = temp;
				temp = temp -> link;
				prev -> link = temp -> link;
				free (temp);
				return;
			}
			prev = temp;
			temp = temp -> link;
	} while (temp != head);
}

int find_max () {
	struct cnode *temp = head;
	int max = temp -> data; 
	
	if (head==NULL) {
		printf("List is empty.");
		return -1;
	}
	
	do {
		if (temp -> data > max) {
			max = temp -> data;
		}
		temp = temp -> link;
	} while (temp!=head);
	
	return max;
}

int find_min() {
	struct cnode *temp = head;
	int min = temp -> data;
	
	if (head==NULL) {
		printf("List is empty");
		return -1;
	}
	
	do {
		if (temp -> data < min) {
			min = temp -> data;
		}
		temp = temp -> link;
	} while (temp != head);
	
	return min;
}

void bubblesort() {
    if (head == NULL) {
        return;
    }

    struct cnode *temp = head;
    int swapped;

    do {
        temp = head;
        swapped = 0;
        while (temp->link != head) 
    	{
            if (temp->data > temp->link->data) 
      		{
                int swap = temp->data;
                temp->data = temp->link->data;
                temp->link->data = swap;
                swapped = 1;
            }
            temp = temp->link;
        }
    } while (swapped);
}

void reverse() {
    if (head == NULL) {
    	printf("The list is empty. ");
        return;
    }

    struct cnode *prev = NULL, *curr = head, *next=NULL;

    do {
        next = curr->link;
        curr->link = prev;
        prev = curr;
        curr = next;
    } while (curr != head);

    head->link = prev;
    head = prev;
}

long long int product () {
	long long int prod = 1;
	struct cnode *temp = head;
	do {
		prod *= temp -> data;
		temp = temp -> link;
	} while (temp != head);
	
	return prod;
}

int sum() {
	int sume = 0;
	struct cnode *temp = head;
	do {
		sume += temp -> data;
		temp = temp -> link;
	} while (temp != head);
	
	return sume;
}