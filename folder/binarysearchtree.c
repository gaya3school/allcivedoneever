#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node *left;
	int data;
	struct node *right;
} *root = NULL;

void insert (struct node *temp, struct node *newnode);

void create (int ele) {
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
	if (newnode->data < temp->data) {
		if (temp->left == NULL)
			temp->left = newnode;
		else
			insert(temp->left, newnode);
	} else if (newnode->data >= temp->data) {
		if (temp->right==NULL)
			temp -> right = newnode;
		else
			insert (temp->right, newnode);
	}
}

int recsearch(int key, struct node *temp, int level) {
    if (temp == NULL) {
        return 0;
    }

    if (key < temp->data) {
		return recsearch(key, temp->left, level+1);
	}
    else if (key > temp->data) {
        return recsearch(key, temp->right, level+1);                
	} else {
		printf("Found at level %d\n", level);
		return 1;
	}
}

int nonrecsearch(int key, struct node *temp) {
	int level=0;
	while (temp!=NULL) {
		if (temp->data == key) {
			printf("Element was found at %d\n", level);
			return 1;
		} else if (temp->data>key) {
			temp=temp->left;
			level++;
		} else {
			temp=temp->right;
			level++;
		}
	}
	return 0;
}

void inorder(struct node *temp) {
	if (temp!=NULL) {
		inorder(temp->left);
		printf("%d -> ", temp->data);
		inorder(temp->right);
	}
}

void preorder(struct node *temp) {
	if (temp!=NULL) {
		printf("%d -> ", temp->data);
		preorder(temp->left);
		preorder(temp->right);
	}
}

void postorder (struct node *temp) {
	if (temp!=NULL) {
		postorder(temp->left); 
        postorder(temp->right); 
        printf("%d -> ", temp->data); 
	}
}

struct node *findmin(struct node *temp) {
	while (temp->left!=NULL) {
		temp = temp->left;
	}
	//printf("The minimum element is %d", temp->data);
	return temp;
}

int findmax() {
	struct node *temp=root;
	while (temp->right!=NULL) {
		temp = temp->right;
	}
	return temp->data;
}

void delete (int ele) {
    struct node *temp = root, *prev = NULL, *del;
    
    while (temp != NULL) {
        if (temp->data == ele) {
            if (temp->left == NULL && temp->right == NULL) {
                if (prev == NULL) {
                    root = NULL;
                } else if (prev->left == temp) {
                    prev->left = NULL;
                } else {
                    prev->right = NULL;
                }
                free(temp);
                return;
            } else if (temp->right == NULL) { // <- has left child
                if (prev == NULL) {
                    root = temp->left;
                } else if (prev->left == temp) { // <-- the temp node is the left child of the previous node and its got left child
                    prev->left = temp->left;
                } else { // <-- the temp node is the right child of the previous node and its got a left child
                    prev->right = temp->left;
                }
                free(temp);
                return;
            } else if (temp->left == NULL) { 
                if (prev == NULL) {
                    root = temp->right;
                } else if (prev->left == temp) {
                    prev->left = temp->right;
                } else {
                    prev->right = temp->right;
                }
                free(temp);
                return;
            } else {
                del = findmin(temp->right);
                temp->data = del->data;
                
                prev = temp;
                temp = temp->right;
                while (temp != NULL && temp->data != del->data) {
                    prev = temp;
                    temp = temp->left;
                }
                
                if (del->right == NULL) {
                    if (prev->left == del) {
                        prev->left = del->left;
                    } else {
                        prev->right = del->left;
                    }
                } else {
                    if (prev->left == del) {
                        prev->left = del->right;
                    } else {
                        prev->right = del->right;
                    }
                }
                
                free(del);
                return;
            }
        }
        prev = temp;
        if (ele < temp->data) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }
    
    printf("Element not found\n");
}

int main() {
	int choice, data, key;
	printf("0 - Exit\n1 - Create\n2 - Search\n3 - Inorder\n4 - Preorder\n5 - Postorder\n6 - Maximum\n7 - Minimum\n8 - Search2.0\n9 - Delete\n");
	
	while (1) {
		printf("Enter choice: ");
		scanf(" %d", &choice);
		
		switch (choice) {
			case 0: 
				return 0;
			case 1: 
				printf("Enter data: ");
				scanf(" %d", &data);
				create(data);
				break;
			case 2:
				printf("Enter element to search for: ");
				scanf(" %d", &key);
				if (!recsearch(key, root, 0)) 
					printf("Element was not found\n");
				break;
			case 3:
				inorder(root);
				printf("NULL \n")				;
				break;
			case 4:
				preorder(root);
				printf("NULL \n");
				break;
			case 5:
				postorder(root);
				printf("NULL \n");
				break;
			case 6:
				printf("The maximum element is %d\n", findmax());
				break;
			case 7:
				printf("The minimum element is %d\n", findmin(root)->data);
				break;
			case 8:
				printf("Enter element to search for: ");
				scanf(" %d", &key);
				
				if (!nonrecsearch(key, root))
					printf("Element was not found\n");
				break;
			case 9:
				printf("Enter element to delete: ");
				scanf(" %d", &key);
				
				delete(key);
				break;
			default: printf("Invalid choice. \n");
		}
	}

}