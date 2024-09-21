/*
Program Number : 30 - c
Name : Akash Upadhyay
Register Number : MT2024013
Date : 21/09/2024
Description : Program to create a shared memory.
                c. detach the shared memory
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

int main()
{
    key_t key = ftok(".", 'a');
    int shmid = shmget(key, 1024, IPC_CREAT | 0666);

    char *data = shmat(shmid, (void *)0, 0);
    printf("Detaching\n");
    shmdt(data);

    return (0);
}


// akash@DESKTOP-LD4J4EM:~/HandsOnList2$ ./a.out
// Detaching