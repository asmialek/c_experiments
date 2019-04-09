//
// Created by smial on 09/04/2019.
//

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t my_mutex = PTHREAD_MUTEX_INITIALIZER;
static int var = 0;


void print_var(pthread_mutex_t* local_mutex, char* name){
    while (1) {
        pthread_mutex_lock(local_mutex);
        var++;
        printf("Func %s: var is now %d\n", name, var);
        sleep(5);
        pthread_mutex_unlock(local_mutex);
    }
}

void* func_one(){
    print_var(&my_mutex, "1");
}

void* func_two(){
    print_var(&my_mutex, "2");
}

void* func_three(){
    while(1) {
//        pthread_mutex_lock(&my_mutex);
        printf("I'm just printing here.\n");
        sleep(1);
//        pthread_mutex_unlock(&my_mutex);
    }
}

int main(){
    func_one();
//    pthread_t one, two, three;
//    pthread_create(&one, NULL, func_one, NULL);
//    pthread_create(&two, NULL, func_two, NULL);
//    pthread_create(&three, NULL, func_three, NULL);
//    pthread_join(three, NULL);
}