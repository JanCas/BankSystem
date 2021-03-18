//
// Created by janlc on 3/17/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include "file_utils.h"

void create_file(char filename[]){
    FILE *file = fopen(filename, "w");
    fclose(file);
}

FILE *open_file_read(char filename[]){
    FILE *file;
    file = fopen(filename, "r");
    if (file){
        return file;
    }
    else if (file == NULL){
        printf(stderr, "\n Error opening the file \n");
        exit(1);
    } else {
        printf("I was here");
        create_file(filename);
        open_file_read(filename);
    }
    return file;
}

FILE *open_file_write(char filename[]){
    FILE *file;
    file = fopen(filename, "w");

    if (file == NULL) {
        printf(stderr, "\n Error opening the file \n");
        exit(1);
    }
    return file;
}