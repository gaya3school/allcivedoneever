#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node *left;
	char data;
	struct node *right;
} *root = NULL;

void create (char ele);
void insert (struct node *temp, struct node *newnode);
void inorder(struct node *temp); 
void preorder(struct node *temp);
void postorder(struct node *temp);

int main() {
	int choice; 
	char data;
	printf("0 - Exit\n1 - Create\n2 - Inorder\n3 - Preorder\n4 - Postorder\n");
	
	while (1) {
		printf("Enter choice: ");
		scanf(" %d", &choice);
		
		switch (choice) {
			case 0: 
				return 0;
			case 1: 
				printf("Enter data: ");
				scanf(" %c", &data);
				create(data);
				break;
			case 2:
				inorder(root);
				printf("NULL \n")				;
				break;
			case 3:
				preorder(root);
				printf("NULL \n");
				break;
			case 4:
				postorder(root);
				printf("NULL \n");
				break;
			default: printf("Invalid choice. \n");
		}
	}
}

void create (char ele) {
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	
	newnode -> data = ele; 
	newnode -> left = NULL;
	newnode -> right = NULL;
	
	if (root==NULL) 
		root = newnode;
	else
		insert (root, newnode);
}

void insert (struct node *temp, struct node *newnode) {
	char pref;
	printf("Enter the preference (L or l) OR (R or r): ");
	scanf(" %c", &pref);
	
	if (pref=='L' || pref=='l') {
		if (temp->left==NULL)
			temp->left = newnode;
		else
			insert(temp->left, newnode);
	} else if (pref=='R' || pref=='r') {
		if (temp->right==NULL)
			temp -> right = newnode;
		else
			insert(temp->right, newnode);
	}
}

void inorder(struct node *temp) {
	if (temp!=NULL) {
		inorder(temp->left);
		printf("%c -> ", temp->data);
		inorder(temp->right);
	}
}

void preorder(struct node *temp) {
	if (temp!=NULL) {
		printf("%c -> ", temp->data);
		preorder(temp->left);
		preorder(temp->right);
	}
}

void postorder (struct node *temp) {
	if (temp!=NULL) {
		postorder(temp->left); 
        postorder(temp->right); 
        printf("%c -> ", temp->data); 
	}
}