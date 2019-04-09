//
// Created by smial on 09/04/2019.
//

#include <stdlib.h>
#include <stdio.h>

int array_printer(int array[], int array_size){
    printf("Printing array of size %d:\n", array_size);
    for (int i = 0; i < array_size; ++i) {
        printf("> %d\n", *array);
        array++;
    }
    return 0;
}

int main(){
    int one[] = {1, 2, 3, 4, 5, 6};
    array_printer(&one, sizeof(one)/sizeof(one[0]));

    int two = 2;
    array_printer(&two, 1);

    return 0;
}