//
// Created by janlc on 3/18/2021.
//
#include "user.h"
#include "bankSystem.h"

int main(){
    //login and signup
    struct Person person = menu();

    account_menu(person);

    return 0;
}