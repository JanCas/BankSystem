//
// Created by janlc on 3/17/2021.
//
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "user.h"
#include "file_utils.h"

char filename_people[] = "data_people.dat";

struct Person login(){
    char username[20], password[20];
    struct Person person;

    FILE *file = open_file_read(filename_people);

    printf("username: ");
    scanf("%s", &username);
    printf("\n");

    printf("password: ");
    scanf("%s", &password);
    printf("\n");

    while(fread(&person, sizeof(struct Person), 1, file)){
        if (!strcmp(person.username, username) && !strcmp(person.password, password)){
            return person;
        }
    }
    printf("Could not find you in file");
    fclose(file);
}

bool does_username_exist(char username[]){
    FILE *data_file;
    struct Person person;

    data_file = open_file_read(filename_people);

    while(fread(&person, sizeof(struct Person), 1, data_file)){
        if (!strcmp(person.username, username)){
            return true;
        }
    }
    return false;
}

struct Person sign_up(){
    struct Person person;
    struct Date date;
    FILE *file;

    char username[20], password[20], first_name[50], last_name[50];
    int day, month, year;

    printf("username: ");
    scanf("%s", &username);
    printf("\n");
    while (does_username_exist(username)){
        printf("This username already exists\n");
        printf("username: ");
        scanf("%s", &username);
        printf("\n");
    }

    printf("password: ");
    scanf("%s", &password);
    printf("\n");

    printf("Firs Name: ");
    scanf("%s", &first_name);
    printf("\n");

    printf("Last Name: ");
    scanf("%s", &last_name);
    printf("\n");

    printf("DOB (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &day, &month, &year);
    printf("\n");

    date.Day = day;
    date.Month = month;
    date.Year = year;

    strcpy(person.first_name,first_name);
    strcpy(person.last_name, last_name);
    strcpy(person.password, password);
    strcpy(person.username, username);
    person.dob = date;

    file = open_file_write(filename_people);

    fwrite(&person, sizeof(struct Person), 1, file);

    fclose(file);

    return person;
}

struct Person menu(){
    int choice;

    printf("1. Login\n");
    printf("2. Sign Up\n");
    printf("\n");

    printf("Please enter your choice: ");
    scanf("%d", &choice);

    switch (choice){
        case 1:
            return login();
        case 2:
            return sign_up();
    }
}
