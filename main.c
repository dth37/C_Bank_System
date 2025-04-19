#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
struct bank{
	char firstName[20];
	char middleName[20];
	char surName[20];
	char setUserName[40];
	char setPassword[50];
	char setPasswordConfirm[50];
	int choice;
	bool isLog;
	int balance;
};
//Global Variables
int j;

//Functions Declare
void registe(struct bank banka[100], int i);
void login(struct bank banka[100], int i);
void mainmenu(struct bank banka[100], int i);



int main()
{
	int i = 0;
	struct bank banka[100];
	banka->balance = 0;
	bool wh = true;
	while(wh == true)
	{
		system("cls");
		printf("*****Welcome to Bank System. What Do You Want to Do?*****\n\n*****1.Register*****\n\n*****2.Log In*****\n\n*****3.Exit*****\n: ");
		scanf("%d", &banka[i].choice);
		switch(banka[i].choice)
		{
			case 1:
				registe(banka, i);
				i++;
				break;
			case 2:
				login(banka, i);
				if(banka->isLog == true)
				{
					mainmenu(banka, i);
				}
				break;
			case 3:
				wh = false;
				break;
		}
	}
}



void registe(struct bank banka[100], int i)
{
	system("cls");
	printf("Enter your First Name: \n");
	scanf("%s", banka[i].firstName);
	printf("Enter your Middle Name: \n");
	scanf("%s", banka[i].middleName);
	printf("Enter your Surname: \n");
	scanf("%s", banka[i].surName);
	printf("Enter your Username: \n");
	scanf("%s", banka[i].setUserName);
	printf("Enter your Password: \n");
	scanf("%s", banka[i].setPassword);
	printf("Confirm your Password: \n");
	scanf("%s", banka[i].setPasswordConfirm);
	while(strcmp(banka[i].setPassword, banka[i].setPasswordConfirm))
	{
		printf("Passwords do not match. Please try again\n");
		printf("Enter your Password: \n");
		scanf("%s", banka[i].setPassword);
		printf("Confirm your Password: \n");
		scanf("%s", banka[i].setPasswordConfirm);
	}
	printf("Registering is successful. You can log in.");
	getchar();
	getchar();
	system("cls");
}

void login(struct bank banka[100], int i)
{
	char username[40];
	char password[50];
	int found = 0;
	printf("Enter your Username: \n");
	scanf("%s", username);
	printf("Enter your Password: \n");
	scanf("%s", password);
	for(j; j < i; j++)
	{
		if(strcmp(username, banka[j].setUserName) == 0 && strcmp(password, banka[j].setPassword) == 0)
		{
			found = 1;
			break;
		}
	}
	while(found != 1)
	{
		printf("Username or password are incorrect. Please try again\n");
		printf("Enter your Username: \n");
		scanf("%s", username);
		printf("Enter your Password: \n");
		scanf("%s", password);
		for(int j; j < i; j++)
		{
			if(strcmp(username, banka[j].setUserName) == 0 && strcmp(password, banka[j].setPassword))
			{
				found = 1;
				break;
			}
		}
	}
	banka->isLog = true;
	system("cls");
	printf("Log In is Successful");
	getchar();
	getchar();
}
void mainmenu(struct bank banka[100], int i)
{
	int found;
	int s; // For search
	char searchName[40];
	bool wh = true;
	int dd;
	while(wh == true)
	{
		printf("-----1.Check Balance-----\n\n");
		printf("-----2.Deposit Money-----\n\n");
		printf("-----3.Withdraw Money----\n\n");
		printf("-----4.Transfer Money----\n\n");
		printf("-----5.Log Out-----------\n: ");
		scanf("%d", &banka->choice);
		switch (banka->choice)
		{
			case 1:
				printf("Your Balance is %d", banka[j].balance);
				getchar();
				getchar();
				system("cls");
				break;
			case 2:
				system("cls");
				printf("How much money do you want to deposit?: ");
				scanf("%d", &dd);
				banka[j].balance += dd;
				printf("Process Successful");
				getchar();
				system("cls");
				break;
			case 3:
				printf("How much money do you want to withdraw: ");
				scanf("%d", &dd);
				banka[j].balance -= dd;
				printf("Process Successful");
				getchar();
				system("cls");
				break;
			case 4:
				printf("Which account do you want to transfer to?: ");
				scanf("%s", searchName);
				for(s = 0; s < i; s++)
				{
					if(strcmp(searchName, banka[s].setUserName) == 0)
					{
						found = 1;
						break;
					}
				}
				while(found != 1)
				{
					printf("User couldn't find. Please try again.\n\n");
					getchar();
					getchar();
					system("cls");
					printf("Which account do you want to transfer to?: ");
					scanf("%s", searchName);
					for(s = 0; s < i; s++)
					{
						if(strcmp(searchName, banka[s].setUserName) == 0)
						{
							found = 1;
							break;
						}
					}
				}
				printf("Account found. How much money to transfer?: ");
				scanf("%d", &dd);
				while(dd > banka[j].balance)
				{
					printf("You cannot transfer more money than you have. Please try again.\n\n");
					printf("Account found. How much money to transfer?: ");
					scanf("%d", &dd);
				}
				banka[s].balance += dd;
				banka[j].balance -= dd;
				system("cls");

				break;
			case 5:
				printf("Goodbye");
				wh = false;
				break;
		}
	}
	
}