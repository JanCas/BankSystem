//
// Created by janlc on 3/17/2021.
//

#ifndef BANKSYSTEM_USER_H
#define BANKSYSTEM_USER_H

struct Date {
    int Day, Month, Year;
};

struct Person {
    char username[50];
    char first_name[50];
    char last_name[50];
    struct Date dob;
    char password[20];
};

struct Person menu();
bool struct_is_same(struct Person p1, struct Person p2);

#endif //BANKSYSTEM_USER_H
