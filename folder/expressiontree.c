#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node {
	struct node *left;
	struct node *right;
	char data;
} *stack[40];

int top=-1;

void push(struct node *temp) {
	top++;
	stack[top] = temp;
}

struct node *pop() {
	return stack[top--];
}

void inorder(struct node *temp) {
	if (temp!=NULL) {
		inorder (temp->left);
		printf(" %c", temp->data);
		inorder(temp->right);
	}
}

void main() {
	char postfix[30];
	int i;
	printf("Enter the postfix notation: ");
	scanf(" %s", postfix);
	
	for (i=0;postfix[i]!='\0';i++) {
		struct node *newnode = (struct node*)malloc(sizeof(struct node));
		newnode->data=postfix[i];
		if (isalnum(postfix[i])) {
			newnode->left=NULL;
			newnode->right=NULL;
			push(newnode);
		} else {
			newnode->right = pop();
			newnode->left = pop(); 
			push(newnode);
		}
	}
	
	inorder(stack[top]);
}