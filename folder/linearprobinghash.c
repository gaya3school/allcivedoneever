#include <stdio.h>
#include <stdlib.h>

#define size 10
int HT[size];
int count=0;

void innit (){
	int i=0;
	while (i<size) {
		HT[i] = -1;
		i++;
	}
}

void insert (int value) {
	int index = value % size;
	int si = index;
	if (count == size) {
        printf("List is full\n");
        return;
    }

	if (HT[index] == -1)
		HT[index] = value;
	else {
		while (HT[index]!=-1) {
			index = (index+1)%size;	
			if (index==si) {
            	printf("List is full\n");
            	return;
        	}		
		}
		HT[index] = value;
		count++;
	}
}

void display() {
	int i;
	for (i=0;i<size;i++) {
		printf("%d(index) - %d\n", i, HT[i]);
	}	
	printf("\n");
}

void search (int value) {
	int index = value % size;
	int si = index;
	if (HT[index]==-1) {
		printf("Value not found\n");
		return;
	} else if (HT[index]!=-1 && HT[index]!=value) {
		while (HT[index]!=value) {
			if (HT[index] == -1 || (index + 1) % size == si) {
            	printf("Value not found\n");
            	return;
        	}
			index = (index+1)%size;			
		}
		
		printf("Value found at index %d and position %d\n", index, index+1);
	} else {
		printf("Value found at index %d and position %d\n", index, index+1);
		return;
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
				printf("Enter value to search for: ");
				scanf(" %d", &value);
				
				search(value);
				break;
			default:
				printf("Invalid choice\n");
		}
	}
}