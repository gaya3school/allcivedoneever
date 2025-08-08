#include <stdio.h>
#include <stdlib.h>

struct accdetails {
	int accnumber;
	char pin[6];
	float balance; 
	struct accdetails *link;
};
typedef struct accdetails accdetails;
accdetails *head = NULL;

void create_account (/*accdetails*head, */int accnumber, char pin[], float balance)
{
	accdetails *new_account, *temp;
	new_account = (accdetails *)malloc(sizeof(accdetails));
	
	new_account -> accnumber = accnumber;
	new_account -> pin = pin[];
	new_account -> balance = balance;
	
	if (head==NULL)
	{
		head = new_account;
		new_account -> link = NULL;
	}
	else
	{
		temp = head; 
		while (temp!=NULL)
		{
			temp = temp -> link;
		}
		temp = new_account;
		new_account -> link = NULL;
	}
}

void deposit (float depositedamt)
{
	
}

void withdrawal ()
{
	
}

void displaybalance()
{
	
}

void fundtransfer()
{
	
}

/*int authentication(char pin[6], int accnumber)
{
	fopen ("filename", "r");
	
	search file for account number
	
	if (accnumber exists)
	{
		get that accounts pin; 
		verify if the pin given is equal to the pin stored
		if it is equal
		return 1;
		else
		return 0;
	}
	
	accnmuber does not exist; 
	return -1; (in main print to ask to create account);
} */
