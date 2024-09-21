/*
Program Number : 30 - d
Name : Akash Upadhyay
Register Number : MT2024013
Date : 21/09/2024
Description : Program to create a shared memory.
                d. remove the shared memory
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

int main()
{
    key_t key = ftok(".", 'a');
    int shmid = shmget(key, 1024, 0);

    if (shmctl(shmid, IPC_RMID, NULL) == -1)
    {
        printf("Delete unsuccessful\n");
    }
    else
    {
        printf("Delete successful\n");
    }

    return (0);
}

// akash@DESKTOP-LD4J4EM:~/HandsOnList2$ ./a.out
// Delete successful