#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "user.h"
#include "bankSystem.h"
#include "file_utils.h"
#include <stdbool.h>

char filename[] = "data.dat";

struct Account {
	float amount;
	int id;
	struct Person owner;
};

void account_str(struct Account account){
	printf("Account ID: %d \n", account.id);
	printf("Account amout: $%.2f \n", account.amount);
	printf("Account owner %s - %s\n", account.owner.first_name, account.owner.last_name);
}

void write_account(struct Account account){
	FILE *data_file;

	data_file = open_file_write(filename);
	fwrite(&account, sizeof(struct Account), 1, data_file);
	fclose(data_file);
}


void open_acc(struct Person person){
	time_t t;

	struct Account account;
	float amt;
	printf("How much money is there in this account: ");
	scanf("%f", &amt);
	account.amount = amt;
	
	srand((unsigned) time(&t));
	account.id = rand();

	account.owner = person;

	account_str(account);
	write_account(account);
	printf("Account successfully stored \n");
}

struct Account read_by_id(int id){
	FILE *data_file;
	struct Account account;
	
	data_file = open_file_read(filename);
	
	while(fread(&account, sizeof(struct Account), 1, data_file)){
		if (account.id == id){
			return account;
		}
	}
}

void read_account(int id){
	struct Account account = read_by_id(id);
	account_str(account);
}

void show_all_accounts(struct Person person) {
    FILE *file = open_file_read(filename);
    struct Account account;

    while(fread(&account, sizeof(struct Account), 1, file)){
        if (struct_is_same(account.owner, person)){
            account_str(account);
            printf("\n");
        }
    }
}

void account_menu(struct Person person){
	int choice, id;
	
	printf("1. Open a new account\n");
	printf("2. Read Account by Id\n");
	printf("3. Display all accounts\n");
	printf("\n");
	printf("Please enter your choice: ");	
	scanf ("%d", &choice);

	switch(choice){
		case 1:
			open_acc(person);
			break;
		case 2:
			printf("The ID of your bank Account: ");
			scanf("%d", &id);

			read_account(id);
			break;
	    case 3:
	        printf("---------------- \n");
	        show_all_accounts(person);
	        printf("---------------- \n");
	        break;

	}
}