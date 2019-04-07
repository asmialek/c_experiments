//
// Created by smial on 05/04/2019.
//


#include <stdio.h>
#include <stdlib.h>

#include "struct.h"

book book2;

typedef struct Books {
    int title;
    char author[50];
} book;

struct Books* foo() {
    book* temp = 0;
    return temp;
}

int main() {
    book book1;
    book1.title = 10;
    book2.title = 12;
    printf("%d\n", book1.title);
    printf("%d\n", book2.title);

//    printf("%x\n", book2);
//    printf("%x\n", book2*);
}