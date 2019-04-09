//
// Created by smial on 05/04/2019.
//

#include <stdio.h>
#include <stdlib.h>

void foo(int *a){
    printf("\n-foo-------\n");
    printf("%d\n", a);
    printf("%x\n", a);
    printf("%d\n", *a);
    printf("%x\n", *a);
}

void bar(int a){
    printf("\n-bar-------\n");
    printf("%d\n", a);
    printf("%x\n", a);
    printf("%d\n", &a);
    printf("%x\n", &a);
}

void main(){
    int a = 13;
//    foo(a);
    foo(&a);
    bar(a);
    bar(&a);
}

//int main() {
//    int a = 5;
//    printf("%d\n", a);
//
//    int *b, *c, *d, *e;
//    b = 10;
//    c = a;
//    d = &a;
//    *e = a;
//    printf("%d\n", a);
//    printf("%x\n", &a);
//    printf("%d\n", b);
//    printf("%x\n", &b);
//    printf("%d\n", c);
//    printf("%x\n", &c);
//    printf("%d\n", d);
//    printf("%x\n", &d);
//    printf("%d\n", e);
//    printf("%x\n", &e);
//    return 0;
//}

//int foo(int* a){
//    return a;
//}
//
//int bar(int a){
//    return a;
//}
//
//void foobar(int* a){
//    *a = 13;
//}
//
//void foobar(int a){
//    *a = 23;
//}
//
//void main(){
//    int var = 3;
//    printf("%d\n", foo(var));
//    printf("%x\n", foo(&var));
//    printf("%d\n", bar(var));
//    printf("%x\n", bar(&var));
//    printf("%d\n", var);
//    printf("%x\n", &var);
////    foobar(var);
//    foobar(&var);
//    printf("%d\n", var);
//    printf("%x\n", &var);
//}