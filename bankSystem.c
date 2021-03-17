#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char filename[] = "data.dat";

struct Date {
	int Day, Month, Year;
}

struct Person {
	char first_name[50];
	char last_name{50};
	struct Date dob;
};

struct Account {
	float amount;
	int id;
	struct Person owner;
};

void account_str(struct Account account){
	printf("Account ID: %d \n", account.id);
	printf("Account amout: $%.2f \n", account.amount);
}

void write_account(struct Account account){
	FILE *data_file;

	data_file = fopen(filename, "w");
	if (data_file == NULL){
		fprintf(stderr, "\n Error opening file \n");
		exit(1);
	}

	fwrite(&account, sizeof(struct Account), 1, data_file);

	if (fwrite == 0){
		printf("Account store successfully");
	} else {
		printf("error writing to file! \n");
	}

	fclose(data_file);
}


void open_acc(){
	time_t t;

	struct Account account;
	float amt;
	printf("How much money is there in this account: ");
	scanf("%f", &amt);
	account.amount = amt;
	
	srand((unsigned) time(&t));
	account.id = rand();

	account_str(account);
	write_account(account);
	printf("Account successfully stored \n");
}

struct Account read_by_id(int id){
	FILE *data_file;
	struct Account account;
	
	data_file = fopen(filename, "r");
	if (data_file == NULL){
		fprintf(stderr, "\n Error opening the file \n");
		exit(1);
	}
	
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

int main(){
	int choice, id;
	
	printf("1. Open a new account\n");
	printf("2. Read Account");
	printf("\n");
	printf("Please enter your choice: ");	
	scanf ("%d", &choice);

	switch(choice){
		case 1:
			open_acc();
			break;
		case 2:
			printf("The ID of your bank Account: ");
			scanf("%d", &id);

			read_account(id);
			break;	

	}

	return -1;
}