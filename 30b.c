/*
Program Number : 30 - b
Name : Akash Upadhyay
Register Number : MT2024013
Date : 21/09/2024
Description : Program to create a shared memory.
                b. attach with O_RDONLY and check whether you are able to overwrite.
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

int main()
{
    key_t key = ftok(".", 'a');
    int shmid = shmget(key, 1024, 0);

    char *data = shmat(shmid, (void *)0, SHM_RDONLY);
    printf("Enter text to put in shared memory: ");
    scanf("%[^\n]s", data);

    printf("Write successful\n");
    shmdt(data);
    return (0);
}


// akash@DESKTOP-LD4J4EM:~/HandsOnList2$ ./a.out
// Enter text to put in shared memory: Akash
// Segmentation fault (core dumped)