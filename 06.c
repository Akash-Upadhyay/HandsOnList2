/*
Program Number : 06
Name : Akash Upadhyay
Register Number : MT2024013
Date : 21/09/2024
Description : Simple program to create three threads.
*/

#include <pthread.h>
#include <stdio.h>
// Use gcc 6.c -lpthread

void show_thread(void)
{
    printf("This is a thread\n");
}

int main()
{
    pthread_t t1, t2, t3;

    pthread_create(&t1, NULL, (void *)show_thread, NULL);
    pthread_create(&t2, NULL, (void *)show_thread, NULL);
    pthread_create(&t3, NULL, (void *)show_thread, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    return 0;
}

// akash@DESKTOP-LD4J4EM:~/HandsOnList2$ ./a.out
// This is a thread
// This is a thread
// This is a thread