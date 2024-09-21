/*
Program Number : 31
Name : Akash Upadhyay
Register Number : MT2024013
Date : 21/09/2024
Description : Program to create a semaphore and initialize value to the semaphore.
                a. create a binary semaphore
                b. create a counting semaphore
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <sys/ipc.h>

union semun
{
    int val;                   // Value for SETVAL
    struct semid_ds *buf;      // Buffer for IPC_STAT, IPC_SET.
    unsigned short int *array; // Array for GETALL, SETALL.
};

// Creating binary semaphore and initializing value to the semaphore.
int main()
{
    union semun arg;
    key_t k = ftok(".", 'a');
    int semid = semget(k, 1, IPC_CREAT | 0666);

    int choice;
    printf("Choose an option:\n1.) Binary Semaphore\n2.) Counting Semaphore\n=> ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("Creating binary semaphore\n");
        arg.val = 1; // Binary semaphore.
        break;
    case 2:
        printf("Creating counting semaphore\n");
        arg.val = 5; // Counting semaphore.
        break;
    default:
        printf("Invalid choice\n");
        break;
    }
    
    // Set value of semaphore.
    semctl(semid, 0, SETVAL, arg);
    return (0);
}

// akash@DESKTOP-LD4J4EM:~/HandsOnList2$ ./a.out
// Choose an option:
// 1.) Binary Semaphore
// 2.) Counting Semaphore
// => 1
// Creating binary semaphore
// akash@DESKTOP-LD4J4EM:~/HandsOnList2$ ./a.out
// Choose an option:
// 1.) Binary Semaphore
// 2.) Counting Semaphore
// => 2
// Creating counting semaphore