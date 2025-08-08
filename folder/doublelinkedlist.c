#include <stdio.h> 
#include <stdlib.h>

struct dnode {
	struct dnode *left;
	int data;
	struct dnode *right;
};

struct dnode *head = NULL, *curr;

void create(int element);
void display_forward();
void display_backward();
void insert_at_begin(int element);
void insert_at_end (int element);
int count();
void insert_at_position (int element, int position);
int find_max ();
int find_min();
void delete_at_begin();
void delete_at_end();
void delete_at_position(int position);
int linear_search(int x);
void sort();
long long int product ();
int sum();

int main () {
	int choice, element, position, res;
	long long int re;
	printf("0 - exit \n1 - create \n2 - display forward \n3 - display backward / in reverse\n4 - insert at beginning \n5 - insert at end \n6 - count");
	printf("\n7 - insert at position \n8 - find maximum \n9 - find minimum \n10 - delete at beginning \n11 - delete at end\n12 - delete at position");
	printf("\n13 - search\n14 - sort\n15 - product\n16 - sum");
	
	while (1) {
		printf("\nEnter your choice: ");
		scanf(" %d", &choice);
		
		switch(choice) {
			case 0:
				printf("Exiting...");
				return 0;
			case 1:
				printf("Enter element: ");
				scanf(" %d", &element);
				
				create(element);
				break;
			case 2: 
				printf("The list in normal is: ");
				display_forward();
				break;
			case 3:
				printf("The list in reverse is: ");
				display_backward();
				break;
			case 4:
				printf("Enter element: ");
				scanf(" %d", &element);
				
				insert_at_begin(element);
				break;
			case 5:
				printf("Enter element: ");
				scanf(" %d", &element);
				
				insert_at_end(element);
				break;
			case 6:
				if (count()) {
					printf("The number of node(s) is %d", count());
				} else {
					printf("The list is empty");
				}
				break;
			case 7:
				printf("Enter position: ");
				scanf(" %d", &position);
				
				printf("Enter element: ");
				scanf(" %d", &element);
				
				insert_at_position(element, position);
				break;
			case 8:
				res = find_max();
				if (res==-1) {
					printf("List is empty.");
				} else {
					printf("The maximum element is %d", res);
				}
				break;
			case 9:
				res = find_min();
				if (res==-1) {
					printf("List is empty.");
				} else {
					printf("The minimum element is %d", res);
				}
				break;
			case 10:
				delete_at_begin();
				break;
			case 11:
				delete_at_end();
				break;
			case 12:
				printf("Enter position: ");
				scanf(" %d", &position);
				delete_at_position(position);
				break;
			case 13:
				printf("Enter the element to search for: ");
				scanf(" %d", &element);
				
				int ll = linear_search(element);
				if (ll!=0 && ll!=-1) {
					printf("Element was found at %d node", ll);
				} else if (ll==0){
					printf("Element was not found");
				} else {
					printf("List is empty.");
				}
				break;
			case 14:
				sort();
				printf("The list sorted is: ");
				display_forward();
				break;
			case 15:
				re = product();
				if (re==-1) {
					printf("List is empty");
				} else {
					printf("The product of all the elements is %lld", re);
				}
				break;
			case 16:
				re = sum();
				if (re==-1) {
					printf("List is empty");
				} else {
					printf("The sum of all the elements is %lld", re);
				}
				break;
			default: 
				printf("Invalid choice.");
		}
	}
}

void create(int element) {
	struct dnode *newnode;
	newnode = (struct dnode*)malloc(sizeof(struct dnode));
	newnode -> left = NULL;
	newnode -> data = element;
	newnode -> right = NULL;
	
	if (head == NULL) {
		head = newnode;
	} else {
		newnode -> left = curr;
		curr -> right = newnode;
	}
	
	curr = newnode;
}

void display_forward() {
	struct dnode*temp = head;
	
	if (head==NULL) {
		printf("List is empty");
		return;
	} 
	
	while (temp!=NULL) {
		printf("%d ", temp->data);
		temp = temp->right;
	}
}

void display_backward() {
	struct dnode*temp = curr;
	
	if (head==NULL) {
		printf("List is empty");
		return;
	} 
	
	while (temp!=NULL) {
		printf("%d ", temp->data);
		temp = temp->left;
	}
}

void insert_at_begin (int element) {
	if (head==NULL) {
		create(element);
		return;
	}
	
	struct dnode *newnode;
	newnode = (struct dnode*)malloc(sizeof(struct dnode));
	newnode -> left = NULL;
	newnode -> data = element;
	newnode -> right = NULL;
	
	head -> left = newnode;
	newnode -> right = head;
	head = newnode;
	return;
}

void insert_at_end (int element) {
	if (head==NULL) {
		create(element);
		return;
	}
	
	struct dnode *newnode;
	newnode = (struct dnode*)malloc(sizeof(struct dnode));
	newnode -> data = element;
	newnode -> right = NULL;
	
	newnode -> left = curr;
	curr -> right = newnode;
	curr = newnode;
	return;
}

int count() {
	struct dnode *temp = head;
	int c=0;
	if (head==NULL) {
		return 0;
	}
	
	while (temp != NULL) {
		c++;
		temp = temp -> right;
	}
	
	return c;
}

void insert_at_position (int element, int position) {
	if (head==NULL) {
		printf("List is empty... creating new list");
		create (element);
		return;
	}
	
	if (position==1) {
		insert_at_begin(element);
		return;
	} else if (position==count()) {
		insert_at_end(element);
		return;
	}
	
	struct dnode *temp = head, *newnode;
	newnode = (struct dnode*)malloc(sizeof(struct dnode));
	newnode -> data = element;
	int c = 0;
	while (temp!=NULL) {
		c++;
		if (c==position-1) {
			newnode -> right = temp -> right;
			newnode -> left = temp;
			newnode -> right -> left = newnode;
			temp -> right = newnode;
		}
		temp = temp -> right;
	}
}

int find_max () {
	struct dnode *temp = curr;
	int max = curr -> data;
	if (head==NULL) {
		return -1;
	}
	
	while (temp!=NULL) {
		if (temp -> data > max) {
			max = temp -> data;
		}
		temp = temp -> left;
	}
	return max;
}

int find_min () {
	struct dnode *temp = curr;
	int min = curr -> data;
	if (head==NULL) {
		return -1;
	}
	
	while (temp!=NULL) {
		if (temp -> data < min) {
			min = temp -> data;
		}
		temp = temp -> left;
	}
	return min;
}

void delete_at_begin() {
	struct dnode *temp = head;
	if (head==NULL) {
		printf("List is empty.");
		return;
	} else if (head -> right == NULL) {
		head = NULL;
		curr = NULL;
		free(temp);
		return;
	}
	
	head = head -> right;
	head -> right -> left = NULL;
	free (temp);
}

void delete_at_end() {
	struct dnode *temp = head;
	if (head==NULL) {
		printf("List is empty");
		return;
	} else if (head -> right == NULL) {
		head = NULL;
		curr = NULL;
		free(temp);
		return;
	}
	
	temp = curr;
	curr -> left -> right = NULL;
	curr = curr -> left;
	free (temp);
}

void delete_at_position(int position) {
	struct dnode *temp = head, *del;
	int c = 0;
	if (head==NULL) {
		printf("List is empty");
		return;
	}
	
	if (position <1 || position >count()) {
		printf("Position is invalid.");
		return;
	}
	
	if (position==1) {
		delete_at_begin();
	} else if (position==count()) {
		delete_at_end();
	} else {
		while (temp!=NULL) {
			c++;
			if (c==position-1) {
				del = temp -> right;
				temp -> right = temp -> right -> right;
				temp -> right -> left = temp;
				free (del);
				return;
			}
			temp = temp -> right;
		}
	}
}

int linear_search(int x) {
	int found = 0;
	if (head==NULL) {
		return -1;
	}
	
	struct dnode *temp = head;
	while (temp!=NULL) {
		found++;
		if (temp -> data == x) {
			return found;
		}
		temp = temp -> right;
	}
	
	if (temp==NULL) {
		return 0;
	}
}

void sort () {
	if(head==NULL) {
		printf("List is empty");
		return;
	}
	int c = 0;
	struct dnode *temp;
	while (c<count()) {
		temp = head;
		while (temp->right!=NULL) {
			if (temp -> data > temp -> right -> data) {
				int tempe = temp -> data;
				temp -> data = temp -> right -> data;
				temp -> right -> data = tempe;
			}
			temp = temp -> right;
		}
		c++;
	}
}

long long int product () {
	if (head==NULL) {
		return -1;
	}
	long long int p = 1;
	struct dnode *temp = head;
	while (temp!=NULL) {
		p *= temp -> data;
		temp = temp -> right;
	}
	return p;
}

int sum () {
	if (head==NULL) {
		return -1;
	}
	
	int s = 0;
	struct dnode *temp = head;
	while (temp!=NULL) {
		s += temp -> data;
		temp = temp -> right;
	}
	return s;
}
