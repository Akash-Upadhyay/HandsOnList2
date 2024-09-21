/*
Program Number : 24
Name : Akash Upadhyay
Register Number : MT2024013
Date : 21/09/2024
Description : Program to create a message queue and print the key and message queue id.
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>

// Create a message queue.
int main()
{
    key_t key = ftok(".", 'a');
    int msqid = msgget(key, IPC_CREAT | 0666);
    printf("Key: %d, ID: %d\n", key, msqid);
    return(0);
}


// akash@DESKTOP-LD4J4EM:~/HandsOnList2$ ./a.out
// Key: 1627557603, ID: -1